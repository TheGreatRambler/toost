#include "Drawers.hpp"
#include "Helpers.hpp"
#include "LevelParser.hpp"

#define CURL_STATICLIB

#include <SDL.h>
#include <atomic>
#include <cairo-ft.h>
#include <cairo.h>
#include <chrono>
#include <csignal>
#include <cstdio>
#include <cxxopts.hpp>
#include <filesystem>
#include <fmt/core.h>
#include <fstream>
#include <gzip/decompress.hpp>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_sdl.h>
#include <iostream>
#include <iterator>
#include <mutex>
#include <stdio.h>
#include <vector>

#ifdef _WIN32
#include <Windows.h>
#endif

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/bind.h>
#include <emscripten/fetch.h>
#include <emscripten/html5.h>
#include <freetype.h>
using namespace emscripten;
#else
#include <curl/curl.h>
#include <freetype/freetype.h>
#include <portable-file-dialogs.h>
#include <thread>
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
uint64_t new_window_counter = 3;

#ifndef __EMSCRIPTEN__
std::thread downloading_thread;
#endif

FT_Library freetype_library;
FT_Face main_font;

std::string assetsFolder;

int focused_window_index        = -1;
int cached_focused_window_index = -1;
std::vector<std::string> cached_focused_window_info;

bool remove_grid;
bool render_objects_over_pipes;
float image_scale = 1.0f;

GLuint background_image;
int background_image_width  = 0;
int background_image_height = 0;
GLuint side_image;
int side_width  = 0;
int side_height = 0;

uint64_t frame_counter = 0;

std::string popup_text;
uint64_t remaining_popup_time = 0;

struct LevelWindow {
	int level_render_width  = 0;
	int level_render_height = 0;
	std::string filename;
	std::string name;
	uint64_t window_id;
	GLuint level_render_image = 0;
	LevelParser* level;
};

std::vector<LevelWindow> opened_level_windows;

void DrawMap(LevelParser* level, bool isOverworld, bool log, std::string destination) {
	Drawers drawer(*level);

	drawer.Setup();
	drawer.SetZoom(16);
	drawer.SetIsOverworld(isOverworld);
	drawer.SetLog(log);
	drawer.SetAssetFolder(assetsFolder);

	puts("Set zoom");

	cairo_surface_t* surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, drawer.GetWidth(), drawer.GetHeight());
	cairo_t* cr              = cairo_create(surface);

	cairo_font_face_t* font = cairo_ft_font_face_create_for_ft_face(main_font, 0);
	cairo_set_font_face(cr, font);
	cairo_font_face_destroy(font);

	fmt::print("Width: {}\nHeight: {}\n", drawer.GetWidth(), drawer.GetHeight());

	drawer.SetGraphics(cr);

	puts("Set graphics");

	std::string tilesheet = fmt::format("{}/img/tile/{}-{}{}.png", assetsFolder, level->LH.GameStyle,
		level->MapHdr.Theme, (level->MapHdr.Flag == 2) ? "A" : "");
	drawer.SetTilesheet(tilesheet);

	fmt::print("Set tilesheet to {}\n", tilesheet);

	if(!remove_grid) {
		drawer.DrawGridlines();
	}

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

	if(!render_objects_over_pipes) {
		drawer.DrawItem({ 9 }, false);
	}

	puts("Scaling image");
	cairo_pattern_t* pattern = cairo_pattern_create_for_surface(surface);
	cairo_destroy(cr);
	cairo_surface_destroy(surface);
	cairo_pattern_set_filter(pattern, CAIRO_FILTER_NEAREST);
	surface = cairo_image_surface_create(
		CAIRO_FORMAT_ARGB32, drawer.GetWidth() * image_scale, drawer.GetHeight() * image_scale);
	cr = cairo_create(surface);
	cairo_scale(cr, image_scale, image_scale);
	cairo_set_source(cr, pattern);
	cairo_paint(cr);
	cairo_pattern_destroy(pattern);
	puts("Done scaling");

	puts("Writing image");
	cairo_surface_write_to_png(surface, destination.c_str());
	puts("Done writing");

	LevelWindow newLevelWindow;
	Helpers::LoadTextureFromSurface(surface, &newLevelWindow.level_render_image, &newLevelWindow.level_render_width,
		&newLevelWindow.level_render_height);
	newLevelWindow.filename  = destination;
	newLevelWindow.name      = std::filesystem::path(destination).filename().string();
	newLevelWindow.window_id = new_window_counter;
	newLevelWindow.level     = level;
	opened_level_windows.push_back(newLevelWindow);
	new_window_counter++;

	cairo_destroy(cr);
	cairo_surface_destroy(surface);
}

void AttemptRender(std::string choice, bool log, std::string destination) {
	LevelParser* levelParser = new LevelParser();

	uintmax_t filesize = std::filesystem::file_size(choice);
	fmt::print("Level filesize is {}\n", filesize);

	if(filesize == 0x5C000) {
		puts("File is encrypted");
		levelParser->DecryptLevelData(choice, fmt::format("{}/temp.bcd", assetsFolder));
		choice = fmt::format("{}/temp.bcd", assetsFolder);
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
			std::ofstream writeFile(fmt::format("{}/temp.bcd", assetsFolder), std::ios::out | std::ios::binary);
			writeFile.write(decompressed.data(), decompressed.size());
			writeFile.close();

			choice = fmt::format("{}/temp.bcd", assetsFolder);
		} else {
			puts("File is uncompressed or an unknown format");
		}
	}

	uintmax_t newFilesize = std::filesystem::file_size(choice);

	if(newFilesize == 0x5BFC0) {
		bool isOverworld = true;

		puts("Loading level data");
		levelParser->LoadLevelData(choice, isOverworld);
		puts("Done loading level data");

#ifdef _WIN32
		SetConsoleOutputCP(CP_UTF8);
#endif

		fmt::print("Assets folder: {}\n", assetsFolder);

		auto start = std::chrono::high_resolution_clock::now();
		DrawMap(levelParser, isOverworld, log, destination);
		auto stop = std::chrono::high_resolution_clock::now();

		fmt::print("Rendering took {} milliseconds\n",
			std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count());
	} else {
		puts("File is not a level");
	}
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

#ifndef __EMSCRIPTEN__
std::atomic_uint8_t download_level_flag = 0;
std::mutex download_level_mutex;
#else
uint8_t download_level_flag = 0;
#endif
std::string download_level_id;
std::string download_level_destination;
void level_downloading_thread() {
#ifndef __EMSCRIPTEN__
	CURL* curl_handle = curl_easy_init();
	if(curl_handle == NULL) {
		puts("CURL was not able to start");
	}
#endif
	while(!done) {
#ifndef __EMSCRIPTEN__
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
		download_level_mutex.lock();
#endif
		if(!download_level_id.empty()) {
			fmt::print("Recieved request for {}\n", download_level_id);
			std::string request_url = fmt::format("https://tgrcode.com/mm2/level_data/{}", download_level_id);
			fmt::print("URL is {}\n", request_url);
#ifdef __EMSCRIPTEN__
			emscripten_fetch_attr_t attr;
			emscripten_fetch_attr_init(&attr);
			strcpy(attr.requestMethod, "GET");
			attr.attributes = EMSCRIPTEN_FETCH_LOAD_TO_MEMORY;
			attr.onsuccess  = +[](emscripten_fetch_t* fetch) {
                puts("Request worked");
                download_level_destination = fmt::format("{}/{}.bcd", assetsFolder, download_level_id);
                std::filesystem::remove(download_level_destination);
                auto destination_file = std::fstream(download_level_destination, std::ios::out | std::ios::binary);
                destination_file.write((char*)&fetch->data[0], fetch->numBytes);
                destination_file.close();
                download_level_flag = 1;
                download_level_id   = "";
                download_level_id   = "";
			};
			attr.onerror = +[](emscripten_fetch_t* fetch) {
				fmt::print("Request failed, http status code {}\n", fetch->status);
				download_level_destination = download_level_id;
				download_level_flag        = 2;
				download_level_id          = "";
			};
			emscripten_fetch(&attr, request_url.c_str());
			return;
#else
			curl_easy_setopt(curl_handle, CURLOPT_URL, request_url.c_str());
			curl_easy_setopt(curl_handle, CURLOPT_SSL_VERIFYPEER, 0L);
			curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 0L);
			curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 1L);
			auto callback = +[](void* ptr, size_t size, size_t nmemb, void* stream) {
				std::size_t written = fwrite(ptr, size, nmemb, (FILE*)stream);
				return written;
			};
			curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, callback);
			download_level_destination = fmt::format("{}/{}.bcd", assetsFolder, download_level_id);
			fmt::print("Writing to {}\n", download_level_destination);
			std::filesystem::remove(download_level_destination);
			FILE* dest = fopen(download_level_destination.c_str(), "wb");
			curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, dest);
			CURLcode ret = curl_easy_perform(curl_handle);
			if(ret != CURLE_OK) {
				fmt::print("CURL error: {}\n", curl_easy_strerror(ret));
			}
			fclose(dest);
			long http_code = 0;
			curl_easy_getinfo(curl_handle, CURLINFO_RESPONSE_CODE, &http_code);
			if(http_code == 200) {
				puts("Request worked");
				download_level_id   = "";
				download_level_flag = 1;
			} else {
				fmt::print("Request failed, http status code {}\n", http_code);
				download_level_destination = download_level_id;
				download_level_flag        = 2;
			}
			download_level_id = "";
#endif
		}
#ifndef __EMSCRIPTEN__
		download_level_mutex.unlock();
#endif
	}
#ifndef __EMSCRIPTEN__
	curl_easy_cleanup(curl_handle);
#endif
}

static void main_loop() {
	ImGuiIO& io = ImGui::GetIO();
	SDL_Event event;
	while(SDL_PollEvent(&event)) {
		ImGui_ImplSDL2_ProcessEvent(&event);
		if(event.type == SDL_QUIT) {
			done = true;
		}

		if(event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE
			&& event.window.windowID == SDL_GetWindowID(window)) {
			for(auto& window : opened_level_windows) {
				std::filesystem::remove(window.filename);
				delete window.level;
				glDeleteTextures(1, &window.level_render_image);
			}

			done = true;
#ifndef __EMSCRIPTEN__
			downloading_thread.join();
#endif
		}
	}

	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.50f, 0.33f, 0.22f, 1.0f));
	ImGui::NewFrame();

	int w;
	int h;
	SDL_GetWindowSize(window, &w, &h);

	// ImGui::SetNextWindowPos(ImVec2(0, 0));
	// ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
	// ImGui::Begin("background_image", NULL, ImVec2(0, 0), 0.0f,
	//	ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar
	//		| ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoBringToFrontOnFocus);

	auto background_draw_list = ImGui::GetBackgroundDrawList();
	int frame_offset_x        = frame_counter % background_image_width;
	int frame_offset_y        = frame_counter % background_image_height;
	for(int x = -background_image_width + frame_offset_x; x < w + background_image_width; x += background_image_width) {
		for(int y = -background_image_height + frame_offset_y; y < h + background_image_height;
			y += background_image_height) {
			background_draw_list->AddImage((void*)(intptr_t)background_image, ImVec2(x, y),
				ImVec2(x + background_image_width, y + background_image_height));
		}
	}

	ImGui::SetNextWindowSize(ImVec2(450, h));
	ImGui::SetNextWindowPos(ImVec2(0, 0));
	ImGui::Begin("Toost, by TheGreatRambler", nullptr,
		ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoResize
			| ImGuiWindowFlags_NoMove);

	ImGui::Checkbox("Remove Grid", &remove_grid);
	ImGui::Checkbox("Render Objects Over Pipes", &render_objects_over_pipes);
	ImGui::Text("Image Scale");
	ImGui::DragFloat("##1", &image_scale, 0.125f, 0.125f, 8.0f, "%.3f", ImGuiSliderFlags_AlwaysClamp);

	std::string choice;
	if(ImGui::Button("Load Level")) {
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

#ifdef __EMSCRIPTEN__
	char* fileString = CheckReadFileFromUserJS();
	if(fileString != nullptr) {
		puts("File chosen");
		choice = std::string(fileString);
		free(fileString);
	}
#endif

	if(!choice.empty()) {
		puts(choice.c_str());
		AttemptRender(
			choice, true, fmt::format("{}/{}.png", assetsFolder, std::filesystem::path(choice).filename().string()));
	}

	static char input_string[10] = { 0 };
	ImGui::Text("Download By Level ID");
	ImGui::InputText("##2", input_string, sizeof(input_string));
	if(ImGui::Button("Download Level")) {
		std::string download_id                 = std::string(input_string);
		static std::unordered_set<char> charset = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'B', 'C', 'D',
			'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y' };
		bool id_valid                           = true;
		if(download_id.size() != 9) {
			id_valid = false;
		} else {
			for(std::size_t i = 0; i < download_id.size(); i++) {
				download_id[i] = std::toupper(download_id.at(i));
				if(!charset.contains(download_id.at(i))) {
					id_valid = false;
					break;
				}
			}
		}

		if(id_valid) {
			puts("Sending request");
#ifdef __EMSCRIPTEN__
			download_level_id = download_id;
			level_downloading_thread();
#else
			download_level_mutex.lock();
			download_level_id = download_id;
			download_level_mutex.unlock();
#endif
		} else {
			popup_text           = fmt::format("Level ID {} is not of the right format", download_id);
			remaining_popup_time = 180;
		}
	}

	if(download_level_flag != 0) {
#ifndef __EMSCRIPTEN__
		download_level_mutex.lock();
#endif
		if(download_level_flag == 2) {
			popup_text           = fmt::format("Level ID {} could not be downloaded", download_level_destination);
			remaining_popup_time = 180;
		} else {
			fmt::print("Level was downloaded to {}\n", download_level_destination);
			AttemptRender(download_level_destination, true,
				fmt::format(
					"{}/{}.png", assetsFolder, std::filesystem::path(download_level_destination).filename().string()));
		}
		download_level_flag = 0;
#ifndef __EMSCRIPTEN__
		download_level_mutex.unlock();
#endif
	}

	if(remaining_popup_time > 0) {
		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.74f, 0.25f, 0.18f, 1.0f));
		if(ImGui::BeginPopupModal("Problem encountered")) {
			ImGui::TextUnformatted(popup_text.c_str());
			ImGui::EndPopup();
			remaining_popup_time--;
		} else {
			remaining_popup_time = 0;
		}
		ImGui::PopStyleColor(1);
	}

	bool close_current_level = false;
	if(focused_window_index != -1) {
		if(ImGui::Button("Download Image")) {
			LevelWindow selected_level_info = opened_level_windows[focused_window_index];
#ifdef __EMSCRIPTEN__
			EM_ASM(
				{
					var filenameToDownload = UTF8ToString($0, $1);
					var buf                = FS.readFile(filenameToDownload, { encoding: "binary" });
					var fileBlob           = new Blob([buf.buffer], {
						type:
							"image/png"
					});
					saveAs(fileBlob, UTF8ToString($2, $3));
				},
				selected_level_info.filename.c_str(), selected_level_info.filename.size(),
				selected_level_info.name.c_str(), selected_level_info.name.size());
#else
			auto selection = pfd::save_file(
				"Choose level to open", selected_level_info.name, { "PNG Image", ".png" }, pfd::opt::none)
								 .result();
			if(!selection.empty()) {
				puts("Location chosen");
				if(std::filesystem::exists(selection)) {
					std::filesystem::remove(selection);
				}
				std::filesystem::copy(selected_level_info.filename, selection);
			} else {
				puts("No location chosen");
			}
#endif
		}

		close_current_level = ImGui::Button("Close Level");

		if(focused_window_index != cached_focused_window_index) {
			auto& cwfi = cached_focused_window_info;

			cwfi.clear();
			cached_focused_window_index = focused_window_index;

			fmt::print("Caching level data for {}\n", opened_level_windows[focused_window_index].name);
			LevelParser& level = *opened_level_windows[focused_window_index].level;
			cwfi.reserve(40);
			cwfi.push_back(fmt::format("Name: {}", level.LH.Name));
			cwfi.push_back(fmt::format("Description: {}", level.LH.Desc));
			cwfi.push_back(fmt::format("Gamestyle: {}", levelMappings->NumToGameStyle.at(level.LH.GameStyle)));
			cwfi.push_back(fmt::format("Theme: {}", levelMappings->NumToTheme.at(level.MapHdr.Theme)));
			cwfi.push_back(fmt::format("Is Night Time: {}", level.MapHdr.Flag == 1 ? "yes" : "no"));
			cwfi.push_back(fmt::format("Clear Time: {}", levelMappings->FormatMillisecondTime(level.LH.ClearTime)));
			cwfi.push_back(fmt::format("Clear Attempts: {}", level.LH.ClearAttempts));
			cwfi.push_back(fmt::format("Game Version: {}", levelMappings->NumToGameVersion.at(level.LH.ClearVer)));
			// cwfi.push_back(fmt::format("Uploaded: {:02}-{:02}-{} {}:{:02}", level.LH.DateDD, level.LH.DateMM,
			// 	level.LH.DateYY, level.LH.DateH, level.LH.DateM));
			cwfi.push_back(fmt::format("Timer: {}", level.LH.Timer));
			cwfi.push_back(fmt::format("Start Y: {}", level.LH.StartY));
			cwfi.push_back(fmt::format("Goal X: {}", level.LH.GoalX));
			cwfi.push_back(fmt::format("Goal Y: {}", level.LH.GoalY));
			std::string clear_condition
				= fmt::format(levelMappings->NumToClearCondition.at(level.LH.ClearCRC), level.LH.ClearCA);
			cwfi.push_back(fmt::format("Clear Condition: {}", clear_condition));
			cwfi.push_back(fmt::format(
				"Clear Condition Category: {}", levelMappings->NumToClearConditionCategory.at(level.LH.ClearCC)));
			cwfi.push_back(
				fmt::format("Autoscroll Speed: {}", levelMappings->NumToAutoscrollSpeed.at(level.LH.AutoscrollSpd)));
			cwfi.push_back(
				fmt::format("Autoscroll Type: {}", levelMappings->NumToAutoscrollType.at(level.MapHdr.AutoscrollType)));
			cwfi.push_back(fmt::format("Orientation: {}", levelMappings->NumToOrientation.at(level.MapHdr.Ori)));
			cwfi.push_back(fmt::format("Liquid Start Height: {}", level.MapHdr.LiqSHeight));
			cwfi.push_back(fmt::format("Liquid End Height: {}", level.MapHdr.LiqEHeight));
			cwfi.push_back(fmt::format("Liquid Mode: {}", levelMappings->NumToLiquidMode.at(level.MapHdr.LiqMode)));
			cwfi.push_back(fmt::format("Liquid Speed: {}", levelMappings->NumToLiquidSpeed.at(level.MapHdr.LiqSpd)));
			cwfi.push_back(fmt::format("Boundary Type: {}", levelMappings->NumToBoundaryType.at(level.MapHdr.BorFlag)));
			cwfi.push_back(fmt::format("Right Boundary: {}", level.MapHdr.BorR));
			cwfi.push_back(fmt::format("Top Boundary: {}", level.MapHdr.BorT));
			cwfi.push_back(fmt::format("Left Boundary: {}", level.MapHdr.BorL));
			cwfi.push_back(fmt::format("Bottom Boundary: {}", level.MapHdr.BorB));
			cwfi.push_back(fmt::format("Object Count: {}", level.MapHdr.ObjCount));
			cwfi.push_back(fmt::format("Sound Effect Count: {}", level.MapHdr.SndCount));
			cwfi.push_back(fmt::format("Snake Block Count: {}", level.MapHdr.SnakeCount));
			cwfi.push_back(fmt::format("Clear Pipe Count: {}", level.MapHdr.ClearPipCount));
			cwfi.push_back(fmt::format("Piranha Creeper Count: {}", level.MapHdr.CreeperCount));
			cwfi.push_back(fmt::format("! Block Count: {}", level.MapHdr.iBlkCount));
			cwfi.push_back(fmt::format("Track Count: {}", level.MapHdr.TrackCount));
			cwfi.push_back(fmt::format("Track Block Count: {}", level.MapHdr.TrackBlkCount));
			cwfi.push_back(fmt::format("Ground Count: {}", level.MapHdr.GroundCount));
			cwfi.push_back(fmt::format("Icicle Count: {}", level.MapHdr.IceCount));

			// Due to string corruption on emscripten, don't use fmt
			cwfi.push_back(std::string("UploadID (Unknown): ") + std::to_string(level.LH.UploadID));
			cwfi.push_back(std::string("CreationID (Unknown): ") + std::to_string(level.LH.CreationID));
			cwfi.push_back(std::string("GameVer (Unknown): ") + std::to_string(level.LH.GameVer));
			cwfi.push_back(std::string("Management Flags (Unknown): ") + std::to_string(level.LH.MFlag));
			// cwfi.push_back(fmt::format("UploadID (Unknown): {}", level.LH.UploadID));
			// cwfi.push_back(fmt::format("CreationID (Unknown): {}", level.LH.CreationID));
			// cwfi.push_back(fmt::format("GameVer (Unknown): {}", level.LH.GameVer));
			// cwfi.push_back(fmt::format("Management Flags (Unknown): {}", level.LH.MFlag));
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
	auto iter = opened_level_windows.begin();
	int i     = 0;
	while(iter != opened_level_windows.end()) {
		is_open            = true;
		bool should_render = ImGui::Begin(
			fmt::format("{}##{}", iter->name, iter->window_id).c_str(), &is_open, ImGuiWindowFlags_NoResize);
		if(!is_open || (close_current_level && i == focused_window_index)) {
			fmt::print("Deleted window {}\n", iter->name);
			std::filesystem::remove(iter->filename);
			delete iter->level;
			focused_window_index        = -1;
			cached_focused_window_index = -1;
			glDeleteTextures(1, &iter->level_render_image);
			iter = opened_level_windows.erase(iter);
		} else {
			if(should_render) {
				ImGui::Image((void*)(intptr_t)iter->level_render_image,
					ImVec2(iter->level_render_width, iter->level_render_height));
				ImGui::SetWindowSize(
					ImVec2((float)iter->level_render_width + 25.0f, (float)iter->level_render_height + 45.0f));
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

	frame_counter++;
}

int main(int argc, char** argv) {

	cxxopts::Options options("TOOST", "A Super Mario Maker 2 level viewer, based on JiXiaomai's SMM2LevelViewer");

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

	signal(SIGINT, [](int) {
		for(auto& window : opened_level_windows) {
			std::filesystem::remove(window.filename);
			delete window.level;
			glDeleteTextures(1, &window.level_render_image);
		}

		done = true;
#ifndef __EMSCRIPTEN__
		downloading_thread.join();
#endif
	});

#ifndef __EMSCRIPTEN__
	curl_global_init(CURL_GLOBAL_ALL);
	puts("Creating downloading thread");
	downloading_thread = std::thread(level_downloading_thread);
#endif

	puts("Starting toost GUI");
	auto start = std::chrono::high_resolution_clock::now();

	std::string font_path = fmt::format("{}/fonts/NotoSansJP-Bold.otf", assetsFolder);
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
			SDL_WINDOWPOS_CENTERED, 1366, 768, window_flags);
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
	// static ImWchar ranges[] = { 0x20, 0xFFFF, 0 };
	// Taken loosely from the Nintendo font
	static ImWchar ranges[] = { 0x0020, 0x277F, 0x3000, 0x33D4, 0x4E00, 0x4FFF, 0x5005, 0x5FFF, 0x600E, 0x6FFE, 0x7001,
		0x7FFC, 0x8000, 0x8FFD, 0x9000, 0x9FA0, 0xF929, 0xF9DC, 0xFA0E, 0xFA2D, 0xFB01, 0xFB02, 0xFE30, 0xFFE6, 0 };
	static ImFontConfig cfg;
	io.Fonts->AddFontFromFileTTF(font_path.c_str(), 24.0, &cfg, ranges);
	io.Fonts->GetGlyphRangesChineseFull();
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

	// Create backgrounds
	cairo_surface_t* image
		= cairo_image_surface_create_from_png(fmt::format("{}/img/background.png", assetsFolder).c_str());
	Helpers::LoadTextureFromSurface(image, &background_image, &background_image_width, &background_image_height);
	cairo_surface_destroy(image);

	auto stop = std::chrono::high_resolution_clock::now();
	fmt::print(
		"Startup took {} milliseconds\n", std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count());

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