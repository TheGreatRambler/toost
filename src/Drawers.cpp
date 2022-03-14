#include "Drawers.hpp"

void Drawers::Setup() {
	// 4,4A 5 6 8 8A 21 22 23 23A 29 43 49 63 79 79A 92 99 100 100A
	level.TileLoc[4][0]   = Point(1, 0);
	level.TileLoc[4][1]   = Point(2, 43);
	level.TileLoc[5][0]   = Point(2, 0);
	level.TileLoc[6][0]   = Point(6, 0);
	level.TileLoc[8][0]   = Point(7, 0);
	level.TileLoc[8][1]   = Point(0, 17);
	level.TileLoc[21][0]  = Point(0, 4);
	level.TileLoc[22][0]  = Point(6, 6);
	level.TileLoc[23][0]  = Point(4, 0);
	level.TileLoc[23][1]  = Point(6, 5);
	level.TileLoc[29][0]  = Point(3, 0);
	level.TileLoc[43][0]  = Point(2, 4);
	level.TileLoc[49][0]  = Point(15, 15);
	level.TileLoc[63][0]  = Point(8, 7);
	level.TileLoc[79][0]  = Point(1, 43);
	level.TileLoc[79][1]  = Point(0, 43);
	level.TileLoc[92][0]  = Point(0, 16);
	level.TileLoc[99][0]  = Point(2, 23);
	level.TileLoc[100][0] = Point(3, 22);
	level.TileLoc[100][1] = Point(2, 21);

	// pipe loc
	// UDLRVH
	// GRBO
	level.PipeLoc[0][0] = Point(14, 0);
	level.PipeLoc[0][1] = Point(14, 2);
	level.PipeLoc[0][2] = Point(11, 0);
	level.PipeLoc[0][3] = Point(13, 0);
	level.PipeLoc[0][4] = Point(12, 0);
	level.PipeLoc[0][5] = Point(14, 1);

	level.PipeLoc[1][0] = Point(6, 37);
	level.PipeLoc[1][1] = Point(12, 37);
	level.PipeLoc[1][2] = Point(4, 24);
	level.PipeLoc[1][3] = Point(6, 24);
	level.PipeLoc[1][4] = Point(5, 24);
	level.PipeLoc[1][5] = Point(6, 38);

	level.PipeLoc[2][0] = Point(10, 37);
	level.PipeLoc[2][1] = Point(12, 38);
	level.PipeLoc[2][2] = Point(3, 37);
	level.PipeLoc[2][3] = Point(5, 37);
	level.PipeLoc[2][4] = Point(4, 37);
	level.PipeLoc[2][5] = Point(10, 38);

	level.PipeLoc[3][0] = Point(8, 37);
	level.PipeLoc[3][1] = Point(14, 37);
	level.PipeLoc[3][2] = Point(0, 37);
	level.PipeLoc[3][3] = Point(2, 37);
	level.PipeLoc[3][4] = Point(1, 37);
	level.PipeLoc[3][5] = Point(8, 38);

	uint8_t GS[] = { 0x0D, 0x4D, 0x1D, 0xAD, 0x3D, 0x9D, 0x2D, 0xCD, 0x6D, 0x5D, 0x8D, 0xED, 0x7D, 0xDD, 0xBD, 0xFD,
		0x0D, 0x4D, 0x1D, 0x2F, 0x3D, 0x9D, 0x2D, 0x4E, 0x6D, 0x5D, 0x8D, 0x0E, 0x7D, 0xDD, 0xBD, 0x8E, 0x0D, 0x4D,
		0x1D, 0xAD, 0x3D, 0x4F, 0x2D, 0x5E, 0x6D, 0x5D, 0x8D, 0xED, 0x7D, 0x1E, 0xBD, 0x9E, 0x0D, 0x4D, 0x1D, 0x2F,
		0x3D, 0x4F, 0x2D, 0x3F, 0x6D, 0x5D, 0x8D, 0x0E, 0x7D, 0x1E, 0xBD, 0xCE, 0x0D, 0x4D, 0x1D, 0xAD, 0x3D, 0x9D,
		0x2D, 0xCD, 0x6D, 0x5D, 0x8F, 0x2E, 0x7D, 0xDD, 0x6E, 0xAE, 0x0D, 0x4D, 0x1D, 0x2F, 0x3D, 0x9D, 0x2D, 0x4E,
		0x6D, 0x5D, 0x8F, 0x5F, 0x7D, 0xDD, 0x6E, 0xEE, 0x0D, 0x4D, 0x1D, 0xAD, 0x3D, 0x4F, 0x2D, 0x5E, 0x6D, 0x5D,
		0x8F, 0x2E, 0xAF, 0x1E, 0x6E, 0x1F, 0x0D, 0x4D, 0x1D, 0x2F, 0x3D, 0x4F, 0x2D, 0x3F, 0x6D, 0x5D, 0x8F, 0x5F,
		0x7D, 0x1E, 0x6E, 0xBF, 0x0D, 0x4D, 0x1D, 0xAD, 0x3D, 0x9D, 0x2D, 0xCD, 0x6D, 0x5D, 0x8D, 0xED, 0xAF, 0x3E,
		0x7E, 0xBE, 0x0D, 0x4D, 0x1D, 0x2F, 0x3D, 0x9D, 0x2D, 0x4E, 0x6D, 0x5D, 0x8D, 0x0E, 0x7D, 0x3E, 0x7E, 0x0F,
		0x0D, 0x4D, 0x1D, 0xAD, 0x3D, 0x4F, 0x2D, 0x5E, 0x6D, 0x5D, 0x8D, 0xED, 0xAF, 0x7F, 0x7E, 0xFE, 0x0D, 0x4D,
		0x1D, 0x2F, 0x3D, 0x4F, 0x2D, 0x3F, 0x6D, 0x5D, 0x8D, 0x0E, 0xAF, 0x7F, 0x7E, 0xCF, 0x0D, 0x4D, 0x1D, 0xAD,
		0x3D, 0x9D, 0x2D, 0xCD, 0x6D, 0x5D, 0x8F, 0x2E, 0xAF, 0x3E, 0x9F, 0xDE, 0x0D, 0x4D, 0x1D, 0x2F, 0x3D, 0x9D,
		0x2D, 0x4E, 0x6D, 0x5D, 0x8F, 0x5F, 0xAF, 0x3E, 0x9F, 0xDF, 0x0D, 0x4D, 0x1D, 0xAD, 0x3D, 0x4F, 0x2D, 0x5E,
		0x6D, 0x5D, 0x8F, 0x2E, 0xAF, 0x7F, 0x9F, 0xEF, 0x0D, 0x4D, 0x1D, 0x2F, 0x3D, 0x4F, 0x2D, 0x3F, 0x6D, 0x5D,
		0x8F, 0x5F, 0xAF, 0x7F, 0x9F, 0x6F };

	for(int i = 0; i <= 255; i++) {
		level.GrdLoc[i].X = GS[i] >> 4;
		level.GrdLoc[i].Y = GS[i] & 0x0F;
	}

	level.TrackYPt[8][0]  = Point(4, 0);
	level.TrackYPt[8][1]  = Point(0, 2);
	level.TrackYPt[8][2]  = Point(4, 4);
	level.TrackYPt[12][0] = Point(4, 0);
	level.TrackYPt[12][1] = Point(0, 2);
	level.TrackYPt[12][2] = Point(4, 4);

	level.TrackYPt[9][0]  = Point(0, 0);
	level.TrackYPt[9][1]  = Point(0, 4);
	level.TrackYPt[9][2]  = Point(4, 2);
	level.TrackYPt[13][0] = Point(0, 0);
	level.TrackYPt[13][1] = Point(0, 4);
	level.TrackYPt[13][2] = Point(4, 2);

	level.TrackYPt[10][0] = Point(0, 0);
	level.TrackYPt[10][1] = Point(4, 0);
	level.TrackYPt[10][2] = Point(2, 4);
	level.TrackYPt[14][0] = Point(0, 0);
	level.TrackYPt[14][1] = Point(4, 0);
	level.TrackYPt[14][2] = Point(2, 4);

	level.TrackYPt[11][0] = Point(2, 0);
	level.TrackYPt[11][1] = Point(0, 4);
	level.TrackYPt[11][2] = Point(4, 4);
	level.TrackYPt[15][0] = Point(2, 0);
	level.TrackYPt[15][1] = Point(0, 4);
	level.TrackYPt[15][2] = Point(4, 4);
}

void Drawers::SetGraphics(cairo_t* graphics) {
	cr = graphics;
}

void Drawers::LoadTilesheet() {
	tilesheetPath = fmt::format("{}/img/tile/{}-{}{}.png", assetFolder, level.LH.GameStyle, level.MapHdr.Theme,
		(level.MapHdr.Flag == 2) ? "A" : "");
	tilesheet     = cairo_image_surface_create_from_png(tilesheetPath.c_str());

	if(cairo_surface_status(tilesheet) == CAIRO_STATUS_FILE_NOT_FOUND) {
		fmt::print("Tilesheet {} does not exist\n", tilesheetPath);
	}

	TileW = cairo_image_surface_get_width(tilesheet) / 16;

	std::string spritesheetPath = fmt::format("{}/img/spritesheet.png", assetFolder);
	spritesheet                 = cairo_image_surface_create_from_png(spritesheetPath.c_str());

	if(cairo_surface_status(spritesheet) == CAIRO_STATUS_FILE_NOT_FOUND) {
		fmt::print("Spritesheet {} does not exist\n", spritesheetPath);
	}
}

void Drawers::SetIsOverworld(bool isOverworld) {
	NowIO = isOverworld;
}

void Drawers::SetLog(bool log) {
	doLogging = log;
}

void Drawers::SetAssetFolder(std::string folder) {
	assetFolder = folder;
}

void Drawers::SetOnlyInstructions() {
	noRender = true;
}

std::vector<DrawingInstruction>& Drawers::GetInstructions() {
	return drawingInstructions;
}

int Drawers::GetWidth() {
	return renderWidth;
}

int Drawers::GetHeight() {
	return renderHeight;
}

void Drawers::ClearImageCache() {
	for(auto& pattern : patternCache) {
		cairo_pattern_destroy(pattern.second);
	}

	cairo_surface_destroy(tilesheet);
	cairo_surface_destroy(spritesheet);
}

void Drawers::DrawGridlines() {
	int i = 0;

	if(!noRender) {
		cairo_set_antialias(cr, CAIRO_ANTIALIAS_NONE);
		cairo_set_operator(cr, CAIRO_OPERATOR_SOURCE);
		cairo_set_line_width(cr, 1);

		for(i = 0; i <= H; i++) {
			cairo_set_source_rgba(cr, 0.41, 0.41, 0.41, 0.25);
			cairo_move_to(cr, 0, i * Zm);
			cairo_line_to(cr, W * Zm, i * Zm);
			cairo_stroke(cr);

			if(i % 13 == 0) {
				cairo_move_to(cr, 0, (H - i) * Zm + 1);
				cairo_line_to(cr, W * Zm, (H - i) * Zm + 1);
				cairo_stroke(cr);
			}

			if((H - i) % 10 == 0) {
				cairo_set_source_rgb(cr, 0, 0, 0);
				cairo_move_to(cr, 3, (i - 0.25) * Zm);
				cairo_show_text(cr, std::to_string(H - i).c_str());
			}
		}

		for(i = 0; i <= W; i++) {
			cairo_set_source_rgba(cr, 0.41, 0.41, 0.41, 0.25);
			cairo_move_to(cr, i * Zm, 0);
			cairo_line_to(cr, i * Zm, W * Zm);
			cairo_stroke(cr);

			if(i % 24 == 0) {
				cairo_move_to(cr, i * Zm + 1, 0);
				cairo_line_to(cr, i * Zm + 1, H * Zm);
				cairo_stroke(cr);
			}

			if(i % 10 == 9) {
				cairo_set_source_rgb(cr, 0, 0, 0);
				cairo_move_to(cr, i * Zm + 3, Zm * 0.75);
				cairo_show_text(cr, std::to_string(i + 1).c_str());
			}
		}

		if(level.MapHdr.Theme == 2) {
			cairo_set_source_rgba(cr, 1.0, 0.0, 0.0, 0.4);
			cairo_rectangle(cr, 0, (H - level.MapHdr.LiqEHeight - 0.5) * Zm, W * Zm, H * Zm);
			cairo_rectangle(cr, 0, (H - level.MapHdr.LiqSHeight - 0.5) * Zm, W * Zm, H * Zm);
			cairo_stroke_preserve(cr);
			cairo_fill(cr);
		} else if(level.MapHdr.Theme == 9) {
			cairo_set_source_rgba(cr, 0.0, 0.0, 1.0, 0.4);
			cairo_rectangle(cr, 0, (H - level.MapHdr.LiqEHeight - 0.5) * Zm, W * Zm, H * Zm);
			cairo_rectangle(cr, 0, (H - level.MapHdr.LiqSHeight - 0.5) * Zm, W * Zm, H * Zm);
			cairo_stroke_preserve(cr);
			cairo_fill(cr);
		}

		cairo_set_antialias(cr, CAIRO_ANTIALIAS_DEFAULT);
		cairo_set_operator(cr, CAIRO_OPERATOR_OVER);
	}
}

cairo_pattern_t* Drawers::GetCachedPattern(std::string path) {
	if(patternCache.contains(path)) {
		return patternCache[path];
	} else {
		if(!objectSpritesheet->ObjectLocation.contains(path)) {
			fmt::print("Image {} does not exist\n", path);
			return NULL;
		}

		const auto sprite = objectSpritesheet->ObjectLocation.at(path);
		cairo_surface_t* subsurface
			= cairo_surface_create_for_rectangle(spritesheet, sprite.x, sprite.y, sprite.width, sprite.height);
		cairo_pattern_t* pattern = cairo_pattern_create_for_surface(subsurface);
		cairo_surface_destroy(subsurface);
		cairo_pattern_set_filter(pattern, CAIRO_FILTER_NEAREST);
		patternCache[path] = pattern;
		return pattern;
	}
}

void Drawers::DrawTile(int tileX, int tileY, int tileW, int tileH, int x, int y, int targetWidth, int targetHeight) {
	if(doLogging)
		fmt::print("Printing tile X:{} Y:{}\n", tileX, tileY);

	if(!noRender) {
		cairo_save(cr);
		cairo_translate(cr, (double)x, (double)y);
		cairo_scale(cr, (double)targetWidth / (TileW * tileW), (double)targetHeight / (TileW * tileH));
		cairo_set_source_surface(cr, tilesheet, -TileW * tileX, -TileW * tileY);
		cairo_rectangle(cr, 0, 0, TileW * tileW, TileW * tileH);
		cairo_clip(cr);
		cairo_paint(cr);
		cairo_restore(cr);
	}

	if(addDrawingInstructions) {
		DrawingInstruction instruction;
		instruction.path         = tilesheetPath;
		instruction.isTile       = true;
		instruction.x            = x;
		instruction.y            = y;
		instruction.targetWidth  = targetWidth;
		instruction.targetHeight = targetHeight;
		instruction.tileX        = tileX;
		instruction.tileY        = tileY;
		instruction.tileW        = tileW;
		instruction.tileH        = tileH;
		drawingInstructions.push_back(instruction);
	}
}

void Drawers::DrawImage(std::string path, int x, int y, int targetWidth, int targetHeight) {
	if(doLogging)
		fmt::print("Printing {} at X:{} Y:{} with W:{} and H:{}\n", path, x, y, targetWidth, targetHeight);

	if(!noRender) {
		cairo_pattern_t* pattern = GetCachedPattern(path);

		if(pattern) {
			const auto sprite = objectSpritesheet->ObjectLocation.at(path);
			cairo_save(cr);
			cairo_translate(cr, (double)x, (double)y);
			cairo_scale(cr, (double)targetWidth / sprite.width, (double)targetHeight / sprite.height);
			cairo_set_source(cr, pattern);
			cairo_paint_with_alpha(cr, 1.0);
			cairo_restore(cr);
		}
	}

	if(addDrawingInstructions) {
		DrawingInstruction instruction;
		instruction.path         = path.erase(0, assetFolder.length());
		instruction.isTile       = false;
		instruction.x            = x;
		instruction.y            = y;
		instruction.targetWidth  = targetWidth;
		instruction.targetHeight = targetHeight;
		instruction.angle        = 0;
		instruction.opacity      = 1.0;
		drawingInstructions.push_back(instruction);
	}
}

void Drawers::DrawImageOpacity(std::string path, double opacity, int x, int y, int targetWidth, int targetHeight) {
	if(doLogging)
		fmt::print("Printing {} at X:{} Y:{} with W:{} and H:{}\n", path, x, y, targetWidth, targetHeight);

	if(!noRender) {
		cairo_pattern_t* pattern = GetCachedPattern(path);

		if(pattern) {
			const auto sprite = objectSpritesheet->ObjectLocation.at(path);
			cairo_save(cr);
			cairo_translate(cr, (double)x, (double)y);
			cairo_scale(cr, (double)targetWidth / sprite.width, (double)targetHeight / sprite.height);
			cairo_set_source(cr, pattern);
			cairo_paint_with_alpha(cr, opacity);
			cairo_restore(cr);
		}
	}

	if(addDrawingInstructions) {
		DrawingInstruction instruction;
		instruction.path         = path.erase(0, assetFolder.length());
		instruction.isTile       = false;
		instruction.x            = x;
		instruction.y            = y;
		instruction.targetWidth  = targetWidth;
		instruction.targetHeight = targetHeight;
		instruction.angle        = 0;
		instruction.opacity      = opacity;
		drawingInstructions.push_back(instruction);
	}
}

void Drawers::DrawImageRotate(std::string path, double angle, int x, int y, int targetWidth, int targetHeight) {
	if(doLogging)
		fmt::print("Printing {} at X:{} Y:{} with W:{} and H:{}\n", path, x, y, targetWidth, targetHeight);

	if(!noRender) {
		cairo_pattern_t* pattern = GetCachedPattern(path);

		if(pattern) {
			const auto sprite = objectSpritesheet->ObjectLocation.at(path);
			cairo_save(cr);
			cairo_translate(cr, (double)x + (targetWidth / 2), (double)y + (targetHeight / 2));
			cairo_rotate(cr, angle);
			cairo_scale(cr, (double)targetWidth / sprite.width, (double)targetHeight / sprite.height);
			cairo_translate(cr, -sprite.width / 2, -sprite.height / 2);
			cairo_set_source(cr, pattern);
			cairo_paint(cr);
			cairo_restore(cr);
		}
	}

	if(addDrawingInstructions) {
		DrawingInstruction instruction;
		instruction.path         = path.erase(0, assetFolder.length());
		instruction.isTile       = false;
		instruction.x            = x;
		instruction.y            = y;
		instruction.targetWidth  = targetWidth;
		instruction.targetHeight = targetHeight;
		instruction.angle        = angle;
		instruction.opacity      = 1.0;
		drawingInstructions.push_back(instruction);
	}
}

void Drawers::DrawImageRotateOpacity(
	std::string path, double angle, double opacity, int x, int y, int targetWidth, int targetHeight) {
	if(doLogging)
		fmt::print("Printing {} at X:{} Y:{} with W:{} and H:{}\n", path, x, y, targetWidth, targetHeight);

	if(!noRender) {
		cairo_pattern_t* pattern = GetCachedPattern(path);

		if(pattern) {
			const auto sprite = objectSpritesheet->ObjectLocation.at(path);
			cairo_save(cr);
			cairo_translate(cr, (double)x + (targetWidth / 2), (double)y + (targetHeight / 2));
			cairo_rotate(cr, angle);
			cairo_scale(cr, (double)targetWidth / sprite.width, (double)targetHeight / sprite.height);
			cairo_translate(cr, -sprite.width / 2, -sprite.height / 2);
			cairo_set_source(cr, pattern);
			cairo_paint_with_alpha(cr, opacity);
			cairo_restore(cr);
		}
	}

	if(addDrawingInstructions) {
		DrawingInstruction instruction;
		instruction.path         = path.erase(0, assetFolder.length());
		instruction.isTile       = false;
		instruction.x            = x;
		instruction.y            = y;
		instruction.targetWidth  = targetWidth;
		instruction.targetHeight = targetHeight;
		instruction.angle        = angle;
		instruction.opacity      = opacity;
		drawingInstructions.push_back(instruction);
	}
}

void Drawers::DrawCrp(unsigned char EX, int X, int Y) {
	int XX = std::round(X / 160.0 + 1);
	int YY = std::round((Y + 80) / 160.0 + 1);
	int i  = 0;

	switch(level.MapCrp[EX - 1].Node[0]) {
	case 1:
	case 5:
	case 7:
	case 14:
		XX -= 4;
		break;
	case 2:
	case 9:
	case 11:
	case 13:

		break;
	case 3:
	case 6:
	case 10:
	case 16:
		XX -= 2;
		YY -= 2;
		break;
	case 4:
	case 8:
	case 12:
	case 15:
		XX -= 2;
		YY += 2;
		break;
	}

	for(i = 0; i < level.MapCrp[EX - 1].NodeCount; i++) {
		DrawImage("img/cmn/SS.png", XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);

		std::string path;
		switch(level.MapCrp[EX - 1].Node[i]) {
		case 1: // L
			path = "img/cmn/SL.png";
			XX -= 2;
			break;
		case 2: // R
			path = "img/cmn/SR.png";
			XX += 2;
			break;
		case 3: // D
			path = "img/cmn/SD.png";
			YY -= 2;
			break;
		case 4: // U
			path = "img/cmn/SU.png";
			YY += 2;
			break;
		case 5: // LD
			path = "img/cmn/SRD.png";
			YY -= 2;
			break;
		case 6: // DL
			path = "img/cmn/SUL.png";
			XX -= 2;
			break;
		case 7: // LU
			path = "img/cmn/SRU.png";
			YY += 2;
			break;
		case 8: // UL
			path = "img/cmn/SDL.png";
			XX -= 2;
			break;
		case 9: // RD
			path = "img/cmn/SLD.png";
			YY -= 2;
			break;
		case 10: // DR
			path = "img/cmn/SUR.png";
			XX += 2;
			break;
		case 11: // RU
			path = "img/cmn/SLU.png";
			YY += 2;
			break;
		case 12: // UR
			path = "img/cmn/SDR.png";
			XX += 2;
			break;
		case 13: // RE
			path = "img/cmn/SE.png";
			break;
		case 14: // LE
			path = "img/cmn/SE.png";
			break;
		case 15: // UE
			path = "img/cmn/SE.png";
			break;
		case 16: // DE
			path = "img/cmn/SE.png";
			break;
		}
		DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
	}
}

void Drawers::DrawSnake(unsigned char EX, int X, int Y, int SW, int SH) {
	int XX = 0;
	int YY = 0;

	YY = std::round((Y + SH * 80) / 160.0);
	if(EX < 0x10) {
		XX = std::round((X + SW * 80) / 160.0);
		EX = (unsigned char)(EX % 0x10);
		switch(level.MapSnk[EX - 1].Node[0].Dir) {
		case 1:
		case 5:
		case 7:
			XX -= 1;
			break;
		case 2:
		case 9:
		case 11:

			break;
		case 3:
		case 6:
		case 10:
			XX -= 1;
			YY -= 1;
			break;
		case 4:
		case 8:
		case 12:
			XX -= 1;
			YY += 1;
			break;
		}
	} else {
		XX = std::round((X - SW * 80) / 160.0);
		EX = (unsigned char)(EX % 0x10);
		switch(level.MapSnk[EX - 1].Node[0].Dir) {
		case 1:
		case 5:
		case 7:
			XX -= 1;
			break;
		case 2:
		case 9:
		case 11:

			break;
		case 3:
		case 6:
		case 10:
			YY -= 1;
			break;
		case 4:
		case 8:
		case 12:
			YY += 1;
			break;
		}
	}

	int i = 0;

	for(i = 0; i < level.MapSnk[EX - 1].NodeCount; i++) {
		DrawImage("img/cmn/SS.png", XX * Zm, (H - YY) * Zm, Zm, Zm);

		std::string path;
		switch(level.MapSnk[EX - 1].Node[i].Dir) {
		case 1: // L
			path = "img/cmn/SL.png";
			XX -= 1;
			break;
		case 2: // R
			path = "img/cmn/SR.png";
			XX += 1;
			break;
		case 3: // D
			path = "img/cmn/SD.png";
			YY -= 1;
			break;
		case 4: // U
			path = "img/cmn/SU.png";
			YY += 1;
			break;
		case 5: // LD
			path = "img/cmn/SRD.png";
			YY -= 1;
			break;
		case 6: // DL
			path = "img/cmn/SUL.png";
			XX -= 1;
			break;
		case 7: // LU
			path = "img/cmn/SRU.png";
			YY += 1;
			break;
		case 8: // UL
			path = "img/cmn/SDL.png";
			XX -= 1;
			break;
		case 9: // RD
			path = "img/cmn/SLD.png";
			YY -= 1;
			break;
		case 10: // DR
			path = "img/cmn/SUR.png";
			XX += 1;
			break;
		case 11: // RU
			path = "img/cmn/SLU.png";
			YY += 1;
			break;
		case 12: // UR
			path = "img/cmn/SDR.png";
			XX += 1;
			break;
		case 13: // RE
			path = "img/cmn/SE.png";
			break;
		case 14: // LE
			path = "img/cmn/SE.png";
			break;
		case 15: // UE
			path = "img/cmn/SE.png";
			break;
		case 16: // DE
			path = "img/cmn/SE.png";
			break;
		}
		DrawImage(path, XX * Zm, (H - YY) * Zm, Zm, Zm);
	}
	// Err:;
}

void Drawers::DrawMoveBlock(unsigned char ID, unsigned char EX, int X, int Y) {
	int XX = 0;
	int YY = 0;
	XX     = std::round(X / 160.0 + 1);
	YY     = std::round((Y + 80) / 160.0 + 1);
	int i  = 0;

	switch(ID) {
	case 85: {
		switch(level.MapTrackBlk[EX - 1].Node[0].p1) {
		case 1:
		case 5:
		case 7:
		case 14:
			XX -= 4;
			break;
		case 2:
		case 9:
		case 11:
		case 13:

			break;
		case 3:
		case 6:
		case 10:
		case 16:
			XX -= 2;
			YY -= 2;
			break;
		case 4:
		case 8:
		case 12:
		case 15:
			XX -= 2;
			YY += 2;
			break;
		}

		for(i = 0; i < level.MapTrackBlk[EX - 1].NodeCount; i++) {
			DrawImage("img/cmn/SS.png", XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);

			std::string path;
			switch(level.MapTrackBlk[EX - 1].Node[i].p1) {
			case 1: // L
				path = "img/cmn/SL.png";
				XX -= 2;
				break;
			case 2: // R
				path = "img/cmn/SR.png";
				XX += 2;
				break;
			case 3: // D
				path = "img/cmn/SD.png";
				YY -= 2;
				break;
			case 4: // U
				path = "img/cmn/SU.png";
				YY += 2;
				break;
			case 5: // LD
				path = "img/cmn/SRD.png";
				YY -= 2;
				break;
			case 6: // DL
				path = "img/cmn/SUL.png";
				XX -= 2;
				break;
			case 7: // LU
				path = "img/cmn/SRU.png";
				YY += 2;
				break;
			case 8: // UL
				path = "img/cmn/SDL.png";
				XX -= 2;
				break;
			case 9: // RD
				path = "img/cmn/SLD.png";
				YY -= 2;
				break;
			case 10: // DR
				path = "img/cmn/SUR.png";
				XX += 2;
				break;
			case 11: // RU
				path = "img/cmn/SLU.png";
				YY += 2;
				break;
			case 12: // UR
				path = "img/cmn/SDR.png";
				XX += 2;
				break;
			case 13: // RE
				path = "img/cmn/SE.png";
				break;
			case 14: // LE
				path = "img/cmn/SE.png";
				break;
			case 15: // UE
				path = "img/cmn/SE.png";
				break;
			case 16: // DE
				path = "img/cmn/SE.png";
				break;
			}
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
		}
	} break;
	case 119: {
		switch(level.MapMoveBlk[EX - 1].Node[0].p1) {
		case 1:
		case 5:
		case 7:
		case 14:
			XX -= 4;
			break;
		case 2:
		case 9:
		case 11:
		case 13:

			break;
		case 3:
		case 6:
		case 10:
		case 16:
			XX -= 2;
			YY -= 2;
			break;
		case 4:
		case 8:
		case 12:
		case 15:
			XX -= 2;
			YY += 2;
			break;
		}

		for(i = 0; i < level.MapMoveBlk[EX - 1].NodeCount; i++) {
			DrawImage("img/cmn/SS.png", XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);

			std::string path;
			switch(level.MapMoveBlk[EX - 1].Node[i].p1) {
			case 1: // L
				path = "img/cmn/SL.png";
				XX -= 2;
				break;
			case 2: // R
				path = "img/cmn/SR.png";
				XX += 2;
				break;
			case 3: // D
				path = "img/cmn/SD.png";
				YY -= 2;
				break;
			case 4: // U
				path = "img/cmn/SU.png";
				YY += 2;
				break;
			case 5: // LD
				path = "img/cmn/SRD.png";
				YY -= 2;
				break;
			case 6: // DL
				path = "img/cmn/SUL.png";
				XX -= 2;
				break;
			case 7: // LU
				path = "img/cmn/SRU.png";
				YY += 2;
				break;
			case 8: // UL
				path = "img/cmn/SDL.png";
				XX -= 2;
				break;
			case 9: // RD
				path = "img/cmn/SLD.png";
				YY -= 2;
				break;
			case 10: // DR
				path = "img/cmn/SUR.png";
				XX += 2;
				break;
			case 11: // RU
				path = "img/cmn/SLU.png";
				YY += 2;
				break;
			case 12: // UR
				path = "img/cmn/SDR.png";
				XX += 2;
				break;
			case 13: // RE
				path = "img/cmn/SE.png";
				break;
			case 14: // LE
				path = "img/cmn/SE.png";
				break;
			case 15: // UE
				path = "img/cmn/SE.png";
				break;
			case 16: // DE
				path = "img/cmn/SE.png";
				break;
			}
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
		}
	} break;
	}
	// Err:;
}

void Drawers::DrawItem(const std::unordered_set<short>& K, bool L) {
	// On Error Resume Next
	int i          = 0;
	int j          = 0;
	int tileY      = 0;
	std::string PR = "";
	int LX         = 0;
	int LY         = 0;
	int KY         = 0;
	int PP         = 0;
	std::string P  = assetFolder;
	std::string path;

	for(i = 0; i < level.MapHdr.ObjCount; i++) {
		int objID = level.MapObj[i].ID;
		if(K.count(objID)) {
			int objW    = level.MapObj[i].W;
			int objH    = level.MapObj[i].H;
			int objFlag = level.MapObj[i].Flag;
			int objLid  = level.MapObj[i].LID;
			int objCid  = level.MapObj[i].CID;
			int objX    = level.MapObj[i].X;
			int objY    = level.MapObj[i].Y;

			if(objID == 105) {
				if((objFlag / 0x400) % 2 == 1) {
					KY = 0;
				} else {
					KY = -3 * Zm;
				}
				level.ObjLinkType[objLid + 1] = 105;

				if((objFlag / 0x80) % 2 == 1) {
					path = fmt::format("img/{}/obj/105A.png", level.LH.GameStyle);
				} else {
					path = fmt::format("img/{}/obj/105.png", level.LH.GameStyle);
				}
				DrawImage(path, (float)(-1.5 + objX / 160.0) * Zm, H * Zm - (float)(0.5 + objY / 160.0) * Zm + KY,
					Zm * 3, Zm * 5);

				if(objCid != -1) {
					if((level.MapObj[i].CFlag / 0x4) % 2 == 1) {
						path = fmt::format("img/{}/cid/{}A.png", level.LH.GameStyle, objCid);
					} else {
						path = fmt::format("img/{}/cid/{}.png", level.LH.GameStyle, objCid);
					}
					DrawImage(path, LX, LY + KY, Zm, Zm);
				}
			} else {
				switch(level.ObjLinkType[objLid + 1]) {
				case 9: //管道L
					KY = ((std::min(objW, objH) - 1) / 2) * Zm;
					break;
				case 105: //夹子L
					KY = std::round(-Zm / 4.0);
					break;
				case 59: //轨道
					KY = ((std::min(objW, objH) - 1) / 2) * Zm;
					break;
				case 31:
					KY = 0; // 3 * Zm
					break;
				case 106: //树
					KY = 0;
					break;
				case 0:
					KY = 0;
					break;
				}

				if((objLid + 1 == 0 && !L) || (objLid + 1 > 0 && L) || objID == 9) {
					switch(objID) {
					case 14: {
						//蘑菇平台
						if((objFlag / 0x40000) % 2 == 1) {
							tileY = 3;
						} else if((objFlag / 0x80000) % 2 == 1) {
							tileY = 4;
						} else {
							tileY = 2;
						}

						for(j = 0; j < objW; j++) {
							int tileX = 4;
							if(j == 0) {
								tileX = 3;
							} else if(j == objW - 1) {
								tileX = 5;
							}
							DrawTile(tileX, tileY, 1, 1, (float)((j - 0.5 + objX / 160.0) * Zm),
								H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm, Zm);
						}

						if(objW % 2 == 0) {
							for(j = 1; j < objH; j++) {
								tileY = 2;
								if(j == 1) {
									tileY = 1;
								}

								DrawTile(6, tileY, 1, 1, (float)((objX / 160.0 + objW / 2.0 - 1.5) * Zm),
									H * Zm - (float)((objH - 0.5 + objY / 160.0 - j) * Zm), Zm, Zm);
								DrawTile(7, tileY, 1, 1, (float)((objX / 160.0 + objW / 2.0 - 0.5) * Zm),
									H * Zm - (float)((objH - 0.5 + objY / 160.0 - j) * Zm), Zm, Zm);
							}
						} else {
							for(j = 1; j < objH; j++) {
								tileY = 4;
								if(j == 1) {
									tileY = 3;
								}

								DrawTile(6, tileY, 1, 1, (float)((0.5 + objX / 160.0 + (objW - 3) / 2.0) * Zm),
									H * Zm - (float)((objH - 0.5 + objY / 160.0 - j) * Zm), Zm, Zm);
							}
						}
						break;
					}
					case 16: {
						//半碰撞地形
						if((objFlag / 0x40000) % 2 == 1) {
							tileY = 10;
						} else if((objFlag / 0x80000) % 2 == 1) {
							tileY = 13;
						} else {
							tileY = 7;
						}

						for(j = 0; j < objW; j++) {
							int offsetX = 1;
							if(j == 0) {
								offsetX = 0;
							} else if(j == (objW - 1)) {
								offsetX = 2;
							}

							for(int y = 0; y < objH; y++) {
								int offsetY = 5;

								if(y == 0) {
									offsetY = 3;
								} else if(y == 1) {
									offsetY = 4;
								} else if(y == (objH - 1)) {
									offsetY = 6;
								}

								DrawTile(tileY + offsetX, offsetY, 1, 1, (float)((j - 0.5 + objX / 160.0) * Zm),
									H * Zm - (float)((objH - 0.5 - y + objY / 160.0) * Zm), Zm, Zm);
							}
						}
						break;
					}
					case 71: {
						// 3D半碰撞地形
						std::string TL;
						std::string TM;
						std::string TR;

						for(tileY = 0; tileY < objH; tileY++) {
							if(tileY == 0) {
								TL = "71";
								TM = "71A";
								TR = "71B";
							} else if(tileY == objH - 1) {
								TL = "71F";
								TM = "71G";
								TR = "71H";
							} else {
								TL = "71C";
								TM = "71D";
								TR = "71E";
							}

							for(j = 0; j < objW; j++) {
								std::string path = fmt::format("img/{}/obj/{}.png", level.LH.GameStyle, TM);
								if(j == 0) {
									path = fmt::format("img/{}/obj/{}.png", level.LH.GameStyle, TL);
								} else if(j == objW - 1) {
									path = fmt::format("img/{}/obj/{}.png", level.LH.GameStyle, TR);
								}

								DrawImage(path, (float)((j - 0.5 + objX / 160.0) * Zm),
									(H + tileY) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm, Zm);
							}
						}
						break;
					}
					case 17: {
						for(j = 0; j < objW; j++) {
							if(j == 0) {
								DrawTile(0, 2, 1, 2, (float)((j - 0.5 + objX / 160.0) * Zm),
									H * Zm - (float)((1.5 + objY / 160.0) * Zm), Zm, Zm * 2);
							} else if(j == objW - 1) {
								DrawTile(2, 2, 1, 2, (float)((j - 0.5 + objX / 160.0) * Zm),
									H * Zm - (float)((1.5 + objY / 160.0) * Zm), Zm, Zm * 2);
							} else {
								DrawTile(1, 2, 1, 2, (float)((j - 0.5 + objX / 160.0) * Zm),
									H * Zm - (float)((1.5 + objY / 160.0) * Zm), Zm, Zm * 2);
							}
						}
						break;
					}
					case 113:
					case 132: {
						if((objFlag / 0x4) % 2 == 1) {
							for(j = 0; j < objW; j++) {
								if(j == 0) {
									DrawImage(fmt::format("img/{}/obj/{}D.png", level.LH.GameStyle, objID),
										(float)((j - objW / 2.0 + objX / 160.0) * Zm),
										H * Zm - (float)((0.5 + objY / 160.0) * Zm), Zm, Zm);
								} else if(j == objW - 1) {
									DrawImage(fmt::format("img/{}/obj/{}E.png", level.LH.GameStyle, objID),
										(float)((j - objW / 2.0 + objX / 160.0) * Zm),
										H * Zm - (float)((0.5 + objY / 160.0) * Zm), Zm, Zm);
								} else {
									DrawImage(fmt::format("img/{}/obj/{}C.png", level.LH.GameStyle, objID),
										(float)((j - objW / 2.0 + objX / 160.0) * Zm),
										H * Zm - (float)((0.5 + objY / 160.0) * Zm), Zm, Zm);
								}
							}
						} else {
							for(j = 0; j < objW; j++) {
								if(j == 0) {
									DrawImage(fmt::format("img/{}/obj/{}A.png", level.LH.GameStyle, objID),
										(float)((j - objW / 2.0 + objX / 160.0) * Zm),
										H * Zm - (float)((0.5 + objY / 160.0) * Zm), Zm, Zm);
								} else if(j == objW - 1) {
									DrawImage(fmt::format("img/{}/obj/{}B.png", level.LH.GameStyle, objID),
										(float)((j - objW / 2.0 + objX / 160.0) * Zm),
										H * Zm - (float)((0.5 + objY / 160.0) * Zm), Zm, Zm);
								} else {
									DrawImage(fmt::format("img/{}/obj/{}.png", level.LH.GameStyle, objID),
										(float)((j - objW / 2.0 + objX / 160.0) * Zm),
										H * Zm - (float)((0.5 + objY / 160.0) * Zm), Zm, Zm);
								}
							}
						}

						break;
					}
					case 66:
					case 67:
					case 90: {
						//箭头 单向板 中间旗
						switch(objFlag) {
						case 0x6000040:
							PR = "";
							break;
						case 0x6400040:
							PR = "A";
							break;
						case 0x6800040:
							PR = "B";
							break;
						case 0x6C00040:
							PR = "C";
							break;
						case 0x7000040:
							PR = "D";
							break;
						case 0x7400040:
							PR = "E";
							break;
						case 0x7800040:
							PR = "F";
							break;
						case 0x7C00040:
							PR = "G";
							break;
						}
						LX = std::round((float)((-0.5 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH / 2.0 + objY / 160.0) * Zm));

						DrawImage(fmt::format("img/{}/obj/{}{}.png", level.LH.GameStyle, objID, PR),
							(float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm * objW, Zm * objH);
						break;
					}
					case 83: //狼牙棒
					{
						switch(objFlag) {
						case 0x6000040:
							PR = "";
							break;
						case 0x6400040:
							PR = "A";
							break;
						case 0x6800040:
							PR = "B";
							break;
						case 0x6C00040:
							PR = "C";
							break;
						case 0x7000040:
							PR = "D";
							break;
						case 0x7400040:
							PR = "E";
							break;
						case 0x7800040:
							PR = "F";
							break;
						case 0x7C00040:
							PR = "G";
							break;
						}
						LX = std::round((float)((-0.5 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH / 2.0 + objY / 160.0) * Zm));

						DrawImage(fmt::format("img/{}/obj/83{}.png", level.LH.GameStyle, PR),
							(float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm * objW, Zm * objH);
						break;
					}
					case 64: {
						for(j = 1; j <= objH; j++) {
							if(j == 1) {
								DrawTile(13, 7, 1, 1, (float)(-objW / 2.0 + objX / 160.0) * Zm,
									H * Zm - (float)((j + std::round(objY) / 160.0) * Zm), Zm, Zm);
							} else if(j == objH) {
								DrawTile(15, 7, 1, 1, (float)(-objW / 2.0 + objX / 160.0) * Zm,
									H * Zm - (float)((j + std::round(objY) / 160.0) * Zm), Zm, Zm);
							} else {
								DrawTile(14, 7, 1, 1, (float)(-objW / 2.0 + objX / 160.0) * Zm,
									H * Zm - (float)((j + std::round(objY) / 160.0) * Zm), Zm, Zm);
							}
						}
						break;
					}
					case 4:
					case 5:
					case 6:
					case 21:
					case 22:
					case 23:
					case 29:
					case 63:
					case 79:
					case 99:
					case 100:
					case 43:
					case 8: {
						// 4,4A 5 6 8 8A 21 22 23 23A 29 43 49 63 79 79A 92 99 100 100A
						//砖 问号 硬砖 地面 竹轮 云砖 刺 金币
						//音符  隐藏
						//冰砖  P砖 开关 开关砖

						if((objFlag / 0x4) % 2 == 1) {
							PP = 1;
						} else {
							PP = 0;
						}
						LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
						LY = std::round(
							(H + (std::round(objH) / 2) / 2.0) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawTile(level.TileLoc[objID][PP].X, level.TileLoc[objID][PP].Y, 1, 1,
							(float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);
						break;
					}
					case 108: {
						//闪烁砖
						if((objFlag / 0x4) % 2 == 1) {
							PR = "A";
						} else {
							PR = "";
						}
						LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
						LY = std::round(
							(H + (std::round(objH) / 2) / 2.0) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(fmt::format("img/{}/obj/108{}.png", level.LH.GameStyle, PR),
							(float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);

						break;
					}
					case 106: //树
					{
						LX = std::round((float)((-0.5 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH + 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(fmt::format("img/{}/obj/106.png", level.LH.GameStyle),
							(float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * 4, Zm * 4);

						for(j = 4; j < objH; j++) {
							DrawImage(fmt::format("img/{}/obj/106A.png", level.LH.GameStyle),
								(float)((-objW / 2.0 + 1.5 + objX / 160.0) * Zm),
								(H + j) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm, Zm);
						}
						DrawImage(fmt::format("img/{}/obj/106B.png", level.LH.GameStyle),
							(float)((-objW / 2.0 + 1 + objX / 160.0) * Zm),
							H * Zm - (float)((-0.5 + objY / 160.0) * Zm) + KY, Zm * 2, Zm);
						break;
					}
					case 85:
					case 119: {
						//机动砖 轨道砖
						if((objFlag / 0x4) % 2 == 1) {
							PR = "A";
						} else {
							PR = "";
						}
						LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
						LY = std::round(
							(H + (std::round(objH) / 2) / 2.0) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(fmt::format("img/{}/obj/{}{}.png", level.LH.GameStyle, objID, PR),
							(float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);

						DrawMoveBlock(objID, level.MapObj[i].Ex, objX, objY);
						break;
					}
					case 94: {
						//斜传送带
						Point C1;
						Point C2;
						if((objFlag / 0x400000) % 2 == 0) {
							C1 = Point(8, 0);
							C2 = Point(4, 16);
						} else {
							C1 = Point(13, 24);
							C2 = Point(10, 22);
						}
						if((objFlag / 0x200000) % 0x2 == 0) {
							//左斜
							LX = std::round((float)((-1 + objW / 2.0 + objX / 160.0) * Zm));
							LY = std::round((H - 0.5 - objH / 2) * Zm - (float)((-0.5 + objY / 160.0) * Zm));

							DrawTile(C1.X, C1.Y, 1, 1, (float)((-0.5 + objX / 160.0) * Zm),
								(H - 1) * Zm - (float)((-0.5 + objY / 160.0) * Zm), Zm, Zm);

							DrawTile(C1.X + 2, C1.Y, 1, 1, (float)((objW - 1.5 + objX / 160.0) * Zm),
								(H - 1) * Zm - (float)((objH - 1.5 + objY / 160.0) * Zm), Zm, Zm);

							for(j = 1; j <= objW - 2; j++) {
								DrawTile(C2.X + 1, C2.Y, 1, 2, (float)((j - 0.5 + objX / 160.0) * Zm),
									(H - 1) * Zm - (float)((j - 0.5 + objY / 160.0) * Zm), Zm, Zm * 2);
							}

						} else {
							//右斜
							LX = std::round((float)((-1 + objW / 2.0 + objX / 160.0) * Zm));
							LY = std::round((H - 0.5 - objH / 2) * Zm - (float)((-0.5 + objY / 160.0) * Zm));

							DrawTile(C1.X, C1.Y, 1, 1, (float)((-0.5 + objX / 160.0) * Zm),
								(H - 1) * Zm - (float)((objH - 1.5 + objY / 160.0) * Zm), Zm, Zm);

							DrawTile(C1.X + 2, C1.Y, 1, 1, (float)((objW - 1.5 + objX / 160.0) * Zm),
								(H - 1) * Zm - (float)((-0.5 + objY / 160.0) * Zm), Zm, Zm);

							for(j = 1; j <= objW - 2; j++) {
								DrawTile(C2.X + 4, C2.Y, 1, 2, (float)((j - 0.5 + objX / 160.0) * Zm),
									(H - 1) * Zm - (float)((-0.5 - j + objH + objY / 160.0) * Zm), Zm, Zm * 2);
							}
						}

						if((objFlag / 0x40000) % 2 == 0) {
							if((objFlag / 0x8) % 2 == 1) {
								DrawImage("img/cmn/A1.png", LX, LY, Zm, Zm);
							} else {
								DrawImage("img/cmn/A0.png", LX, LY, Zm, Zm);
							}
						} else {
							if((objFlag / 0x8) % 2 == 1) {
								DrawImage("img/cmn/A3.png", LX, LY, Zm, Zm);
							} else {
								DrawImage("img/cmn/A2.png", LX, LY, Zm, Zm);
							}
						}
						break;
					}
					case 53: {
						//传送带
						LX = std::round((float)((-0.5 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((0.5 + objY / 160.0) * Zm));
						Point C1;
						if((objFlag / 0x400000) % 2 == 0) {
							C1 = Point(8, 0);
						} else {
							C1 = Point(13, 24);
						}

						for(j = 0; j < objW; j++) {
							if(j == 0) {
								DrawTile(C1.X, C1.Y, 1, 1, (float)((j - 0.5 + objX / 160.0) * Zm),
									H * Zm - (float)((0.5 + objY / 160.0) * Zm), Zm, Zm);
							} else if(j == objW - 1) {
								DrawTile(C1.X + 2, C1.Y, 1, 1, (float)((j - 0.5 + objX / 160.0) * Zm),
									H * Zm - (float)((0.5 + objY / 160.0) * Zm), Zm, Zm);
							} else {
								DrawTile(C1.X + 1, C1.Y, 1, 1, (float)((j - 0.5 + objX / 160.0) * Zm),
									H * Zm - (float)((0.5 + objY / 160.0) * Zm), Zm, Zm);
							}

							if((objFlag) / 0x40000 % 2 == 0) {
								if((objFlag / 0x8) % 2 == 1) {
									DrawImage("img/cmn/A1.png", LX + std::round((-0.5 + objW / 2) * Zm), LY, Zm, Zm);
								} else {
									DrawImage("img/cmn/A0.png", LX + std::round((-0.5 + objW / 2) * Zm), LY, Zm, Zm);
								}
							} else {
								if((objFlag / 0x8) % 2 == 1) {
									DrawImage("img/cmn/A3.png", LX + std::round((-0.5 + objW / 2) * Zm), LY, Zm, Zm);
								} else {
									DrawImage("img/cmn/A2.png", LX + std::round((-0.5 + objW / 2) * Zm), LY, Zm, Zm);
								}
							}
						}
						break;
					}
					case 9: {
						level.ObjLinkType[objLid + 1] = 9;
						PP                            = ((objFlag / 0x10000) % 0x10) / 4;
						switch((objFlag) % 0x80) {
						case 0x0: { // R
							LX = std::round((float)((objH - 1 - 1 - 0.5 + objX / 160.0) * Zm));
							LY = std::round(H * Zm - (float)((objY / 160.0) * Zm));

							for(j = 0; j <= objH - 2; j++) {
								DrawTile(level.PipeLoc[PP][4].X, level.PipeLoc[PP][4].Y, 1, 2,
									(float)((j - 0.5 + objX / 160.0) * Zm), H * Zm - (float)((0.5 + objY / 160.0) * Zm),
									Zm, 2 * Zm);
							}
							DrawTile(level.PipeLoc[PP][3].X, level.PipeLoc[PP][3].Y, 1, 2,
								(float)((j - 0.5 + objX / 160.0) * Zm), H * Zm - (float)((0.5 + objY / 160.0) * Zm), Zm,
								2 * Zm);
						} break;
						case 0x20: { // L
							LX = std::round((float)((-objH + 1 + 1 - 0.5 + objX / 160.0) * Zm));
							LY = std::round(H * Zm - (float)((1 + objY / 160.0) * Zm));

							for(j = 0; j <= objH - 2; j++) {
								DrawTile(level.PipeLoc[PP][4].X, level.PipeLoc[PP][4].Y, 1, 2,
									(float)((-j - 0.5 + objX / 160.0) * Zm),
									H * Zm - (float)((1.5 + objY / 160.0) * Zm), Zm, 2 * Zm);
							}
							DrawTile(level.PipeLoc[PP][2].X, level.PipeLoc[PP][2].Y, 1, 2,
								(float)((-j - 0.5 + objX / 160.0) * Zm), H * Zm - (float)((1.5 + objY / 160.0) * Zm),
								Zm, 2 * Zm);
						} break;
						case 0x40: { // U
							LX = std::round((float)((+objX / 160.0) * Zm));
							LY = (H - objH + 1 + 1) * Zm - (float)((0.5 + objY / 160.0) * Zm);

							for(j = 0; j <= objH - 2; j++) {
								DrawTile(level.PipeLoc[PP][5].X, level.PipeLoc[PP][5].Y, 2, 1,
									(float)((-0.5 + objX / 160.0) * Zm),
									(H - j) * Zm - (float)((0.5 + objY / 160.0) * Zm), 2 * Zm, Zm);
							}
							DrawTile(level.PipeLoc[PP][0].X, level.PipeLoc[PP][0].Y, 2, 1,
								(float)((-0.5 + objX / 160.0) * Zm), (H - j) * Zm - (float)((0.5 + objY / 160.0) * Zm),
								2 * Zm, Zm);
						} break;
						case 0x60: { // D
							LX = std::round((float)((-1 + objX / 160.0) * Zm));
							LY = (H + objH - 1 - 1) * Zm - (float)((0.5 + objY / 160.0) * Zm);

							for(j = 0; j <= objH - 2; j++) {
								DrawTile(level.PipeLoc[PP][5].X, level.PipeLoc[PP][5].Y, 2, 1,
									(float)((-1.5 + objX / 160.0) * Zm),
									(H + j) * Zm - (float)((0.5 + objY / 160.0) * Zm), 2 * Zm, Zm);
							}
							DrawTile(level.PipeLoc[PP][1].X, level.PipeLoc[PP][1].Y, 2, 1,
								(float)((-1.5 + objX / 160.0) * Zm), (H + j) * Zm - (float)((0.5 + objY / 160.0) * Zm),
								2 * Zm, Zm);
						} break;
						}
						PR = std::to_string(objFlag % 0x1000000 / 0x100000 - 1);
						if(PR != "-1") {
							DrawImage(fmt::format("img/cmn/C{}.png", PR), LX, LY, Zm, Zm);
						}

						break;
					}
					case 55: {
						//门
						if((objFlag / 0x40000) % 2 == 1) {
							PR = "A";
						} else if((objFlag / 0x80000) % 2 == 1) {
							PR = "B";
						} else {
							PR = "";
						}
						DrawImage(fmt::format("img/{}/obj/55{}.png", level.LH.GameStyle, PR),
							(float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm * objW, Zm * objH);

						PR = std::to_string(objFlag % 0x800000 / 0x200000);
						DrawImage(fmt::format("img/cmn/C{}.png", PR), (float)((-objW / 2.0 + objX / 160.0) * Zm),
							(H + 1) * Zm - (float)((objH + objY / 160.0) * Zm), Zm, Zm);
						break;
					}
					case 97: {
						//传送箱
						if((objFlag / 0x4) % 2 == 1) {
							PR = "A";
						} else {
							PR = "";
						}
						DrawImage(fmt::format("img/{}/obj/97{}.png", level.LH.GameStyle, PR),
							(float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm * objW, Zm * objH);

						PR = std::to_string(objFlag % 0x800000 / 0x200000);
						DrawImage(fmt::format("img/cmn/C{}.png", PR), (float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm, Zm);
						break;
					}
					case 84: {
						for(j = 0; j < objW; j++) {
							if((objFlag / 0x4) % 2 == 1) {
								DrawImage(fmt::format("img/{}/obj/84A.png", level.LH.GameStyle),
									(float)((j - objW / 2.0 + objX / 160.0) * Zm),
									H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm, Zm);
							} else {
								DrawImage(fmt::format("img/{}/obj/84.png", level.LH.GameStyle),
									(float)((j - objW / 2.0 + objX / 160.0) * Zm),
									H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm, Zm);
							}
						}
						//&H10方向
						DrawSnake(level.MapObj[i].Ex, objX, objY, objW, objH);

						break;
					}
					case 68:
					case 82: {
						//齿轮 甜甜圈

						LX = std::round((float)((-0.5 + objX / 160.0) * Zm));
						LY = std::round((H - 1.5) * Zm - (float)((objY / 160.0) * Zm) + KY);

						DrawImageOpacity(fmt::format("img/{}/obj/{}.png", level.LH.GameStyle, objID), 0.7,
							(float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);

						break;
					}
					case 0:
					case 10:
					case 15:
					case 19:
					case 20:
					case 35:
					case 48:
					case 56:
					case 57:
					case 60:
					case 76:
					case 92:
					case 95:
					case 102:
					case 72:
					case 50:
					case 51:
					case 65:
					case 80:
					case 114:
					// case 119:
					case 77:
					case 104:
					case 120:
					case 121:
					case 122:
					case 123:
					case 124:
					case 125:
					case 126:
					case 112:
					case 127:
					case 128:
					case 129:
					case 130:
					case 131:
					case 96:
					case 117:
					case 86: {
						//板栗  金币 弹簧 炸弹 P POW 蘑菇
						// 无敌星 鱿鱼 鱼
						//黑花 火球  风  红币 钥匙  地鼠 慢慢龟汽车 跳跳怪 跳跳鼠 蜜蜂 冲刺砖块 尖刺鱼 !方块
						//奔奔  太阳 库巴七人 木箱 纸糊道具
						//蚂蚁 斗斗 乌卡
						if((objFlag / 0x4) % 2 == 1) {
							PR = "A";
						} else {
							PR = "";
						}
						LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
						LY = std::round(
							(H + (std::round(objH) / 2) / 2.0) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(fmt::format("img/{}/obj/{}{}.png", level.LH.GameStyle, objID, PR),
							(float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);
						break;
					}
					case 33: {
						// 1UP
						if(level.MapHdr.Theme == 0 && level.MapHdr.Flag == 2) {
							PR = "A";
						} else {
							PR = "";
						}
						LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
						LY = std::round(
							(H + (std::round(objH) / 2) / 2.0) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(fmt::format("img/{}/obj/33{}.png", level.LH.GameStyle, PR),
							(float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);

						break;
					}
					case 74: {
						//加邦
						if((objFlag / 0x4) % 2 == 1) {
							if(level.MapHdr.Theme == 6) {
								PR = "B";
							} else {
								PR = "A";
							}
						} else {
							PR = "";
						}
						LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
						LY = std::round(
							(H + (std::round(objH) / 2) / 2.0) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(fmt::format("img/{}/obj/74{}.png", level.LH.GameStyle, PR),
							(float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);

						break;
					}
					case 42: {
						//飞机
						if((objFlag / 0x4 % 2 == 1) || (objFlag / 0x40000 % 2 == 1)) {
							PR = "A";
						} else {
							PR = "";
						}
						LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
						LY = (H + objH - 2) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY;

						DrawImage(fmt::format("img/{}/obj/42{}.png", level.LH.GameStyle, PR),
							(float)((-objW / 2.0 + objX / 160.0) * Zm),
							(H + objH - 2) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * 2, Zm * 2);

						break;
					}
					case 34: {
						//火花
						if((objFlag / 0x4) % 2 == 1) {
							if((objFlag / 0x40000) % 2 == 1) {
								PR = "C";
							} else {
								PR = "A";
							}
						} else {
							if((objFlag / 0x40000) % 2 == 1) {
								PR = "B";
							} else {
								PR = "";
							}
						}

						LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
						LY = std::round(
							(H + (std::round(objH) / 2) / 2.0) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(fmt::format("img/{}/obj/34{}.png", level.LH.GameStyle, PR),
							(float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);

						break;
					}
					case 81:
					case 116: {
						// USA  锤子

						if((objFlag / 0x40000) % 2 == 1) {
							PR = "A";
						} else {
							PR = "";
						}

						LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
						LY = std::round(
							(H + (std::round(objH) / 2) / 2.0) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(fmt::format("img/{}/obj/{}{}.png", level.LH.GameStyle, objID, PR),
							(float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);

						break;
					}
					case 44: {
						//大蘑菇

						if((objFlag / 0x40000) % 2 == 1) {
							PR = "A";
						} else {
							PR = "";
						}

						LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
						LY = std::round(
							(H + (std::round(objH) / 2) / 2.0) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(fmt::format("img/{}/obj/44{}.png", level.LH.GameStyle, PR),
							(float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);

						break;
					}
					case 12: {
						//咚咚
						LX = std::round((float)((-0.5 + objX / 160.0) * Zm));
						LY = (H + objH / 2.0 - 0.5) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY;

						DrawImageOpacity(fmt::format("img/{}/obj/12.png", level.LH.GameStyle), 0.7,
							(float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);

						if(objLid == -1) {
							switch((objFlag) % 0x100) {
							case 0x40:
							case 0x42:
							case 0x44:
								DrawImage("img/cmn/E1.png", LX, LY, Zm, Zm);
								break;
							case 0x48:
							case 0x4A:
							case 0x4C:
								DrawImage("img/cmn/E2.png", LX, LY, Zm, Zm);
								break;
							case 0x50:
							case 0x52:
							case 0x54:
								DrawImage("img/cmn/E0.png", LX, LY, Zm, Zm);
								break;
							case 0x58:
							case 0x5A:
							case 0x5C:
								DrawImage("img/cmn/E3.png", LX, LY, Zm, Zm);
								break;
							}
						}

						break;
					}
					case 41: {
						//幽灵
						LX = std::round((float)((-objW / 2.0 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);
						switch(level.LH.GameStyle) {
						case 22323:
							if((objFlag / 0x4) % 2 == 1) {
								DrawImage(fmt::format("img/{}/obj/41D.png", level.LH.GameStyle), LX, LY, Zm * objW,
									Zm * objH);
							} else {
								DrawImage(
									fmt::format("img/{}/obj/41.png", level.LH.GameStyle), LX, LY, Zm * objW, Zm * objH);
							}
							break;
						default:
							if((objFlag / 0x4) % 2 == 1) {
								DrawImage(fmt::format("img/{}/obj/41A.png", level.LH.GameStyle), LX, LY, Zm * objW,
									Zm * objH);
							} else if((objFlag / 0x1000000) % 0x8 == 0x4) {
								DrawImage(fmt::format("img/{}/obj/41C.png", level.LH.GameStyle), LX, LY, Zm * objW,
									Zm * objH);
							} else if((objFlag / 0x100) % 2 == 1) {
								DrawImage(fmt::format("img/{}/obj/41B.png", level.LH.GameStyle), LX, LY, Zm * objW,
									Zm * objH);
							} else {
								DrawImage(
									fmt::format("img/{}/obj/41.png", level.LH.GameStyle), LX, LY, Zm * objW, Zm * objH);
							}
							break;
						}

						break;
					}
					case 28:
					case 25:
					case 18: {
						//钢盔 刺龟 P
						LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
						LY = std::round(
							(H + (std::round(objH) / 2) / 2.0) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);
						if((objFlag / 0x4) % 2 == 1) {
							DrawImage(fmt::format("img/{}/obj/{}A.png", level.LH.GameStyle, objID),
								(float)((-objW / 2.0 + objX / 160.0) * Zm),
								H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);

						} else if((objFlag / 0x1000000) % 8 == 0x6) {
							DrawImage(fmt::format("img/{}/obj/{}.png", level.LH.GameStyle, objID),
								(float)((-objW / 2.0 + objX / 160.0) * Zm),
								H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);
						} else {
							DrawImage(fmt::format("img/{}/obj/{}B.png", level.LH.GameStyle, objID),
								(float)((-objW / 2.0 + objX / 160.0) * Zm),
								H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);
						}
						break;
					}
					case 40: {
						//小刺龟
						LX = std::round((float)((-objW / 2.0 + objX / 160.0) * Zm));
						LY = (H + objW) * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY;
						if((objFlag / 0x4) % 2 == 1) {
							switch((objFlag / 0x1000000) % 8) {
								//方向6上 4下 0左 2右
							case 0x0: // L
								DrawImage(fmt::format("img/{}/obj/40B0.png", level.LH.GameStyle), LX, LY, Zm * objW,
									Zm * objH);
								break;
							case 0x2: // R
								DrawImage(fmt::format("img/{}/obj/40B2.png", level.LH.GameStyle), LX, LY, Zm * objW,
									Zm * objH);
								break;
							case 0x4: // D
								DrawImage(fmt::format("img/{}/obj/40B4.png", level.LH.GameStyle), LX, LY, Zm * objW,
									Zm * objH);
								break;
							case 0x6: // U
								DrawImage(fmt::format("img/{}/obj/40B6.png", level.LH.GameStyle), LX, LY, Zm * objW,
									Zm * objH);
								break;
							}
						} else {
							switch((objFlag / 0x1000000) % 8) {
								//方向6上 4下 0左 2右
							case 0x0: // L
								DrawImage(fmt::format("img/{}/obj/40A0.png", level.LH.GameStyle), LX, LY, Zm * objW,
									Zm * objH);
								break;
							case 0x2: // R
								DrawImage(fmt::format("img/{}/obj/40A2.png", level.LH.GameStyle), LX, LY, Zm * objW,
									Zm * objH);
								break;
							case 0x4: // D
								DrawImage(fmt::format("img/{}/obj/40A0.png", level.LH.GameStyle), LX, LY, Zm * objW,
									Zm * objH);
								break;
							case 0x6: // U
								DrawImage(fmt::format("img/{}/obj/40A6.png", level.LH.GameStyle), LX, LY, Zm * objW,
									Zm * objH);
								break;
							}
						}
						LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
						LY = std::round(
							(H + (std::round(objH) / 2) / 2.0) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);
						break;
					}
					case 2: {
						//绿花
						if((objFlag / 0x4) % 2 == 1) {
							PR = "2B";
						} else {
							PR = "2A";
						}
						switch((objFlag / 0x1000000) % 0x8) {
							//方向6上 4下 0左 2右
						case 0x0: // L
							LX = std::round((float)((objH / 2.0 - 1 + objX / 160.0) * Zm));
							LY = (H + objW + (std::round(objW) / 2) / 2.0) * Zm
								 - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY;

							DrawImage(fmt::format("img/{}/obj/{}0.png", level.LH.GameStyle, PR),
								(float)((-objW * 3 / 2.0 + objX / 160.0) * Zm),
								(H + objW) * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW * 2,
								Zm * objH);
							break;
						case 0x2: // R
							LX = std::round((float)((-objW / 2.0 + objX / 160.0) * Zm));
							LY = (H + objW + (std::round(objW) / 2) / 2.0) * Zm
								 - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY;

							DrawImage(fmt::format("img/{}/obj/{}2.png", level.LH.GameStyle, PR),
								(float)((-objW / 2.0 + objX / 160.0) * Zm),
								(H + objW) * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW * 2,
								Zm * objH);
							break;
						case 0x4: // D
							LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
							LY = (H + objW) * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY;

							DrawImage(fmt::format("img/{}/obj/{}4.png", level.LH.GameStyle, PR),
								(float)((-objW / 2.0 + objX / 160.0) * Zm),
								(H + objW) * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW,
								Zm * objH * 2);
							break;
						case 0x6: // U
							LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
							LY = (H + objH + (std::round(objW) / 2)) * Zm
								 - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY;

							DrawImage(fmt::format("img/{}/obj/{}6.png", level.LH.GameStyle, PR),
								(float)((-objW / 2.0 + objX / 160.0) * Zm),
								H * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW,
								Zm * objH * 2);
							break;
						}
						break;
					}
					case 107: {
						//长长吞食花
						if((objFlag / 0x4) % 2 == 1) {
							PR = "E";
						} else {
							PR = "";
						}
						switch(objFlag / 0x1000000) {
						case 0x0:
							PR += "C";
							break;
						case 0x2:
							PR += "A";
							break;
						case 0x4:
							PR += "B";
							break;
						case 0x6:
							PR += "";
							break;
						}
						LX = std::round((float)((-objW / 2.0 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(fmt::format("img/{}/obj/107{}.png", level.LH.GameStyle, PR), LX, LY, Zm * 2, Zm * 2);

						DrawCrp(level.MapObj[i].Ex, objX, objY);
						break;
					}
					case 32: {
						//大炮弹

						switch(objFlag) {
						case 0x6000040:
							PR = "";
							break;
						case 0x6400040:
							PR = "A";
							break;
						case 0x6800040:
							PR = "B";
							break;
						case 0x6C00040:
							PR = "C";
							break;
						case 0x6000044:
							PR = "D";
							break;
						case 0x6400044:
							PR = "E";
							break;
						case 0x6800044:
							PR = "F";
							break;
						case 0x6C00044:
							PR = "G";
							break;
						case 0x7000040:
							PR = "H";
							break;
						}
						LX = std::round((float)((-objW / 2.0 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(
							fmt::format("img/{}/obj/32{}.png", level.LH.GameStyle, PR), LX, LY, Zm * objW, Zm * objH);

						break;
					}
					case 1:
					case 46:
					case 52:
					case 58: {
						//慢慢龟，碎碎龟，花花，扳手
						if((objFlag / 0x4) % 2 == 1) {
							PR = "A";
						} else {
							PR = "";
						}
						LX = std::round((float)((-objW / 2.0 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(fmt::format("img/{}/obj/{}{}.png", level.LH.GameStyle, objID, PR), LX, LY, Zm * objW,
							Zm * objH * 2);

						LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
						LY = std::round(
							(H + (std::round(objH) / 2) / 2.0) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);
						break;
					}
					case 30: {
						//裁判
						LX = std::round((float)((-objW / 2.0 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH - 1 + objY / 160.0) * Zm) + KY);

						DrawImage(fmt::format("img/{}/obj/30.png", level.LH.GameStyle), LX, LY, Zm, Zm * 2);
						DrawImage(
							fmt::format("img/{}/obj/31.png", level.LH.GameStyle), LX - Zm / 2, LY + Zm / 2, Zm * 2, Zm);
						break;
					}
					case 31: {
						//裁判云
						level.ObjLinkType[objLid + 1] = 31;
						LX                            = std::round((float)((-objW / 2.0 - 0.5 + objX / 160.0) * Zm));
						LY                            = std::round(H * Zm - (float)((0.5 + objY / 160.0) * Zm));

						DrawImage(fmt::format("img/{}/obj/31.png", level.LH.GameStyle), LX, LY, Zm * 2, Zm);

						break;
					}
					case 45: //鞋 耀西
					{
						switch(level.LH.GameStyle) {
						case 21847:
						case 22349: // U W
							if(objW == 2) {
								PR = "A";
							} else {
								PR = "";
							}
							break;
						default:
							if((objFlag / 0x4) % 2 == 1) {
								PR = "A";
							} else {
								PR = "";
							}
							break;
						}

						LX = std::round((float)((-objW / 2.0 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(fmt::format("img/{}/obj/45{}.png", level.LH.GameStyle, PR), LX, LY, Zm * objW,
							Zm * objH * 2);

						LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
						LY = std::round(
							(H + (std::round(objH) / 2) / 2.0) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						break;
					}
					case 62: {
						//库巴
						LX = std::round((float)((-objW / 2.0 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);
						switch(level.LH.GameStyle) {
						case 22323:
							DrawImage(fmt::format("img/{}/obj/{}A.png", level.LH.GameStyle, objID),
								(float)((-objW / 2.0 + objX / 160.0) * Zm),
								H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);
							break;
						default:
							DrawImage(fmt::format("img/{}/obj/62.png", level.LH.GameStyle),
								(float)((-objW / 2.0 + objX / 160.0) * Zm),
								H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);
							break;
						}

						break;
					}
					case 3: {
						//德莱文
						switch(level.LH.GameStyle) {
						case 22323:
							if((objFlag / 0x4) % 2 == 1) {
								LX = std::round((float)((-objW / 2.0 + 0.5 + objX / 160.0) * Zm));
								LY = std::round(H * Zm - (float)((1 + objY / 160.0) * Zm) + KY);

								DrawImage(fmt::format("img/{}/obj/3B.png", level.LH.GameStyle),
									(float)((-objW / 2.0 + objX / 160.0) * Zm),
									(H)*Zm - (float)((1.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);
							} else {
								LX = std::round((float)((-objW / 2.0 + objX / 160.0) * Zm));
								LY = std::round(H * Zm - (float)((objH * 2.0 - 1.5 + objY / 160.0) * Zm) + KY);

								DrawImage(fmt::format("img/{}/obj/3.png", level.LH.GameStyle),
									(float)((-objW / 2.0 + objX / 160.0) * Zm),
									(H + 2) * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW,
									Zm * objH);
							}
							break;
						default:
							if((objFlag / 0x4000) % 2 == 1) {
								LX = std::round((float)((-objW / 2.0 + 0.5 + objX / 160.0) * Zm));
								LY = std::round(H * Zm - (float)((1 + objY / 160.0) * Zm) + KY);

								DrawImage(fmt::format("img/{}/obj/3A.png", level.LH.GameStyle),
									(float)((-objW / 2.0 + objX / 160.0) * Zm),
									H * Zm - (float)((1.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);
							} else {
								LX = std::round((float)((-objW / 2.0 + objX / 160.0) * Zm));
								LY = std::round(H * Zm - (float)((objH * 2.0 - 1.5 + objY / 160.0) * Zm) + KY);

								DrawImage(fmt::format("img/{}/obj/3.png", level.LH.GameStyle),
									(float)((-objW / 2.0 + objX / 160.0) * Zm),
									H * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW,
									2 * Zm * objH);
							}
							break;
						}

						break;
					}
					case 13: {
						//炮台
						if((objFlag / 0x4) % 2 == 1) {
							PR = "B";
						} else {
							PR = "";
						}
						LX = std::round((float)((-0.5 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImageOpacity(
							fmt::format("img/{}/obj/13{}.png", level.LH.GameStyle, PR), 0.7, LX, LY, Zm * objW, Zm * 2);

						for(j = 2; j < objH; j++) {
							if((objFlag / 0x4) % 2 == 1) {
								DrawImageOpacity(fmt::format("img/{}/obj/13C.png", level.LH.GameStyle), 0.7, LX,
									LY + j * Zm, Zm, Zm);
							} else {
								DrawImageOpacity(fmt::format("img/{}/obj/13A.png", level.LH.GameStyle), 0.7, LX,
									LY + j * Zm, Zm, Zm);
							}
						}

						break;
					}
					case 39: {
						//魔法师
						LX = std::round((float)((2.0 - objW / 2.0 - objW + objX / 160.0) * Zm));
						LY = std::round((H + 1) * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(fmt::format("img/{}/obj/39.png", level.LH.GameStyle), LX - Zm - Zm, LY - Zm + KY,
							2 * Zm * objW + KY, 2 * Zm * objH);
						break;
					}
					case 47: {
						//小炮
						if((objFlag / 0x4) % 2 == 1) {
							PR = "E";
						} else {
							PR = "";
						}
						float ANG     = 0;
						std::string D = "";
						switch(objFlag / 0x100000) {
						case 0x0:
						case 0x4:
						case 0x8:
						case 0xC:
						case 0x10:
							D = "D";
							break;
						case 0x2:
						case 0x24:
						case 0x28:
						case 0x2C:
						case 0x30:
							D = "B";
							break;
						case 0x40:
						case 0x44:
						case 0x48:
						case 0x4C:
						case 0x50:
							D = "C";
							break;
						case 0x60:
						case 0x64:
						case 0x68:
						case 0x6C:
						case 0x70:
							D = "A";
							break;
						default:
							D = "A";
							break;
						}

						switch(objFlag / 0x100000) {
						// UDLR
						case 0xC:
						case 0x30:
						case 0x64:
							ANG = 0;
							break;
						case 0x10:
						case 0x2C:
						case 0x44:
							ANG = 180;
							break;
						case 0x4:
						case 0x4C:
						case 0x70:
							ANG = 270;
							break;
						case 0x24:
						case 0x50:
						case 0x6C:
							ANG = 90;
							// UL UR DL DR
							break;
						case 0x8:
						case 0x60:
							ANG = 315;
							break;
						case 0x20:
						case 0x68:
							ANG = 45;
							break;
						case 0x0:
						case 0x48:
							ANG = 225;
							break;
						case 0x28:
						case 0x40:
							ANG = 135;
							break;
						default:
							ANG = 0;
							break;
						}
						LX = std::round((float)((-objW / 2.0 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm));

						DrawImageRotate(fmt::format("img/{}/obj/47{}.png", level.LH.GameStyle, PR), ANG,
							LX + std::round(objW * Zm) / 2.0 - std::round(objW * Zm) / 2,
							LY + std::round(objH * Zm) / 2.0 - std::round(objH * Zm) / 2, Zm * objW, Zm * objH);
						DrawImage(fmt::format("img/{}/obj/47{}{}.png", level.LH.GameStyle, PR, D),
							(float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm * objW, Zm * objH);
						break;
					}
					case 61: {
						//汪汪
						LX = std::round((float)((-0.5 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((0.5 + objY / 160.0) * Zm) + KY);
						if((objFlag / 0x4) % 2 == 0) {
							DrawImage(fmt::format("img/{}/obj/61A.png", level.LH.GameStyle),
								(float)((-0.5 + objX / 160.0) * Zm), H * Zm - (float)((0.5 + objY / 160.0) * Zm) + KY,
								Zm, Zm);
						}
						DrawImage(fmt::format("img/{}/obj/61.png", level.LH.GameStyle),
							(float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);
						break;
					}
					case 78: {
						//仙人掌
						LX = std::round((float)(-objW / 2.0 + objX / 160.0) * Zm);
						LY = std::round((H + 1) * Zm - (float)((objH + std::round(objY) / 160.0) * Zm) + KY);

						for(j = 0; j < objH; j++) {
							if(j == objH - 1) {
								DrawImage(fmt::format("img/{}/obj/78.png", level.LH.GameStyle),
									(float)(-objW / 2.0 + objX / 160.0) * Zm,
									(H - 1) * Zm - (float)((j + std::round(objY) / 160.0) * Zm) + KY, Zm, Zm);
							} else {
								DrawImage(fmt::format("img/{}/obj/78A.png", level.LH.GameStyle),
									(float)(-objW / 2.0 + objX / 160.0) * Zm,
									(H - 1) * Zm - (float)((j + std::round(objY) / 160.0) * Zm) + KY, Zm, Zm);
							}
						}
						break;
					}
					case 111: {
						//机械库巴
						if((objFlag / 0x40000) % 2 == 1) {
							PR = "B";
						} else if((objFlag / 0x80000) % 2 == 1) {
							PR = "A";
						} else {
							PR = "";
						}
						LX = std::round((float)((-objW + 0.5 + objX / 160.0) * Zm));
						LY = std::round((H + 1) * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(fmt::format("img/{}/obj/111{}.png", level.LH.GameStyle, PR),
							(float)((-objW + objX / 160.0) * Zm),
							H * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY, 2 * Zm * objW,
							2 * Zm * objH);
						break;
					}
					case 70: {
						//大金币
						if((objFlag / 0x40000) % 2 == 1) {
							PR = "A";
						} else if((objFlag / 0x80000) % 2 == 1) {
							PR = "B";
						} else {
							PR = "";
						}

						DrawImage(fmt::format("img/{}/obj/70{}.png", level.LH.GameStyle, PR),
							(float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);

						LX = std::round((float)((-objW / 2.0 + 0.5 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH - 1 + objY / 160.0) * Zm) + KY);
						break;
					}
					case 110: {
						//刺方块
						if((objFlag / 0x40000) % 2 == 1) {
							PR = "A";
						} else if((objFlag / 0x80000) % 2 == 1) {
							PR = "B";
						} else {
							PR = "";
						}

						DrawImage(fmt::format("img/{}/obj/110{}.png", level.LH.GameStyle, PR),
							(float)((-objW / 2.0 + 0.5 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);
						break;
					}
					case 98: {
						//小库巴
						if((objFlag / 0x4) % 2 == 1) {
							PR = "A";
						} else {
							PR = "";
						}
						LX = std::round((float)((-objW + 0.5 + objX / 160.0) * Zm));
						LY = std::round((H + 1) * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(fmt::format("img/{}/obj/98{}.png", level.LH.GameStyle, PR),
							(float)((-objW + objX / 160.0) * Zm),
							H * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY, 2 * Zm * objW,
							2 * Zm * objH);
						break;
					}
					case 103: {
						//骨鱼
						LX = std::round((float)((-objW + 0.5 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(fmt::format("img/{}/obj/103.png", level.LH.GameStyle),
							(float)((-objW + objX / 160.0) * Zm) + KY, LY, 2 * Zm * objW, Zm * objH);

						break;
					}
					case 91: {
						for(j = 0; j < objW; j++) {
							if(j == 0) {
								DrawImage(fmt::format("img/{}/obj/91A.png", level.LH.GameStyle),
									(float)((j - std::round(objW) / 2 + std::round(objX) / 160.0) * Zm),
									H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm, Zm);
							} else if(j == objW - 1) {
								DrawImage(fmt::format("img/{}/obj/91B.png", level.LH.GameStyle),
									(float)((j - std::round(objW) / 2 + std::round(objX) / 160.0) * Zm),
									H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm, Zm);
							} else {
								DrawImage(fmt::format("img/{}/obj/91.png", level.LH.GameStyle),
									(float)((j - std::round(objW) / 2 + std::round(objX) / 160.0) * Zm),
									H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm, Zm);
							}
						}

						DrawImage(fmt::format("img/{}/obj/91C.png", level.LH.GameStyle),
							(float)((-0.5 + objX / 160.0) * Zm), H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm,
							Zm);

						LX = std::round((float)((-0.5 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm));
						break;
					}
					case 36: {
						//熔岩台
						if((objFlag / 0x4) % 2 == 1) {
							PR = "A";
						} else {
							PR = "";
						}
						if(objLid != -1) {
							objW = 1;
						}

						for(j = 0; j < objW; j++) {
							DrawImage(fmt::format("img/{}/obj/36{}.png", level.LH.GameStyle, PR),
								(float)((j - std::round(objW) / 2 + std::round(objX) / 160.0) * Zm),
								H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm, Zm);
						}
						LX = std::round((float)((j - 1 - std::round(objW) / 2.0 + std::round(objX) / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);
						break;
					}
					case 11: {
						//升降台
						LX = std::round((float)((-0.5 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((0.5 + objY / 160.0) * Zm) + KY);

						for(j = 0; j < objW; j++) {
							if((objFlag / 0x4) % 2 == 0) {
								if(j == 0) {
									PR = "A";
								} else if(j == objW - 1) {
									PR = "B";
								} else {
									PR = "";
								}

								DrawImage(fmt::format("img/{}/obj/11{}.png", level.LH.GameStyle, PR),
									(float)((j - objW / 2.0 + objX / 160.0) * Zm),
									H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm, Zm);
							} else {
								if(j == 0) {
									PR = "D";
								} else if(j == objW - 1) {
									PR = "E";
								} else {
									PR = "C";
								}

								DrawImage(fmt::format("img/{}/obj/11{}.png", level.LH.GameStyle, PR),
									(float)((j - objW / 2.0 + objX / 160.0) * Zm),
									H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm, Zm);
							}
						}

						//'If MapObj(i).LID >= 0 Then
						//'	'PR = ((MapObj(i).Flag Mod &H400000) \ &H100000).ToString
						//'	'G.DrawImage(Image.FromFile(P & "\img\CMN\D" & PR & ".png"), LX, LY, Zm, Zm)
						//'ELSE IF    ///END IF

						if((objFlag / 0x4) % 2 == 0) {
							switch((objFlag) % 0x100) {
							case 0x40:
								DrawImage("img/cmn/D1.png", LX, LY, Zm, Zm);
								break;
							case 0x48:
								DrawImage("img/cmn/D2.png", LX, LY, Zm, Zm);
								break;
							case 0x50:
								DrawImage("img/cmn/D0.png", LX, LY, Zm, Zm);
								break;
							case 0x58:
								DrawImage("img/cmn/D3.png", LX, LY, Zm, Zm);
								break;
							}
						}

						break;
					}
					case 54: {
						//喷枪
						LX = std::round((float)((-0.5 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((0.5 + objY / 160.0) * Zm) + KY);
						switch((objFlag) % 0x100) {
						case 0x40:
							DrawImage(fmt::format("img/{}/obj/54.png", level.LH.GameStyle),
								(float)((-objW / 2.0 + objX / 160.0) * Zm),
								H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);
							break;
						case 0x48:
							DrawImage(fmt::format("img/{}/obj/54A.png", level.LH.GameStyle),
								(float)((-objW / 2.0 + objX / 160.0) * Zm),
								H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);
							break;
						case 0x50:
							DrawImage(fmt::format("img/{}/obj/54B.png", level.LH.GameStyle),
								(float)((-objW / 2.0 + objX / 160.0) * Zm),
								H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);
							break;
						case 0x58:
							DrawImage(fmt::format("img/{}/obj/54C.png", level.LH.GameStyle),
								(float)((-objW / 2.0 + objX / 160.0) * Zm),
								H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);
							// G.DrawImage(Image.FromFile(P & "\img\" & LH.GameStyle.ToString & "\obj\54A7.png"),
							// CSng((-MapObj(i).W / 2.0 - 3 + MapObj(i).X / 160.0) * Zm), H * Zm - CSng((MapObj(i).H -
							// 0.5
							// + MapObj(i).Y / 160.0) * Zm) + KY, 3 * Zm * MapObj(i).W, Zm * MapObj(i).H)
							break;
						case 0x44:
							DrawImage(fmt::format("img/{}/obj/54.png", level.LH.GameStyle),
								(float)((-objW / 2.0 + objX / 160.0) * Zm),
								H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);
							break;
						case 0x4C:
							DrawImage(fmt::format("img/{}/obj/54A.png", level.LH.GameStyle),
								(float)((-objW / 2.0 + objX / 160.0) * Zm),
								H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);
							break;
						case 0x54:
							DrawImage(fmt::format("img/{}/obj/54B.png", level.LH.GameStyle),
								(float)((-objW / 2.0 + objX / 160.0) * Zm),
								H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);
							break;
						case 0x5C:
							DrawImage(fmt::format("img/{}/obj/54C.png", level.LH.GameStyle),
								(float)((-objW / 2.0 + objX / 160.0) * Zm),
								H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);
							break;
						}
						break;
					}
					case 24: {
						//火棍
						LX = std::round((float)(-objW / 2.0 + objX / 160.0) * Zm);
						LY = std::round(H * Zm - (float)(objH - 0.5 + objY / 160.0) * Zm);
						DrawImage(fmt::format("img/{}/obj/24.png", level.LH.GameStyle), LX, LY, Zm, Zm);

						break;
					}
					case 105: {
						//夹子
						if((objFlag) % 0x400 >= 0x100) {
							KY                            = Zm * 3;
							level.ObjLinkType[objLid + 1] = 105;
						} else {
							KY                            = 0;
							level.ObjLinkType[objLid + 1] = 105;
						}
						LX = std::round((float)(-1.5 + objX / 160.0) * Zm);
						LY = std::round(H * Zm - (float)(3.5 + objY / 160.0) * Zm + KY);

						if((objFlag / 0x80) % 2 == 1) {
							DrawImage(fmt::format("img/{}/obj/105A.png", level.LH.GameStyle), LX, LY, Zm * 3, Zm * 5);
						} else {
							DrawImage(fmt::format("img/{}/obj/105.png", level.LH.GameStyle), LX, LY, Zm * 3, Zm * 5);
						}
						break;
					}
					}

					PR = "";
					// PR += IIf((MapObj(i).Flag \ &H4000) Mod 2 = 1, "M", "")
					PR += ((objFlag / 0x8000) % 2 == 1) ? "P" : "";
					PR += ((objFlag / 2) % 2 == 1) ? "W" : "";
					if(PR == "PW") {
						PR = "B";
					}
					if(PR.length() > 0) {
						DrawImage(fmt::format("img/{}/cid/{}.png", level.LH.GameStyle, PR), LX, LY, Zm / 2, Zm / 2);
					}

					if(L && level.ObjLinkType[objLid + 1] == 59) {
						PR = std::to_string(std::round((objFlag) % 0x400000) / 0x100000);
						DrawImage(fmt::format("img/cmn/D{}.png", PR), LX, LY, Zm, Zm);
					}
				}
			}
		}
	}
}

void Drawers::ReGrdCode() {
	int i  = 0;
	int j  = 0;
	int m  = 0;
	int CX = 0;
	int CY = 0;
	for(i = 0; i < level.MapHdr.ObjCount; i++) {
		int objW    = level.MapObj[i].W;
		int objH    = level.MapObj[i].H;
		int objFlag = level.MapObj[i].Flag;
		int objX    = level.MapObj[i].X;
		int objY    = level.MapObj[i].Y;

		switch(level.MapObj[i].ID) {
		case 87:
			//缓坡
			CX = std::round((-0.5 + objX / 160.0));
			CY = std::round((-0.5 + objY / 160.0));
			if((objFlag / 0x100000) % 0x2 == 0) {
				//左斜
				switch(level.GroundNode[CX + 1][CY + 1]) {
				case 0:
					level.GroundNode[CX + 1][CY + 1] = 23;
					break;
				case 6:
				case 20:
				case 8:
				case 22:
					level.GroundNode[CX + 1][CY + 1] = 1;
					break;
				}
				switch(level.GroundNode[CX + objW][CY + objH]) {
				case 0:
					level.GroundNode[CX + objW][CY + objH] = 20;
					break;
				case 9:
				case 23:
				case 7:
				case 21:
					level.GroundNode[CX + objW][CY + objH] = 1;
					break;
				}

				for(j = 1; j <= objW - 2; j += 2) {
					level.GroundNode[CX + 1 + j][CY + 1 + (j / 2) + 1] = 19;
					switch(level.GroundNode[CX + 1 + j][CY + 1 + (j / 2)]) {
					case 0:
					case 6:
					case 20:
						level.GroundNode[CX + 1 + j][CY + 1 + (j / 2)] = 12;
						break;
					}
					// GroundNode(CX + 1 + j, CY + 1 + (j \ 2) + 1) = 12
					switch(level.GroundNode[CX + 2.0 + j][CY + 1 + (j / 2) + 1]) {
					case 0:
					case 9:
					case 23:
						level.GroundNode[CX + 2.0 + j][CY + 1 + (j / 2) + 1] = 15;
						break;
					}
					// GroundNode(CX + 2.0 + j, CY + 1 + (j \ 2) + 2) = 15
					level.GroundNode[CX + 2.0 + j][CY + 1 + (j / 2)] = 16;
				}
			} else {
				//右斜
				switch(level.GroundNode[CX + 1][CY + objH]) {
				case 0:
					level.GroundNode[CX + 1][CY + objH] = 21;
					break;
				case 6:
				case 8:
				case 20:
				case 22:
					level.GroundNode[CX + 1][CY + objH] = 1;
					break;
				}
				switch(level.GroundNode[CX + objW][CY + 1]) {
				case 0:
					level.GroundNode[CX + objW][CY + 1] = 22;
					break;
				case 9:
				case 7:
				case 23:
				case 21:
					level.GroundNode[CX + objW][CY + 1] = 1;
					break;
				}

				for(j = 1; j <= objW - 2; j += 2) {
					level.GroundNode[CX + 1 + j][CY + objH - (j / 2) - 1] = 17;
					switch(level.GroundNode[CX + 1 + j][CY + objH - (j / 2)]) {
					case 0:
					case 22:
					case 8:
						level.GroundNode[CX + 1 + j][CY + objH - (j / 2)] = 14;
						break;
					}
					// GroundNode(CX + 1 + j, CY + MapObj(i).H - (j \ 2)) = 14
					switch(level.GroundNode[CX + 2.0 + j][CY + objH - (j / 2) - 1]) {
					case 0:
					case 21:
					case 7:
						level.GroundNode[CX + 2.0 + j][CY + objH - (j / 2) - 1] = 13;
						break;
					}
					// GroundNode(CX + 2.0 + j, CY + MapObj(i).H - (j \ 2) - 1) = 13
					level.GroundNode[CX + 2.0 + j][CY + objH - (j / 2)] = 18;
				}
			}
			break;
		case 88:
			//陡坡
			CX = std::round((-0.5 + objX / 160.0));
			CY = std::round((-0.5 + objY / 160.0));
			if((objFlag / 0x100000) % 0x2 == 0) {
				//左斜
				switch(level.GroundNode[CX + 1][CY + 1]) {
				case 0:
					level.GroundNode[CX + 1][CY + 1] = 9;
					break;
				case 6:
				case 8:
				case 20:
				case 22:
					level.GroundNode[CX + 1][CY + 1] = 1;
					break;
				}
				switch(level.GroundNode[CX + objW][CY + objH]) {
				case 0:
					level.GroundNode[CX + objW][CY + objH] = 6;
					break;
				case 9:
				case 7:
				case 23:
				case 21:
					level.GroundNode[CX + objW][CY + objH] = 1;
					break;
				}

				for(j = 1; j <= objW - 2; j++) {
					// GroundNode(CX + 1 + j, CY + 1 + j) = 5
					switch(level.GroundNode[CX + 1 + j][CY + 1 + j]) {
					case 0:
					case 9:
					case 23:
						level.GroundNode[CX + 1 + j][CY + 1 + j] = 5;
						break;
					}
					// GroundNode(CX + 1 + j, CY + j) = 2
					switch(level.GroundNode[CX + 1 + j][CY + j]) {
					case 0:
					case 6:
					case 20:
						level.GroundNode[CX + 1 + j][CY + j] = 2;
						break;
					}
				}
			} else {
				//右斜
				switch(level.GroundNode[CX + 1][CY + objH]) {
				case 0:
					level.GroundNode[CX + 1][CY + objH] = 7;
					break;
				case 6:
				case 8:
				case 20:
				case 22:
					level.GroundNode[CX + 1][CY + objH] = 1;
					break;
				}
				switch(level.GroundNode[CX + objW][CY + 1]) {
				case 0:
					level.GroundNode[CX + objW][CY + 1] = 8;
					break;
				case 9:
				case 7:
				case 23:
				case 21:
					level.GroundNode[CX + objW][CY + 1] = 1;
					break;
				}

				for(j = 1; j <= objW - 2; j++) {
					// GroundNode(CX + 1 + j, CY + MapObj(i).W - j) = 4
					switch(level.GroundNode[CX + 1 + j][CY + objW - j]) {
					case 0:
					case 8:
					case 22:
						level.GroundNode[CX + 1 + j][CY + objW - j] = 4;
						break;
					}
					// GroundNode(CX + 1 + j, CY + MapObj(i).W - 1 - j) = 3
					switch(level.GroundNode[CX + 1 + j][CY + objW - 1 - j]) {
					case 0:
					case 7:
					case 21:
						level.GroundNode[CX + 1 + j][CY + objW - 1 - j] = 3;
						break;
					}
				}
			}
			break;
		}
	}
	// GrdType
	// 0无 1方 2陡左上 3陡右上 4陡左下 5陡右下 6端左上 7端右上 8端左下 9端右下
	// 10  11  12缓大左上 13缓大右上 14缓大左下 15缓大右下  16缓小左上 17缓小右上 18缓小左下 19缓小右下
	// 20端左上 21端右上 22端左下 23端右下 24    25    26
	for(m = 0; m <= 2; m++) {
		for(i = 0; i <= W; i++) {
			for(j = 0; j <= H; j++) {
				switch(level.GroundNode[i + 1][j + 1]) {
				case 2:
				case 16: // UL
					if(level.GroundNode[i + 2][j + 1] > 0 || level.GroundNode[i + 1][j] > 0) {
						level.GroundNode[i + 1][j + 1] = 1;
					}
					break;
				case 3:
				case 17: // UR
					if(level.GroundNode[i][j + 1] > 0 || level.GroundNode[i + 1][j] > 0) {
						level.GroundNode[i + 1][j + 1] = 1;
					}
					break;
				case 4:
				case 18: // DL
					if(level.GroundNode[i + 2][j + 1] > 0 || level.GroundNode[i + 1][j + 2] > 0) {
						level.GroundNode[i + 1][j + 1] = 1;
					}
					break;
				case 5:
				case 19: // DR
					if(level.GroundNode[i][j + 1] > 0 || level.GroundNode[i + 1][j + 2] > 0) {
						level.GroundNode[i + 1][j + 1] = 1;
					}
					break;
				case 12:
					if(level.GroundNode[i + 1][j] > 0 || level.GroundNode[i + 2][j + 1] == 1) {
						level.GroundNode[i + 1][j + 1] = 1;
					}
					break;
				case 13:
					if(level.GroundNode[i + 1][j] > 0 || level.GroundNode[i][j + 1] == 1) {
						level.GroundNode[i + 1][j + 1] = 1;
					}
					break;
				case 14:
					if(level.GroundNode[i + 1][j + 2] > 0 || level.GroundNode[i + 2][j + 1] == 1) {
						level.GroundNode[i + 1][j + 1] = 1;
					}
					break;
				case 15:
					if(level.GroundNode[i + 1][j + 2] > 0 || level.GroundNode[i][j + 1] == 1) {
						level.GroundNode[i + 1][j + 1] = 1;
					}
					break;
				}
			}
		}
	}

	/* puts("Printing GroundNode\n");
	for(size_t y = 0; y < level.GroundNode[0].size(); y++) {
		std::string debugString;
		for(size_t x = 0; x < level.GroundNode.size(); x++) {
			debugString += fmt::format("{} ", level.GroundNode[x][y]);
		}
		debugString.pop_back();
		fmt::print("{}\n", debugString);
	}
	*/
}

void Drawers::DrawGrd() {
	int i = 0;
	// std::shared_ptr<Image> K;
	// K = GetTile(0, 12, 1, 1); //Image.FromFile(PT & "\img\" & LH.GameStyle.ToString & "\obj\7.png")
	if(NowIO) {
		//终点
		switch(level.LH.GameStyle) {
		case 12621: // 1
			if(level.MapHdr.Theme == 2) {
				DrawImage(fmt::format("img/{}/obj/27A.png", level.LH.GameStyle),
					(float)((level.LH.GoalX / 10.0 - 0.5) * Zm), (level.MapHdr.BorT / 16 - level.LH.GoalY - 4) * Zm,
					Zm * 2, Zm * 4);

				for(i = 0; i <= 13; i++) {
					DrawTile(15, 15, 1, 1, (float)((level.LH.GoalX / 10.0 - 14.5 + i) * Zm),
						(level.MapHdr.BorT / 16 - level.LH.GoalY) * Zm, Zm, Zm);
				}
			} else {
				DrawImage(fmt::format("img/{}/obj/27.png", level.LH.GameStyle),
					(float)((level.LH.GoalX / 10.0 - 0.5) * Zm), (level.MapHdr.BorT / 16 - level.LH.GoalY - 11) * Zm,
					Zm, Zm * 11);
			}
			break;
		case 13133: // 3
			if(level.MapHdr.Theme == 2) {
				DrawImage(fmt::format("img/{}/obj/27A.png", level.LH.GameStyle),
					(float)((level.LH.GoalX / 10.0 - 0.5) * Zm), (level.MapHdr.BorT / 16 - level.LH.GoalY - 4) * Zm,
					Zm * 2, Zm * 4);

				for(i = 0; i <= 13; i++) {
					DrawTile(15, 15, 1, 1, (float)((level.LH.GoalX / 10.0 - 14.5 + i) * Zm),
						(level.MapHdr.BorT / 16 - level.LH.GoalY) * Zm, Zm, Zm);
				}
			} else {
				DrawImage(fmt::format("img/{}/obj/27.png", level.LH.GameStyle),
					(float)((level.LH.GoalX / 10.0 - 0.5) * Zm),
					(level.MapHdr.BorT / 16 - level.LH.GoalY - 5 - 0.5) * Zm, Zm * 2, Zm * 2);
			}
			break;
		case 22349: // W
			if(level.MapHdr.Theme == 2) {
				DrawImage(fmt::format("img/{}/obj/27A.png", level.LH.GameStyle),
					(float)((level.LH.GoalX / 10.0 - 0.5) * Zm), (level.MapHdr.BorT / 16 - level.LH.GoalY - 4) * Zm,
					Zm * 2, Zm * 4);

				for(i = 0; i <= 13; i++) {
					DrawTile(15, 15, 1, 1, (float)((level.LH.GoalX / 10.0 - 14.5 + i) * Zm),
						(level.MapHdr.BorT / 16 - level.LH.GoalY) * Zm, Zm, Zm);
				}
			} else {
				// For i = 1 To 8
				//	G.DrawImage(Image.FromFile(PT & "\img\" & LH.GameStyle.ToString & "\obj\27C.png"), CSng((LH.GoalX /
				// 10 - 0.5) * Zm), (MapHdr.BorT \ 16 - LH.GoalY - i) * Zm, Zm, Zm) 	G.DrawImage(Image.FromFile(PT &
				//"\img\" & LH.GameStyle.ToString & "\obj\27E.png"), CSng((LH.GoalX / 10 + 1.5) * Zm), (MapHdr.BorT \ 16
				//- LH.GoalY - i) * Zm, Zm, Zm) Next G.DrawImage(Image.FromFile(PT & "\img\" & LH.GameStyle.ToString &
				// "\obj\27B.png"), CSng((LH.GoalX / 10 - 0.5) * Zm), (MapHdr.BorT \ 16 - LH.GoalY - 9) * Zm, Zm, Zm)
				// G.DrawImage(Image.FromFile(PT & "\img\" & LH.GameStyle.ToString & "\obj\27D.png"), CSng((LH.GoalX /
				// 10 + 1.5) * Zm), (MapHdr.BorT \ 16 - LH.GoalY - 9) * Zm, Zm, Zm)

				DrawImage(fmt::format("img/{}/obj/27F.png", level.LH.GameStyle),
					(float)((level.LH.GoalX / 10.0 - 0.5) * Zm),
					(float)(level.MapHdr.BorT / 16 - level.LH.GoalY - 8.5) * Zm, Zm, Zm * 9);
				DrawImage(fmt::format("img/{}/obj/27.png", level.LH.GameStyle), (float)((level.LH.GoalX / 10.0) * Zm),
					(float)(level.MapHdr.BorT / 16 - level.LH.GoalY - 8) * Zm, Zm * 2, Zm);
				DrawImage(fmt::format("img/{}/obj/27G.png", level.LH.GameStyle),
					(float)((level.LH.GoalX / 10.0 + 1.5) * Zm),
					(float)(level.MapHdr.BorT / 16 - level.LH.GoalY - 8.5) * Zm, Zm, Zm * 9);
			}
			break;
		case 21847: // U
			if(level.MapHdr.Theme == 2) {
				DrawImage(fmt::format("img/{}/obj/27A.png", level.LH.GameStyle),
					(float)((level.LH.GoalX / 10.0 - 0.5) * Zm), (level.MapHdr.BorT / 16 - level.LH.GoalY - 4) * Zm,
					Zm * 2, Zm * 4);

				for(i = 0; i <= 13; i++) {
					DrawTile(15, 15, 1, 1, (float)((level.LH.GoalX / 10.0 - 14.5 + i) * Zm),
						(level.MapHdr.BorT / 16 - level.LH.GoalY) * Zm, Zm, Zm);
				}
			} else {
				DrawImage(fmt::format("img/{}/obj/27.png", level.LH.GameStyle),
					(float)((level.LH.GoalX / 10.0 - 0.5) * Zm), (level.MapHdr.BorT / 16 - level.LH.GoalY - 11) * Zm,
					Zm, Zm * 11);
			}
			break;
		case 22323: // 3D
			DrawImage(fmt::format("img/{}/obj/27.png", level.LH.GameStyle), (float)((level.LH.GoalX / 10.0 - 0.5) * Zm),
				(level.MapHdr.BorT / 16 - level.LH.GoalY - 11) * Zm, Zm, Zm * 11);
			break;
		}

		DrawImage(fmt::format("img/{}/obj/38.png", level.LH.GameStyle), 1 * Zm,
			(level.MapHdr.BorT / 16 - level.LH.StartY - 3) * Zm, Zm * 3, Zm * 3);
	}
}

int Drawers::GetGrdType(const std::string& A) {
	int p = 0;
	int i = 0;
	p     = 0;
	for(i = 0; i <= 7; i++) {
		p += ((A.substr((8 - i) - 1, 1) == "0") ? 0 : 1) * std::pow(2, i);
	}
	return p;
}

std::string Drawers::GetGrdCode(int x, int y) {
	std::string S = "";
	// C
	S += (level.GroundNode[x][y + 2] == 0) ? "0" : "1";
	S += (level.GroundNode[x + 2][y + 2] == 0) ? "0" : "1";
	S += (level.GroundNode[x][y] == 0) ? "0" : "1";
	S += (level.GroundNode[x + 2][y] == 0) ? "0" : "1";

	// E ULRD
	S += (level.GroundNode[x + 1][y + 2] == 0) ? "0" : "1";
	S += (level.GroundNode[x][y + 1] == 0) ? "0" : "1";
	S += (level.GroundNode[x + 2][y + 1] == 0) ? "0" : "1";
	S += (level.GroundNode[x + 1][y] == 0) ? "0" : "1";

	return S;
}

int Drawers::GetGrdBold(int x, int y) {
	int tempGetGrdBold = 0;
	if(level.GroundNode[x][y + 1] > 1) {
		// U
		tempGetGrdBold = level.GroundNode[x][y + 1];
	} else if(level.GroundNode[x][y - 1] > 1) {
		// D
		tempGetGrdBold = level.GroundNode[x][y - 1];
	} else {
		tempGetGrdBold = 0;
	}
	return tempGetGrdBold;
}

int Drawers::CalC(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	return ((level.GroundNode[x1][y1] == 0) ? 0 : 1000) + ((level.GroundNode[x2][y2] == 0) ? 0 : 100)
		   + ((level.GroundNode[x3][y3] == 0) ? 0 : 10) + ((level.GroundNode[x4][y4] == 0) ? 0 : 1);
}

LevelParser::Point Drawers::GetCorCode(int x, int y) {
	using Point          = LevelParser::Point;
	Point tempGetCorCode = Point();
	int C                = 0;

	int grd = GetGrdBold(x, y);
	switch(grd) {
	case 2: // D陡左上
		C = CalC(x - 1, y, x - 1, y + 1, x, y + 1, x + 1, y + 1);
		switch(C) {
		case 0:
			tempGetCorCode = Point(5, 30);
			break;
		case 1:
		case 100:
		case 101:
			tempGetCorCode = Point(10, 13);
			break;
		case 10:
			tempGetCorCode = Point(15, 26);
			break;
		case 11:
		case 111:
			tempGetCorCode = Point(9, 27);
			break;
		case 110:
			tempGetCorCode = Point(15, 27);
			break;
		case 1000:
		case 1001:
		case 1100:
		case 1101:
			tempGetCorCode = Point(5, 27);
			break;
		case 1010:
			tempGetCorCode = Point(13, 27);
			break;
		case 1011:
			tempGetCorCode = Point(7, 27);
			break;
		case 1110:
			tempGetCorCode = Point(11, 27);
			break;
		case 1111:
			tempGetCorCode = Point(1, 26);
			break;
		}
		break;
	case 3: // D陡右上
		C = CalC(x - 1, y + 1, x, y + 1, x + 1, y + 1, x + 1, y);
		switch(C) {
		case 0:
		case 10:
		case 1000:
		case 1010:
			tempGetCorCode = Point(4, 30);
			break;
		case 1:
		case 11:
		case 1001:
		case 1011:
			tempGetCorCode = Point(4, 27);
			break;
		case 100:
		case 110:
			tempGetCorCode = Point(14, 27);
			break;
		case 101:
			tempGetCorCode = Point(12, 27);
			break;
		case 111:
			tempGetCorCode = Point(10, 27);
			break;
		case 1100:
		case 1110:
			tempGetCorCode = Point(8, 27);
			break;
		case 1101:
			tempGetCorCode = Point(6, 27);
			break;
		case 1111:
			tempGetCorCode = Point(0, 26);
			break;
		}
		break;
	case 4: // U陡左下
		C = CalC(x - 1, y, x - 1, y - 1, x, y - 1, x + 1, y - 1);
		switch(C) {
		case 0:
		case 1:
		case 100:
		case 101:
			tempGetCorCode = Point(5, 29);
			break;
		case 10:
		case 110:
			tempGetCorCode = Point(15, 26);
			break;
		case 11:
		case 111:
			tempGetCorCode = Point(9, 26);
			break;
		case 1000:
		case 1001:
		case 1100:
		case 1101:
			tempGetCorCode = Point(5, 26);
			break;
		case 1010:
			tempGetCorCode = Point(13, 26);
			break;
		case 1011:
			tempGetCorCode = Point(7, 26);
			break;
		case 1110:
			tempGetCorCode = Point(11, 26);
			break;
		case 1111:
			tempGetCorCode = Point(1, 25);
			break;
		}
		break;
	case 5: // U陡右下
		C = CalC(x - 1, y - 1, x, y - 1, x + 1, y - 1, x + 1, y);
		switch(C) {
		case 0:
		case 10:
		case 1000:
		case 1010:
			tempGetCorCode = Point(4, 29);
			break;
		case 1:
		case 11:
		case 1001:
		case 1011:
			tempGetCorCode = Point(4, 26);
			break;
		case 100:
		case 110:
			tempGetCorCode = Point(14, 26);
			break;
		case 101:
			tempGetCorCode = Point(12, 26);
			break;
		case 111:
			tempGetCorCode = Point(10, 26);
			break;
		case 1100:
		case 1110:
			tempGetCorCode = Point(8, 26);
			break;
		case 1101:
			tempGetCorCode = Point(6, 26);
			break;
		case 1111:
			tempGetCorCode = Point(0, 25);
			break;
		}
		break;
	case 12: // D缓大左上
		C = CalC(x - 1, y, x - 1, y + 1, x, y + 1, x + 1, y + 1);
		switch(C) {
		case 0:
		case 1:
		case 100:
		case 101:
			tempGetCorCode = Point(5, 30);
			break;
		case 10:
		case 110:
			tempGetCorCode = Point(15, 30);
			break;
		case 11:
		case 111:
			tempGetCorCode = Point(13, 31);
			break;
		case 1000:
		case 1001:
		case 1100:
		case 1101:
			tempGetCorCode = Point(8, 31);
			break;
		case 1010:
			tempGetCorCode = Point(13, 30);
			break;
		case 1011:
			tempGetCorCode = Point(11, 31);
			break;
		case 1110:
			tempGetCorCode = Point(11, 30);
			break;
		case 1111:
			tempGetCorCode = Point(2, 30);
			break;
		}
		break;
	case 13: // D缓大右上
		C = CalC(x - 1, y + 1, x, y + 1, x + 1, y + 1, x + 1, y);
		switch(C) {
		case 0:
		case 10:
		case 1000:
		case 1010:
			tempGetCorCode = Point(4, 30);
			break;
		case 1:
		case 11:
		case 1001:
		case 1011:
			tempGetCorCode = Point(7, 31);
			break;
		case 100:
		case 110:
			tempGetCorCode = Point(14, 30);
			break;
		case 101:
			tempGetCorCode = Point(12, 30);
			break;
		case 111:
			tempGetCorCode = Point(10, 30);
			break;
		case 1100:
		case 1110:
			tempGetCorCode = Point(12, 31);
			break;
		case 1101:
			tempGetCorCode = Point(10, 31);
			break;
		case 1111:
			tempGetCorCode = Point(1, 30);
			break;
		}
		break;
	case 14: // U缓大左下
		C = CalC(x - 1, y, x - 1, y - 1, x, y - 1, x + 1, y - 1);
		switch(C) {
		case 0:
		case 1:
		case 100:
		case 101:
			tempGetCorCode = Point(5, 29);
			break;
		case 10:
		case 110:
			tempGetCorCode = Point(15, 29);
			break;
		case 11:
		case 111:
			tempGetCorCode = Point(13, 28);
			break;
		case 1000:
		case 1001:
		case 1100:
		case 1101:
			tempGetCorCode = Point(8, 28);
			break;
		case 1010:
			tempGetCorCode = Point(13, 29);
			break;
		case 1011:
			tempGetCorCode = Point(10, 29);
			break;
		case 1110:
			tempGetCorCode = Point(11, 29);
			break;
		case 1111:
			tempGetCorCode = Point(2, 29);
			break;
		}
		break;
	case 15: // U缓大右下
		C = CalC(x - 1, y - 1, x, y - 1, x + 1, y - 1, x + 1, y);
		switch(C) {
		case 0:
		case 10:
		case 1000:
		case 1010:
			tempGetCorCode = Point(4, 29);
			break;
		case 1:
		case 11:
		case 1001:
		case 1011:
			tempGetCorCode = Point(7, 28);
			break;
		case 100:
		case 110:
			tempGetCorCode = Point(14, 29);
			break;
		case 101:
			tempGetCorCode = Point(12, 29);
			break;
		case 111:
			tempGetCorCode = Point(10, 29);
			break;
		case 1100:
		case 1110:
			tempGetCorCode = Point(12, 28);
			break;
		case 1101:
			tempGetCorCode = Point(11, 29);
			break;
		case 1111:
			tempGetCorCode = Point(1, 29);
			break;
		}
		break;
	case 16: // D缓小左上
		C = CalC(x - 1, y, x - 1, y + 1, x, y + 1, x + 1, y + 1);
		switch(C) {
		case 0:
		case 1:
		case 100:
		case 101:
			tempGetCorCode = Point(5, 30);
			break;
		case 10:
		case 110:
			tempGetCorCode = Point(15, 27);
			break;
		case 11:
		case 111:
			tempGetCorCode = Point(9, 27);
			break;
		case 1000:
		case 1001:
		case 1100:
		case 1101:
			tempGetCorCode = Point(9, 31);
			break;
		case 1010:
			tempGetCorCode = Point(9, 30);
			break;
		case 1011:
			tempGetCorCode = Point(15, 31);
			break;
		case 1110:
			tempGetCorCode = Point(7, 30);
			break;
		case 1111:
			tempGetCorCode = Point(3, 30);
			break;
		}
		break;
	case 17: // D缓小右上
		C = CalC(x - 1, y + 1, x, y + 1, x + 1, y + 1, x + 1, y);
		switch(C) {
		case 0:
		case 10:
		case 1000:
		case 1010:
			tempGetCorCode = Point(4, 30);
			break;
		case 1:
		case 11:
		case 1001:
		case 1011:
			tempGetCorCode = Point(6, 31);
			break;
		case 100:
		case 110:
			tempGetCorCode = Point(14, 27);
			break;
		case 101:
			tempGetCorCode = Point(8, 30);
			break;
		case 111:
			tempGetCorCode = Point(6, 30);
			break;
		case 1100:
		case 1110:
			tempGetCorCode = Point(8, 27);
			break;
		case 1101:
			tempGetCorCode = Point(14, 31);
			break;
		case 1111:
			tempGetCorCode = Point(0, 30);
			break;
		}
		break;
	case 18: // U缓小左下
		C = CalC(x - 1, y, x - 1, y - 1, x, y - 1, x + 1, y - 1);
		switch(C) {
		case 0:
		case 1:
		case 100:
		case 101:
			tempGetCorCode = Point(5, 29);
			break;
		case 10:
		case 110:
			tempGetCorCode = Point(15, 26);
			break;
		case 11:
		case 111:
			tempGetCorCode = Point(9, 26);
			break;
		case 1000:
		case 1001:
		case 1100:
		case 1101:
			tempGetCorCode = Point(9, 28);
			break;
		case 1010:
			tempGetCorCode = Point(9, 29);
			break;
		case 1011:
			tempGetCorCode = Point(15, 28);
			break;
		case 1110:
			tempGetCorCode = Point(7, 29);
			break;
		case 1111:
			tempGetCorCode = Point(3, 29);
			break;
		}
		break;
	case 19: // U缓小右下
		C = CalC(x - 1, y - 1, x, y - 1, x + 1, y - 1, x + 1, y);
		switch(C) {
		case 0:
		case 10:
		case 1000:
		case 1010:
			tempGetCorCode = Point(4, 29);
			break;
		case 1:
		case 11:
		case 1001:
		case 1011:
			tempGetCorCode = Point(6, 28);
			break;
		case 100:
		case 110:
			tempGetCorCode = Point(14, 26);
			break;
		case 101:
			tempGetCorCode = Point(8, 29);
			break;
		case 111:
			tempGetCorCode = Point(6, 29);
			break;
		case 1100:
		case 1110:
			tempGetCorCode = Point(8, 26);
			break;
		case 1101:
			tempGetCorCode = Point(14, 28);
			break;
		case 1111:
			tempGetCorCode = Point(0, 29);
			break;
		}
		break;
	default:
		tempGetCorCode = level.GrdLoc[GetGrdType(GetGrdCode(x - 1, y - 1))];

		break;
	}
	return tempGetCorCode;
}

void Drawers::DrawGrdCode() {
	//绘制地形
	int i = 0;
	int j = 0;
	Point R;

	for(i = 1; i <= W + 1; i++) {
		for(j = 1; j <= H + 1; j++) {
			switch(level.GroundNode[i][j]) {
			case 0:
				// G.DrawString(GroundNode(i, j), Me.Font, Brushes.Black, (i - 1) * Zm, (H - j) * Zm)
				break;
			case 6:
			case 7:
			case 8:
			case 9:
			case 20:
			case 21:
			case 22:
			case 23:
				R = level.GrdLoc[GetGrdType(GetGrdCode(i - 1, j - 1))];
				DrawTile(R.X, R.Y, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				level.GroundNode[i][j] = 1;
				break;
			case 2:
				if(level.GroundNode[i][j + 1] == 5) {
					DrawTile(2, 25, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				} else if(level.GroundNode[i - 1][j + 1] == 1) {
					DrawTile(1, 27, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				} else {
					DrawTile(3, 27, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				}
				break;
			case 3:
				if(level.GroundNode[i][j + 1] == 4) {
					DrawTile(3, 25, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				} else if(level.GroundNode[i + 1][j + 1] == 1) {
					DrawTile(0, 27, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				} else {
					DrawTile(2, 27, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				}
				break;
			case 4:
				if(level.GroundNode[i][j - 1] == 3) {
					DrawTile(3, 24, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				} else if(level.GroundNode[i - 1][j - 1] == 1) {
					DrawTile(1, 24, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				} else {
					DrawTile(3, 26, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				}
				break;
			case 5:
				if(level.GroundNode[i][j - 1] == 2) {
					DrawTile(2, 24, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				} else if(level.GroundNode[i + 1][j - 1] == 1) {
					DrawTile(0, 24, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				} else {
					DrawTile(2, 26, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				}
				break;
			case 12:
				if(level.GroundNode[i][j + 1] == 19) {
					DrawTile(0, 33, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				} else if(level.GroundNode[i - 1][j + 1] == 1) {
					DrawTile(2, 31, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				} else {
					DrawTile(5, 31, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				}
				break;
			case 13:
				if(level.GroundNode[i][j + 1] == 18) {
					DrawTile(3, 33, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				} else if(level.GroundNode[i + 1][j + 1] == 1) {
					DrawTile(1, 31, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				} else {
					DrawTile(4, 31, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				}
				break;
			case 14:
				if(level.GroundNode[i][j - 1] == 17) {
					DrawTile(2, 32, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				} else if(level.GroundNode[i - 1][j - 1] == 1) {
					DrawTile(2, 28, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				} else {
					DrawTile(5, 28, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				}
				break;
			case 15:
				if(level.GroundNode[i][j - 1] == 16) {
					DrawTile(1, 32, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				} else if(level.GroundNode[i + 1][j - 1] == 1) {
					DrawTile(1, 28, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				} else {
					DrawTile(4, 28, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				}
				break;
			case 16:
				DrawTile(3, 31, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				break;
			case 17:
				DrawTile(0, 31, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				break;
			case 18:
				DrawTile(3, 28, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				break;
			case 19:
				DrawTile(0, 28, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);

				break;
			default:
				// G.DrawString(GroundNode(i, j), Me.Font, Brushes.Black, (i - 1) * Zm, (H - j) * Zm)
				break;
			}
			// G.DrawString(GroundNode(i, j), Me.Font, Brushes.Black, (i - 1) * Zm, (H - j) * Zm)
			// G.DrawString(GetCorCode(i, j).X & "," & GetCorCode(i, j).Y, Me.Font, Brushes.Black, (i - 1) * Zm, (H - j)
			// * Zm + 10)
		}
	}
	for(i = 0; i <= W; i++) {
		for(j = 0; j <= H; j++) {
			if(level.GroundNode[i][j] == 1) {
				R = GetCorCode(i, j);
				DrawTile(R.X, R.Y, 1, 1, (i - 1) * Zm, (H - j) * Zm, Zm, Zm);
				// G.DrawString(GroundNode(i, j), Me.Font, Brushes.Black, (i - 1) * Zm, (H - j) * Zm)
				// G.DrawString(GetCorCode(i, j).X & "," & GetCorCode(i, j).Y, Me.Font, Brushes.Black, (i - 1) * Zm, (H
				// - j) * Zm + 10)
			}
		}
	}
}

void Drawers::DrawIce() {
	//冰块
	int i = 0;
	int H = 0;
	for(i = 0; i < level.MapHdr.IceCount; i++) {
		if(level.MapIce[i].ID == 0) {
			DrawTile(15, 41, 1, 2, level.MapIce[i].X * Zm, (level.MapHdr.BorT / 16 - 2) * Zm - level.MapIce[i].Y * Zm,
				Zm, Zm * 2);
			for(H = 1; H <= 2; H++) {
				level.ObjLocData[NowIO][level.MapIce[i].X + 1][H + level.MapIce[i].Y].Obj += "118,";
				level.ObjLocData[NowIO][level.MapIce[i].X + 1][H + level.MapIce[i].Y].Flag += ",";
				level.ObjLocData[NowIO][level.MapIce[i].X + 1][H + level.MapIce[i].Y].SubObj += ",";
				level.ObjLocData[NowIO][level.MapIce[i].X + 1][H + level.MapIce[i].Y].SubFlag += ",";
				level.ObjLocData[NowIO][level.MapIce[i].X + 1][H + level.MapIce[i].Y].State += ",";
				level.ObjLocData[NowIO][level.MapIce[i].X + 1][H + level.MapIce[i].Y].SubState += ",";
			}
		} else {
			DrawTile(15, 39, 1, 2, level.MapIce[i].X * Zm, (level.MapHdr.BorT / 16 - 2) * Zm - level.MapIce[i].Y * Zm,
				Zm, Zm * 2);
			for(H = 1; H <= 2; H++) {
				level.ObjLocData[NowIO][level.MapIce[i].X + 1][H + level.MapIce[i].Y].Obj += "118A,";
				level.ObjLocData[NowIO][level.MapIce[i].X + 1][H + level.MapIce[i].Y].Flag += ",";
				level.ObjLocData[NowIO][level.MapIce[i].X + 1][H + level.MapIce[i].Y].SubObj += ",";
				level.ObjLocData[NowIO][level.MapIce[i].X + 1][H + level.MapIce[i].Y].SubFlag += ",";
				level.ObjLocData[NowIO][level.MapIce[i].X + 1][H + level.MapIce[i].Y].State += ",";
				level.ObjLocData[NowIO][level.MapIce[i].X + 1][H + level.MapIce[i].Y].SubState += ",";
			}
		}
	}
}

void Drawers::DrawTrack() {
	//轨道
	int i = 0;
	for(i = 0; i < level.MapHdr.TrackCount; i++) {
		// LID+1?
		level.ObjLinkType[level.MapTrk[i].LID] = 59;
		if(level.MapTrk[i].Type < 8) {
			DrawImage(fmt::format("img/{}/obj/T{}.png", level.LH.GameStyle, (int)level.MapTrk[i].Type),
				level.MapTrk[i].X * Zm - Zm, (H - 2) * Zm - level.MapTrk[i].Y * Zm, Zm * 3, Zm * 3);
			switch(level.MapTrk[i].Type) {
			case 0:
				if(level.TrackNode[level.MapTrk[i].X + 1 + 1][level.MapTrk[i].Y + 1] == 1 && level.MapTrk[i].F0 == 0) {
					DrawImage(fmt::format("img/{}/obj/T.png", level.LH.GameStyle), level.MapTrk[i].X * Zm + Zm,
						(H - 1) * Zm - level.MapTrk[i].Y * Zm, Zm, Zm);
				}
				if(level.TrackNode[level.MapTrk[i].X + 1 - 1][level.MapTrk[i].Y + 1] == 1 && level.MapTrk[i].F1 == 0) {
					DrawImage(fmt::format("img/{}/obj/T.png", level.LH.GameStyle), level.MapTrk[i].X * Zm - Zm,
						(H - 1) * Zm - level.MapTrk[i].Y * Zm, Zm, Zm);
				}
				break;
			case 1:
				if(level.TrackNode[level.MapTrk[i].X + 1][level.MapTrk[i].Y + 1 + 1] == 1 && level.MapTrk[i].F0 == 0) {
					DrawImage(fmt::format("img/{}/obj/T.png", level.LH.GameStyle), level.MapTrk[i].X * Zm,
						(H - 2) * Zm - level.MapTrk[i].Y * Zm, Zm, Zm);
				}
				if(level.TrackNode[level.MapTrk[i].X + 1][level.MapTrk[i].Y + 1 - 1] == 1 && level.MapTrk[i].F1 == 0) {
					DrawImage(fmt::format("img/{}/obj/T.png", level.LH.GameStyle), level.MapTrk[i].X * Zm,
						H * Zm - level.MapTrk[i].Y * Zm, Zm, Zm);
				}
				break;
			case 2:
			case 4:
			case 5:
				if(level.TrackNode[level.MapTrk[i].X + 1 + 1][level.MapTrk[i].Y + 1 - 1] == 1
					&& level.MapTrk[i].F0 == 0) {
					DrawImage(fmt::format("img/{}/obj/T.png", level.LH.GameStyle), level.MapTrk[i].X * Zm + Zm,
						H * Zm - level.MapTrk[i].Y * Zm, Zm, Zm);
				}
				if(level.TrackNode[level.MapTrk[i].X + 1 - 1][level.MapTrk[i].Y + 1 + 1] == 1
					&& level.MapTrk[i].F1 == 0) {
					DrawImage(fmt::format("img/{}/obj/T.png", level.LH.GameStyle), level.MapTrk[i].X * Zm - Zm,
						(H - 2) * Zm - level.MapTrk[i].Y * Zm, Zm, Zm);
				}
				break;
			case 3:
			case 6:
			case 7:
				if(level.TrackNode[level.MapTrk[i].X + 1 + 1][level.MapTrk[i].Y + 1 + 1] == 1
					&& level.MapTrk[i].F0 == 0) {
					DrawImage(fmt::format("img/{}/obj/T.png", level.LH.GameStyle), level.MapTrk[i].X * Zm + Zm,
						(H - 2) * Zm - level.MapTrk[i].Y * Zm, Zm, Zm);
				}
				if(level.TrackNode[level.MapTrk[i].X + 1 - 1][level.MapTrk[i].Y + 1 - 1] == 1
					&& level.MapTrk[i].F1 == 0) {
					DrawImage(fmt::format("img/{}/obj/T.png", level.LH.GameStyle), level.MapTrk[i].X * Zm - Zm,
						H * Zm - level.MapTrk[i].Y * Zm, Zm, Zm);
				}
				break;
			}
		} else // Y轨道
		{
			DrawImage(fmt::format("img/{}/obj/T{}.png", level.LH.GameStyle, (int)level.MapTrk[i].Type),
				level.MapTrk[i].X * Zm - Zm, (H - 4) * Zm - level.MapTrk[i].Y * Zm, Zm * 5, Zm * 5);
			// G.DrawImage(Image.FromFile(PT & "\img\" & LH.GameStyle.ToString & "\obj\T.png"), (MapTrk(i).X - 1 +
			// TrackYPt(MapTrk(i).Type, 0).X) * Zm, H * Zm - (MapTrk(i).Y + TrackYPt(MapTrk(i).Type, 0).Y) * Zm, Zm, Zm)
			// G.DrawImage(Image.FromFile(PT & "\img\" & LH.GameStyle.ToString & "\obj\T.png"), (MapTrk(i).X - 1 +
			// TrackYPt(MapTrk(i).Type, 1).X) * Zm, H * Zm - (MapTrk(i).Y + TrackYPt(MapTrk(i).Type, 1).Y) * Zm, Zm, Zm)
			// G.DrawImage(Image.FromFile(PT & "\img\" & LH.GameStyle.ToString & "\obj\T.png"), (MapTrk(i).X - 1 +
			// TrackYPt(MapTrk(i).Type, 2).X) * Zm, H * Zm - (MapTrk(i).Y + TrackYPt(MapTrk(i).Type, 2).Y) * Zm, Zm, Zm)

			if(level.TrackNode[level.MapTrk[i].X + level.TrackYPt[level.MapTrk[i].Type][0].X]
							  [level.MapTrk[i].Y + level.TrackYPt[level.MapTrk[i].Type][0].Y]
					== 1
				&& level.MapTrk[i].F0 == 0) {
				DrawImage(fmt::format("img/{}/obj/T.png", level.LH.GameStyle),
					(level.MapTrk[i].X - 1 + level.TrackYPt[level.MapTrk[i].Type][0].X) * Zm,
					(H - 4) * Zm - (level.MapTrk[i].Y - level.TrackYPt[level.MapTrk[i].Type][0].Y) * Zm, Zm, Zm);
			}
			if(level.TrackNode[level.MapTrk[i].X + level.TrackYPt[level.MapTrk[i].Type][1].X]
							  [level.MapTrk[i].Y + level.TrackYPt[level.MapTrk[i].Type][1].Y]
					== 1
				&& level.MapTrk[i].F1 == 0) {
				DrawImage(fmt::format("img/{}/obj/T.png", level.LH.GameStyle),
					(level.MapTrk[i].X - 1 + level.TrackYPt[level.MapTrk[i].Type][1].X) * Zm,
					(H - 4) * Zm - (level.MapTrk[i].Y - level.TrackYPt[level.MapTrk[i].Type][1].Y) * Zm, Zm, Zm);
			}
			if(level.TrackNode[level.MapTrk[i].X + level.TrackYPt[level.MapTrk[i].Type][2].X]
							  [level.MapTrk[i].Y + level.TrackYPt[level.MapTrk[i].Type][2].Y]
					== 1
				&& level.MapTrk[i].F2 == 0) {
				DrawImage(fmt::format("img/{}/obj/T.png", level.LH.GameStyle),
					(level.MapTrk[i].X - 1 + level.TrackYPt[level.MapTrk[i].Type][2].X) * Zm,
					(H - 4) * Zm - (level.MapTrk[i].Y - level.TrackYPt[level.MapTrk[i].Type][2].Y) * Zm, Zm, Zm);
			}
		}
	}
}

void Drawers::DrawCID() {
	int i          = 0;
	std::string PR = "";
	int LX         = 0;
	int LY         = 0;

	std::string P = assetFolder;

	for(i = 0; i < level.MapHdr.ObjCount; i++) {
		int objFlag = level.MapObj[i].Flag;
		int objCid  = level.MapObj[i].CID;
		int objX    = level.MapObj[i].X;
		int objY    = level.MapObj[i].Y;

		LX = std::round((float)((-0.5 + objX / 160.0) * Zm));
		LY = std::round(H * Zm - (float)((0.5 + objY / 160.0) * Zm));
		switch(objCid) {
		case -1: //无

			break;
		case 44:
		case 81:
		case 116: //状态
			if((level.MapObj[i].CFlag / 0x40000) % 2 == 1) {
				DrawImage(fmt::format("img/{}/cid/{}A.png", level.LH.GameStyle, objCid), LX, LY, Zm, Zm);
			} else {
				DrawImage(fmt::format("img/{}/cid/{}.png", level.LH.GameStyle, objCid), LX, LY, Zm, Zm);
			}
			DrawImage("img/cmn/F1.png", LX, LY, Zm, Zm);
			break;
		case 34: //状态火花
			if((level.MapObj[i].CFlag / 0x4) % 2 == 1) {
				if((level.MapObj[i].CFlag / 0x40000) % 2 == 1) {
					DrawImage(fmt::format("img/{}/cid/34C.png", level.LH.GameStyle), LX, LY, Zm, Zm);
				} else {
					DrawImage(fmt::format("img/{}/cid/34A.png", level.LH.GameStyle), LX, LY, Zm, Zm);
				}
			} else {
				if((level.MapObj[i].CFlag / 0x40000) % 2 == 1) {
					DrawImage(fmt::format("img/{}/cid/34B.png", level.LH.GameStyle), LX, LY, Zm, Zm);
				} else {
					DrawImage(fmt::format("img/{}/cid/34.png", level.LH.GameStyle), LX, LY, Zm, Zm);
				}
			}
			DrawImage("img/cmn/F1.png", LX, LY, Zm, Zm);
			break;
		case 111: //机械库巴
			if((level.MapObj[i].CFlag / 0x40000) % 2 == 1) {
				PR = "B";
			} else if((level.MapObj[i].CFlag / 0x80000) % 2 == 1) {
				PR = "A";
			} else {
				PR = "";
			}

			DrawImage(fmt::format("img/{}/cid/111{}.png", level.LH.GameStyle, PR), LX, LY, Zm, Zm);
			DrawImage("img/cmn/F1.png", LX, LY, Zm, Zm);
			break;
		case 76: //加邦
			if((objFlag / 0x4) % 2 == 1) {
				if(level.MapHdr.Theme == 6) {
					PR = "B";
				} else {
					PR = "A";
				}
			} else {
				PR = "";
			}
			DrawImage(fmt::format("img/{}/cid/76{}.png", level.LH.GameStyle, PR), LX, LY, Zm, Zm);
			DrawImage("img/cmn/F1.png", LX, LY, Zm, Zm);
			break;
		case 33: // 1UP
			if(level.MapHdr.Theme == 1 && level.MapHdr.Flag == 2) {
				DrawImage(fmt::format("img/{}/cid/33A.png", level.LH.GameStyle), LX, LY, Zm, Zm);
			} else {
				DrawImage(fmt::format("img/{}/cid/33.png", level.LH.GameStyle), LX, LY, Zm, Zm);
			}

			DrawImage("img/cmn/F1.png", LX, LY, Zm, Zm);

			break;
		default:
			if((level.MapObj[i].CFlag / 0x4) % 2 == 1) {
				DrawImage(fmt::format("img/{}/cid/{}A.png", level.LH.GameStyle, objCid), LX, LY, Zm, Zm);
			} else {
				DrawImage(fmt::format("img/{}/cid/{}.png", level.LH.GameStyle, objCid), LX, LY, Zm, Zm);
			}

			DrawImage("img/cmn/F1.png", LX, LY, Zm, Zm);
			break;
		}
	}
}

void Drawers::DrawFireBar() {
	int i         = 0;
	int j         = 0;
	int LX        = 0;
	int LY        = 0;
	std::string P = assetFolder;
	float FR      = 0;
	for(i = 0; i < level.MapHdr.ObjCount; i++) {
		int objW    = level.MapObj[i].W;
		int objH    = level.MapObj[i].H;
		int objFlag = level.MapObj[i].Flag;
		int objX    = level.MapObj[i].X;
		int objY    = level.MapObj[i].Y;

		if(level.MapObj[i].ID == 24) {
			LX = std::round((float)(-objW / 2.0 + objX / 160.0) * Zm);
			LY = std::round(H * Zm - (float)(objH - 0.5 + objY / 160.0) * Zm);
			FR = level.MapObj[i].Ex / 0x38E38E0;

			for(j = 0; j <= (objFlag - 0x6000000) / 0x400000 + 1; j++) {
				DrawImageRotateOpacity(fmt::format("img/{}/obj/24A.png", level.LH.GameStyle), -FR * 5, 0.5,
					-Zm / 4 + j * Zm + LX + Zm / 2, -Zm / 4 + LY + Zm / 2, Zm, Zm / 2);
			}

			if((objFlag / 0x8) % 2 == 1) {
				DrawImage("img/cmn/B0.png", LX, LY, Zm, Zm);
			} else {
				DrawImage("img/cmn/B1.png", LX, LY, Zm, Zm);
			}
		}
	}
}

void Drawers::DrawFire() {
	int i         = 0;
	std::string P = assetFolder;

	for(i = 0; i < level.MapHdr.ObjCount; i++) {
		int objW = level.MapObj[i].W;
		int objH = level.MapObj[i].H;
		int objX = level.MapObj[i].X;
		int objY = level.MapObj[i].Y;

		if(level.MapObj[i].ID == 54) {
			switch(level.MapObj[i].Flag % 0x100) {
			case 0x40:
				DrawImageOpacity(fmt::format("img/{}/obj/54A1.png", level.LH.GameStyle), 0.5,
					(float)((-objW / 2.0 + objX / 160.0) * Zm),
					(H - 3) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm * objW, 3 * Zm * objH);
				break;
			case 0x48:
				DrawImageOpacity(fmt::format("img/{}/obj/54A3.png", level.LH.GameStyle), 0.5,
					(float)((-objW / 2.0 + 1 + objX / 160.0) * Zm), H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm),
					3 * Zm * objW, Zm * objH);
				break;
			case 0x50:
				DrawImageOpacity(fmt::format("img/{}/obj/54A5.png", level.LH.GameStyle), 0.5,
					(float)((-objW / 2.0 + objX / 160.0) * Zm),
					(H + 1) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm * objW, 3 * Zm * objH);
				break;
			case 0x58:
				DrawImageOpacity(fmt::format("img/{}/obj/54A7.png", level.LH.GameStyle), 0.5,
					(float)((-objW / 2.0 - 3 + objX / 160.0) * Zm), H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm),
					3 * Zm * objW, Zm * objH);
				break;
			case 0x44:
				DrawImageOpacity(fmt::format("img/{}/obj/54A2.png", level.LH.GameStyle), 0.5,
					(float)((-objW / 2.0 + objX / 160.0) * Zm),
					(H - 3) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm * objW, 3 * Zm * objH);
				break;
			case 0x4C:
				DrawImageOpacity(fmt::format("img/{}/obj/54A4.png", level.LH.GameStyle), 0.5,
					(float)((-objW / 2.0 + 1 + objX / 160.0) * Zm), H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm),
					3 * Zm * objW, Zm * objH);
				break;
			case 0x54:
				DrawImageOpacity(fmt::format("img/{}/obj/54A6.png", level.LH.GameStyle), 0.5,
					(float)((-objW / 2.0 + objX / 160.0) * Zm),
					(H + 1) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm * objW, 3 * Zm * objH);
				break;
			case 0x5C:
				DrawImageOpacity(fmt::format("img/{}/obj/54A8.png", level.LH.GameStyle), 0.5,
					(float)((-objW / 2.0 - 3 + objX / 160.0) * Zm), H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm),
					3 * Zm * objW, Zm * objH);
				break;
			}
		}
	}
}

void Drawers::DrawCPipe() {
	int i          = 0;
	int J          = 0;
	int K          = 0;
	std::string CP = "";

	for(i = 0; i < level.MapHdr.ClearPipCount; i++) {
		for(J = 0; J < level.MapCPipe[i].NodeCount; J++) {
			if(J == 0) {
				for(K = 0; K < level.MapCPipe[i].Node[J].H; K++) {
					switch(level.MapCPipe[i].Node[J].Dir) {
					case 0: // R
						if(K == 0) {
							CP = "C";
						} else if(level.MapCPipe[i].NodeCount == 1 && K == level.MapCPipe[i].Node[J].H - 1) {
							CP = "E";
						} else {
							CP = "D";
						}
						DrawImage(fmt::format("img/{}/obj/93{}.png", level.LH.GameStyle, CP),
							(level.MapCPipe[i].Node[J].X + K) * Zm, (H - 1 - level.MapCPipe[i].Node[J].Y) * Zm, Zm,
							2 * Zm);
						break;
					case 1: // L
						if(K == 0) {
							CP = "E";
						} else if(level.MapCPipe[i].NodeCount == 1 && K == level.MapCPipe[i].Node[J].H - 1) {
							CP = "C";
						} else {
							CP = "D";
						}
						DrawImage(fmt::format("img/{}/obj/93{}.png", level.LH.GameStyle, CP),
							(level.MapCPipe[i].Node[J].X - K) * Zm, (H - 1 - level.MapCPipe[i].Node[J].Y - 1) * Zm, Zm,
							2 * Zm);
						break;
					case 2: // U
						if(K == 0) {
							CP = "";
						} else if(level.MapCPipe[i].NodeCount == 1 && K == level.MapCPipe[i].Node[J].H - 1) {
							CP = "B";
						} else {
							CP = "A";
						}
						DrawImage(fmt::format("img/{}/obj/93{}.png", level.LH.GameStyle, CP),
							level.MapCPipe[i].Node[J].X * Zm, (H - 1 - level.MapCPipe[i].Node[J].Y - K) * Zm, 2 * Zm,
							Zm);
						break;
					case 3: // D
						if(K == 0) {
							CP = "B";
						} else if(level.MapCPipe[i].NodeCount == 1 && K == level.MapCPipe[i].Node[J].H - 1) {
							CP = "";
						} else {
							CP = "A";
						}
						DrawImage(fmt::format("img/{}/obj/93{}.png", level.LH.GameStyle, CP),
							(level.MapCPipe[i].Node[J].X - 1) * Zm, (H - 1 - level.MapCPipe[i].Node[J].Y + K) * Zm,
							2 * Zm, Zm);
						break;
					}
				}
			}

			else if(J == level.MapCPipe[i].NodeCount - 1) {
				for(K = 0; K < level.MapCPipe[i].Node[J].H; K++) {
					switch(level.MapCPipe[i].Node[J].Dir) {
					case 0: // R
						CP = (K == level.MapCPipe[i].Node[J].H - 1) ? "E" : "D";
						DrawImage(fmt::format("img/{}/obj/93{}.png", level.LH.GameStyle, CP),
							(level.MapCPipe[i].Node[J].X + K) * Zm, (H - 1 - level.MapCPipe[i].Node[J].Y) * Zm, Zm,
							2 * Zm);
						break;
					case 1: // L
						CP = (K == level.MapCPipe[i].Node[J].H - 1) ? "C" : "D";
						DrawImage(fmt::format("img/{}/obj/93{}.png", level.LH.GameStyle, CP),
							(level.MapCPipe[i].Node[J].X - K) * Zm, (H - 1 - level.MapCPipe[i].Node[J].Y - 1) * Zm, Zm,
							2 * Zm);
						break;
					case 2: // U
						CP = (K == level.MapCPipe[i].Node[J].H - 1) ? "B" : "A";
						DrawImage(fmt::format("img/{}/obj/93{}.png", level.LH.GameStyle, CP),
							level.MapCPipe[i].Node[J].X * Zm, (H - 1 - level.MapCPipe[i].Node[J].Y - K) * Zm, 2 * Zm,
							Zm);
						break;
					case 3: // D
						CP = (K == level.MapCPipe[i].Node[J].H - 1) ? "" : "A";
						DrawImage(fmt::format("img/{}/obj/93{}.png", level.LH.GameStyle, CP),
							(level.MapCPipe[i].Node[J].X - 1) * Zm, (H - 1 - level.MapCPipe[i].Node[J].Y + K) * Zm,
							2 * Zm, Zm);
						break;
					}
				}
			}
			// ORIGINAL LINE: Case Else
			else {
				if(level.MapCPipe[i].Node[J].type >= 3 && level.MapCPipe[i].Node[J].type <= 10) {
					switch(level.MapCPipe[i].Node[J].type) {
					case 3:
					case 7: // RU DL
						DrawImage(fmt::format("img/{}/obj/93G.png", level.LH.GameStyle),
							(level.MapCPipe[i].Node[J].X) * Zm, (H - 2.0 - level.MapCPipe[i].Node[J].Y) * Zm, 2 * Zm,
							2 * Zm);
						break;
					case 4:
					case 9: // RD UL
						DrawImage(fmt::format("img/{}/obj/93H.png", level.LH.GameStyle),
							(level.MapCPipe[i].Node[J].X) * Zm, (H - 2.0 - level.MapCPipe[i].Node[J].Y) * Zm, 2 * Zm,
							2 * Zm);
						break;
					case 6:
					case 10: // UR LD
						DrawImage(fmt::format("img/{}/obj/93J.png", level.LH.GameStyle),
							(level.MapCPipe[i].Node[J].X) * Zm, (H - 2.0 - level.MapCPipe[i].Node[J].Y) * Zm, 2 * Zm,
							2 * Zm);
						break;
					case 5:
					case 8: // DR LU
						DrawImage(fmt::format("img/{}/obj/93F.png", level.LH.GameStyle),
							(level.MapCPipe[i].Node[J].X) * Zm, (H - 2.0 - level.MapCPipe[i].Node[J].Y) * Zm, 2 * Zm,
							2 * Zm);
						break;
					}
				} else {
					for(K = 0; K < level.MapCPipe[i].Node[J].H; K++) {
						switch(level.MapCPipe[i].Node[J].Dir) {
						case 0: // R
							DrawImage(fmt::format("img/{}/obj/93D.png", level.LH.GameStyle),
								(level.MapCPipe[i].Node[J].X + K) * Zm, (H - 1 - level.MapCPipe[i].Node[J].Y) * Zm, Zm,
								2 * Zm);
							break;
						case 1: // L
							DrawImage(fmt::format("img/{}/obj/93D.png", level.LH.GameStyle),
								(level.MapCPipe[i].Node[J].X - K) * Zm, (H - 1 - level.MapCPipe[i].Node[J].Y - 1) * Zm,
								Zm, 2 * Zm);
							break;
						case 2: // U
							DrawImage(fmt::format("img/{}/obj/93A.png", level.LH.GameStyle),
								level.MapCPipe[i].Node[J].X * Zm, (H - 1 - level.MapCPipe[i].Node[J].Y - K) * Zm,
								2 * Zm, Zm);
							break;
						case 3: // D
							DrawImage(fmt::format("img/{}/obj/93A.png", level.LH.GameStyle),
								(level.MapCPipe[i].Node[J].X - 1) * Zm, (H - 1 - level.MapCPipe[i].Node[J].Y + K) * Zm,
								2 * Zm, Zm);
							break;
						}
					}
				}
			}
		}
	}
}
