#include "Helpers.hpp"

std::filesystem::path Helpers::GetExecutableDirectory() {
#ifdef _WIN32
	wchar_t path[MAX_PATH] = { 0 };
	GetModuleFileNameW(NULL, path, MAX_PATH);
	return path;
#else
	char result[PATH_MAX];
	ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);
	return std::string(result, (count > 0) ? count : 0);
#endif
}

bool Helpers::LoadTextureFromSurface(cairo_surface_t* surface, GLuint* out_texture, int* out_width, int* out_height) {
	// Load from file
	int image_width  = cairo_image_surface_get_width(surface);
	int image_height = cairo_image_surface_get_height(surface);
	cairo_surface_flush(surface);
	uint32_t* image_data = (uint32_t*)cairo_image_surface_get_data(surface);
	if(image_data == NULL)
		return false;

	/*
	cairo_pattern_t* pattern = cairo_pattern_create_for_surface(surface);
	cairo_pattern_set_filter(pattern, CAIRO_FILTER_NEAREST);
	int new_width                = image_width * scale;
	int new_height               = image_width * scale;
	cairo_surface_t* new_surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, new_width, new_height);
	cairo_t* cr                  = cairo_create(new_surface);
	cairo_scale(cr, scale, scale);
	cairo_set_source(cr, pattern);
	cairo_paint(cr);
	cairo_pattern_destroy(pattern);
	*/

	int image_data_pixels = image_width * image_height;
	// Need to convert from cairo ARGB to OpenGL RGBA
	uint32_t* fixed_image_data = (uint32_t*)malloc(image_data_pixels * 4);
	for(int i = 0; i < image_data_pixels; i++) {
		uint32_t pixel      = image_data[i];
		fixed_image_data[i] = ((pixel & 0x00FF0000) >> 16) | ((pixel & 0x0000FF00)) | ((pixel & 0x000000FF) << 16)
							  | ((pixel & 0xFF000000));
	}

	// Create a OpenGL texture identifier
	GLuint image_texture;
	glGenTextures(1, &image_texture);
	glBindTexture(GL_TEXTURE_2D, image_texture);

	// Setup filtering parameters for display
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
		GL_CLAMP_TO_EDGE); // This is required on WebGL for non power-of-two textures
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Same

	// Upload pixels into texture
#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
	glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE,
		(unsigned char*)fixed_image_data);

	free(fixed_image_data);

	*out_texture = image_texture;
	*out_width   = image_width;
	*out_height  = image_height;

	return true;
}