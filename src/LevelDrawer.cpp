#include "LevelDrawer.hpp"

void LevelDrawer::Setup() {
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

	static uint8_t GS[] = { 0x0D, 0x4D, 0x1D, 0xAD, 0x3D, 0x9D, 0x2D, 0xCD, 0x6D, 0x5D, 0x8D, 0xED, 0x7D, 0xDD, 0xBD,
		0xFD, 0x0D, 0x4D, 0x1D, 0x2F, 0x3D, 0x9D, 0x2D, 0x4E, 0x6D, 0x5D, 0x8D, 0x0E, 0x7D, 0xDD, 0xBD, 0x8E, 0x0D,
		0x4D, 0x1D, 0xAD, 0x3D, 0x4F, 0x2D, 0x5E, 0x6D, 0x5D, 0x8D, 0xED, 0x7D, 0x1E, 0xBD, 0x9E, 0x0D, 0x4D, 0x1D,
		0x2F, 0x3D, 0x4F, 0x2D, 0x3F, 0x6D, 0x5D, 0x8D, 0x0E, 0x7D, 0x1E, 0xBD, 0xCE, 0x0D, 0x4D, 0x1D, 0xAD, 0x3D,
		0x9D, 0x2D, 0xCD, 0x6D, 0x5D, 0x8F, 0x2E, 0x7D, 0xDD, 0x6E, 0xAE, 0x0D, 0x4D, 0x1D, 0x2F, 0x3D, 0x9D, 0x2D,
		0x4E, 0x6D, 0x5D, 0x8F, 0x5F, 0x7D, 0xDD, 0x6E, 0xEE, 0x0D, 0x4D, 0x1D, 0xAD, 0x3D, 0x4F, 0x2D, 0x5E, 0x6D,
		0x5D, 0x8F, 0x2E, 0xAF, 0x1E, 0x6E, 0x1F, 0x0D, 0x4D, 0x1D, 0x2F, 0x3D, 0x4F, 0x2D, 0x3F, 0x6D, 0x5D, 0x8F,
		0x5F, 0x7D, 0x1E, 0x6E, 0xBF, 0x0D, 0x4D, 0x1D, 0xAD, 0x3D, 0x9D, 0x2D, 0xCD, 0x6D, 0x5D, 0x8D, 0xED, 0xAF,
		0x3E, 0x7E, 0xBE, 0x0D, 0x4D, 0x1D, 0x2F, 0x3D, 0x9D, 0x2D, 0x4E, 0x6D, 0x5D, 0x8D, 0x0E, 0x7D, 0x3E, 0x7E,
		0x0F, 0x0D, 0x4D, 0x1D, 0xAD, 0x3D, 0x4F, 0x2D, 0x5E, 0x6D, 0x5D, 0x8D, 0xED, 0xAF, 0x7F, 0x7E, 0xFE, 0x0D,
		0x4D, 0x1D, 0x2F, 0x3D, 0x4F, 0x2D, 0x3F, 0x6D, 0x5D, 0x8D, 0x0E, 0xAF, 0x7F, 0x7E, 0xCF, 0x0D, 0x4D, 0x1D,
		0xAD, 0x3D, 0x9D, 0x2D, 0xCD, 0x6D, 0x5D, 0x8F, 0x2E, 0xAF, 0x3E, 0x9F, 0xDE, 0x0D, 0x4D, 0x1D, 0x2F, 0x3D,
		0x9D, 0x2D, 0x4E, 0x6D, 0x5D, 0x8F, 0x5F, 0xAF, 0x3E, 0x9F, 0xDF, 0x0D, 0x4D, 0x1D, 0xAD, 0x3D, 0x4F, 0x2D,
		0x5E, 0x6D, 0x5D, 0x8F, 0x2E, 0xAF, 0x7F, 0x9F, 0xEF, 0x0D, 0x4D, 0x1D, 0x2F, 0x3D, 0x4F, 0x2D, 0x3F, 0x6D,
		0x5D, 0x8F, 0x5F, 0xAF, 0x7F, 0x9F, 0x6F };

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

void LevelDrawer::SetGraphics(cairo_t* graphics) {
	cr = graphics;
}

void LevelDrawer::LoadTilesheet() {
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

void LevelDrawer::SetIsOverworld(bool isOverworld) {
	NowIO = isOverworld;
}

void LevelDrawer::SetLog(bool log) {
	doLogging = log;
}

void LevelDrawer::SetAssetFolder(std::string folder) {
	assetFolder = folder;
}

void LevelDrawer::SetOnlyInstructions() {
	noRender = true;
}

std::vector<DrawingInstruction>& LevelDrawer::GetInstructions() {
	return drawingInstructions;
}

int LevelDrawer::GetWidth() {
	return renderWidth;
}

int LevelDrawer::GetHeight() {
	return renderHeight;
}

void LevelDrawer::ClearImageCache() {
	for(auto& pattern : tileCache) {
		cairo_pattern_destroy(pattern.second);
	}
	tileCache.clear();

	for(auto& pattern : patternCache) {
		cairo_pattern_destroy(pattern.second);
	}
	patternCache.clear();

	cairo_surface_destroy(tilesheet);
	cairo_surface_destroy(spritesheet);
}

void LevelDrawer::DrawGridlines() {
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
			cairo_line_to(cr, i * Zm, H * Zm);
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

cairo_pattern_t* LevelDrawer::GetCachedTile(int x, int y, int w, int h) {
	int index = (y * 16 + x) * 3;

	if(w == 2) {
		index += 1;
	}

	if(h == 2) {
		index += 2;
	}

	if(tileCache.count(index)) {
		return tileCache[index];
	} else {
		cairo_surface_t* subsurface
			= cairo_surface_create_for_rectangle(tilesheet, TileW * x, TileW * y, TileW * w, TileW * h);
		cairo_pattern_t* pattern = cairo_pattern_create_for_surface(subsurface);
		cairo_surface_destroy(subsurface);
		cairo_pattern_set_filter(pattern, CAIRO_FILTER_NEAREST);
		tileCache[index] = pattern;
		return pattern;
	}
}

cairo_pattern_t* LevelDrawer::GetCachedPattern(int id) {
	if(patternCache.count(id)) {
		return patternCache[id];
	} else {
		const auto sprite = LevelData::ObjectLocation.at(id);
		cairo_surface_t* subsurface
			= cairo_surface_create_for_rectangle(spritesheet, sprite.x, sprite.y, sprite.width, sprite.height);
		cairo_pattern_t* pattern = cairo_pattern_create_for_surface(subsurface);
		cairo_surface_destroy(subsurface);
		cairo_pattern_set_filter(pattern, CAIRO_FILTER_NEAREST);
		patternCache[id] = pattern;
		return pattern;
	}
}

void LevelDrawer::DrawTile(
	int tileX, int tileY, int tileW, int tileH, int x, int y, int targetWidth, int targetHeight) {
	if(doLogging) {
		fmt::print("Printing tile X:{} Y:{}\n", tileX, tileY);
	}

	if(!noRender) {
		cairo_pattern_t* pattern = GetCachedTile(tileX, tileY, tileW, tileH);

		cairo_translate(cr, (double)x, (double)y);
		cairo_scale(cr, (double)targetWidth / (TileW * tileW), (double)targetHeight / (TileW * tileH));
		cairo_set_source(cr, pattern);
		cairo_paint_with_alpha(cr, 1.0);
		cairo_identity_matrix(cr);
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

void LevelDrawer::DrawImage(uint32_t id, int x, int y, int targetWidth, int targetHeight) {
	if(doLogging) {
		fmt::print("Printing {} at X:{} Y:{} with W:{} and H:{}\n", id, x, y, targetWidth, targetHeight);
	}

	if(!noRender) {
		cairo_pattern_t* pattern = GetCachedPattern(id);

		if(pattern) {
			const auto sprite = LevelData::ObjectLocation.at(id);

			cairo_translate(cr, (double)x, (double)y);
			cairo_scale(cr, (double)targetWidth / sprite.width, (double)targetHeight / sprite.height);
			cairo_set_source(cr, pattern);
			cairo_paint_with_alpha(cr, 1.0);
			cairo_identity_matrix(cr);
		}
	}

	if(addDrawingInstructions) {
		DrawingInstruction instruction;
		instruction.path         = std::to_string(id);
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

void LevelDrawer::DrawImageOpacity(uint32_t id, double opacity, int x, int y, int targetWidth, int targetHeight) {
	if(doLogging) {
		fmt::print("Printing {} at X:{} Y:{} with W:{} and H:{}\n", id, x, y, targetWidth, targetHeight);
	}

	if(!noRender) {
		cairo_pattern_t* pattern = GetCachedPattern(id);

		if(pattern) {
			const auto sprite = LevelData::ObjectLocation.at(id);

			cairo_translate(cr, (double)x, (double)y);
			cairo_scale(cr, (double)targetWidth / sprite.width, (double)targetHeight / sprite.height);
			cairo_set_source(cr, pattern);
			cairo_paint_with_alpha(cr, opacity);
			cairo_identity_matrix(cr);
		}
	}

	if(addDrawingInstructions) {
		DrawingInstruction instruction;
		instruction.path         = std::to_string(id);
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

void LevelDrawer::DrawImageRotate(uint32_t id, double angle, int x, int y, int targetWidth, int targetHeight) {
	if(doLogging) {
		fmt::print("Printing {} at X:{} Y:{} with W:{} and H:{}\n", id, x, y, targetWidth, targetHeight);
	}

	if(!noRender) {
		cairo_pattern_t* pattern = GetCachedPattern(id);

		if(pattern) {
			const auto sprite = LevelData::ObjectLocation.at(id);

			cairo_translate(cr, (double)x + (targetWidth / 2), (double)y + (targetHeight / 2));
			cairo_rotate(cr, angle);
			cairo_scale(cr, (double)targetWidth / sprite.width, (double)targetHeight / sprite.height);
			cairo_translate(cr, -sprite.width / 2, -sprite.height / 2);
			cairo_set_source(cr, pattern);
			cairo_paint(cr);
			cairo_identity_matrix(cr);
		}
	}

	if(addDrawingInstructions) {
		DrawingInstruction instruction;
		instruction.path         = std::to_string(id);
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

void LevelDrawer::DrawImageRotateOpacity(
	uint32_t id, double angle, double opacity, int x, int y, int targetWidth, int targetHeight) {
	if(doLogging) {
		fmt::print("Printing {} at X:{} Y:{} with W:{} and H:{}\n", id, x, y, targetWidth, targetHeight);
	}

	if(!noRender) {
		cairo_pattern_t* pattern = GetCachedPattern(id);

		if(pattern) {
			const auto sprite = LevelData::ObjectLocation.at(id);

			cairo_translate(cr, (double)x + (targetWidth / 2), (double)y + (targetHeight / 2));
			cairo_rotate(cr, angle);
			cairo_scale(cr, (double)targetWidth / sprite.width, (double)targetHeight / sprite.height);
			cairo_translate(cr, -sprite.width / 2, -sprite.height / 2);
			cairo_set_source(cr, pattern);
			cairo_paint_with_alpha(cr, opacity);
			cairo_identity_matrix(cr);
		}
	}

	if(addDrawingInstructions) {
		DrawingInstruction instruction;
		instruction.path         = std::to_string(id);
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

void LevelDrawer::DrawCrp(unsigned char EX, int X, int Y) {
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
		DrawImage(LevelData::OBJ_CMN_SS, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);

		uint32_t path = 0;
		switch(level.MapCrp[EX - 1].Node[i]) {
		case 1: // L
			path = LevelData::OBJ_CMN_SL;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
			XX -= 2;
			break;
		case 2: // R
			path = LevelData::OBJ_CMN_SR;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
			XX += 2;
			break;
		case 3: // D
			path = LevelData::OBJ_CMN_SD;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
			YY -= 2;
			break;
		case 4: // U
			path = LevelData::OBJ_CMN_SU;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
			YY += 2;
			break;
		case 5: // LD
			path = LevelData::OBJ_CMN_SRD;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
			YY -= 2;
			break;
		case 6: // DL
			path = LevelData::OBJ_CMN_SUL;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
			XX -= 2;
			break;
		case 7: // LU
			path = LevelData::OBJ_CMN_SRU;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
			YY += 2;
			break;
		case 8: // UL
			path = LevelData::OBJ_CMN_SDL;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
			XX -= 2;
			break;
		case 9: // RD
			path = LevelData::OBJ_CMN_SLD;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
			YY -= 2;
			break;
		case 10: // DR
			path = LevelData::OBJ_CMN_SUR;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
			XX += 2;
			break;
		case 11: // RU
			path = LevelData::OBJ_CMN_SLU;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
			YY += 2;
			break;
		case 12: // UR
			path = LevelData::OBJ_CMN_SDR;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
			XX += 2;
			break;
		case 13: // RE
			path = LevelData::OBJ_CMN_SE;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
			break;
		case 14: // LE
			path = LevelData::OBJ_CMN_SE;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
			break;
		case 15: // UE
			path = LevelData::OBJ_CMN_SE;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
			break;
		case 16: // DE
			path = LevelData::OBJ_CMN_SE;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
			break;
		}
	}
}

void LevelDrawer::DrawSnake(unsigned char EX, int X, int Y, int SW, int SH) {
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
		DrawImage(LevelData::OBJ_CMN_SS, XX * Zm, (H - YY) * Zm, Zm, Zm);

		uint32_t path = 0;
		switch(level.MapSnk[EX - 1].Node[i].Dir) {
		case 1: // L
			path = LevelData::OBJ_CMN_SL;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm, Zm);
			XX -= 1;
			break;
		case 2: // R
			path = LevelData::OBJ_CMN_SR;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm, Zm);
			XX += 1;
			break;
		case 3: // D
			path = LevelData::OBJ_CMN_SD;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm, Zm);
			YY -= 1;
			break;
		case 4: // U
			path = LevelData::OBJ_CMN_SU;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm, Zm);
			YY += 1;
			break;
		case 5: // LD
			path = LevelData::OBJ_CMN_SRD;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm, Zm);
			YY -= 1;
			break;
		case 6: // DL
			path = LevelData::OBJ_CMN_SUL;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm, Zm);
			XX -= 1;
			break;
		case 7: // LU
			path = LevelData::OBJ_CMN_SRU;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm, Zm);
			YY += 1;
			break;
		case 8: // UL
			path = LevelData::OBJ_CMN_SDL;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm, Zm);
			XX -= 1;
			break;
		case 9: // RD
			path = LevelData::OBJ_CMN_SLD;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm, Zm);
			YY -= 1;
			break;
		case 10: // DR
			path = LevelData::OBJ_CMN_SUR;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm, Zm);
			XX += 1;
			break;
		case 11: // RU
			path = LevelData::OBJ_CMN_SLU;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm, Zm);
			YY += 1;
			break;
		case 12: // UR
			path = LevelData::OBJ_CMN_SDR;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm, Zm);
			XX += 1;
			break;
		case 13: // RE
			path = LevelData::OBJ_CMN_SE;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm, Zm);
			break;
		case 14: // LE
			path = LevelData::OBJ_CMN_SE;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm, Zm);
			break;
		case 15: // UE
			path = LevelData::OBJ_CMN_SE;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm, Zm);
			break;
		case 16: // DE
			path = LevelData::OBJ_CMN_SE;
			DrawImage(path, XX * Zm, (H - YY) * Zm, Zm, Zm);
			break;
		}
	}
	// Err:;
}

void LevelDrawer::DrawMoveBlock(unsigned char ID, unsigned char EX, int X, int Y) {
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
			DrawImage(LevelData::OBJ_CMN_SS, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);

			uint32_t path = 0;
			switch(level.MapTrackBlk[EX - 1].Node[i].p1) {
			case 1: // L
				path = LevelData::OBJ_CMN_SL;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				XX -= 2;
				break;
			case 2: // R
				path = LevelData::OBJ_CMN_SR;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				XX += 2;
				break;
			case 3: // D
				path = LevelData::OBJ_CMN_SD;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				YY -= 2;
				break;
			case 4: // U
				path = LevelData::OBJ_CMN_SU;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				YY += 2;
				break;
			case 5: // LD
				path = LevelData::OBJ_CMN_SRD;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				YY -= 2;
				break;
			case 6: // DL
				path = LevelData::OBJ_CMN_SUL;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				XX -= 2;
				break;
			case 7: // LU
				path = LevelData::OBJ_CMN_SRU;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				YY += 2;
				break;
			case 8: // UL
				path = LevelData::OBJ_CMN_SDL;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				XX -= 2;
				break;
			case 9: // RD
				path = LevelData::OBJ_CMN_SLD;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				YY -= 2;
				break;
			case 10: // DR
				path = LevelData::OBJ_CMN_SUR;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				XX += 2;
				break;
			case 11: // RU
				path = LevelData::OBJ_CMN_SLU;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				YY += 2;
				break;
			case 12: // UR
				path = LevelData::OBJ_CMN_SDR;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				XX += 2;
				break;
			case 13: // RE
				path = LevelData::OBJ_CMN_SE;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				break;
			case 14: // LE
				path = LevelData::OBJ_CMN_SE;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				break;
			case 15: // UE
				path = LevelData::OBJ_CMN_SE;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				break;
			case 16: // DE
				path = LevelData::OBJ_CMN_SE;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				break;
			}
		}
	} break;
	case 119: {
		if(EX > level.MapMoveBlk.size()) {
			return;
		}

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
			DrawImage(LevelData::OBJ_CMN_SS, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);

			uint32_t path = 0;
			switch(level.MapMoveBlk[EX - 1].Node[i].p1) {
			case 1: // L
				path = LevelData::OBJ_CMN_SL;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				XX -= 2;
				break;
			case 2: // R
				path = LevelData::OBJ_CMN_SR;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				XX += 2;
				break;
			case 3: // D
				path = LevelData::OBJ_CMN_SD;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				YY -= 2;
				break;
			case 4: // U
				path = LevelData::OBJ_CMN_SU;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				YY += 2;
				break;
			case 5: // LD
				path = LevelData::OBJ_CMN_SRD;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				YY -= 2;
				break;
			case 6: // DL
				path = LevelData::OBJ_CMN_SUL;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				XX -= 2;
				break;
			case 7: // LU
				path = LevelData::OBJ_CMN_SRU;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				YY += 2;
				break;
			case 8: // UL
				path = LevelData::OBJ_CMN_SDL;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				XX -= 2;
				break;
			case 9: // RD
				path = LevelData::OBJ_CMN_SLD;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				YY -= 2;
				break;
			case 10: // DR
				path = LevelData::OBJ_CMN_SUR;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				XX += 2;
				break;
			case 11: // RU
				path = LevelData::OBJ_CMN_SLU;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				YY += 2;
				break;
			case 12: // UR
				path = LevelData::OBJ_CMN_SDR;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				XX += 2;
				break;
			case 13: // RE
				path = LevelData::OBJ_CMN_SE;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				break;
			case 14: // LE
				path = LevelData::OBJ_CMN_SE;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				break;
			case 15: // UE
				path = LevelData::OBJ_CMN_SE;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				break;
			case 16: // DE
				path = LevelData::OBJ_CMN_SE;
				DrawImage(path, XX * Zm, (H - YY) * Zm, Zm * 2, Zm * 2);
				break;
			}
		}
	} break;
	}
	// Err:;
}

void LevelDrawer::DrawItem(const std::unordered_set<short>& K, bool L) {
	int tileY     = 0;
	int LX        = 0;
	int LY        = 0;
	int KY        = 0;
	uint32_t path = 0;

	for(int i = 0; i < level.MapHdr.ObjCount; i++) {
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
					path = level.LH.GameStyle | LevelData::OBJ_105A;
				} else {
					path = level.LH.GameStyle | LevelData::OBJ_105;
				}

				DrawImage(path, (float)(-1.5 + objX / 160.0) * Zm, H * Zm - (float)(0.5 + objY / 160.0) * Zm + KY,
					Zm * 3, Zm * 5);

				if(objCid != -1) {
					path = LevelData::GetIndex(level.LH.GameStyle, objCid,
						(level.MapObj[i].CFlag / 0x4) % 2 == 1 ? LevelData::A_ : LevelData::NONE, LevelData::CID);
					DrawImage(level.LH.GameStyle | path, LX, LY + KY, Zm, Zm);
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

						for(int j = 0; j < objW; j++) {
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
							for(int j = 1; j < objH; j++) {
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
							for(int j = 1; j < objH; j++) {
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

						for(int j = 0; j < objW; j++) {
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
						int TL;
						int TM;
						int TR;

						for(tileY = 0; tileY < objH; tileY++) {
							if(tileY == 0) {
								TL = level.LH.GameStyle | LevelData::OBJ_71;
								TM = level.LH.GameStyle | LevelData::OBJ_71A;
								TR = level.LH.GameStyle | LevelData::OBJ_71B;
							} else if(tileY == objH - 1) {
								TL = level.LH.GameStyle | LevelData::OBJ_71F;
								TM = level.LH.GameStyle | LevelData::OBJ_71G;
								TR = level.LH.GameStyle | LevelData::OBJ_71H;
							} else {
								TL = level.LH.GameStyle | LevelData::OBJ_71C;
								TM = level.LH.GameStyle | LevelData::OBJ_71D;
								TR = level.LH.GameStyle | LevelData::OBJ_71E;
							}

							for(int j = 0; j < objW; j++) {
								path = TM;
								if(j == 0) {
									path = TL;
								} else if(j == objW - 1) {
									path = TR;
								}

								DrawImage(path, (float)((j - 0.5 + objX / 160.0) * Zm),
									(H + tileY) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm, Zm);
							}
						}
						break;
					}
					case 17: {
						for(int j = 0; j < objW; j++) {
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
							for(int j = 0; j < objW; j++) {
								if(j == 0) {
									path = LevelData::GetIndex(level.LH.GameStyle, objID, LevelData::D_);
								} else if(j == objW - 1) {
									path = LevelData::GetIndex(level.LH.GameStyle, objID, LevelData::E_);
								} else {
									path = LevelData::GetIndex(level.LH.GameStyle, objID, LevelData::C_);
								}

								DrawImage(path, (float)((j - objW / 2.0 + objX / 160.0) * Zm),
									H * Zm - (float)((0.5 + objY / 160.0) * Zm), Zm, Zm);
							}
						} else {
							for(int j = 0; j < objW; j++) {
								if(j == 0) {
									path = LevelData::GetIndex(level.LH.GameStyle, objID, LevelData::A_);
								} else if(j == objW - 1) {
									path = LevelData::GetIndex(level.LH.GameStyle, objID, LevelData::B_);
								} else {
									path = LevelData::GetIndex(level.LH.GameStyle, objID);
								}

								DrawImage(path, (float)((j - objW / 2.0 + objX / 160.0) * Zm),
									H * Zm - (float)((0.5 + objY / 160.0) * Zm), Zm, Zm);
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
							path = LevelData::GetIndex(level.LH.GameStyle, objID);
							break;
						case 0x6400040:
							path = LevelData::GetIndex(level.LH.GameStyle, objID, LevelData::A_);
							break;
						case 0x6800040:
							path = LevelData::GetIndex(level.LH.GameStyle, objID, LevelData::B_);
							break;
						case 0x6C00040:
							path = LevelData::GetIndex(level.LH.GameStyle, objID, LevelData::C_);
							break;
						case 0x7000040:
							path = level.LH.GameStyle | LevelData::OBJ_66D;
							break;
						case 0x7400040:
							path = level.LH.GameStyle | LevelData::OBJ_66E;
							break;
						case 0x7800040:
							path = level.LH.GameStyle | LevelData::OBJ_66F;
							break;
						case 0x7C00040:
							path = level.LH.GameStyle | LevelData::OBJ_66G;
							break;
						}

						LX = std::round((float)((-0.5 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH / 2.0 + objY / 160.0) * Zm));

						DrawImage(path, (float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm * objW, Zm * objH);
						break;
					}
					case 83: //狼牙棒
					{
						switch(objFlag) {
						case 0x6000040:
							path = level.LH.GameStyle | LevelData::OBJ_83;
							break;
						case 0x6400040:
							path = level.LH.GameStyle | LevelData::OBJ_83A;
							break;
						case 0x6800040:
							path = level.LH.GameStyle | LevelData::OBJ_83B;
							break;
						case 0x6C00040:
							path = level.LH.GameStyle | LevelData::OBJ_83C;
							break;
						case 0x7000040:
							path = level.LH.GameStyle | LevelData::OBJ_83C;
							break;
						case 0x7400040:
							path = level.LH.GameStyle | LevelData::OBJ_83C;
							break;
						case 0x7800040:
							path = level.LH.GameStyle | LevelData::OBJ_83C;
							break;
						case 0x7C00040:
							path = level.LH.GameStyle | LevelData::OBJ_83C;
							break;
						}
						LX = std::round((float)((-0.5 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH / 2.0 + objY / 160.0) * Zm));

						DrawImage(path, (float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm * objW, Zm * objH);
						break;
					}
					case 64: {
						for(int j = 1; j <= objH; j++) {
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
						int PP = 0;
						if((objFlag / 0x4) % 2 == 1) {
							PP = 1;
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
							path = level.LH.GameStyle | LevelData::OBJ_108A;
						} else {
							path = level.LH.GameStyle | LevelData::OBJ_108;
						}

						LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
						LY = std::round(
							(H + (std::round(objH) / 2) / 2.0) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(path, (float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);

						break;
					}
					case 106: //树
					{
						LX = std::round((float)((-0.5 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH + 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(level.LH.GameStyle | LevelData::OBJ_106, (float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * 4, Zm * 4);

						for(int j = 4; j < objH; j++) {
							DrawImage(level.LH.GameStyle | LevelData::OBJ_106A,
								(float)((-objW / 2.0 + 1.5 + objX / 160.0) * Zm),
								(H + j) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm, Zm);
						}
						DrawImage(level.LH.GameStyle | LevelData::OBJ_106B,
							(float)((-objW / 2.0 + 1 + objX / 160.0) * Zm),
							H * Zm - (float)((-0.5 + objY / 160.0) * Zm) + KY, Zm * 2, Zm);
						break;
					}
					case 85:
					case 119: {
						//机动砖 轨道砖
						if((objFlag / 0x4) % 2 == 1) {
							path = level.LH.GameStyle | LevelData::OBJ_85A;
						} else {
							if(objID == 85) {
								path = level.LH.GameStyle | LevelData::OBJ_85;
							} else {
								path = level.LH.GameStyle | LevelData::OBJ_119;
							}
						}

						LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
						LY = std::round(
							(H + (std::round(objH) / 2) / 2.0) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(path, (float)((-objW / 2.0 + objX / 160.0) * Zm),
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

							for(int j = 1; j <= objW - 2; j++) {
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

							for(int j = 1; j <= objW - 2; j++) {
								DrawTile(C2.X + 4, C2.Y, 1, 2, (float)((j - 0.5 + objX / 160.0) * Zm),
									(H - 1) * Zm - (float)((-0.5 - j + objH + objY / 160.0) * Zm), Zm, Zm * 2);
							}
						}

						if((objFlag / 0x40000) % 2 == 0) {
							if((objFlag / 0x8) % 2 == 1) {
								DrawImage(LevelData::OBJ_CMN_A1, LX, LY, Zm, Zm);
							} else {
								DrawImage(LevelData::OBJ_CMN_A0, LX, LY, Zm, Zm);
							}
						} else {
							if((objFlag / 0x8) % 2 == 1) {
								DrawImage(LevelData::OBJ_CMN_A3, LX, LY, Zm, Zm);
							} else {
								DrawImage(LevelData::OBJ_CMN_A2, LX, LY, Zm, Zm);
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

						for(int j = 0; j < objW; j++) {
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
									DrawImage(
										LevelData::OBJ_CMN_A1, LX + std::round((-0.5 + objW / 2) * Zm), LY, Zm, Zm);
								} else {
									DrawImage(
										LevelData::OBJ_CMN_A0, LX + std::round((-0.5 + objW / 2) * Zm), LY, Zm, Zm);
								}
							} else {
								if((objFlag / 0x8) % 2 == 1) {
									DrawImage(
										LevelData::OBJ_CMN_A3, LX + std::round((-0.5 + objW / 2) * Zm), LY, Zm, Zm);
								} else {
									DrawImage(
										LevelData::OBJ_CMN_A2, LX + std::round((-0.5 + objW / 2) * Zm), LY, Zm, Zm);
								}
							}
						}
						break;
					}
					case 9: {
						level.ObjLinkType[objLid + 1] = 9;
						int PP                        = ((objFlag / 0x10000) % 0x10) / 4;
						switch(objFlag % 0x80) {
						case 0x0: { // R
							LX = std::round((float)((objH - 1 - 1 - 0.5 + objX / 160.0) * Zm));
							LY = std::round(H * Zm - (float)((objY / 160.0) * Zm));

							for(int j = 0; j <= (objH - 2); j++) {
								DrawTile(level.PipeLoc[PP][4].X, level.PipeLoc[PP][4].Y, 1, 2,
									(float)((j - 0.5 + objX / 160.0) * Zm), H * Zm - (float)((0.5 + objY / 160.0) * Zm),
									Zm, 2 * Zm);
							}
							DrawTile(level.PipeLoc[PP][3].X, level.PipeLoc[PP][3].Y, 1, 2,
								(float)((objH - 1.5 + objX / 160.0) * Zm), H * Zm - (float)((0.5 + objY / 160.0) * Zm),
								Zm, 2 * Zm);
						} break;
						case 0x20: { // L
							LX = std::round((float)((-objH + 1 + 1 - 0.5 + objX / 160.0) * Zm));
							LY = std::round(H * Zm - (float)((1 + objY / 160.0) * Zm));

							for(int j = 0; j <= (objH - 2); j++) {
								DrawTile(level.PipeLoc[PP][4].X, level.PipeLoc[PP][4].Y, 1, 2,
									(float)((-j - 0.5 + objX / 160.0) * Zm),
									H * Zm - (float)((1.5 + objY / 160.0) * Zm), Zm, 2 * Zm);
							}
							DrawTile(level.PipeLoc[PP][2].X, level.PipeLoc[PP][2].Y, 1, 2,
								(float)((-objH + 0.5 + objX / 160.0) * Zm), H * Zm - (float)((1.5 + objY / 160.0) * Zm),
								Zm, 2 * Zm);
						} break;
						case 0x40: { // U
							LX = std::round((float)((+objX / 160.0) * Zm));
							LY = (H - objH + 1 + 1) * Zm - (float)((0.5 + objY / 160.0) * Zm);

							for(int j = 0; j <= (objH - 2); j++) {
								DrawTile(level.PipeLoc[PP][5].X, level.PipeLoc[PP][5].Y, 2, 1,
									(float)((-0.5 + objX / 160.0) * Zm),
									(H - j) * Zm - (float)((0.5 + objY / 160.0) * Zm), 2 * Zm, Zm);
							}
							DrawTile(level.PipeLoc[PP][0].X, level.PipeLoc[PP][0].Y, 2, 1,
								(float)((-0.5 + objX / 160.0) * Zm),
								(H - objH + 1) * Zm - (float)((0.5 + objY / 160.0) * Zm), 2 * Zm, Zm);
						} break;
						case 0x60: { // D
							LX = std::round((float)((-1 + objX / 160.0) * Zm));
							LY = (H + objH - 1 - 1) * Zm - (float)((0.5 + objY / 160.0) * Zm);

							for(int j = 0; j <= (objH - 2); j++) {
								DrawTile(level.PipeLoc[PP][5].X, level.PipeLoc[PP][5].Y, 2, 1,
									(float)((-1.5 + objX / 160.0) * Zm),
									(H + j) * Zm - (float)((0.5 + objY / 160.0) * Zm), 2 * Zm, Zm);
							}
							DrawTile(level.PipeLoc[PP][1].X, level.PipeLoc[PP][1].Y, 2, 1,
								(float)((-1.5 + objX / 160.0) * Zm),
								(H + objH - 1) * Zm - (float)((0.5 + objY / 160.0) * Zm), 2 * Zm, Zm);
						} break;
						}

						int cmnId = objFlag % 0x1000000 / 0x100000 - 1;
						if(cmnId != -1) {
							path = LevelData::GetIndex(0, LevelData::C0 + cmnId, LevelData::NONE, LevelData::CMN);
						}

						if(path) {
							DrawImage(path, LX, LY, Zm, Zm);
						}

						break;
					}
					case 55: {
						//门
						if((objFlag / 0x40000) % 2 == 1) {
							path = level.LH.GameStyle | LevelData::OBJ_55A;
						} else if((objFlag / 0x80000) % 2 == 1) {
							path = level.LH.GameStyle | LevelData::OBJ_55B;
						} else {
							path = level.LH.GameStyle | LevelData::OBJ_55;
						}

						DrawImage(path, (float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm * objW, Zm * objH);

						int cmnId = objFlag % 0x800000 / 0x200000;
						path      = LevelData::GetIndex(0, LevelData::C0 + cmnId, LevelData::NONE, LevelData::CMN);

						DrawImage(path, (float)((-objW / 2.0 + objX / 160.0) * Zm),
							(H + 1) * Zm - (float)((objH + objY / 160.0) * Zm), Zm, Zm);
						break;
					}
					case 97: {
						//传送箱
						if((objFlag / 0x4) % 2 == 1) {
							path = level.LH.GameStyle | LevelData::OBJ_97A;
						} else {
							path = level.LH.GameStyle | LevelData::OBJ_97;
						}

						DrawImage(path, (float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm * objW, Zm * objH);

						int cmnId = objFlag % 0x800000 / 0x200000;
						path      = LevelData::GetIndex(0, LevelData::C0 + cmnId, LevelData::NONE, LevelData::CMN);

						DrawImage(path, (float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm, Zm);
						break;
					}
					case 84: {
						for(int j = 0; j < objW; j++) {
							if((objFlag / 0x4) % 2 == 1) {
								DrawImage(level.LH.GameStyle | LevelData::OBJ_84A,
									(float)((j - objW / 2.0 + objX / 160.0) * Zm),
									H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm, Zm);
							} else {
								DrawImage(level.LH.GameStyle | LevelData::OBJ_84,
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
						if(objID == 68) {
							path = level.LH.GameStyle | LevelData::OBJ_68;
						} else {
							path = level.LH.GameStyle | LevelData::OBJ_82;
						}

						LX = std::round((float)((-0.5 + objX / 160.0) * Zm));
						LY = std::round((H - 1.5) * Zm - (float)((objY / 160.0) * Zm) + KY);

						DrawImageOpacity(path, 0.7, (float)((-objW / 2.0 + objX / 160.0) * Zm),
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
						path = LevelData::GetIndex(
							level.LH.GameStyle, objID, (objFlag / 0x4) % 2 == 1 ? LevelData::A_ : LevelData::NONE);

						LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
						LY = std::round(
							(H + (std::round(objH) / 2) / 2.0) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(path, (float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);
						break;
					}
					case 33: {
						// 1UP
						if(level.MapHdr.Theme == 0 && level.MapHdr.Flag == 2) {
							path = level.LH.GameStyle | LevelData::OBJ_33A;
						} else {
							path = level.LH.GameStyle | LevelData::OBJ_33;
						}
						LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
						LY = std::round(
							(H + (std::round(objH) / 2) / 2.0) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(path, (float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);

						break;
					}
					case 74: {
						//加邦
						if((objFlag / 0x4) % 2 == 1) {
							if(level.MapHdr.Theme == 6) {
								path = level.LH.GameStyle | LevelData::OBJ_74B;
							} else {
								path = level.LH.GameStyle | LevelData::OBJ_74A;
							}
						} else {
							path = level.LH.GameStyle | LevelData::OBJ_74;
						}

						LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
						LY = std::round(
							(H + (std::round(objH) / 2) / 2.0) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(path, (float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);

						break;
					}
					case 42: {
						//飞机
						if((objFlag / 0x4 % 2 == 1) || (objFlag / 0x40000 % 2 == 1)) {
							path = level.LH.GameStyle | LevelData::OBJ_42A;
						} else {
							path = level.LH.GameStyle | LevelData::OBJ_42;
						}
						LX = std::round((float)((-1 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
						LY = (H + objH / 2.0 - 0.5) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY;

						DrawImage(path, (float)((-1 + objX / 160.0) * Zm),
							(H + objH / 2.0 - 0.5) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * 2,
							Zm * 2);

						break;
					}
					case 34: {
						//火花
						if((objFlag / 0x4) % 2 == 1) {
							if((objFlag / 0x40000) % 2 == 1) {
								path = level.LH.GameStyle | LevelData::OBJ_34C;
							} else {
								path = level.LH.GameStyle | LevelData::OBJ_34A;
							}
						} else {
							if((objFlag / 0x40000) % 2 == 1) {
								path = level.LH.GameStyle | LevelData::OBJ_34B;
							} else {
								path = level.LH.GameStyle | LevelData::OBJ_34;
							}
						}

						LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
						LY = std::round(
							(H + (std::round(objH) / 2) / 2.0) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(path, (float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);

						break;
					}
					case 81:
					case 116: {
						// USA  锤子

						if((objFlag / 0x40000) % 2 == 1) {
							if(objID == 81) {
								path = level.LH.GameStyle | LevelData::OBJ_81A;
							} else {
								path = level.LH.GameStyle | LevelData::OBJ_116A;
							}
						} else {
							if(objID == 81) {
								path = level.LH.GameStyle | LevelData::OBJ_81;
							} else {
								path = level.LH.GameStyle | LevelData::OBJ_116;
							}
						}

						LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
						LY = std::round(
							(H + (std::round(objH) / 2) / 2.0) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(path, (float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);

						break;
					}
					case 44: {
						//大蘑菇

						if((objFlag / 0x40000) % 2 == 1) {
							path = level.LH.GameStyle | LevelData::OBJ_44A;
						} else {
							path = level.LH.GameStyle | LevelData::OBJ_44;
						}

						LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
						LY = std::round(
							(H + (std::round(objH) / 2) / 2.0) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(path, (float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);

						break;
					}
					case 12: {
						//咚咚
						LX = std::round((float)((-0.5 + objX / 160.0) * Zm));
						LY = (H + objH / 2.0 - 0.5) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY;

						DrawImageOpacity(level.LH.GameStyle | LevelData::OBJ_12, 0.7,
							(float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);

						if(objLid == -1) {
							switch((objFlag) % 0x100) {
							case 0x40:
							case 0x42:
							case 0x44:
								DrawImage(LevelData::OBJ_CMN_E1, LX, LY, Zm, Zm);
								break;
							case 0x48:
							case 0x4A:
							case 0x4C:
								DrawImage(LevelData::OBJ_CMN_E2, LX, LY, Zm, Zm);
								break;
							case 0x50:
							case 0x52:
							case 0x54:
								DrawImage(LevelData::OBJ_CMN_E0, LX, LY, Zm, Zm);
								break;
							case 0x58:
							case 0x5A:
							case 0x5C:
								DrawImage(LevelData::OBJ_CMN_E3, LX, LY, Zm, Zm);
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
								path = level.LH.GameStyle | LevelData::OBJ_41D;
							} else {
								path = level.LH.GameStyle | LevelData::OBJ_41;
							}
							break;
						default:
							if((objFlag / 0x4) % 2 == 1) {
								path = level.LH.GameStyle | LevelData::OBJ_41A;
							} else if((objFlag / 0x1000000) % 0x8 == 0x4) {
								path = level.LH.GameStyle | LevelData::OBJ_41C;
							} else if((objFlag / 0x100) % 2 == 1) {
								path = level.LH.GameStyle | LevelData::OBJ_41B;
							} else {
								path = level.LH.GameStyle | LevelData::OBJ_41;
							}
							break;
						}
						DrawImage(path, LX, LY, Zm * objW, Zm * objH);

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
							if(objID == 28) {
								path = level.LH.GameStyle | LevelData::OBJ_28A;
							} else if(objID == 25) {
								path = level.LH.GameStyle | LevelData::OBJ_25A;
							} else {
								path = level.LH.GameStyle | LevelData::OBJ_18A;
							}
						} else if((objFlag / 0x1000000) % 8 == 0x6) {
							if(objID == 28) {
								path = level.LH.GameStyle | LevelData::OBJ_28;
							} else if(objID == 25) {
								path = level.LH.GameStyle | LevelData::OBJ_25;
							} else {
								path = level.LH.GameStyle | LevelData::OBJ_18;
							}
						} else {
							if(objID == 28) {
								path = level.LH.GameStyle | LevelData::OBJ_28B;
							} else if(objID == 25) {
								path = level.LH.GameStyle | LevelData::OBJ_25B;
							} else {
								path = level.LH.GameStyle | LevelData::OBJ_18B;
							}
						}

						DrawImage(path, (float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);

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
								DrawImage(level.LH.GameStyle | LevelData::OBJ_40B0, LX, LY, Zm * objW, Zm * objH);
								break;
							case 0x2: // R
								DrawImage(level.LH.GameStyle | LevelData::OBJ_40B2, LX, LY, Zm * objW, Zm * objH);
								break;
							case 0x4: // D
								DrawImage(level.LH.GameStyle | LevelData::OBJ_40B4, LX, LY, Zm * objW, Zm * objH);
								break;
							case 0x6: // U
								DrawImage(level.LH.GameStyle | LevelData::OBJ_40B6, LX, LY, Zm * objW, Zm * objH);
								break;
							}
						} else {
							switch((objFlag / 0x1000000) % 8) {
								//方向6上 4下 0左 2右
							case 0x0: // L
								DrawImage(level.LH.GameStyle | LevelData::OBJ_40A0, LX, LY, Zm * objW, Zm * objH);
								break;
							case 0x2: // R
								DrawImage(level.LH.GameStyle | LevelData::OBJ_40A2, LX, LY, Zm * objW, Zm * objH);
								break;
							case 0x4: // D
								DrawImage(level.LH.GameStyle | LevelData::OBJ_40A0, LX, LY, Zm * objW, Zm * objH);
								break;
							case 0x6: // U
								DrawImage(level.LH.GameStyle | LevelData::OBJ_40A6, LX, LY, Zm * objW, Zm * objH);
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
							switch((objFlag / 0x1000000) % 0x8) {
							case 0x0:
								path = level.LH.GameStyle | LevelData::OBJ_2B0;
								break;
							case 0x2:
								path = level.LH.GameStyle | LevelData::OBJ_2B2;
								break;
							case 0x4:
								path = level.LH.GameStyle | LevelData::OBJ_2B4;
								break;
							case 0x6:
								path = level.LH.GameStyle | LevelData::OBJ_2B6;
								break;
							}
						} else {
							switch((objFlag / 0x1000000) % 0x8) {
							case 0x0:
								path = level.LH.GameStyle | LevelData::OBJ_2A0;
								break;
							case 0x2:
								path = level.LH.GameStyle | LevelData::OBJ_2A2;
								break;
							case 0x4:
								path = level.LH.GameStyle | LevelData::OBJ_2A4;
								break;
							case 0x6:
								path = level.LH.GameStyle | LevelData::OBJ_2A6;
								break;
							}
						}

						switch((objFlag / 0x1000000) % 0x8) {
							//方向6上 4下 0左 2右
						case 0x0: // L
							LX = std::round((float)((objH / 2.0 - 1 + objX / 160.0) * Zm));
							LY = (H + objW + (std::round(objW) / 2) / 2.0) * Zm
								 - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY;

							DrawImage(path, (float)((-objW * 3 / 2.0 + objX / 160.0) * Zm),
								(H + objW) * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW * 2,
								Zm * objH);
							break;
						case 0x2: // R
							LX = std::round((float)((-objW / 2.0 + objX / 160.0) * Zm));
							LY = (H + objW + (std::round(objW) / 2) / 2.0) * Zm
								 - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY;

							DrawImage(path, (float)((-objW / 2.0 + objX / 160.0) * Zm),
								(H + objW) * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW * 2,
								Zm * objH);
							break;
						case 0x4: // D
							LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
							LY = (H + objW) * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY;

							DrawImage(path, (float)((-objW / 2.0 + objX / 160.0) * Zm),
								(H + objW) * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW,
								Zm * objH * 2);
							break;
						case 0x6: // U
							LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
							LY = (H + objH + (std::round(objW) / 2)) * Zm
								 - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY;

							DrawImage(path, (float)((-objW / 2.0 + objX / 160.0) * Zm),
								H * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW,
								Zm * objH * 2);
							break;
						}
						break;
					}
					case 107: {
						if((objFlag / 0x4) % 2 == 1) {
							switch(objFlag / 0x1000000) {
							case 0x0:
								path = level.LH.GameStyle | LevelData::OBJ_107EC;
								break;
							case 0x2:
								path = level.LH.GameStyle | LevelData::OBJ_107EA;
								break;
							case 0x4:
								path = level.LH.GameStyle | LevelData::OBJ_107EB;
								break;
							case 0x6:
								path = level.LH.GameStyle | LevelData::OBJ_107E;
								break;
							}
						} else {
							switch(objFlag / 0x1000000) {
							case 0x0:
								path = level.LH.GameStyle | LevelData::OBJ_107C;
								break;
							case 0x2:
								path = level.LH.GameStyle | LevelData::OBJ_107A;
								break;
							case 0x4:
								path = level.LH.GameStyle | LevelData::OBJ_107B;
								break;
							case 0x6:
								path = level.LH.GameStyle | LevelData::OBJ_107;
								break;
							}
						}

						LX = std::round((float)((-objW / 2.0 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(path, LX, LY, Zm * 2, Zm * 2);

						DrawCrp(level.MapObj[i].Ex, objX, objY);
						break;
					}
					case 32: {
						switch(objFlag) {
						case 0x6000040:
							path = level.LH.GameStyle | LevelData::OBJ_32;
							break;
						case 0x6400040:
							path = level.LH.GameStyle | LevelData::OBJ_32A;
							break;
						case 0x6800040:
							path = level.LH.GameStyle | LevelData::OBJ_32B;
							break;
						case 0x6C00040:
							path = level.LH.GameStyle | LevelData::OBJ_32C;
							break;
						case 0x6000044:
							path = level.LH.GameStyle | LevelData::OBJ_32D;
							break;
						case 0x6400044:
							path = level.LH.GameStyle | LevelData::OBJ_32E;
							break;
						case 0x6800044:
							path = level.LH.GameStyle | LevelData::OBJ_32F;
							break;
						case 0x6C00044:
							path = level.LH.GameStyle | LevelData::OBJ_32G;
							break;
						case 0x7000040:
							path = level.LH.GameStyle | LevelData::OBJ_32H;
							break;
						}

						LX = std::round((float)((-objW / 2.0 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(path, LX, LY, Zm * objW, Zm * objH);

						break;
					}
					case 1:
					case 46:
					case 52:
					case 58: {
						//慢慢龟，碎碎龟，花花，扳手
						path = LevelData::GetIndex(
							level.LH.GameStyle, objID, (objFlag / 0x4) % 2 == 1 ? LevelData::A_ : LevelData::NONE);

						LX = std::round((float)((-objW / 2.0 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(path, LX, LY, Zm * objW, Zm * objH * 2);

						LX = std::round((float)((-objW / 2.0 + (std::round(objW) / 2) / 2.0 + objX / 160.0) * Zm));
						LY = std::round(
							(H + (std::round(objH) / 2) / 2.0) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);
						break;
					}
					case 30: {
						//裁判
						LX = std::round((float)((-objW / 2.0 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH - 1 + objY / 160.0) * Zm) + KY);

						DrawImage(level.LH.GameStyle | LevelData::OBJ_30, LX, LY, Zm, Zm * 2);
						DrawImage(level.LH.GameStyle | LevelData::OBJ_31, LX - Zm / 2, LY + Zm / 2, Zm * 2, Zm);
						break;
					}
					case 31: {
						//裁判云
						level.ObjLinkType[objLid + 1] = 31;
						LX                            = std::round((float)((-objW / 2.0 - 0.5 + objX / 160.0) * Zm));
						LY                            = std::round(H * Zm - (float)((0.5 + objY / 160.0) * Zm));

						DrawImage(level.LH.GameStyle | LevelData::OBJ_31, LX, LY, Zm * 2, Zm);

						break;
					}
					case 45: //鞋 耀西
					{
						switch(level.LH.GameStyle) {
						case 21847:
						case 22349: // U W
							if(objW == 2) {
								path = level.LH.GameStyle | LevelData::OBJ_45A;
							} else {
								path = level.LH.GameStyle | LevelData::OBJ_45;
							}
							break;
						default:
							if((objFlag / 0x4) % 2 == 1) {
								path = level.LH.GameStyle | LevelData::OBJ_45A;
							} else {
								path = level.LH.GameStyle | LevelData::OBJ_45;
							}
							break;
						}

						LX = std::round((float)((-objW / 2.0 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(path, LX, LY, Zm * objW, Zm * objH * 2);

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
							path = level.LH.GameStyle | LevelData::OBJ_62A;
							break;
						default:
							path = level.LH.GameStyle | LevelData::OBJ_62;
							break;
						}
						DrawImage(path, (float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);

						break;
					}
					case 3: {
						//德莱文
						switch(level.LH.GameStyle) {
						case 22323:
							if((objFlag / 0x4) % 2 == 1) {
								LX = std::round((float)((-objW / 2.0 + 0.5 + objX / 160.0) * Zm));
								LY = std::round(H * Zm - (float)((1 + objY / 160.0) * Zm) + KY);

								DrawImage(level.LH.GameStyle | LevelData::OBJ_3B,
									(float)((-objW / 2.0 + objX / 160.0) * Zm),
									(H)*Zm - (float)((1.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);
							} else {
								LX = std::round((float)((-objW / 2.0 + objX / 160.0) * Zm));
								LY = std::round(H * Zm - (float)((objH * 2.0 - 1.5 + objY / 160.0) * Zm) + KY);

								DrawImage(level.LH.GameStyle | LevelData::OBJ_3,
									(float)((-objW / 2.0 + objX / 160.0) * Zm),
									(H + 2) * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW,
									Zm * objH);
							}
							break;
						default:
							if((objFlag / 0x4000) % 2 == 1) {
								LX = std::round((float)((-objW / 2.0 + 0.5 + objX / 160.0) * Zm));
								LY = std::round(H * Zm - (float)((1 + objY / 160.0) * Zm) + KY);

								DrawImage(level.LH.GameStyle | LevelData::OBJ_3A,
									(float)((-objW / 2.0 + objX / 160.0) * Zm),
									H * Zm - (float)((1.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);
							} else {
								LX = std::round((float)((-objW / 2.0 + objX / 160.0) * Zm));
								LY = std::round(H * Zm - (float)((objH * 2.0 - 1.5 + objY / 160.0) * Zm) + KY);

								DrawImage(level.LH.GameStyle | LevelData::OBJ_3,
									(float)((-objW / 2.0 + objX / 160.0) * Zm),
									H * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW,
									2 * Zm * objH);
							}
							break;
						}

						break;
					}
					case 13: {
						if((objFlag / 0x4) % 2 == 1) {
							path = level.LH.GameStyle | LevelData::OBJ_13B;
						} else {
							path = level.LH.GameStyle | LevelData::OBJ_13;
						}

						LX = std::round((float)((-0.5 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImageOpacity(path, 0.7, LX, LY, Zm * objW, Zm * 2);

						for(int j = 2; j < objH; j++) {
							if((objFlag / 0x4) % 2 == 1) {
								DrawImageOpacity(level.LH.GameStyle | LevelData::OBJ_13C, 0.7, LX, LY + j * Zm, Zm, Zm);
							} else {
								DrawImageOpacity(level.LH.GameStyle | LevelData::OBJ_13A, 0.7, LX, LY + j * Zm, Zm, Zm);
							}
						}

						break;
					}
					case 39: {
						//魔法师
						LX = std::round((float)((2.0 - objW / 2.0 - objW + objX / 160.0) * Zm));
						LY = std::round((H + 1) * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(level.LH.GameStyle | LevelData::OBJ_39, LX - Zm - Zm, LY - Zm + KY,
							2 * Zm * objW + KY, 2 * Zm * objH);
						break;
					}
					case 47: {
						float ANG = 0;
						LX        = std::round((float)((-objW / 2.0 + objX / 160.0) * Zm));
						LY        = std::round(H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm));

						switch(objFlag / 0x100000) {
						// UDLR
						case 0xC:
						case 0x30:
						case 0x64:
							ANG = 0.0;
							break;
						case 0x10:
						case 0x2C:
						case 0x44:
							ANG = 3.14159;
							break;
						case 0x4:
						case 0x4C:
						case 0x70:
							ANG = 4.71239;
							break;
						case 0x24:
						case 0x50:
						case 0x6C:
							ANG = 1.5708;
							// UL UR DL DR
							break;
						case 0x8:
						case 0x60:
							ANG = 5.49779;
							break;
						case 0x20:
						case 0x68:
							ANG = 0.785398;
							break;
						case 0x0:
						case 0x48:
							ANG = 3.92699;
							break;
						case 0x28:
						case 0x40:
							ANG = 2.35619;
							break;
						}

						int flag = (objFlag / 0x4) % 2 == 1;
						if(flag) {
							path = level.LH.GameStyle | LevelData::OBJ_47E;
						} else {
							path = level.LH.GameStyle | LevelData::OBJ_47;
						}

						DrawImageRotate(path, ANG, LX + std::round(objW * Zm) / 2.0 - std::round(objW * Zm) / 2,
							LY + std::round(objH * Zm) / 2.0 - std::round(objH * Zm) / 2, Zm * objW, Zm * objH);

						switch(objFlag / 0x100000) {
						case 0x0:
						case 0x4:
						case 0x8:
						case 0xC:
						case 0x10:
							if(flag) {
								path = level.LH.GameStyle | LevelData::OBJ_47ED;
							} else {
								path = level.LH.GameStyle | LevelData::OBJ_47D;
							}
							break;
						case 0x2:
						case 0x24:
						case 0x28:
						case 0x2C:
						case 0x30:
							if(flag) {
								path = level.LH.GameStyle | LevelData::OBJ_47EB;
							} else {
								path = level.LH.GameStyle | LevelData::OBJ_47B;
							}
							break;
						case 0x40:
						case 0x44:
						case 0x48:
						case 0x4C:
						case 0x50:
							if(flag) {
								path = level.LH.GameStyle | LevelData::OBJ_47EC;
							} else {
								path = level.LH.GameStyle | LevelData::OBJ_47C;
							}
							break;
						default:
							if(flag) {
								path = level.LH.GameStyle | LevelData::OBJ_47EA;
							} else {
								path = level.LH.GameStyle | LevelData::OBJ_47A;
							}
							break;
						}

						DrawImage(path, (float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm * objW, Zm * objH);
						break;
					}
					case 61: {
						//汪汪
						LX = std::round((float)((-0.5 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((0.5 + objY / 160.0) * Zm) + KY);
						if((objFlag / 0x4) % 2 == 0) {
							DrawImage(level.LH.GameStyle | LevelData::OBJ_61A, (float)((-0.5 + objX / 160.0) * Zm),
								H * Zm - (float)((0.5 + objY / 160.0) * Zm) + KY, Zm, Zm);
						}
						DrawImage(level.LH.GameStyle | LevelData::OBJ_61, (float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);
						break;
					}
					case 78: {
						//仙人掌
						LX = std::round((float)(-objW / 2.0 + objX / 160.0) * Zm);
						LY = std::round((H + 1) * Zm - (float)((objH + std::round(objY) / 160.0) * Zm) + KY);

						for(int j = 0; j < objH; j++) {
							if(j == objH - 1) {
								DrawImage(level.LH.GameStyle | LevelData::OBJ_78,
									(float)(-objW / 2.0 + objX / 160.0) * Zm,
									(H - 1) * Zm - (float)((j + std::round(objY) / 160.0) * Zm) + KY, Zm, Zm);
							} else {
								DrawImage(level.LH.GameStyle | LevelData::OBJ_78A,
									(float)(-objW / 2.0 + objX / 160.0) * Zm,
									(H - 1) * Zm - (float)((j + std::round(objY) / 160.0) * Zm) + KY, Zm, Zm);
							}
						}
						break;
					}
					case 111: {
						if((objFlag / 0x40000) % 2 == 1) {
							path = level.LH.GameStyle | LevelData::OBJ_111B;
						} else if((objFlag / 0x80000) % 2 == 1) {
							path = level.LH.GameStyle | LevelData::OBJ_111A;
						} else {
							path = level.LH.GameStyle | LevelData::OBJ_111;
						}

						LX = std::round((float)((-objW + 0.5 + objX / 160.0) * Zm));
						LY = std::round((H + 1) * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(path, (float)((-objW + objX / 160.0) * Zm),
							H * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY, 2 * Zm * objW,
							2 * Zm * objH);
						break;
					}
					case 70: {
						if((objFlag / 0x40000) % 2 == 1) {
							path = level.LH.GameStyle | LevelData::OBJ_70A;
						} else if((objFlag / 0x80000) % 2 == 1) {
							path = level.LH.GameStyle | LevelData::OBJ_70B;
						} else {
							path = level.LH.GameStyle | LevelData::OBJ_70;
						}

						DrawImage(path, (float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);

						LX = std::round((float)((-objW / 2.0 + 0.5 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH - 1 + objY / 160.0) * Zm) + KY);
						break;
					}
					case 110: {
						//刺方块
						if((objFlag / 0x40000) % 2 == 1) {
							path = level.LH.GameStyle | LevelData::OBJ_110A;
						} else if((objFlag / 0x80000) % 2 == 1) {
							path = level.LH.GameStyle | LevelData::OBJ_110B;
						} else {
							path = level.LH.GameStyle | LevelData::OBJ_110;
						}

						DrawImage(path, (float)((-objW / 2.0 + 0.5 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);
						break;
					}
					case 98: {
						LX = std::round((float)((-objW + 0.5 + objX / 160.0) * Zm));
						LY = std::round((H + 1) * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(level.LH.GameStyle | LevelData::OBJ_98, (float)((-objW + objX / 160.0) * Zm),
							H * Zm - (float)((objH * 2.0 - 0.5 + objY / 160.0) * Zm) + KY, 2 * Zm * objW,
							2 * Zm * objH);
						break;
					}
					case 103: {
						//骨鱼
						LX = std::round((float)((-objW + 0.5 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);

						DrawImage(level.LH.GameStyle | LevelData::OBJ_103, (float)((-objW + objX / 160.0) * Zm) + KY,
							LY, 2 * Zm * objW, Zm * objH);

						break;
					}
					case 91: {
						for(int j = 0; j < objW; j++) {
							if(j == 0) {
								DrawImage(level.LH.GameStyle | LevelData::OBJ_91A,
									(float)((j - std::round(objW) / 2 + std::round(objX) / 160.0) * Zm),
									H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm, Zm);
							} else if(j == objW - 1) {
								DrawImage(level.LH.GameStyle | LevelData::OBJ_91B,
									(float)((j - std::round(objW) / 2 + std::round(objX) / 160.0) * Zm),
									H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm, Zm);
							} else {
								DrawImage(level.LH.GameStyle | LevelData::OBJ_91,
									(float)((j - std::round(objW) / 2 + std::round(objX) / 160.0) * Zm),
									H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm, Zm);
							}
						}

						DrawImage(level.LH.GameStyle | LevelData::OBJ_91C, (float)((-0.5 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm, Zm);

						LX = std::round((float)((-0.5 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm));
						break;
					}
					case 36: {
						if((objFlag / 0x4) % 2 == 1) {
							path = level.LH.GameStyle | LevelData::OBJ_36A;
						} else {
							path = level.LH.GameStyle | LevelData::OBJ_36;
						}

						if(objLid != -1) {
							objW = 1;
						}

						for(int j = 0; j < objW; j++) {
							DrawImage(path, (float)((j - std::round(objW) / 2 + std::round(objX) / 160.0) * Zm),
								H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm, Zm);
						}

						LX = std::round((float)((objW - 1 - std::round(objW) / 2.0 + std::round(objX) / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY);
						break;
					}
					case 11: {
						//升降台
						LX = std::round((float)((-0.5 + objX / 160.0) * Zm));
						LY = std::round(H * Zm - (float)((0.5 + objY / 160.0) * Zm) + KY);

						for(int j = 0; j < objW; j++) {
							if((objFlag / 0x4) % 2 == 0) {
								if(j == 0) {
									path = level.LH.GameStyle | LevelData::OBJ_11A;
								} else if(j == objW - 1) {
									path = level.LH.GameStyle | LevelData::OBJ_11B;
								} else {
									path = level.LH.GameStyle | LevelData::OBJ_11;
								}

								DrawImage(path, (float)((j - objW / 2.0 + objX / 160.0) * Zm),
									H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm, Zm);
							} else {
								if(j == 0) {
									path = level.LH.GameStyle | LevelData::OBJ_11D;
								} else if(j == objW - 1) {
									path = level.LH.GameStyle | LevelData::OBJ_11E;
								} else {
									path = level.LH.GameStyle | LevelData::OBJ_11C;
								}

								DrawImage(path, (float)((j - objW / 2.0 + objX / 160.0) * Zm),
									H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm, Zm);
							}
						}

						if((objFlag / 0x4) % 2 == 0) {
							switch((objFlag) % 0x100) {
							case 0x40:
								DrawImage(LevelData::OBJ_CMN_D1, LX, LY, Zm, Zm);
								break;
							case 0x48:
								DrawImage(LevelData::OBJ_CMN_D2, LX, LY, Zm, Zm);
								break;
							case 0x50:
								DrawImage(LevelData::OBJ_CMN_D0, LX, LY, Zm, Zm);
								break;
							case 0x58:
								DrawImage(LevelData::OBJ_CMN_D3, LX, LY, Zm, Zm);
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
							path = level.LH.GameStyle | LevelData::OBJ_54;
							break;
						case 0x48:
							path = level.LH.GameStyle | LevelData::OBJ_54A;
							break;
						case 0x50:
							path = level.LH.GameStyle | LevelData::OBJ_54B;
							break;
						case 0x58:
							path = level.LH.GameStyle | LevelData::OBJ_54C;
							break;
						case 0x44:
							path = level.LH.GameStyle | LevelData::OBJ_54;
							break;
						case 0x4C:
							path = level.LH.GameStyle | LevelData::OBJ_54A;
							break;
						case 0x54:
							path = level.LH.GameStyle | LevelData::OBJ_54B;
							break;
						case 0x5C:
							path = level.LH.GameStyle | LevelData::OBJ_54C;
						}

						DrawImage(path, (float)((-objW / 2.0 + objX / 160.0) * Zm),
							H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm) + KY, Zm * objW, Zm * objH);
						break;
					}
					case 24: {
						//火棍
						LX = std::round((float)(-objW / 2.0 + objX / 160.0) * Zm);
						LY = std::round(H * Zm - (float)(objH - 0.5 + objY / 160.0) * Zm);
						DrawImage(level.LH.GameStyle | LevelData::OBJ_24, LX, LY, Zm, Zm);

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
							DrawImage(level.LH.GameStyle | LevelData::OBJ_105A, LX, LY, Zm * 3, Zm * 5);
						} else {
							DrawImage(level.LH.GameStyle | LevelData::OBJ_105, LX, LY, Zm * 3, Zm * 5);
						}
						break;
					}
					}

					bool P = ((objFlag / 0x8000) % 2 == 1);
					bool W = ((objFlag / 2) % 2 == 1);
					path   = 0;
					if(P && W) {
						path = level.LH.GameStyle | LevelData::OBJ_CID_B;
					} else {
						if(P) {
							path = level.LH.GameStyle | LevelData::OBJ_CID_P;
						} else if(W) {
							path = level.LH.GameStyle | LevelData::OBJ_CID_W;
						}
					}

					if(path) {
						DrawImage(path, LX, LY, Zm / 2, Zm / 2);
					}

					if(L && level.ObjLinkType[objLid + 1] == 59) {
						int cmnId = objFlag % 0x400000 / 0x100000;
						path      = LevelData::GetIndex(0, LevelData::D0 + cmnId, LevelData::NONE, LevelData::CMN);

						DrawImage(path, LX, LY, Zm, Zm);
					}
				}
			}
		}
	}
}

void LevelDrawer::ReGrdCode() {
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

void LevelDrawer::DrawGrd() {
	int i = 0;
	// std::shared_ptr<Image> K;
	// K = GetTile(0, 12, 1, 1); //Image.FromFile(PT & "\img\" & LH.GameStyle.ToString & "\obj\7 )
	if(NowIO) {
		//终点
		switch(level.LH.GameStyle) {
		case 12621: // 1
			if(level.MapHdr.Theme == 2) {
				DrawImage(level.LH.GameStyle | LevelData::OBJ_27A, (float)((level.LH.GoalX / 10.0 - 0.5) * Zm),
					(level.MapHdr.BorT / 16 - level.LH.GoalY - 4) * Zm, Zm * 2, Zm * 4);

				for(i = 0; i <= 13; i++) {
					DrawTile(15, 15, 1, 1, (float)((level.LH.GoalX / 10.0 - 14.5 + i) * Zm),
						(level.MapHdr.BorT / 16 - level.LH.GoalY) * Zm, Zm, Zm);
				}
			} else {
				DrawImage(level.LH.GameStyle | LevelData::OBJ_27, (float)((level.LH.GoalX / 10.0 - 0.5) * Zm),
					(level.MapHdr.BorT / 16 - level.LH.GoalY - 11) * Zm, Zm, Zm * 11);
			}
			break;
		case 13133: // 3
			if(level.MapHdr.Theme == 2) {
				DrawImage(level.LH.GameStyle | LevelData::OBJ_27A, (float)((level.LH.GoalX / 10.0 - 0.5) * Zm),
					(level.MapHdr.BorT / 16 - level.LH.GoalY - 4) * Zm, Zm * 2, Zm * 4);

				for(i = 0; i <= 13; i++) {
					DrawTile(15, 15, 1, 1, (float)((level.LH.GoalX / 10.0 - 14.5 + i) * Zm),
						(level.MapHdr.BorT / 16 - level.LH.GoalY) * Zm, Zm, Zm);
				}
			} else {
				DrawImage(level.LH.GameStyle | LevelData::OBJ_27, (float)((level.LH.GoalX / 10.0 - 0.5) * Zm),
					(level.MapHdr.BorT / 16 - level.LH.GoalY - 5 - 0.5) * Zm, Zm * 2, Zm * 2);
			}
			break;
		case 22349: // W
			if(level.MapHdr.Theme == 2) {
				DrawImage(level.LH.GameStyle | LevelData::OBJ_27A, (float)((level.LH.GoalX / 10.0 - 0.5) * Zm),
					(level.MapHdr.BorT / 16 - level.LH.GoalY - 4) * Zm, Zm * 2, Zm * 4);

				for(i = 0; i <= 13; i++) {
					DrawTile(15, 15, 1, 1, (float)((level.LH.GoalX / 10.0 - 14.5 + i) * Zm),
						(level.MapHdr.BorT / 16 - level.LH.GoalY) * Zm, Zm, Zm);
				}
			} else {
				// For i = 1 To 8
				//	G. DrawImage(level.LH.GameStyle |Image.FromFile(PT & "\img\" & LH.GameStyle.ToString & "\obj\27C ),
				// CSng((LH.GoalX /
				// 10 - 0.5) * Zm), (MapHdr.BorT \ 16 - LH.GoalY - i) * Zm, Zm, Zm) 	G. DrawImage(level.LH.GameStyle
				// |Image.FromFile(PT &
				//"\img\" & LH.GameStyle.ToString & "\obj\27E ), CSng((LH.GoalX / 10 + 1.5) * Zm), (MapHdr.BorT \ 16
				//- LH.GoalY - i) * Zm, Zm, Zm) Next G. DrawImage(level.LH.GameStyle |Image.FromFile(PT & "\img\" &
				// LH.GameStyle.ToString &
				// "\obj\27B ), CSng((LH.GoalX / 10 - 0.5) * Zm), (MapHdr.BorT \ 16 - LH.GoalY - 9) * Zm, Zm, Zm)
				// G. DrawImage(level.LH.GameStyle |Image.FromFile(PT & "\img\" & LH.GameStyle.ToString & "\obj\27D ),
				// CSng((LH.GoalX / 10 + 1.5) * Zm), (MapHdr.BorT \ 16 - LH.GoalY - 9) * Zm, Zm, Zm)

				DrawImage(level.LH.GameStyle | LevelData::OBJ_27F, (float)((level.LH.GoalX / 10.0 - 0.5) * Zm),
					(float)(level.MapHdr.BorT / 16 - level.LH.GoalY - 8.5) * Zm, Zm, Zm * 9);
				DrawImage(level.LH.GameStyle | LevelData::OBJ_27, (float)((level.LH.GoalX / 10.0) * Zm),
					(float)(level.MapHdr.BorT / 16 - level.LH.GoalY - 8) * Zm, Zm * 2, Zm);
				DrawImage(level.LH.GameStyle | LevelData::OBJ_27G, (float)((level.LH.GoalX / 10.0 + 1.5) * Zm),
					(float)(level.MapHdr.BorT / 16 - level.LH.GoalY - 8.5) * Zm, Zm, Zm * 9);
			}
			break;
		case 21847: // U
			if(level.MapHdr.Theme == 2) {
				DrawImage(level.LH.GameStyle | LevelData::OBJ_27A, (float)((level.LH.GoalX / 10.0 - 0.5) * Zm),
					(level.MapHdr.BorT / 16 - level.LH.GoalY - 4) * Zm, Zm * 2, Zm * 4);

				for(i = 0; i <= 13; i++) {
					DrawTile(15, 15, 1, 1, (float)((level.LH.GoalX / 10.0 - 14.5 + i) * Zm),
						(level.MapHdr.BorT / 16 - level.LH.GoalY) * Zm, Zm, Zm);
				}
			} else {
				DrawImage(level.LH.GameStyle | LevelData::OBJ_27, (float)((level.LH.GoalX / 10.0 - 0.5) * Zm),
					(level.MapHdr.BorT / 16 - level.LH.GoalY - 11) * Zm, Zm, Zm * 11);
			}
			break;
		case 22323: // 3D
			DrawImage(level.LH.GameStyle | LevelData::OBJ_27, (float)((level.LH.GoalX / 10.0 - 0.5) * Zm),
				(level.MapHdr.BorT / 16 - level.LH.GoalY - 11) * Zm, Zm, Zm * 11);
			break;
		}

		DrawImage(level.LH.GameStyle | LevelData::OBJ_38, 1 * Zm, (level.MapHdr.BorT / 16 - level.LH.StartY - 3) * Zm,
			Zm * 3, Zm * 3);
	}
}

int LevelDrawer::GetGrdType(const std::string& A) {
	int p = 0;
	int i = 0;
	p     = 0;
	for(i = 0; i <= 7; i++) {
		p += ((A.substr((8 - i) - 1, 1) == "0") ? 0 : 1) * std::pow(2, i);
	}
	return p;
}

std::string LevelDrawer::GetGrdCode(int x, int y) {
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

int LevelDrawer::GetGrdBold(int x, int y) {
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

int LevelDrawer::CalC(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	return ((level.GroundNode[x1][y1] == 0) ? 0 : 1000) + ((level.GroundNode[x2][y2] == 0) ? 0 : 100)
		   + ((level.GroundNode[x3][y3] == 0) ? 0 : 10) + ((level.GroundNode[x4][y4] == 0) ? 0 : 1);
}

LevelParser::Point LevelDrawer::GetCorCode(int x, int y) {
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

void LevelDrawer::DrawGrdCode() {
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
			}
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

void LevelDrawer::DrawIce() {
	for(int i = 0; i < level.MapHdr.IceCount; i++) {
		DrawTile(15, level.MapIce[i].ID == 0 ? 41 : 39, 1, 2, level.MapIce[i].X * Zm,
			(level.MapHdr.BorT / 16 - 2) * Zm - level.MapIce[i].Y * Zm, Zm, Zm * 2);
	}
}

void LevelDrawer::DrawTrack() {
	for(int i = 0; i < level.MapHdr.TrackCount; i++) {
		level.ObjLinkType[level.MapTrk[i].LID] = 59;

		int trackType = level.MapTrk[i].Type;
		uint32_t path = 0;
		if(trackType == 0) {
			path = level.LH.GameStyle | LevelData::OBJ_T0;
		} else if(trackType == 1) {
			path = level.LH.GameStyle | LevelData::OBJ_T1;
		} else if(trackType < 10) {
			path = level.LH.GameStyle | (LevelData::OBJ_T2 + (trackType - 2) * 32768);
		} else {
			path = level.LH.GameStyle | (LevelData::OBJ_T10 + (trackType - 10) * 32768);
		}

		if(level.MapTrk[i].Type < 8) {
			DrawImage(path, level.MapTrk[i].X * Zm - Zm, (H - 2) * Zm - level.MapTrk[i].Y * Zm, Zm * 3, Zm * 3);
			switch(level.MapTrk[i].Type) {
			case 0:
				if(level.TrackNode[level.MapTrk[i].X + 1 + 1][level.MapTrk[i].Y + 1] == 1 && level.MapTrk[i].F0 == 0) {
					DrawImage(level.LH.GameStyle | LevelData::OBJ_T, level.MapTrk[i].X * Zm + Zm,
						(H - 1) * Zm - level.MapTrk[i].Y * Zm, Zm, Zm);
				}
				if(level.TrackNode[level.MapTrk[i].X + 1 - 1][level.MapTrk[i].Y + 1] == 1 && level.MapTrk[i].F1 == 0) {
					DrawImage(level.LH.GameStyle | LevelData::OBJ_T, level.MapTrk[i].X * Zm - Zm,
						(H - 1) * Zm - level.MapTrk[i].Y * Zm, Zm, Zm);
				}
				break;
			case 1:
				if(level.TrackNode[level.MapTrk[i].X + 1][level.MapTrk[i].Y + 1 + 1] == 1 && level.MapTrk[i].F0 == 0) {
					DrawImage(level.LH.GameStyle | LevelData::OBJ_T, level.MapTrk[i].X * Zm,
						(H - 2) * Zm - level.MapTrk[i].Y * Zm, Zm, Zm);
				}
				if(level.TrackNode[level.MapTrk[i].X + 1][level.MapTrk[i].Y + 1 - 1] == 1 && level.MapTrk[i].F1 == 0) {
					DrawImage(level.LH.GameStyle | LevelData::OBJ_T, level.MapTrk[i].X * Zm,
						H * Zm - level.MapTrk[i].Y * Zm, Zm, Zm);
				}
				break;
			case 2:
			case 4:
			case 5:
				if(level.TrackNode[level.MapTrk[i].X + 1 + 1][level.MapTrk[i].Y + 1 - 1] == 1
					&& level.MapTrk[i].F0 == 0) {
					DrawImage(level.LH.GameStyle | LevelData::OBJ_T, level.MapTrk[i].X * Zm + Zm,
						H * Zm - level.MapTrk[i].Y * Zm, Zm, Zm);
				}
				if(level.TrackNode[level.MapTrk[i].X + 1 - 1][level.MapTrk[i].Y + 1 + 1] == 1
					&& level.MapTrk[i].F1 == 0) {
					DrawImage(level.LH.GameStyle | LevelData::OBJ_T, level.MapTrk[i].X * Zm - Zm,
						(H - 2) * Zm - level.MapTrk[i].Y * Zm, Zm, Zm);
				}
				break;
			case 3:
			case 6:
			case 7:
				if(level.TrackNode[level.MapTrk[i].X + 1 + 1][level.MapTrk[i].Y + 1 + 1] == 1
					&& level.MapTrk[i].F0 == 0) {
					DrawImage(level.LH.GameStyle | LevelData::OBJ_T, level.MapTrk[i].X * Zm + Zm,
						(H - 2) * Zm - level.MapTrk[i].Y * Zm, Zm, Zm);
				}
				if(level.TrackNode[level.MapTrk[i].X + 1 - 1][level.MapTrk[i].Y + 1 - 1] == 1
					&& level.MapTrk[i].F1 == 0) {
					DrawImage(level.LH.GameStyle | LevelData::OBJ_T, level.MapTrk[i].X * Zm - Zm,
						H * Zm - level.MapTrk[i].Y * Zm, Zm, Zm);
				}
				break;
			}
		} else // Y轨道
		{
			DrawImage(path, level.MapTrk[i].X * Zm - Zm, (H - 4) * Zm - level.MapTrk[i].Y * Zm, Zm * 5, Zm * 5);

			if(level.TrackNode[level.MapTrk[i].X + level.TrackYPt[level.MapTrk[i].Type][0].X]
							  [level.MapTrk[i].Y + level.TrackYPt[level.MapTrk[i].Type][0].Y]
					== 1
				&& level.MapTrk[i].F0 == 0) {
				DrawImage(level.LH.GameStyle | LevelData::OBJ_T,
					(level.MapTrk[i].X - 1 + level.TrackYPt[level.MapTrk[i].Type][0].X) * Zm,
					(H - 4) * Zm - (level.MapTrk[i].Y - level.TrackYPt[level.MapTrk[i].Type][0].Y) * Zm, Zm, Zm);
			}
			if(level.TrackNode[level.MapTrk[i].X + level.TrackYPt[level.MapTrk[i].Type][1].X]
							  [level.MapTrk[i].Y + level.TrackYPt[level.MapTrk[i].Type][1].Y]
					== 1
				&& level.MapTrk[i].F1 == 0) {
				DrawImage(level.LH.GameStyle | LevelData::OBJ_T,
					(level.MapTrk[i].X - 1 + level.TrackYPt[level.MapTrk[i].Type][1].X) * Zm,
					(H - 4) * Zm - (level.MapTrk[i].Y - level.TrackYPt[level.MapTrk[i].Type][1].Y) * Zm, Zm, Zm);
			}
			if(level.TrackNode[level.MapTrk[i].X + level.TrackYPt[level.MapTrk[i].Type][2].X]
							  [level.MapTrk[i].Y + level.TrackYPt[level.MapTrk[i].Type][2].Y]
					== 1
				&& level.MapTrk[i].F2 == 0) {
				DrawImage(level.LH.GameStyle | LevelData::OBJ_T,
					(level.MapTrk[i].X - 1 + level.TrackYPt[level.MapTrk[i].Type][2].X) * Zm,
					(H - 4) * Zm - (level.MapTrk[i].Y - level.TrackYPt[level.MapTrk[i].Type][2].Y) * Zm, Zm, Zm);
			}
		}
	}
}

void LevelDrawer::DrawCID() {
	int LX        = 0;
	int LY        = 0;
	uint32_t path = 0;

	std::string P = assetFolder;

	for(int i = 0; i < level.MapHdr.ObjCount; i++) {
		int objCid = level.MapObj[i].CID;
		int objX   = level.MapObj[i].X;
		int objY   = level.MapObj[i].Y;

		LX = std::round((float)((-0.5 + objX / 160.0) * Zm));
		LY = std::round(H * Zm - (float)((0.5 + objY / 160.0) * Zm));
		switch(objCid) {
		case -1: //无

			break;
		case 44:
		case 81:
		case 116: //状态
			path = LevelData::GetIndex(level.LH.GameStyle, objCid,
				(level.MapObj[i].CFlag / 0x40000) % 2 == 1 ? LevelData::A_ : LevelData::NONE, LevelData::CID);
			DrawImage(path, LX, LY, Zm, Zm);
			DrawImage(LevelData::OBJ_CMN_F1, LX, LY, Zm, Zm);
			break;
		case 34: //状态火花
			if((level.MapObj[i].CFlag / 0x4) % 2 == 1) {
				if((level.MapObj[i].CFlag / 0x40000) % 2 == 1) {
					path = level.LH.GameStyle | LevelData::OBJ_34C;
				} else {
					path = level.LH.GameStyle | LevelData::OBJ_34A;
				}
			} else {
				if((level.MapObj[i].CFlag / 0x40000) % 2 == 1) {
					path = level.LH.GameStyle | LevelData::OBJ_34B;
				} else {
					path = level.LH.GameStyle | LevelData::OBJ_34;
				}
			}

			DrawImage(path, LX, LY, Zm, Zm);
			DrawImage(LevelData::OBJ_CMN_F1, LX, LY, Zm, Zm);
			break;
		case 111: //机械库巴
			if((level.MapObj[i].CFlag / 0x40000) % 2 == 1) {
				path = level.LH.GameStyle | LevelData::OBJ_111B;
			} else if((level.MapObj[i].CFlag / 0x80000) % 2 == 1) {
				path = level.LH.GameStyle | LevelData::OBJ_111A;
			} else {
				path = level.LH.GameStyle | LevelData::OBJ_111;
			}

			DrawImage(path, LX, LY, Zm, Zm);
			DrawImage(LevelData::OBJ_CMN_F1, LX, LY, Zm, Zm);
			break;
		case 76: //加邦
			path = level.LH.GameStyle | LevelData::OBJ_76;
			DrawImage(path, LX, LY, Zm, Zm);
			DrawImage(LevelData::OBJ_CMN_F1, LX, LY, Zm, Zm);
			break;
		case 33: // 1UP
			if(level.MapHdr.Theme == 1 && level.MapHdr.Flag == 2) {
				path = level.LH.GameStyle | LevelData::OBJ_33A;
			} else {
				path = level.LH.GameStyle | LevelData::OBJ_33;
			}

			DrawImage(path, LX, LY, Zm, Zm);
			DrawImage(LevelData::OBJ_CMN_F1, LX, LY, Zm, Zm);
			break;
		default:
			if((level.MapObj[i].CFlag / 0x4) % 2 == 1) {
				path = LevelData::GetIndex(level.LH.GameStyle, objCid, LevelData::A_, LevelData::CID);
			} else {
				path = LevelData::GetIndex(level.LH.GameStyle, objCid, LevelData::NONE, LevelData::CID);
			}

			DrawImage(path, LX, LY, Zm, Zm);
			DrawImage(LevelData::OBJ_CMN_F1, LX, LY, Zm, Zm);
			break;
		}
	}
}

void LevelDrawer::DrawFireBar() {
	int j    = 0;
	int LX   = 0;
	int LY   = 0;
	float FR = 0;

	for(int i = 0; i < level.MapHdr.ObjCount; i++) {
		int objW    = level.MapObj[i].W;
		int objH    = level.MapObj[i].H;
		int objFlag = level.MapObj[i].Flag;
		int objX    = level.MapObj[i].X;
		int objY    = level.MapObj[i].Y;

		if(level.MapObj[i].ID == 24) {
			LX = std::round((float)(-objW / 2.0 + objX / 160.0) * Zm);
			LY = std::round(H * Zm - (float)(objH - 0.5 + objY / 160.0) * Zm);
			FR = (level.MapObj[i].Ex / 0x38E38E0) * -0.0872665;

			for(j = 0; j <= (objFlag - 0x6000000) / 0x400000 + 1; j++) {
				DrawImageRotateOpacity(level.LH.GameStyle | LevelData::OBJ_24A, FR, 0.5,
					-Zm / 4 + j * std::cos(FR) * Zm + LX + Zm / 2, -Zm / 4 + j * std::sin(FR) * Zm + LY + Zm / 2, Zm,
					Zm / 2);
			}

			if((objFlag / 0x8) % 2 == 1) {
				DrawImage(LevelData::OBJ_CMN_B0, LX, LY, Zm, Zm);
			} else {
				DrawImage(LevelData::OBJ_CMN_B1, LX, LY, Zm, Zm);
			}
		}
	}
}

void LevelDrawer::DrawFire() {
	for(int i = 0; i < level.MapHdr.ObjCount; i++) {
		int objW = level.MapObj[i].W;
		int objH = level.MapObj[i].H;
		int objX = level.MapObj[i].X;
		int objY = level.MapObj[i].Y;

		if(level.MapObj[i].ID == 54) {
			switch(level.MapObj[i].Flag % 0x100) {
			case 0x40:
				DrawImageOpacity(level.LH.GameStyle | LevelData::OBJ_54A1, 0.5,
					(float)((-objW / 2.0 + objX / 160.0) * Zm),
					(H - 3) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm * objW, 3 * Zm * objH);
				break;
			case 0x48:
				DrawImageOpacity(level.LH.GameStyle | LevelData::OBJ_54A3, 0.5,
					(float)((-objW / 2.0 + 1 + objX / 160.0) * Zm), H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm),
					3 * Zm * objW, Zm * objH);
				break;
			case 0x50:
				DrawImageOpacity(level.LH.GameStyle | LevelData::OBJ_54A5, 0.5,
					(float)((-objW / 2.0 + objX / 160.0) * Zm),
					(H + 1) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm * objW, 3 * Zm * objH);
				break;
			case 0x58:
				DrawImageOpacity(level.LH.GameStyle | LevelData::OBJ_54A7, 0.5,
					(float)((-objW / 2.0 - 3 + objX / 160.0) * Zm), H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm),
					3 * Zm * objW, Zm * objH);
				break;
			case 0x44:
				DrawImageOpacity(level.LH.GameStyle | LevelData::OBJ_54A2, 0.5,
					(float)((-objW / 2.0 + objX / 160.0) * Zm),
					(H - 3) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm * objW, 3 * Zm * objH);
				break;
			case 0x4C:
				DrawImageOpacity(level.LH.GameStyle | LevelData::OBJ_54A4, 0.5,
					(float)((-objW / 2.0 + 1 + objX / 160.0) * Zm), H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm),
					3 * Zm * objW, Zm * objH);
				break;
			case 0x54:
				DrawImageOpacity(level.LH.GameStyle | LevelData::OBJ_54A6, 0.5,
					(float)((-objW / 2.0 + objX / 160.0) * Zm),
					(H + 1) * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm), Zm * objW, 3 * Zm * objH);
				break;
			case 0x5C:
				DrawImageOpacity(level.LH.GameStyle | LevelData::OBJ_54A8, 0.5,
					(float)((-objW / 2.0 - 3 + objX / 160.0) * Zm), H * Zm - (float)((objH - 0.5 + objY / 160.0) * Zm),
					3 * Zm * objW, Zm * objH);
				break;
			}
		}
	}
}

void LevelDrawer::DrawCPipe() {
	int K         = 0;
	uint32_t path = 0;

	for(int i = 0; i < level.MapHdr.ClearPipCount; i++) {
		for(int J = 0; J < level.MapCPipe[i].NodeCount; J++) {
			if(J == 0) {
				for(K = 0; K < level.MapCPipe[i].Node[J].H; K++) {
					switch(level.MapCPipe[i].Node[J].Dir) {
					case 0: // R
						if(K == 0) {
							path = level.LH.GameStyle | LevelData::OBJ_93C;
						} else if(level.MapCPipe[i].NodeCount == 1 && K == level.MapCPipe[i].Node[J].H - 1) {
							path = level.LH.GameStyle | LevelData::OBJ_93E;
						} else {
							path = level.LH.GameStyle | LevelData::OBJ_93D;
						}

						DrawImage(path, (level.MapCPipe[i].Node[J].X + K) * Zm,
							(H - 1 - level.MapCPipe[i].Node[J].Y) * Zm, Zm, 2 * Zm);
						break;
					case 1: // L
						if(K == 0) {
							path = level.LH.GameStyle | LevelData::OBJ_93E;
						} else if(level.MapCPipe[i].NodeCount == 1 && K == level.MapCPipe[i].Node[J].H - 1) {
							path = level.LH.GameStyle | LevelData::OBJ_93C;
						} else {
							path = level.LH.GameStyle | LevelData::OBJ_93D;
						}
						DrawImage(path, (level.MapCPipe[i].Node[J].X - K) * Zm,
							(H - 1 - level.MapCPipe[i].Node[J].Y - 1) * Zm, Zm, 2 * Zm);
						break;
					case 2: // U
						if(K == 0) {
							path = level.LH.GameStyle | LevelData::OBJ_93;
						} else if(level.MapCPipe[i].NodeCount == 1 && K == level.MapCPipe[i].Node[J].H - 1) {
							path = level.LH.GameStyle | LevelData::OBJ_93B;
						} else {
							path = level.LH.GameStyle | LevelData::OBJ_93A;
						}

						DrawImage(path, level.MapCPipe[i].Node[J].X * Zm,
							(H - 1 - level.MapCPipe[i].Node[J].Y - K) * Zm, 2 * Zm, Zm);
						break;
					case 3: // D
						if(K == 0) {
							path = level.LH.GameStyle | LevelData::OBJ_93B;
						} else if(level.MapCPipe[i].NodeCount == 1 && K == level.MapCPipe[i].Node[J].H - 1) {
							path = level.LH.GameStyle | LevelData::OBJ_93;
						} else {
							path = level.LH.GameStyle | LevelData::OBJ_93A;
						}

						DrawImage(path, (level.MapCPipe[i].Node[J].X - 1) * Zm,
							(H - 1 - level.MapCPipe[i].Node[J].Y + K) * Zm, 2 * Zm, Zm);
						break;
					}
				}
			} else if(J == level.MapCPipe[i].NodeCount - 1) {
				for(K = 0; K < level.MapCPipe[i].Node[J].H; K++) {
					switch(level.MapCPipe[i].Node[J].Dir) {
					case 0: // R
						if(K == level.MapCPipe[i].Node[J].H - 1) {
							path = level.LH.GameStyle | LevelData::OBJ_93E;
						} else {
							path = level.LH.GameStyle | LevelData::OBJ_93D;
						}

						DrawImage(path, (level.MapCPipe[i].Node[J].X + K) * Zm,
							(H - 1 - level.MapCPipe[i].Node[J].Y) * Zm, Zm, 2 * Zm);
						break;
					case 1: // L
						if(K == level.MapCPipe[i].Node[J].H - 1) {
							path = level.LH.GameStyle | LevelData::OBJ_93C;
						} else {
							path = level.LH.GameStyle | LevelData::OBJ_93D;
						}

						DrawImage(path, (level.MapCPipe[i].Node[J].X - K) * Zm,
							(H - 1 - level.MapCPipe[i].Node[J].Y - 1) * Zm, Zm, 2 * Zm);
						break;
					case 2: // U
						if(K == level.MapCPipe[i].Node[J].H - 1) {
							path = level.LH.GameStyle | LevelData::OBJ_93B;
						} else {
							path = level.LH.GameStyle | LevelData::OBJ_93A;
						}

						DrawImage(path, level.MapCPipe[i].Node[J].X * Zm,
							(H - 1 - level.MapCPipe[i].Node[J].Y - K) * Zm, 2 * Zm, Zm);
						break;
					case 3: // D
						if(K == level.MapCPipe[i].Node[J].H - 1) {
							path = level.LH.GameStyle | LevelData::OBJ_93;
						} else {
							path = level.LH.GameStyle | LevelData::OBJ_93A;
						}

						DrawImage(path, (level.MapCPipe[i].Node[J].X - 1) * Zm,
							(H - 1 - level.MapCPipe[i].Node[J].Y + K) * Zm, 2 * Zm, Zm);
						break;
					}
				}
			} else {
				if(level.MapCPipe[i].Node[J].type >= 3 && level.MapCPipe[i].Node[J].type <= 10) {
					switch(level.MapCPipe[i].Node[J].type) {
					case 3:
					case 7: // RU DL
						DrawImage(level.LH.GameStyle | LevelData::OBJ_93G, (level.MapCPipe[i].Node[J].X) * Zm,
							(H - 2.0 - level.MapCPipe[i].Node[J].Y) * Zm, 2 * Zm, 2 * Zm);
						break;
					case 4:
					case 9: // RD UL
						DrawImage(level.LH.GameStyle | LevelData::OBJ_93H, (level.MapCPipe[i].Node[J].X) * Zm,
							(H - 2.0 - level.MapCPipe[i].Node[J].Y) * Zm, 2 * Zm, 2 * Zm);
						break;
					case 6:
					case 10: // UR LD
						DrawImage(level.LH.GameStyle | LevelData::OBJ_93J, (level.MapCPipe[i].Node[J].X) * Zm,
							(H - 2.0 - level.MapCPipe[i].Node[J].Y) * Zm, 2 * Zm, 2 * Zm);
						break;
					case 5:
					case 8: // DR LU
						DrawImage(level.LH.GameStyle | LevelData::OBJ_93F, (level.MapCPipe[i].Node[J].X) * Zm,
							(H - 2.0 - level.MapCPipe[i].Node[J].Y) * Zm, 2 * Zm, 2 * Zm);
						break;
					}
				} else {
					for(K = 0; K < level.MapCPipe[i].Node[J].H; K++) {
						switch(level.MapCPipe[i].Node[J].Dir) {
						case 0: // R
							DrawImage(level.LH.GameStyle | LevelData::OBJ_93D, (level.MapCPipe[i].Node[J].X + K) * Zm,
								(H - 1 - level.MapCPipe[i].Node[J].Y) * Zm, Zm, 2 * Zm);
							break;
						case 1: // L
							DrawImage(level.LH.GameStyle | LevelData::OBJ_93D, (level.MapCPipe[i].Node[J].X - K) * Zm,
								(H - 1 - level.MapCPipe[i].Node[J].Y - 1) * Zm, Zm, 2 * Zm);
							break;
						case 2: // U
							DrawImage(level.LH.GameStyle | LevelData::OBJ_93A, level.MapCPipe[i].Node[J].X * Zm,
								(H - 1 - level.MapCPipe[i].Node[J].Y - K) * Zm, 2 * Zm, Zm);
							break;
						case 3: // D
							DrawImage(level.LH.GameStyle | LevelData::OBJ_93A, (level.MapCPipe[i].Node[J].X - 1) * Zm,
								(H - 1 - level.MapCPipe[i].Node[J].Y + K) * Zm, 2 * Zm, Zm);
							break;
						}
					}
				}
			}
		}
	}
}
