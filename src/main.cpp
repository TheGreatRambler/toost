#include "FontRanges.hpp"
#include "Helpers.hpp"
#include "LevelDrawer.hpp"
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
#include <unordered_map>
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
	LevelParser* parser;
	LevelDrawer* drawer;
};

struct LevelHandler {
	LevelParser* overworld       = nullptr;
	LevelParser* subworld        = nullptr;
	LevelDrawer* drawerOverworld = nullptr;
	LevelDrawer* drawerSubworld  = nullptr;
};

std::vector<LevelWindow> opened_level_windows;
bool started_level_windows = false;

LevelDrawer* DrawMap(LevelParser* level, bool isOverworld, bool log, std::string destination) {
	LevelDrawer* drawer = new LevelDrawer(*level, 16);

	drawer->Setup();
	drawer->SetIsOverworld(isOverworld);
	drawer->SetLog(log);
	drawer->SetAssetFolder(assetsFolder);

	cairo_surface_t* surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, drawer->GetWidth(), drawer->GetHeight());
	cairo_t* cr              = cairo_create(surface);

	cairo_font_face_t* font = cairo_ft_font_face_create_for_ft_face(main_font, 0);
	cairo_set_font_face(cr, font);
	cairo_font_face_destroy(font);

	if(log) {
		fmt::print("Width: {}\nHeight: {}\n", drawer->GetWidth(), drawer->GetHeight());
	}

	drawer->SetGraphics(cr);

	drawer->LoadTilesheet();

	if(destination == "instructionsOnly") {
		// Export as instructions only instead
		drawer->SetOnlyInstructions();
	}

	if(!remove_grid) {
		drawer->DrawGridlines();
	}

	// 3D平台
	// 半碰撞
	// 蘑菇平台
	// 桥
	// 蘑菇跳台
	// 开关跳台
	drawer->DrawItem({ 132 }, false);
	drawer->DrawItem({ 16 }, false);
	drawer->DrawItem({ 14 }, false);
	drawer->DrawItem({ 17 }, false);
	drawer->DrawItem({ 113 }, false);
	drawer->DrawItem({ 71 }, false);

	// 箭头 单向板 中间旗 藤蔓

	drawer->DrawItem({ 66, 67, 106 }, false);
	drawer->DrawItem({ 64 }, false);
	drawer->DrawItem({ 90 }, false);

	// 树 长长吞食花
	drawer->DrawItem({ 106, 107 }, false);

	// 地面 传送带 开关 开关砖 P砖 冰锥
	// 斜坡单独
	drawer->ReGrdCode();
	drawer->DrawGrd();
	// DrawSlope()
	drawer->DrawGrdCode();

	drawer->DrawItem({ 53, 94, 99, 100, 79 }, false);
	drawer->DrawIce();

	// 无LINKE
	// 管道 门 蛇 传送箱
	drawer->DrawItem({ 9, 55, 84, 97 }, false);
	// 机动砖 轨道砖
	drawer->DrawItem({ 85, 119 }, false);
	// 夹子
	drawer->DrawItem({ 105 }, false);
	// 轨道
	drawer->DrawTrack();
	// 软砖 问号 硬砖 竹轮 云 音符 隐藏 刺 冰块 闪烁砖
	drawer->DrawItem({ 4, 5, 6, 21, 22, 23, 29, 43, 63, 110, 108 }, false);

	// 跷跷板 熔岩台 升降台
	drawer->DrawItem({ 91, 36, 11 }, false);

	// 狼牙棒
	drawer->DrawItem({ 83 }, false);

	// 齿轮 甜甜圈
	drawer->DrawItem({ 68, 82 }, false);

	// 道具
	drawer->DrawItem({ 0, 1, 2, 3, 8, 10, 12, 13, 15, 18, 19, 20, 25, 28, 30, 31, 32, 33, 34, 35, 39 }, false);
	drawer->DrawItem({ 40, 41, 42, 44, 45, 46, 47, 48, 52, 56, 57, 58, 60, 61, 62, 70, 74, 76, 77, 78, 81, 92, 95, 98,
						 102, 103, 104 },
		false);
	drawer->DrawItem(
		{ 111, 120, 121, 122, 123, 124, 125, 126, 112, 127, 128, 129, 130, 131, 72, 50, 51, 65, 80, 114, 116 }, false);
	drawer->DrawItem({ 96, 117, 86 }, false);
	// 喷枪 火棍
	drawer->DrawItem({ 24, 54 }, false);

	// DrawFireBar(False)
	// DrawFire(False)
	// 夹子
	drawer->DrawItem({ 105 }, false);
	// 轨道
	drawer->DrawTrack();
	// 夹子
	drawer->DrawItem({ 105 }, true);
	// 卷轴相机
	//  DrawItem("/89/", False)

	// LINK
	// 软砖 问号 硬砖 竹轮 云 音符 隐藏 刺 冰块
	drawer->DrawItem({ 4, 5, 6, 21, 22, 23, 29, 43, 63 }, true);

	// 跷跷板 熔岩台 升降台
	drawer->DrawItem({ 91, 36, 11 }, true);

	// 齿轮 甜甜圈
	drawer->DrawItem({ 68, 82 }, true);

	// 道具
	drawer->DrawItem({ 0, 1, 2, 3, 8, 10, 12, 13, 15, 18, 19, 20, 25, 28, 30, 31, 32, 33, 34, 35, 39 }, true);
	drawer->DrawItem({ 40, 41, 42, 44, 45, 46, 47, 48, 52, 56, 57, 58, 60, 61, 62, 70, 74, 76, 77, 78, 81, 92, 95, 98,
						 102, 103, 104 },
		true);
	drawer->DrawItem(
		{ 111, 120, 121, 122, 123, 124, 125, 126, 112, 127, 128, 129, 130, 131, 72, 50, 51, 65, 80, 114, 116 }, true);
	drawer->DrawItem({ 96, 117, 86 }, true);

	drawer->DrawCID();

	// 喷枪 火棍
	drawer->DrawItem({ 24, 54 }, true);
	drawer->DrawFireBar();
	drawer->DrawFire();

	// 透明管
	drawer->DrawCPipe();

	if(!render_objects_over_pipes) {
		drawer->DrawItem({ 9, 42 }, true);
	}

	drawer->ClearImageCache();

	if(destination != "instructionsOnly") {
		cairo_pattern_t* pattern = cairo_pattern_create_for_surface(surface);
		cairo_destroy(cr);
		cairo_surface_destroy(surface);
		cairo_pattern_set_filter(pattern, CAIRO_FILTER_NEAREST);
		surface = cairo_image_surface_create(
			CAIRO_FORMAT_ARGB32, drawer->GetWidth() * image_scale, drawer->GetHeight() * image_scale);
		cr = cairo_create(surface);
		cairo_scale(cr, image_scale, image_scale);
		cairo_set_source(cr, pattern);
		cairo_paint(cr);
		cairo_pattern_destroy(pattern);

		auto start = std::chrono::high_resolution_clock::now();
		cairo_surface_write_to_png(surface, destination.c_str());
		auto stop = std::chrono::high_resolution_clock::now();
		fmt::print("Cairo PNG writing took {} milliseconds\n",
			std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count());

		if(started_level_windows) {
			LevelWindow newLevelWindow;
			Helpers::LoadTextureFromSurface(surface, &newLevelWindow.level_render_image,
				&newLevelWindow.level_render_width, &newLevelWindow.level_render_height);
			newLevelWindow.filename  = destination;
			newLevelWindow.name      = std::filesystem::path(destination).stem().string();
			newLevelWindow.window_id = new_window_counter;
			newLevelWindow.parser    = level;
			newLevelWindow.drawer    = drawer;
			opened_level_windows.push_back(newLevelWindow);
			new_window_counter++;
		}
	}

	cairo_destroy(cr);
	cairo_surface_destroy(surface);

	return drawer;
}

LevelHandler AttemptRender(
	std::string choice, bool log, std::string destinationOverworld, std::string destinationSubworld) {
	uintmax_t filesize = std::filesystem::file_size(choice);
	std::string content;

	if(log) {
		fmt::print("Level filesize is {}\n", filesize);
	}

	if(filesize == 0x5C000) {
		if(log) {
			puts("File is likely encrypted");
		}

		std::ifstream ifs(choice, std::ios::binary);
		std::string input((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
		LevelParser::DecryptLevelData(input, content);
	} else if(filesize == 0x5BFC0) {
		if(log) {
			puts("File is likely unencrypted");
		}

		std::ifstream ifs(choice, std::ios::binary);
		std::string input((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));
		content = input;
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
			if(log) {
				puts("File is compressed");
			}

			// Is compressed, decompress and write to new file
			std::ifstream readFile(choice, std::ios::in | std::ios::binary);
			std::vector<uint8_t> data((std::istreambuf_iterator<char>(readFile)), std::istreambuf_iterator<char>());
			readFile.close();

			content = gzip::decompress((const char*)data.data(), data.size());
		} else {
			puts("File is an unknown format");
		}
	}

	if(content.size() == 0x5BFC0) {
#ifdef _WIN32
		SetConsoleOutputCP(CP_UTF8);
#endif

		if(log) {
			fmt::print("Assets folder: {}\n", assetsFolder);
		}

		LevelHandler data;

		if(!destinationOverworld.empty()) {
			LevelParser* overworldLevelParser = new LevelParser();
			overworldLevelParser->LoadLevelData(content, true);
			auto start           = std::chrono::high_resolution_clock::now();
			data.drawerOverworld = DrawMap(overworldLevelParser, true, log, destinationOverworld);
			auto stop            = std::chrono::high_resolution_clock::now();
			fmt::print("Rendering overworld took {} milliseconds\n",
				std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count());
			data.overworld = overworldLevelParser;
		}

		if(!destinationSubworld.empty()) {
			LevelParser* subworldLevelParser = new LevelParser();
			subworldLevelParser->LoadLevelData(content, false);
			auto start          = std::chrono::high_resolution_clock::now();
			data.drawerSubworld = DrawMap(subworldLevelParser, false, log, destinationSubworld);
			auto stop           = std::chrono::high_resolution_clock::now();
			fmt::print("Rendering subworld took {} milliseconds\n",
				std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count());
			data.subworld = subworldLevelParser;
		}

		return data;
	} else {
		puts("File is not a level");
	}

	return LevelHandler();
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
CURL* curl_handle;
#else
uint8_t download_level_flag = 0;
#endif
std::string download_level_id;
std::string download_level_destination;

void level_downloading_routine() {
	if(std::filesystem::exists(fmt::format("{}/{}.bcd", assetsFolder, download_level_id))) {
		puts("Using cached level data");
		download_level_destination = fmt::format("{}/{}.bcd", assetsFolder, download_level_id);
		download_level_flag        = 1;
		download_level_id          = "";
	} else {
		std::string request_url = fmt::format("https://tgrcode.com/mm2/level_data/{}", download_level_id);
		fmt::print("Downloading level data from {}\n", request_url);
#ifdef __EMSCRIPTEN__
		emscripten_fetch_attr_t attr;
		emscripten_fetch_attr_init(&attr);
		strcpy(attr.requestMethod, "GET");
		attr.attributes = EMSCRIPTEN_FETCH_LOAD_TO_MEMORY;
		attr.onsuccess  = +[](emscripten_fetch_t* fetch) {
            puts("Downloading complete");
            download_level_destination = fmt::format("{}/{}.bcd", assetsFolder, download_level_id);
            std::filesystem::remove(download_level_destination);
            auto destination_file = std::fstream(download_level_destination, std::ios::out | std::ios::binary);
            destination_file.write((char*)&fetch->data[0], fetch->numBytes);
            destination_file.close();
            download_level_flag = 1;
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
			puts("Downloading complete");
			download_level_id   = "";
			download_level_flag = 1;
		} else {
			fmt::print("Request failed, http status code {}\n", http_code);
			download_level_destination = download_level_id;
			download_level_flag        = 2;
		}
#endif
	}
}

void level_downloading_thread() {
#ifndef __EMSCRIPTEN__
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
			level_downloading_routine();
			download_level_id = "";
		}
#ifndef __EMSCRIPTEN__
		download_level_mutex.unlock();
#endif
	}
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
				delete window.parser;
				delete window.drawer;
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

	auto background_draw_list = ImGui::GetBackgroundDrawList();
	// int frame_offset_x        = (int)(frame_counter / 5.0) % background_image_width;
	// int frame_offset_y        = (int)(frame_counter / 5.0) % background_image_height;
	int frame_offset_x = 0;
	int frame_offset_y = 0;
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
		ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove);

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
		AttemptRender(choice, true,
			fmt::format("{}/{}overworld.png", assetsFolder, std::filesystem::path(choice).stem().string()),
			fmt::format("{}/{}subworld.png", assetsFolder, std::filesystem::path(choice).stem().string()));
	}

	static char input_string[15] = { 0 };
	ImGui::Text("Download By Level ID");
	ImGui::InputText("##2", input_string, sizeof(input_string));
	if(ImGui::Button("Download Level")) {
		std::string download_id                 = std::string(input_string);
		static std::unordered_set<char> charset = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'B', 'C', 'D',
			'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y' };
		download_id.erase(std::remove(download_id.begin(), download_id.end(), '-'), download_id.end());
		download_id.erase(std::remove(download_id.begin(), download_id.end(), ' '), download_id.end());
		bool id_valid = true;
		if(download_id.size() != 9) {
			id_valid = false;
		} else {
			for(std::size_t i = 0; i < download_id.size(); i++) {
				download_id[i] = std::toupper(download_id.at(i));
				if(!charset.count(download_id.at(i))) {
					id_valid = false;
					break;
				}
			}
		}

		if(id_valid) {
			puts("Sending request");
#ifdef __EMSCRIPTEN__
			download_level_id = download_id;
			level_downloading_routine();
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
				fmt::format("{}/{}overworld.png", assetsFolder,
					std::filesystem::path(download_level_destination).stem().string()),
				fmt::format("{}/{}subworld.png", assetsFolder,
					std::filesystem::path(download_level_destination).stem().string()));
		}
		download_level_flag = 0;
#ifndef __EMSCRIPTEN__
		download_level_mutex.unlock();
#endif
	}

	if(remaining_popup_time > 0) {
		ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0.74f, 0.25f, 0.18f, 1.0f));
		ImGui::SetNextWindowSize(ImVec2(400, 100));
		if(ImGui::Begin("Message", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize)) {
			ImGui::TextUnformatted(popup_text.c_str());
			ImGui::End();
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
				"Choose image destination", selected_level_info.name + ".png", { "PNG Image", ".png" }, pfd::opt::none)
								 .result();
			if(!selection.empty()) {
				fmt::print("Copying image to {}\n", selection);
				if(std::filesystem::exists(selection)) {
					std::filesystem::remove(selection);
				}
				std::filesystem::copy(selected_level_info.filename, selection);
			} else {
				puts("No location chosen");
			}
#endif
		}

		if(ImGui::Button("Download JSON")) {
			LevelWindow selected_level_info = opened_level_windows[focused_window_index];
#ifdef __EMSCRIPTEN__
			std::string dest = fmt::format("{}/{}.json", assetsFolder, selected_level_info.name);
			std::string name = selected_level_info.name + ".json";
			selected_level_info.parser->ExportToJSON(dest, selected_level_info.drawer->GetInstructions());
			EM_ASM(
				{
					var filenameToDownload = UTF8ToString($0, $1);
					var buf                = FS.readFile(filenameToDownload, { encoding: "binary" });
					var fileBlob           = new Blob([buf.buffer], {
						type:
							"application/json"
					});
					saveAs(fileBlob, UTF8ToString($2, $3));
				},
				dest.c_str(), dest.size(), name.c_str(), name.size());
#else
			auto selection = pfd::save_file(
				"Choose JSON destination", selected_level_info.name + ".json", { "JSON text", ".json" }, pfd::opt::none)
								 .result();
			if(!selection.empty()) {
				puts("Location chosen");
				selected_level_info.parser->ExportToJSON(selection, selected_level_info.drawer->GetInstructions());
				puts("JSON generated");
			} else {
				puts("No location chosen");
			}
#endif
		}

		close_current_level = ImGui::Button("Close Window");

		if(focused_window_index != cached_focused_window_index) {
			auto& cwfi = cached_focused_window_info;

			cwfi.clear();
			cached_focused_window_index = focused_window_index;

			LevelParser& level = *opened_level_windows[focused_window_index].parser;
			cwfi.reserve(50);
			cwfi.push_back(std::string("Name: ") + level.LH.Name);
			cwfi.push_back(std::string("Description: ") + level.LH.Desc);
			cwfi.push_back(std::string("Gamestyle: ") + levelMappings->NumToGameStyle.at(level.LH.GameStyle));
			cwfi.push_back(std::string("Theme: ") + levelMappings->NumToTheme.at(level.MapHdr.Theme));
			cwfi.push_back(std::string("Is Overworld: ") + (level.isOverworld ? "yes" : "no"));
			cwfi.push_back(std::string("Is Night Time: ") + (level.MapHdr.Flag == 1 ? "yes" : "no"));
			cwfi.push_back(std::string("Clear Time: ") + levelMappings->FormatMillisecondTime(level.LH.ClearTime));
			cwfi.push_back(std::string("Clear Attempts: ") + std::to_string(level.LH.ClearAttempts));
			cwfi.push_back(std::string("Game Version: ") + levelMappings->NumToGameVersion.at(level.LH.ClearVer));
			// cwfi.push_back(fmt::format("Uploaded: {:02}-{:02}-{} {}:{:02}", level.LH.DateDD, level.LH.DateMM,
			// 	level.LH.DateYY, level.LH.DateH, level.LH.DateM));
			cwfi.push_back(std::string("Timer: ") + std::to_string(level.LH.Timer));
			cwfi.push_back(std::string("Start Y: ") + std::to_string(level.LH.StartY));
			cwfi.push_back(fmt::format("Goal X: {}", level.LH.GoalX / 10.0));
			cwfi.push_back(std::string("Goal Y: ") + std::to_string(level.LH.GoalY));
			std::string clear_condition
				= fmt::format(levelMappings->NumToClearCondition.at(level.LH.ClearCRC), level.LH.ClearCA);
			cwfi.push_back(std::string("Clear Condition: ") + clear_condition);
			cwfi.push_back(std::string("Clear Condition Category: ")
						   + levelMappings->NumToClearConditionCategory.at(level.LH.ClearCC));
			cwfi.push_back(
				std::string("Autoscroll Speed: ") + levelMappings->NumToAutoscrollSpeed.at(level.LH.AutoscrollSpd));
			cwfi.push_back(
				std::string("Autoscroll Type: ") + levelMappings->NumToAutoscrollType.at(level.MapHdr.AutoscrollType));
			cwfi.push_back(std::string("Orientation: ") + levelMappings->NumToOrientation.at(level.MapHdr.Ori));
			cwfi.push_back(std::string("Liquid Start Height: ") + std::to_string(level.MapHdr.LiqSHeight));
			cwfi.push_back(std::string("Liquid End Height: ") + std::to_string(level.MapHdr.LiqEHeight));
			cwfi.push_back(std::string("Liquid Mode: ") + levelMappings->NumToLiquidMode.at(level.MapHdr.LiqMode));
			cwfi.push_back(std::string("Liquid Speed: ") + levelMappings->NumToLiquidSpeed.at(level.MapHdr.LiqSpd));
			cwfi.push_back(std::string("Boundary Type: ") + levelMappings->NumToBoundaryType.at(level.MapHdr.BorFlag));
			cwfi.push_back(std::string("Right Boundary: ") + std::to_string(level.MapHdr.BorR));
			cwfi.push_back(std::string("Top Boundary: ") + std::to_string(level.MapHdr.BorT));
			cwfi.push_back(std::string("Left Boundary: ") + std::to_string(level.MapHdr.BorL));
			cwfi.push_back(std::string("Bottom Boundary: ") + std::to_string(level.MapHdr.BorB));
			cwfi.push_back(std::string("Object Count: ") + std::to_string(level.MapHdr.ObjCount));
			cwfi.push_back(std::string("Sound Effect Count: ") + std::to_string(level.MapHdr.SndCount));
			cwfi.push_back(std::string("Snake Block Count: ") + std::to_string(level.MapHdr.SnakeCount));
			cwfi.push_back(std::string("Clear Pipe Count: ") + std::to_string(level.MapHdr.ClearPipCount));
			cwfi.push_back(std::string("Piranha Creeper Count: ") + std::to_string(level.MapHdr.CreeperCount));
			cwfi.push_back(std::string("! Block Count: ") + std::to_string(level.MapHdr.iBlkCount));
			cwfi.push_back(std::string("Track Count: ") + std::to_string(level.MapHdr.TrackCount));
			cwfi.push_back(std::string("Track Block Count: ") + std::to_string(level.MapHdr.TrackBlkCount));
			cwfi.push_back(std::string("Ground Count: ") + std::to_string(level.MapHdr.GroundCount));
			cwfi.push_back(std::string("Icicle Count: ") + std::to_string(level.MapHdr.IceCount));
			cwfi.push_back(std::string("UploadID (Unknown): ") + std::to_string(level.LH.UploadID));
			cwfi.push_back(std::string("CreationID (Unknown): ") + std::to_string(level.LH.CreationID));
			cwfi.push_back(std::string("GameVer (Unknown): ") + std::to_string(level.LH.GameVer));
			cwfi.push_back(std::string("Management Flags (Unknown): ") + std::to_string(level.LH.MFlag));
			cwfi.push_back("");
			cwfi.push_back("Level Objects:");
			for(auto& object : level.MapObj) {
				cwfi.push_back(std::string("- ") + std::string(ObjEng[object.ID]));
				cwfi.push_back(fmt::format("    x: {}", object.X / 10.0));
				cwfi.push_back(std::string("    y: ") + std::to_string(object.Y));
			}
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
		bool should_render = ImGui::Begin(fmt::format("{}##{}", iter->name, iter->window_id).c_str(), &is_open,
			ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar);
		if(!is_open || (close_current_level && i == focused_window_index)) {
			fmt::print("Deleted window {}\n", iter->name);
			std::filesystem::remove(iter->filename);
			delete iter->parser;
			delete iter->drawer;
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

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_KEEPALIVE bool mobile_emscripten_render(char* id) {
	// Not implemented
	download_level_id = std::string(id);
	level_downloading_routine();
	std::string path;
	for(int i = 0; i < 1000; i++) {
		// Give 20 seconds
		if(download_level_flag == 2) {
			return false;
		} else {
			path = download_level_destination;
			break;
		}
	}

	if(path.empty()) {
		return false;
	}

	LevelHandler data
		= AttemptRender(path, false, std::string(id) + "-overworld.png", std::string(id) + "-subworld.png");
	delete data.overworld;
	delete data.subworld;
	delete data.drawerOverworld;
	delete data.drawerSubworld;
	return true;
}
#endif

int main(int argc, char** argv) {
	cxxopts::Options options("TOOST", "A Super Mario Maker 2 level viewer, based on JiXiaomai's SMM2LevelViewer");

	// clang-format off
	options.add_options()
		("p,path", "Path to level to view", cxxopts::value<std::string>())
		("c,code", "Level code to view", cxxopts::value<std::string>())
		("o,overworld", "Where to put rendered overworld image", cxxopts::value<std::string>())
		("s,subworld", "Where to put rendered subworld image", cxxopts::value<std::string>())
		("overworldJson", "Where to put overworld JSON", cxxopts::value<std::string>())
		("subworldJson", "Where to put subworld JSON", cxxopts::value<std::string>())
		("a,scale", "Render level at this scale", cxxopts::value<float>())
		("r,removeGrid", "Remove grid from render")
		("e,objectsOverPipes", "Render objects over pipes rather than under them")
		("d,debug", "Enable debug logging")
		("h,help", "Print help menu");
	// clang-format on
	options.allow_unrecognised_options();

	auto result = options.parse(argc, argv);

	if(result.count("help")) {
		std::cout << options.help() << std::endl;
		return 0;
	}

#ifdef __EMSCRIPTEN__
	assetsFolder = "";
#elif defined(__linux__) and !defined(IS_DEBUG)
	assetsFolder = "/usr/share/toost";
#elif defined(__APPLE__) and !defined(IS_DEBUG)
	assetsFolder = Helpers::GetExecutableDirectory().parent_path().parent_path().append("share").string();
	std::replace(assetsFolder.begin(), assetsFolder.end(), '\\', '/');
#else
	assetsFolder = Helpers::GetExecutableDirectory().parent_path().parent_path().string();
	std::replace(assetsFolder.begin(), assetsFolder.end(), '\\', '/');
#endif

#ifndef __EMSCRIPTEN__
	curl_global_init(CURL_GLOBAL_ALL);
	curl_handle = curl_easy_init();
#endif

	std::string font_path = fmt::format("{}/fonts/NotoSansJP-Bold.otf", assetsFolder);
	FT_Init_FreeType(&freetype_library);
	FT_New_Face(freetype_library, font_path.c_str(), 0, &main_font);

	if(result.count("path") || result.count("code")) {
		std::string path;
		if(result.count("path")) {
			path = result["path"].as<std::string>();
		} else {
			download_level_id = result["code"].as<std::string>();
			level_downloading_routine();
			for(int i = 0; i < 1000; i++) {
#ifndef __EMSCRIPTEN__
				std::this_thread::sleep_for(std::chrono::milliseconds(5));
#endif
				if(download_level_flag == 2) {
					fmt::print("Level ID {} could not be downloaded\n", download_level_destination);
					return 1;
				} else {
					fmt::print("Level was downloaded to {}\n", download_level_destination);
					path = download_level_destination;
					break;
				}
			}

			if(path.empty()) {
				puts("Downloading took too long");
				return 1;
			}
		}

		if(std::filesystem::exists(path)) {
			std::string overworldImage = result.count("overworld") ? result["overworld"].as<std::string>() : "";
			std::string subworldImage  = result.count("subworld") ? result["subworld"].as<std::string>() : "";

			remove_grid               = result.count("removeGrid");
			render_objects_over_pipes = result.count("objectsOverPipes");

			if(result.count("scale")) {
				image_scale = result["scale"].as<float>();
			}

			if(!overworldImage.empty() || !subworldImage.empty()) {
				LevelHandler data = AttemptRender(path, result.count("debug"), overworldImage, subworldImage);
				if(data.overworld) {
					delete data.overworld;
					delete data.subworld;
				}
				if(data.subworld) {
					delete data.drawerOverworld;
					delete data.drawerSubworld;
				}
			}

			LevelHandler data;
			if(result.count("overworldJson") || result.count("subworldJson")) {
				data = AttemptRender(path, result.count("debug"), "instructionsOnly", "instructionsOnly");
			}

			if(result.count("overworldJson")) {
				data.overworld->ExportToJSON(
					result["overworldJson"].as<std::string>(), data.drawerOverworld->GetInstructions());
			}

			if(result.count("subworldJson")) {
				data.subworld->ExportToJSON(
					result["subworldJson"].as<std::string>(), data.drawerSubworld->GetInstructions());
			}

			delete data.overworld;
			delete data.subworld;
			delete data.drawerOverworld;
			delete data.drawerSubworld;

			if(result.count("code")) {
				std::filesystem::remove(path);
			}

			return 0;
		} else {
			fmt::print("Path {} does not exist\n", path);
			return 1;
		}
	}

#ifdef _WIN32
	ShowWindow(GetConsoleWindow(), SW_HIDE);
#endif

	signal(SIGINT, [](int) {
		for(auto& window : opened_level_windows) {
			std::filesystem::remove(window.filename);
			delete window.parser;
			delete window.drawer;
			glDeleteTextures(1, &window.level_render_image);
		}

		done = true;
#ifndef __EMSCRIPTEN__
		downloading_thread.join();
#endif
	});

#ifndef __EMSCRIPTEN__
	puts("Creating downloading thread");
	downloading_thread = std::thread(level_downloading_thread);
#endif

	puts("Starting toost GUI");
	started_level_windows = true;
	auto start            = std::chrono::high_resolution_clock::now();

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
	// WebGL1 + GL ES2
	const char* glsl_version = "#version 100";
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
		= (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_MAXIMIZED);
	window     = SDL_CreateWindow("Toost | Super Mario Maker 2 Level Viewer", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 640, 360, window_flags);
	gl_context = SDL_GL_CreateContext(window);

	if(!gl_context) {
		fprintf(stderr, "Failed to initialize OpenGL3 context!\n");
		return 1;
	}

	SDL_GL_MakeCurrent(window, gl_context);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	static ImFontConfig cfg;
	cfg.OversampleH = 1;
	cfg.OversampleV = 1;
	io.Fonts->AddFontFromFileTTF(font_path.c_str(), 24.0, &cfg, font_ranges);
	io.Fonts->Build();
	io.IniFilename = NULL;
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
	EM_ASM({ Module.showLoading = false; });
	emscripten_set_main_loop(main_loop, 0, true);
#else
	// Main loop
	while(!done) {
		main_loop();
		std::this_thread::sleep_for(std::chrono::milliseconds(16));
	}

	// Cleanup
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

#ifndef __EMSCRIPTEN__
	curl_easy_cleanup(curl_handle);
#endif

	SDL_GL_DeleteContext(gl_context);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
#endif
}