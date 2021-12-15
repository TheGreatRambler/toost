#pragma once

#include <cairo/cairo.h>
#include <cstdint>
#include <filesystem>
#include <fmt/core.h>
#include <string>
#include <unordered_set>
#include <vector>

#include "LevelParser.h"

class Drawers {
public:
	using Point = LevelParser::Point;

	Drawers(LevelParser& level_)
		: level(level_) {
		H            = level.MapHdr.BorT / 16;
		W            = level.MapHdr.BorR / 16;
		renderWidth  = (level.MapHdr.BorR / 16) * Zm;
		renderHeight = (level.MapHdr.BorT / 16) * Zm;
	};

	void SetGraphics(cairo_t* graphics);
	void SetTilesheet(std::string tilesheet);
	void SetZoom(int zoom);
	void SetIsOverworld(bool isOverworld);
	int GetWidth();
	int GetHeight();
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
	cairo_surface_t* Tile;
	int TileW;
	int H            = 0; // Width
	int W            = 0; //  Height
	int renderWidth  = 0;
	int renderHeight = 0;
	// Zm = std::pow(2, TrackBar1->Value);
	// B  = std::make_shared<Bitmap>(W * Zm, H * Zm);
	// G  = Graphics::FromImage(B);
	int Zm      = 16;   // Zoom value
	int NowIO   = 0;    // Overworld 0, subworld 1
	cairo_t* cr = NULL; // Graphics instance
	LevelParser& level; // Level instance
};