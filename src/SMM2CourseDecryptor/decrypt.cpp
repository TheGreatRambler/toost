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

bool LevelDecryptor::decrypt(std::string& input, std::string& output) {
	std::size_t sz = input.size();

	struct AES_ctx ctx;

	uint32_t rand_state[STATE_SIZE];
	uint32_t key_state[STATE_SIZE];

	if(sz == 0x5C000) {
		uint8_t* end = (uint8_t*)input.data() + 0x5BFD0;

		rand_init(
			rand_state, *(uint32_t*)&end[0x10], *(uint32_t*)&end[0x14], *(uint32_t*)&end[0x18], *(uint32_t*)&end[0x1C]);
		gen_key(course_key_table, key_state, rand_state);

		AES_init_ctx_iv(&ctx, (uint8_t*)key_state, end);
		AES_CBC_decrypt_buffer(&ctx, (uint8_t*)input.data() + 0x10, 0x5BFC0);

		output.resize(0x5BFC0);
		memcpy(output.data(), input.data() + 0x10, 0x5BFC0);
		return true;
	} else {
		return false;
	}
}