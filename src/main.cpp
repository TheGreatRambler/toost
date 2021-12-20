#include "Drawers.hpp"
#include "Helpers.hpp"
#include "LevelParser.hpp"

#include <SDL.h>
#include <cairo-ft.h>
#include <cairo.h>
#include <chrono>
#include <cstdio>
#include <cxxopts.hpp>
#include <filesystem>
#include <fmt/core.h>
#include <fstream>
#include <gzip/decompress.hpp>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_sdl.h>
#include <iterator>
#include <stdio.h>
#include <thread>
#include <vector>

#ifdef _WIN32
#include <Windows.h>
#endif

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/bind.h>
#include <emscripten/html5.h>
#include <freetype.h>
using namespace emscripten;
#else
#include <freetype/freetype.h>
#include <portable-file-dialogs.h>
#endif

#if defined(IMGUI_IMPL_OPENGL_ES2) || defined(__EMSCRIPTEN__)
#include <SDL_opengles2.h>
#else
#include <SDL_opengl.h>
#endif

SDL_Window* window          = nullptr;
SDL_GLContext gl_context    = nullptr;
bool done                   = false;
ImVec4 clear_color          = ImVec4(0.69f, 0.54f, 0.41f, 1.00f);
uint64_t new_window_counter = 0;
FT_Library freetype_library;
FT_Face main_font;
std::string assetsFolder;
int focused_window_index        = -1;
int cached_focused_window_index = -1;
std::vector<std::string> cached_focused_window_info;

struct LevelWindow {
	int level_render_width  = 0;
	int level_render_height = 0;
	std::string filename;
	uint64_t window_id;
	GLuint level_render_image = 0;
	LevelParser level;
};

std::vector<LevelWindow> opened_level_windows;

void DrawMap(LevelParser& level, bool isOverworld, bool log, std::string destination) {
	Drawers drawer(level);

	drawer.Setup();
	drawer.SetZoom(16);
	drawer.SetIsOverworld(isOverworld);
	drawer.SetLog(log);

	puts("Set zoom");

	cairo_surface_t* surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, drawer.GetWidth(), drawer.GetHeight());
	cairo_t* cr              = cairo_create(surface);

	cairo_font_face_t* font = cairo_ft_font_face_create_for_ft_face(main_font, 0);
	cairo_set_font_face(cr, font);
	cairo_font_face_destroy(font);

	fmt::print("Width: {}\nHeight: {}\n", drawer.GetWidth(), drawer.GetHeight());

	drawer.SetGraphics(cr);

	puts("Set graphics");

	std::string tilesheet = fmt::format("{}/img/tile/{}-{}{}.png", level.PT, level.LH.GameStyle, level.MapHdr.Theme,
		(level.MapHdr.Flag == 2) ? "A" : "");
	drawer.SetTilesheet(tilesheet);

	fmt::print("Set tilesheet to {}\n", tilesheet);

	drawer.DrawGridlines();

	// 3D平台
	//半碰撞
	//蘑菇平台
	//桥
	//蘑菇跳台
	//开关跳台
	drawer.DrawItem({ 132 }, false);
	drawer.DrawItem({ 16 }, false);
	drawer.DrawItem({ 14 }, false);
	drawer.DrawItem({ 17 }, false);
	drawer.DrawItem({ 113 }, false);
	drawer.DrawItem({ 71 }, false);

	puts("Draw first bunch");

	//箭头 单向板 中间旗 藤蔓

	drawer.DrawItem({ 66, 67, 106 }, false);
	drawer.DrawItem({ 64 }, false);
	drawer.DrawItem({ 90 }, false);

	puts("Draw second bunch");

	//树 长长吞食花
	drawer.DrawItem({ 106, 107 }, false);

	puts("Draw third bunch");

	//地面 传送带 开关 开关砖 P砖 冰锥
	//斜坡单独
	drawer.ReGrdCode();
	drawer.DrawGrd();
	// DrawSlope()
	drawer.DrawGrdCode();

	puts("Draw grid");

	drawer.DrawItem({ 53, 94, 99, 100, 79 }, false);
	drawer.DrawIce();

	puts("Draw ice");

	//无LINKE
	//管道 门 蛇 传送箱
	drawer.DrawItem({ 9, 55, 84, 97 }, false);
	//机动砖 轨道砖
	drawer.DrawItem({ 85, 119 }, false);
	//夹子
	drawer.DrawItem({ 105 }, false);
	//轨道
	drawer.DrawTrack();
	//软砖 问号 硬砖 竹轮 云 音符 隐藏 刺 冰块 闪烁砖
	drawer.DrawItem({ 4, 5, 6, 21, 22, 23, 29, 43, 63, 110, 108 }, false);

	puts("Draw fourth bunch");

	//跷跷板 熔岩台 升降台
	drawer.DrawItem({ 91, 36, 11 }, false);

	//狼牙棒
	drawer.DrawItem({ 83 }, false);

	//齿轮 甜甜圈
	drawer.DrawItem({ 68, 82 }, false);

	puts("Draw fifth bunch");

	//道具
	drawer.DrawItem({ 0, 1, 2, 3, 8, 10, 12, 13, 15, 18, 19, 20, 25, 28, 30, 31, 32, 33, 34, 35, 39 }, false);
	drawer.DrawItem({ 40, 41, 42, 44, 45, 46, 47, 48, 52, 56, 57, 58, 60, 61, 62, 70, 74, 76, 77, 78, 81, 92, 95, 98,
						102, 103, 104 },
		false);
	drawer.DrawItem(
		{ 111, 120, 121, 122, 123, 124, 125, 126, 112, 127, 128, 129, 130, 131, 72, 50, 51, 65, 80, 114, 116 }, false);
	drawer.DrawItem({ 96, 117, 86 }, false);
	//喷枪 火棍
	drawer.DrawItem({ 24, 54 }, false);

	puts("Draw sixth bunch");

	// DrawFireBar(False)
	// DrawFire(False)
	//夹子
	drawer.DrawItem({ 105 }, false);
	//轨道
	drawer.DrawTrack();
	//夹子
	drawer.DrawItem({ 105 }, true);
	//卷轴相机
	// DrawItem("/89/", False)

	puts("Draw seventh bunch");

	// LINK
	//软砖 问号 硬砖 竹轮 云 音符 隐藏 刺 冰块
	drawer.DrawItem({ 4, 5, 6, 21, 22, 23, 29, 43, 63 }, true);

	//跷跷板 熔岩台 升降台
	drawer.DrawItem({ 91, 36, 11 }, true);

	//齿轮 甜甜圈
	drawer.DrawItem({ 68, 82 }, true);

	puts("Draw eigth bunch");

	//道具
	drawer.DrawItem({ 0, 1, 2, 3, 8, 10, 12, 13, 15, 18, 19, 20, 25, 28, 30, 31, 32, 33, 34, 35, 39 }, true);
	drawer.DrawItem({ 40, 41, 42, 44, 45, 46, 47, 48, 52, 56, 57, 58, 60, 61, 62, 70, 74, 76, 77, 78, 81, 92, 95, 98,
						102, 103, 104 },
		true);
	drawer.DrawItem(
		{ 111, 120, 121, 122, 123, 124, 125, 126, 112, 127, 128, 129, 130, 131, 72, 50, 51, 65, 80, 114, 116 }, true);
	drawer.DrawItem({ 96, 117, 86 }, true);

	puts("Draw ninth bunch");

	drawer.DrawCID();

	//喷枪 火棍
	drawer.DrawItem({ 24, 54 }, true);
	drawer.DrawFireBar();
	drawer.DrawFire();

	puts("Draw firebars");

	//透明管
	drawer.DrawCPipe();

	puts("Draw clear pipe");

	// Optional, draw pipes again
	drawer.DrawItem({ 9 }, false);

	cairo_surface_write_to_png(surface, destination.c_str());

	LevelWindow newLevelWindow;
	Helpers::LoadTextureFromSurface(surface, &newLevelWindow.level_render_image, &newLevelWindow.level_render_width,
		&newLevelWindow.level_render_height);
	newLevelWindow.filename  = destination;
	newLevelWindow.window_id = new_window_counter;
	newLevelWindow.level     = level;
	opened_level_windows.push_back(newLevelWindow);
	new_window_counter++;

	cairo_destroy(cr);
	cairo_surface_destroy(surface);
}

void AttemptRender(std::string choice, bool log, std::string destination) {
	LevelParser levelParser;

	uintmax_t filesize = std::filesystem::file_size(choice);
	fmt::print("Level filesize is {}\n", filesize);

	if(filesize == 0x5C000) {
		puts("File is encrypted");
		levelParser.DecryptLevelData(choice, "temp.bcd");
		choice = "temp.bcd";
	} else {
		// First, check if compressed
		FILE* magicFile = fopen(choice.c_str(), "rb");
		uint8_t zlibMagic[2];
		uint8_t validZlibMagic1[2] = { 0x78, 0x01 };
		uint8_t validZlibMagic2[2] = { 0x78, 0x5E };
		uint8_t validZlibMagic3[2] = { 0x78, 0x9C };
		uint8_t validZlibMagic4[2] = { 0x78, 0xDA };
		fread(zlibMagic, 2, 1, magicFile);
		fclose(magicFile);
		if(memcmp(zlibMagic, validZlibMagic1, 2) == 0 || memcmp(zlibMagic, validZlibMagic2, 2) == 0
			|| memcmp(zlibMagic, validZlibMagic3, 2) == 0 || memcmp(zlibMagic, validZlibMagic4, 2) == 0) {
			puts("File is compressed");
			// Is compressed, decompress and write to new file
			std::ifstream readFile(choice, std::ios::in | std::ios::binary);
			std::vector<uint8_t> data((std::istreambuf_iterator<char>(readFile)), std::istreambuf_iterator<char>());
			readFile.close();

			std::string decompressed = gzip::decompress((const char*)data.data(), data.size());
			std::ofstream writeFile("temp.bcd", std::ios::out | std::ios::binary);
			writeFile.write(decompressed.data(), decompressed.size());
			writeFile.close();

			choice = "temp.bcd";
		} else {
			puts("File is uncompressed or an unknown format");
		}
	}

	bool isOverworld = true;

	puts("Loading level data");
	levelParser.LoadLevelData(choice, isOverworld);
	puts("Done loading level data");

#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#endif

	fmt::print("Assets folder: {}\n", assetsFolder);
	levelParser.SetAssetsFolder(assetsFolder);

	auto start = std::chrono::high_resolution_clock::now();
	DrawMap(levelParser, isOverworld, log, destination);
	auto stop = std::chrono::high_resolution_clock::now();

	fmt::print("Rendering took {} milliseconds\n",
		std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count());
}

#ifdef __EMSCRIPTEN__
EM_JS(void, ReadFileFromUserJS, (), {
	var hiddenInput           = document.createElement("input");
	hiddenInput.type          = "file";
	hiddenInput.style.display = "none";
	hiddenInput.title         = "Choose level to open";
	document.body.appendChild(hiddenInput);

	hiddenInput.onchange = function() {
		if(hiddenInput.files.size == 0) {
			rej(0);
		} else {
			var filename = hiddenInput.files[0].name;

			var fr    = new FileReader();
			fr.onload = function() {
				var data = new Uint8Array(fr.result);

				if(FS.analyzePath(filename).exists) {
					FS.unlink(filename);
				}

				FS.createDataFile(".", filename, data, true, true, true);
				document.body.removeChild(hiddenInput);

				Module.fileInputFilename = filename;
			};
			fr.readAsArrayBuffer(hiddenInput.files[0]);
		}
	};

	hiddenInput.click();
});

EM_JS(char*, CheckReadFileFromUserJS, (), {
	if(Module.fileInputFilename) {
		var lengthBytes      = lengthBytesUTF8(Module.fileInputFilename) + 1;
		var stringOnWasmHeap = _malloc(lengthBytes);
		stringToUTF8(Module.fileInputFilename, stringOnWasmHeap, lengthBytes);
		Module.fileInputFilename = undefined;
		return stringOnWasmHeap;
	} else {
		return 0;
	}
});
#endif

static void main_loop() {
	ImGuiIO& io = ImGui::GetIO();
	SDL_Event event;
	while(SDL_PollEvent(&event)) {
		ImGui_ImplSDL2_ProcessEvent(&event);
		if(event.type == SDL_QUIT)
			done = true;
		if(event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE
			&& event.window.windowID == SDL_GetWindowID(window))
			done = true;
	}

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.50f, 0.33f, 0.22f, 1.0f));
	ImGui::NewFrame();

	int h;
	SDL_GetWindowSize(window, nullptr, &h);
	ImGui::SetNextWindowSize(ImVec2(450, h));
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::Begin("Toost", nullptr,
		ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize
			| ImGuiWindowFlags_NoMove);

	std::string choice;
	ImGui::Text("Choose your file:");

#ifdef __EMSCRIPTEN__
	char* fileString = CheckReadFileFromUserJS();
	if(fileString != nullptr) {
		puts("File chosen");
		choice = std::string(fileString);
		free(fileString);
	}
#endif

	if(ImGui::Button("File")) {
#ifdef __EMSCRIPTEN__
		ReadFileFromUserJS();
#else
		auto selection = pfd::open_file("Choose level to open", ".", { "All Files", "*" }, pfd::opt::none).result();
		if(!selection.empty()) {
			puts("File chosen");
			choice = selection[0];
		} else {
			puts("No file chosen");
		}
#endif
	}

	if(!choice.empty()) {
		puts(choice.c_str());
		AttemptRender(choice, true, std::filesystem::path(choice).filename().string() + ".png");
	}

	if(focused_window_index != -1) {
		if(focused_window_index != cached_focused_window_index) {
			auto& cwfi = cached_focused_window_info;

			cwfi.clear();
			cached_focused_window_index = focused_window_index;

			fmt::print("Caching level data for {}\n", opened_level_windows[focused_window_index].filename);
			LevelParser& level = opened_level_windows[focused_window_index].level;
			cwfi.push_back(fmt::format("Name: {}", level.LH.Name));
			cwfi.push_back(fmt::format("Description: {}", level.LH.Desc));
			cwfi.push_back(fmt::format("Gamestyle: {}", LevelParserMappings::NumToGameStyle.at(level.LH.GameStyle)));
			cwfi.push_back(
				fmt::format("Clear Time: {}", LevelParserMappings::FormatMillisecondTime(level.LH.ClearTime)));
			cwfi.push_back(fmt::format("Clear Attempts: {}", level.LH.ClearAttempts));
			// cwfi.push_back(fmt::format("Uploaded: {:02}-{:02}-{} {}:{:02}", level.LH.DateDD, level.LH.DateMM,
			//	level.LH.DateYY, level.LH.DateH, level.LH.DateM));
		}

		for(auto& info : cached_focused_window_info) {
			ImGui::TextWrapped("%s", info.c_str());
		}
	}

	ImGui::End();
	ImGui::PopStyleColor(1);

	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(1.0f, 1.0f, 1.0f, 1.0f));
	ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 3.0f);
	bool is_open;
	auto iter            = opened_level_windows.begin();
	int i                = 0;
	focused_window_index = -1;
	while(iter != opened_level_windows.end()) {
		is_open = true;
		bool should_render = ImGui::Begin(fmt::format("{}##{}", iter->filename, iter->window_id).c_str(), &is_open);
		if(!is_open) {
			fmt::print("Deleted window {}\n", iter->filename);
			glDeleteTextures(1, &iter->level_render_image);
			iter = opened_level_windows.erase(iter);
		} else {
			if (should_render) {
				ImGui::Image((void*)(intptr_t)iter->level_render_image, ImVec2(iter->level_render_width, iter->level_render_height));
				ImGui::SetWindowSize(ImVec2((float)iter->level_render_width + 25.0f, (float)iter->level_render_height + 45.0f));
			}

			if(ImGui::IsWindowFocused()) {
				focused_window_index = i;
			}

			++iter;
			i++;
		}
		ImGui::End();
	}
	ImGui::PopStyleVar(1);
	ImGui::PopStyleColor(1);

	// Rendering
	ImGui::Render();
	SDL_GL_MakeCurrent(window, gl_context);
	glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
	glClearColor(
		clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
	glClear(GL_COLOR_BUFFER_BIT);
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	SDL_GL_SwapWindow(window);
}

int main(int argc, char** argv) {

	cxxopts::Options options("TOOST", "A Super Mario Maker 2 level viewer, based on JiXiaomai/SMM2LevelViewer");

	// clang-format off
	options.add_options()
		("p,path", "Path to level to view", cxxopts::value<std::string>())
		("o,output", "Where to put rendered image", cxxopts::value<std::string>())
		("d,debug", "Enable debug logging")
		("h,help", "Print help menu");
	// clang-format on

	auto result = options.parse(argc, argv);

	if(result.count("help")) {
		std::cout << options.help() << std::endl;
		return 0;
	}

#ifdef __EMSCRIPTEN__
	assetsFolder = "";
#else
	assetsFolder = Helpers::GetExecutableDirectory().parent_path().parent_path().string();
	std::replace(assetsFolder.begin(), assetsFolder.end(), '\\', '/');
#endif

	if(result.count("path")) {
		std::string path = result["path"].as<std::string>();
		if(std::filesystem::exists(path)) {

			if(result.count("output")) {
				std::string output = result["output"].as<std::string>();
				AttemptRender(path, result.count("debug"), output);
				return 0;
			}
			AttemptRender(path, result.count("debug"), std::filesystem::path(path).filename().string() + ".png");
			return 0;
		} else {
			fmt::print("Path {} does not exist\n", path);
			return 1;
		}
	}

	puts("Starting toost GUI");

	std::string font_path = fmt::format("{}/fonts/unifont-14.0.01.ttf", assetsFolder);
	FT_Init_FreeType(&freetype_library);
	FT_New_Face(freetype_library, font_path.c_str(), 0, &main_font);

	// Setup SDL
	// (Some versions of SDL before <2.0.10 appears to have performance/stalling issues on a minority of Windows
	// systems, depending on whether SDL_INIT_GAMECONTROLLER is enabled or disabled.. updating to latest version of SDL
	// is recommended!)
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0) {
		printf("Error: %s\n", SDL_GetError());
		return -1;
	}

	// Decide GL+GLSL versions
#if defined(__EMSCRIPTEN__)
	// For the browser using Emscripten, we are going to use WebGL1 with GL ES2. See the Makefile. for requirement
	// details. It is very likely the generated file won't work in many browsers. Firefox is the only sure bet, but I
	// have successfully run this code on Chrome for Android for example.
	const char* glsl_version = "#version 100";
	// const char* glsl_version = "#version 300 es";
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#elif defined(IMGUI_IMPL_OPENGL_ES2)
	// GL ES 2.0 + GLSL 100
	const char* glsl_version = "#version 100";
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#elif defined(__APPLE__)
	// GL 3.2 Core + GLSL 150
	const char* glsl_version = "#version 150";
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG); // Always required on Mac
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#else
	// GL 3.0 + GLSL 130
	const char* glsl_version = "#version 130";
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
#endif

	// Create window with graphics context
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	SDL_DisplayMode current;
	SDL_GetCurrentDisplayMode(0, &current);
	SDL_WindowFlags window_flags
		= (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
	window     = SDL_CreateWindow("Toost | Super Mario Maker 2 Level Viewer", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);
	gl_context = SDL_GL_CreateContext(window);

	if(!gl_context) {
		fprintf(stderr, "Failed to initialize OpenGL3 context!\n");
		return 1;
	}

	SDL_GL_MakeCurrent(window, gl_context);
	// SDL_GL_SetSwapInterval(1); // Enable vsync

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	static ImWchar ranges[] = { 0x20, 0xFFFF, 0 };
	static ImFontConfig cfg;
	io.Fonts->AddFontFromFileTTF(font_path.c_str(), 18.0, &cfg, ranges);
	io.IniFilename = NULL;
	(void)io;
	// io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	// io.ConfigFlags != ImGuiConfigFlags_NavEnableGamepad; // Enable Gamepad Controls

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	// ImGui::StyleColorsClassic();

	// Setup Platform/Renderer backends
	ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
	ImGui_ImplOpenGL3_Init(glsl_version);

#ifdef __EMSCRIPTEN__
	emscripten_set_main_loop(main_loop, 0, true);
#else
	// Main loop
	while(!done) {
		main_loop();
	}

	// Cleanup
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	SDL_GL_DeleteContext(gl_context);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
#endif
}