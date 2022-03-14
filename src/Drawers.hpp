#pragma once

#include "LevelParser.hpp"
#include "ObjectSpritesheet.hpp"

#include <cairo.h>
#include <cstdint>
#include <filesystem>
#include <fmt/core.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Drawers {
public:
	using Point = LevelParser::Point;

	Drawers(LevelParser& level_, int zoom)
		: level(level_) {
		Zm           = zoom;
		H            = level.MapHdr.BorT / 16;
		W            = level.MapHdr.BorR / 16;
		renderWidth  = (level.MapHdr.BorR / 16) * Zm;
		renderHeight = (level.MapHdr.BorT / 16) * Zm;
	};

	void Setup();
	void SetGraphics(cairo_t* graphics);
	void LoadTilesheet();
	void SetIsOverworld(bool isOverworld);
	void SetLog(bool log);
	void SetAssetFolder(std::string folder);
	void SetOnlyInstructions();
	std::vector<DrawingInstruction>& GetInstructions();
	int GetWidth();
	int GetHeight();
	void ClearImageCache();
	void DrawGridlines();
	cairo_pattern_t* GetCachedPattern(std::string path);
	void DrawTile(int tileX, int tileY, int tileW, int tileH, int x, int y, int targetWidth, int targetHeight);
	void DrawImage(std::string path, int x, int y, int targetWidth, int targetHeight);
	void DrawImageOpacity(std::string path, double opacity, int x, int y, int targetWidth, int targetHeight);
	void DrawImageRotate(std::string path, double angle, int x, int y, int targetWidth, int targetHeight);
	void DrawImageRotateOpacity(
		std::string path, double angle, double opacity, int x, int y, int targetWidth, int targetHeight);
	void DrawCrp(unsigned char EX, int X, int Y);
	void DrawSnake(unsigned char EX, int X, int Y, int SW, int SH);
	void DrawMoveBlock(unsigned char ID, unsigned char EX, int X, int Y);
	void DrawItem(const std::unordered_set<short>& K, bool L);
	void ReGrdCode();
	void DrawGrd();
	int GetGrdType(const std::string& A);
	std::string GetGrdCode(int x, int y);
	int GetGrdBold(int x, int y);
	Point GetCorCode(int x, int y);
	int CalC(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
	void DrawGrdCode();
	void DrawIce();
	void DrawTrack();
	void DrawCID();
	void DrawFireBar();
	void DrawFire();
	void DrawCPipe();

private:
	int TileW;
	int H            = 0;
	int W            = 0;
	int renderWidth  = 0;
	int renderHeight = 0;
	int Zm           = 16;
	int NowIO        = 0;

	cairo_t* cr = NULL;
	LevelParser& level;
	bool doLogging = false;

	std::string assetFolder;
	std::string tilesheetPath;

	bool addDrawingInstructions = true;
	bool noRender               = false;
	std::vector<DrawingInstruction> drawingInstructions;

	std::unordered_map<std::string, cairo_pattern_t*> patternCache;
	cairo_surface_t* tilesheet   = NULL;
	cairo_surface_t* spritesheet = NULL;
};