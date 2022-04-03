#pragma once

#include <cairo.h>
#include <filesystem>
#include <fmt/core.h>
#include <imgui/imgui_impl_opengl3.h>

#if defined(IMGUI_IMPL_OPENGL_ES2) || defined(__EMSCRIPTEN__)
#include <SDL_opengles2.h>
#else
#include <SDL_opengl.h>
#endif

#ifdef _WIN32
#include <Windows.h>
#else
#include <limits.h>
#include <unistd.h>
#endif

namespace Helpers {
	std::filesystem::path GetExecutableDirectory();
	bool LoadTextureFromSurface(cairo_surface_t* surface, GLuint* out_texture, int* out_width, int* out_height);
}