#include "decrypt.h"
#include "keys.h"

void LevelDecryptor::rand_init(uint32_t* rand_state, uint32_t in1, uint32_t in2, uint32_t in3, uint32_t in4) {
	int cond = in1 | in2 | in3 | in4;

	rand_state[0] = cond ? in1 : 1;
	rand_state[1] = cond ? in2 : 0x6C078967;
	rand_state[2] = cond ? in3 : 0x714ACB41;
	rand_state[3] = cond ? in4 : 0x48077044;
}

uint32_t LevelDecryptor::rand_gen(uint32_t* rand_state) {
	uint32_t n    = rand_state[0] ^ rand_state[0] << 11;
	rand_state[0] = rand_state[1];
	n ^= n >> 8 ^ rand_state[3] ^ rand_state[3] >> 19;
	rand_state[1] = rand_state[2];
	rand_state[2] = rand_state[3];
	rand_state[3] = n;
	return n;
}

void LevelDecryptor::gen_key(uint32_t* key_table, uint32_t* out_key, uint32_t* rand_state) {
	out_key[0] = 0;

	for(int i = 0; i < STATE_SIZE; i++) {
		for(int j = 0; j < NUM_ROUNDS; j++) {
			out_key[i] <<= 8;
			out_key[i] |= (key_table[rand_gen(rand_state) >> 26] >> ((rand_gen(rand_state) >> 27) & 24)) & 0xFF;
		}
	}
}

bool LevelDecryptor::decrypt(const char* input, const char* output) {
	FILE* in  = fopen(input, "rb");
	FILE* out = fopen(output, "wb");

	fseek(in, 0, SEEK_END);
	size_t sz = ftell(in);
	rewind(in);

	struct AES_ctx ctx;

	uint32_t rand_state[STATE_SIZE];
	uint32_t key_state[STATE_SIZE];

	switch(sz) // CMAC calculation isn't handled yet, will implement eventually
	{
	case 0x1C000: // Thumbnail image data
	{
		uint8_t* buf = (uint8_t*)malloc(0x1C000);

		fread(buf, 1, 0x1C000, in);
		fclose(in);

		uint8_t* end = buf + sz - 0x30;

		rand_init(
			rand_state, *(uint32_t*)&end[0x10], *(uint32_t*)&end[0x14], *(uint32_t*)&end[0x18], *(uint32_t*)&end[0x1C]);
		gen_key(thumb_key_table, key_state, rand_state);

		AES_init_ctx_iv(&ctx, (uint8_t*)key_state, end);
		AES_CBC_decrypt_buffer(&ctx, buf, sz - 0x30);

		fwrite(buf, 1, sz - 0x30, out);
		fclose(out);

		free(buf);

		break;
	}

	case 0x5C000: // Course data
	{
		uint8_t* buf = (uint8_t*)malloc(0x5C000);

		fread(buf, 1, 0x5C000, in);
		fclose(in);

		uint8_t* end = buf + sz - 0x30;

		rand_init(
			rand_state, *(uint32_t*)&end[0x10], *(uint32_t*)&end[0x14], *(uint32_t*)&end[0x18], *(uint32_t*)&end[0x1C]);
		gen_key(course_key_table, key_state, rand_state);

		AES_init_ctx_iv(&ctx, (uint8_t*)key_state, end);
		AES_CBC_decrypt_buffer(&ctx, buf + 0x10, sz - 0x40);

		fwrite(buf + 0x10, 1, sz - 0x40, out);
		fclose(out);

		free(buf);

		break;
	}

	case 0x68000: // Replay data
	{
		uint8_t* buf = (uint8_t*)malloc(0x68000);

		fread(buf, 1, 0x68000, in);
		fclose(in);

		uint8_t* end = buf + sz - 0x30;

		rand_init(
			rand_state, *(uint32_t*)&end[0x10], *(uint32_t*)&end[0x14], *(uint32_t*)&end[0x18], *(uint32_t*)&end[0x1C]);
		gen_key(replay_key_table, key_state, rand_state);

		AES_init_ctx_iv(&ctx, (uint8_t*)key_state, end);
		AES_CBC_decrypt_buffer(&ctx, buf, sz - 0x30);

		fwrite(buf, 1, sz - 0x30, out);
		fclose(out);

		free(buf);

		break;
	}

	default: {
		puts("Error: Unsupported file!");
		fclose(in);
		fclose(out);
		return false;
	}
	}

	return true;
}