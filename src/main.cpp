#include "Drawers.hpp"
#include "Helpers.hpp"
#include "LevelParser.hpp"

#include <SDL.h>
#include <cairo/cairo.h>
#include <chrono>
#include <cstdio>
#include <filesystem>
#include <fmt/core.h>
#include <fstream>
#include <gzip/decompress.hpp>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_sdl.h>
#include <iterator>
#include <portable-file-dialogs.h>
#include <stdio.h>
#include <thread>
#include <vector>

#ifdef _WIN32
#include <Windows.h>
#endif

#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <SDL_opengles2.h>
#else
#include <SDL_opengl.h>
#endif

void DrawMap(LevelParser& level, bool isOverworld) {
	Drawers drawer(level);

	drawer.Setup();
	drawer.SetZoom(16);
	drawer.SetIsOverworld(isOverworld);

	puts("Set zoom");

	cairo_surface_t* surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, drawer.GetWidth(), drawer.GetHeight());
	cairo_t* cr              = cairo_create(surface);

	fmt::print("Width: {}\nHeight: {}\n", drawer.GetWidth(), drawer.GetHeight());

	drawer.SetGraphics(cr);

	puts("Set graphics");

	std::string tilesheet = fmt::format("{}/img/TILE/{}-{}{}.png", level.PT, level.LH.GameStyle, level.MapHdr.Theme,
		(level.MapHdr.Flag == 2) ? "A" : "");
	drawer.SetTilesheet(tilesheet);

	fmt::print("Set tilesheet to {}\n", tilesheet);

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

	cairo_surface_write_to_png(surface, "test.png");
	cairo_destroy(cr);
	cairo_surface_destroy(surface);
}

// Main code
int main(int, char**) {
	// Setup SDL
	// (Some versions of SDL before <2.0.10 appears to have performance/stalling issues on a minority of Windows
	// systems, depending on whether SDL_INIT_GAMECONTROLLER is enabled or disabled.. updating to latest version of SDL
	// is recommended!)
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0) {
		printf("Error: %s\n", SDL_GetError());
		return -1;
	}

	// Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
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
	SDL_WindowFlags window_flags
		= (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_Window* window = SDL_CreateWindow(
		"Super Mario Maker 2 Level Viewer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);
	SDL_GLContext gl_context = SDL_GL_CreateContext(window);
	SDL_GL_MakeCurrent(window, gl_context);
	SDL_GL_SetSwapInterval(1); // Enable vsync

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;
	// io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	// io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	// ImGui::StyleColorsClassic();

	// Setup Platform/Renderer backends
	ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
	ImGui_ImplOpenGL3_Init(glsl_version);

	// Load Fonts
	// - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use
	// ImGui::PushFont()/PopFont() to select them.
	// - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
	// - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application
	// (e.g. use an assertion, or display an error and quit).
	// - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling
	// ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
	// - Read 'docs/FONTS.md' for more instructions and details.
	// - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double
	// backslash \\ !
	// io.Fonts->AddFontDefault();
	// io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
	// io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
	// io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
	// io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
	// ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL,
	// io.Fonts->GetGlyphRangesJapanese()); IM_ASSERT(font != NULL);

	// Our state
	// bool show_demo_window    = true;
	// bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	// Main loop
	bool done = false;
	while(!done) {
		// Poll and handle events (inputs, window resize, etc.)
		// You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your
		// inputs.
		// - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
		// - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
		// Generally you may always pass all inputs to dear imgui, and hide them from your application based on those
		// two flags.
		SDL_Event event;
		while(SDL_PollEvent(&event)) {
			ImGui_ImplSDL2_ProcessEvent(&event);
			if(event.type == SDL_QUIT)
				done = true;
			if(event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE
				&& event.window.windowID == SDL_GetWindowID(window))
				done = true;
		}

		// Start the Dear ImGui frame
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplSDL2_NewFrame();
		ImGui::NewFrame();

		// 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code
		// to learn more about Dear ImGui!).
		// if(show_demo_window)
		//	ImGui::ShowDemoWindow(&show_demo_window);

		// 2. Show a simple window that we create ourselves. We use a Begin/End pair to created a named window.
		{
			/*
			static float f     = 0.0f;
			static int counter = 0;

			ImGui::Begin("Hello, world!"); // Create a window called "Hello, world!" and append into it.

			ImGui::Text("This is some useful text.");          // Display some text (you can use a format strings too)
			ImGui::Checkbox("Demo Window", &show_demo_window); // Edit bools storing our window open/close state
			ImGui::Checkbox("Another Window", &show_another_window);

			ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
			ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

			if(ImGui::Button(
				   "Button")) // Buttons return true when clicked (most widgets return true when edited/activated)
				counter++;
			ImGui::SameLine();
			ImGui::Text("counter = %d", counter);

			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate,
				ImGui::GetIO().Framerate);
			ImGui::End();
			*/

			LevelParser levelParser;

			ImGui::Begin("SMM2 Level Viewer");

			ImGui::Text("Choose your file:");
			if(ImGui::Button("File")) {
				auto selection
					= pfd::open_file("Choose level to open", ".", { "All Files", "*" }, pfd::opt::none).result();
				puts("File chosen");
				if(!selection.empty()) {
					std::string choice = selection[0];
					puts(choice.c_str());

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
							|| memcmp(zlibMagic, validZlibMagic3, 2) == 0
							|| memcmp(zlibMagic, validZlibMagic4, 2) == 0) {
							puts("File is compressed");
							// Is compressed, decompress and write to new file
							std::ifstream readFile(choice, std::ios::in | std::ios::binary);
							std::vector<uint8_t> data(
								(std::istreambuf_iterator<char>(readFile)), std::istreambuf_iterator<char>());
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

					levelParser.LoadLvlData(choice, true);

#ifdef _WIN32
					SetConsoleOutputCP(CP_UTF8);
#endif

					std::string assetsFolder = Helpers::GetExecutableDirectory().parent_path().parent_path().string();
					fmt::print("Assets folder: {}", assetsFolder);
					levelParser.SetAssetsFolder(assetsFolder);

					DrawMap(levelParser, true);
				}
			}

			ImGui::End();
		}

		// 3. Show another simple window.
		// if(show_another_window) {
		//	ImGui::Begin(
		//		"Another Window", &show_another_window); // Pass a pointer to our bool variable (the window will have a
		//												 // closing button that will clear the bool when clicked)
		//	ImGui::Text("Hello from another window!");
		//	if(ImGui::Button("Close Me"))
		//		show_another_window = false;
		//	ImGui::End();
		//}

		// Rendering
		ImGui::Render();
		glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
		glClearColor(
			clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		SDL_GL_SwapWindow(window);
	}

	// Cleanup
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	SDL_GL_DeleteContext(gl_context);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
