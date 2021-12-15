#include "LevelParser.hpp"

LevelParser::LevelParser() {
	TileLoc.resize(152);
	for(int i = 0; i < 152; i++) {
		TileLoc[i].resize(4);
	}

	PipeLoc.resize(5);
	for(int i = 0; i < 5; i++) {
		PipeLoc[i].resize(9);
	}

	ObjLocData.resize(2);
	ObjLocData[0].resize(301);
	ObjLocData[1].resize(301);
	for(int i = 0; i < 301; i++) {
		ObjLocData[0][i].resize(301);
		ObjLocData[1][i].resize(301);
	}

	GroundNode.resize(301);
	for(int i = 0; i < 301; i++) {
		GroundNode[i].resize(301);
	}

	TrackYPt.resize(17);
	for(int i = 0; i < 17; i++) {
		TrackYPt[i].resize(4);
	}
}

std::string LevelParser::GetItemName(int n, int v) {
	std::string tempGetItemName = "";
	switch(v) {
	case 12621:
		tempGetItemName = ObjEng[n];
		break;
	case 13133:
		tempGetItemName = ObjEng3[n];
		break;
	case 22349:
		tempGetItemName = ObjEngW[n];
		break;
	case 21847:
		tempGetItemName = ObjEngU[n];
		break;
	case 22323:
		tempGetItemName = ObjEngD[n];
		break;
	default:
		tempGetItemName = "?";
		break;
	}
	return tempGetItemName;
}

void LevelParser::SetAssetsFolder(std::string path) {
	PT = path;
}

bool LevelParser::DecryptLevelData(const std::string& input, const std::string& output) {
	return LevelDecryptor::decrypt(input.c_str(), output.c_str());
}

void LevelParser::LoadLvlData(const std::string& P, bool overworld) {
	int Offset;
	Offset = overworld ? 0x200 : 0x2E0E0;

	FILE* levelPtr = fopen(P.c_str(), "rb");
	fread(&LH.StartY, sizeof(LH.StartY), 1, levelPtr);
	fread(&LH.GoalY, sizeof(LH.GoalY), 1, levelPtr);
	fread(&LH.GoalX, sizeof(LH.GoalX), 1, levelPtr);
	fread(&LH.Timer, sizeof(LH.Timer), 1, levelPtr);
	fread(&LH.ClearCA, sizeof(LH.ClearCA), 1, levelPtr);
	fread(&LH.DateYY, sizeof(LH.DateYY), 1, levelPtr);
	fread(&LH.DateMM, sizeof(LH.DateMM), 1, levelPtr);
	fread(&LH.DateDD, sizeof(LH.DateDD), 1, levelPtr);
	fread(&LH.DateH, sizeof(LH.DateH), 1, levelPtr);
	fread(&LH.DateM, sizeof(LH.DateM), 1, levelPtr);
	fread(&LH.AutoscrollSpd, sizeof(LH.AutoscrollSpd), 1, levelPtr);
	fread(&LH.ClearCC, sizeof(LH.ClearCC), 1, levelPtr);
	fread(&LH.ClearCRC, sizeof(LH.ClearCRC), 1, levelPtr);
	fread(&LH.GameVer, sizeof(LH.GameVer), 1, levelPtr);
	fread(&LH.MFlag, sizeof(LH.MFlag), 1, levelPtr);
	fread(&LH.ClearAttempts, sizeof(LH.ClearAttempts), 1, levelPtr);
	fread(&LH.ClearTime, sizeof(LH.ClearTime), 1, levelPtr);
	fread(&LH.CreationID, sizeof(LH.CreationID), 1, levelPtr);
	fread(&LH.UploadID, sizeof(LH.UploadID), 1, levelPtr);
	fread(&LH.ClearVer, sizeof(LH.ClearVer), 1, levelPtr);
	fseek(levelPtr, 0xF1, SEEK_SET);
	fread(&LH.GameStyle, sizeof(LH.GameStyle), 1, levelPtr);

	// VER TEST
	// LH.GameStyle = 12621

	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> wstringConverter;

	long long i    = 0;
	long long j    = 0;
	std::wstring S = L"";
	short K        = 0;
	for(i = 1; i <= 0x42; i += 2) {
		fseek(levelPtr, 0xF3 + i, SEEK_SET);
		fread(&K, sizeof(K), 1, levelPtr);
		if(K == 0) {
			break;
		}
		S += (wchar_t)K;
	}
	LH.Name = wstringConverter.to_bytes(S);

	S = L"";
	for(i = 1; i <= 0xCA; i += 2) {
		fseek(levelPtr, 0x135 + i, SEEK_SET);
		fread(&K, sizeof(K), 1, levelPtr);
		if(K == 0) {
			break;
		}
		S += (wchar_t)K;
	}
	LH.Desc = wstringConverter.to_bytes(S);

	fmt::print("NAME: {}\n", LH.Name);
	fmt::print("DESCRIPTION: {}\n", LH.Desc);

	long long M = 0;

	fseek(levelPtr, Offset, SEEK_SET);
	fread(&MapHdr.Theme, sizeof(MapHdr.Theme), 1, levelPtr);
	fread(&MapHdr.AutoscrollType, sizeof(MapHdr.AutoscrollType), 1, levelPtr);
	fread(&MapHdr.BorFlag, sizeof(MapHdr.BorFlag), 1, levelPtr);
	fread(&MapHdr.Ori, sizeof(MapHdr.Ori), 1, levelPtr);
	fread(&MapHdr.LiqEHeight, sizeof(MapHdr.LiqEHeight), 1, levelPtr);
	fread(&MapHdr.LiqMode, sizeof(MapHdr.LiqMode), 1, levelPtr);
	fread(&MapHdr.LiqSpd, sizeof(MapHdr.LiqSpd), 1, levelPtr);
	fread(&MapHdr.LiqSHeight, sizeof(MapHdr.LiqSHeight), 1, levelPtr);
	fread(&MapHdr.BorR, sizeof(MapHdr.BorR), 1, levelPtr);
	fread(&MapHdr.BorT, sizeof(MapHdr.BorT), 1, levelPtr);
	fread(&MapHdr.BorL, sizeof(MapHdr.BorL), 1, levelPtr);
	fread(&MapHdr.BorB, sizeof(MapHdr.BorB), 1, levelPtr);
	fread(&MapHdr.Flag, sizeof(MapHdr.Flag), 1, levelPtr);
	fread(&MapHdr.ObjCount, sizeof(MapHdr.ObjCount), 1, levelPtr);
	fread(&MapHdr.SndCount, sizeof(MapHdr.SndCount), 1, levelPtr);
	fread(&MapHdr.SnakeCount, sizeof(MapHdr.SnakeCount), 1, levelPtr);
	fread(&MapHdr.ClearPipCount, sizeof(MapHdr.ClearPipCount), 1, levelPtr);
	fread(&MapHdr.CreeperCount, sizeof(MapHdr.CreeperCount), 1, levelPtr);
	fread(&MapHdr.iBlkCount, sizeof(MapHdr.iBlkCount), 1, levelPtr);
	fread(&MapHdr.TrackBlkCount, sizeof(MapHdr.TrackBlkCount), 1, levelPtr);
	fread(&MapHdr.GroundCount, sizeof(MapHdr.GroundCount), 1, levelPtr);
	fread(&MapHdr.TrackCount, sizeof(MapHdr.TrackCount), 1, levelPtr);
	fread(&MapHdr.IceCount, sizeof(MapHdr.IceCount), 1, levelPtr);

	MapObj.resize(MapHdr.ObjCount);
	for(M = 0; M < MapHdr.ObjCount; M++) {
		fseek(levelPtr, Offset + 0x48 + M * 0x20, SEEK_SET);
		fread(&MapObj[M].X, sizeof(MapObj[M].X), 1, levelPtr);
		fread(&MapObj[M].Y, sizeof(MapObj[M].Y), 1, levelPtr);
		fseek(levelPtr, Offset + 0x48 + 0xA + M * 0x20, SEEK_SET);
		fread(&MapObj[M].W, sizeof(MapObj[M].W), 1, levelPtr);
		fread(&MapObj[M].H, sizeof(MapObj[M].H), 1, levelPtr);
		fread(&MapObj[M].Flag, sizeof(MapObj[M].Flag), 1, levelPtr);
		fread(&MapObj[M].CFlag, sizeof(MapObj[M].CFlag), 1, levelPtr);
		fread(&MapObj[M].Ex, sizeof(MapObj[M].Ex), 1, levelPtr);
		fread(&MapObj[M].ID, sizeof(MapObj[M].ID), 1, levelPtr);
		fread(&MapObj[M].CID, sizeof(MapObj[M].CID), 1, levelPtr);
		fread(&MapObj[M].LID, sizeof(MapObj[M].LID), 1, levelPtr);
		fread(&MapObj[M].SID, sizeof(MapObj[M].SID), 1, levelPtr);
		MapObj[M].LinkType = 0;
	}

	// 0x14584  0x4B0 (0x4 * 300)Sound Effect
	//蛇砖块0x149F8  0x12D4 (0x3C4 * 5)Snake Block
	MapSnk.resize(MapHdr.SnakeCount);
	for(M = 0; M < MapHdr.SnakeCount; M++) {
		fseek(levelPtr, Offset + 0x149F8 + M * 0x3C4, SEEK_SET);
		fread(&MapSnk[M].index, sizeof(MapSnk[M].index), 1, levelPtr);
		fread(&MapSnk[M].NodeCount, sizeof(MapSnk[M].NodeCount), 1, levelPtr);

		MapSnk[M].Node.resize(MapSnk[M].NodeCount);

		for(i = 0; i < MapSnk[M].NodeCount; i++) {
			fseek(levelPtr, Offset + 0x149F8 + 0x0 + M * 0x3C4 + i * 0x8, SEEK_SET);
			fread(&MapSnk[M].Node[i].index, sizeof(MapSnk[M].Node[i].index), 1, levelPtr);
			fseek(levelPtr, Offset + 0x149F8 + 0x6 + M * 0x3C4 + i * 0x8, SEEK_SET);
			fread(&MapSnk[M].Node[i].Dir, sizeof(MapSnk[M].Node[i].Dir), 1, levelPtr);
		}
	}

	MapCPipe.resize(MapHdr.ClearPipCount);
	for(M = 0; M < MapHdr.ClearPipCount; M++) {
		fseek(levelPtr, Offset + 0x15CCC + M * 0x124, SEEK_SET);
		fread(&MapCPipe[M].Index, sizeof(MapCPipe[M].Index), 1, levelPtr);
		fread(&MapCPipe[M].NodeCount, sizeof(MapCPipe[M].NodeCount), 1, levelPtr);

		MapCPipe[M].Node.resize(MapCPipe[M].NodeCount);

		for(i = 0; i < MapCPipe[M].NodeCount; i++) {
			fseek(levelPtr, Offset + 0x15CCC + 0x4 + M * 0x124 + i * 0x8, SEEK_SET);
			fread(&MapCPipe[M].Node[i].type, sizeof(MapCPipe[M].Node[i].type), 1, levelPtr);
			fread(&MapCPipe[M].Node[i].index, sizeof(MapCPipe[M].Node[i].index), 1, levelPtr);
			fread(&MapCPipe[M].Node[i].X, sizeof(MapCPipe[M].Node[i].X), 1, levelPtr);
			fread(&MapCPipe[M].Node[i].Y, sizeof(MapCPipe[M].Node[i].Y), 1, levelPtr);
			fread(&MapCPipe[M].Node[i].W, sizeof(MapCPipe[M].Node[i].W), 1, levelPtr);
			fread(&MapCPipe[M].Node[i].H, sizeof(MapCPipe[M].Node[i].H), 1, levelPtr);
			fseek(levelPtr, Offset + 0x15CCC + 0xB + M * 0x124 + i * 0x8, SEEK_SET);
			fread(&MapCPipe[M].Node[i].Dir, sizeof(MapCPipe[M].Node[i].Dir), 1, levelPtr);
		}
	}

	MapCrp.resize(MapHdr.CreeperCount);
	for(M = 0; M < MapHdr.CreeperCount; M++) {
		fseek(levelPtr, Offset + 0x240EC + 0x1 + M * 0x54, SEEK_SET);
		fread(&MapCrp[M].index, sizeof(MapCrp[M].index), 1, levelPtr);
		fread(&MapCrp[M].NodeCount, sizeof(MapCrp[M].NodeCount), 1, levelPtr);

		MapCrp[M].Node.resize(MapCrp[M].NodeCount);

		for(i = 0; i < MapCrp[M].NodeCount; i++) {
			fseek(levelPtr, Offset + 0x240EC + 0x4 + 0x1 + M * 0x54 + i * 0x4, SEEK_SET);
			fread(&MapCrp[M].Node[i], sizeof(MapCrp[M].Node[i]), 1, levelPtr);
		}
	}

	// 0x24434  0x1B8 (0x2C * 10)! Block
	MapMoveBlk.resize(MapHdr.iBlkCount);
	for(M = 0; M < MapHdr.iBlkCount; M++) {
		fseek(levelPtr, Offset + 0x24434 + 0x1 + M * 0x2C, SEEK_SET);
		fread(&MapMoveBlk[M].index, sizeof(MapMoveBlk[M].index), 1, levelPtr);
		fread(&MapMoveBlk[M].NodeCount, sizeof(MapMoveBlk[M].NodeCount), 1, levelPtr);

		MapMoveBlk[M].Node.resize(MapMoveBlk[M].NodeCount);

		for(i = 0; i < MapMoveBlk[M].NodeCount; i++) {
			fseek(levelPtr, Offset + 0x24434 + 0x4 + 0x0 + M * 0x2C + i * 0x4, SEEK_SET);
			fread(&MapMoveBlk[M].Node[i].p0, sizeof(MapMoveBlk[M].Node[i].p0), 1, levelPtr);
			fread(&MapMoveBlk[M].Node[i].p1, sizeof(MapMoveBlk[M].Node[i].p1), 1, levelPtr);
			fread(&MapMoveBlk[M].Node[i].p2, sizeof(MapMoveBlk[M].Node[i].p2), 1, levelPtr);
		}
	}

	// 0x245EC  0x1B8 (0x2C * 10)Track Block
	MapTrackBlk.resize(MapHdr.TrackBlkCount);
	for(M = 0; M < MapHdr.TrackBlkCount; M++) {
		fseek(levelPtr, Offset + 0x245EC + 0x1 + M * 0x2C, SEEK_SET);
		fread(&MapTrackBlk[M].index, sizeof(MapTrackBlk[M].index), 1, levelPtr);
		fread(&MapTrackBlk[M].NodeCount, sizeof(MapTrackBlk[M].NodeCount), 1, levelPtr);

		MapTrackBlk[M].Node.resize(MapTrackBlk[M].NodeCount);

		for(i = 0; i < MapTrackBlk[M].NodeCount; i++) {
			fseek(levelPtr, Offset + 0x245EC + 0x4 + 0x0 + M * 0x2C + i * 0x4, SEEK_SET);
			fread(&MapTrackBlk[M].Node[i].p0, sizeof(MapTrackBlk[M].Node[i].p0), 1, levelPtr);
			fread(&MapTrackBlk[M].Node[i].p1, sizeof(MapTrackBlk[M].Node[i].p1), 1, levelPtr);
			fread(&MapTrackBlk[M].Node[i].p2, sizeof(MapTrackBlk[M].Node[i].p2), 1, levelPtr);
		}
	}

	MapGrd.resize(MapHdr.GroundCount);

	for(M = 0; M <= 300; M++) {
		for(j = 0; j <= 300; j++) {
			GroundNode[M][j] = 0;
		}
	}
	for(M = 0; M < MapHdr.GroundCount; M++) {
		fseek(levelPtr, Offset + 0x247A4 + M * 0x4, SEEK_SET);
		fread(&MapGrd[M].X, sizeof(MapGrd[M].X), 1, levelPtr);
		fread(&MapGrd[M].Y, sizeof(MapGrd[M].Y), 1, levelPtr);
		fread(&MapGrd[M].ID, sizeof(MapGrd[M].ID), 1, levelPtr);
		fread(&MapGrd[M].BID, sizeof(MapGrd[M].BID), 1, levelPtr);

		GroundNode[MapGrd[M].X + 1][MapGrd[M].Y + 1] = 1;
	}
	if(overworld) {
		for(j = std::round((LH.GoalX - 5) / 10.0); j <= (LH.GoalX - 5) / 10.0 + 9; j++) {
			for(i = 0; i < LH.GoalY; i++) {
				GroundNode[j + 1][i + 1] = 1;
			}
		}
		for(j = 0; j <= 6; j++) {
			for(i = 0; i < LH.StartY; i++) {
				GroundNode[j + 1][i + 1] = 1;
			}
		}
	}

	//轨道0x28624  0x4650 (0xC * 1500)Track
	MapTrk.resize(MapHdr.TrackCount);

	TrackNode.resize(MapHdr.BorR + 3);
	for(int i = 0; i < MapHdr.BorR + 3; i++) {
		TrackNode[i].resize(MapHdr.BorT + 3);
	}

	unsigned char TX = 0;
	for(M = 0; M < MapHdr.TrackCount; M++) {
		fseek(levelPtr, Offset + 0x28624 + 0x0 + M * 0xC, SEEK_SET);
		fread(&MapTrk[M].UN, sizeof(MapTrk[M].UN), 1, levelPtr);
		fread(&MapTrk[M].Flag, sizeof(MapTrk[M].Flag), 1, levelPtr);
		fread(&TX, sizeof(TX), 1, levelPtr);

		if(TX == 255) {
			MapTrk[M].X = 0;
		} else {
			MapTrk[M].X = (unsigned char)(TX + 1);
		}

		fread(&TX, sizeof(TX), 1, levelPtr);

		if(TX == 255) {
			MapTrk[M].Y = 0;
		} else {
			MapTrk[M].Y = (unsigned char)(TX + 1);
		}

		fread(&MapTrk[M].Type, sizeof(MapTrk[M].Type), 1, levelPtr);
		fread(&MapTrk[M].LID, sizeof(MapTrk[M].LID), 1, levelPtr);
		fread(&MapTrk[M].K0, sizeof(MapTrk[M].K0), 1, levelPtr);
		fread(&MapTrk[M].K1, sizeof(MapTrk[M].K1), 1, levelPtr);

		switch(MapTrk[M].Type) {
		case 0:
			TrackNode[MapTrk[M].X][MapTrk[M].Y + 1] += 1;
			TrackNode[MapTrk[M].X + 2][MapTrk[M].Y + 1] += 1;
			MapTrk[M].F0 = (unsigned char)(((MapTrk[M].K0 + 0x10000) / 0x80) % 2);
			MapTrk[M].F1 = (unsigned char)(((MapTrk[M].K1 + 0x10000) / 0x80) % 2);
			break;
		case 1:
			TrackNode[MapTrk[M].X + 1][MapTrk[M].Y + 2] += 1;
			TrackNode[MapTrk[M].X + 1][MapTrk[M].Y] += 1;
			MapTrk[M].F0 = (unsigned char)(((MapTrk[M].K0 + 0x10000) / 0x80) % 2);
			MapTrk[M].F1 = (unsigned char)(((MapTrk[M].K1 + 0x10000) / 0x80) % 2);
			break;
		case 2:
		case 4:
		case 5:
			TrackNode[MapTrk[M].X][MapTrk[M].Y + 2] += 1;
			TrackNode[MapTrk[M].X + 2][MapTrk[M].Y] += 1;
			MapTrk[M].F0 = (unsigned char)(((MapTrk[M].K0 + 0x10000) / 0x80) % 2);
			MapTrk[M].F1 = (unsigned char)(((MapTrk[M].K1 + 0x10000) / 0x80) % 2);
			break;
		case 3:
		case 6:
		case 7:
			TrackNode[MapTrk[M].X + 2][MapTrk[M].Y + 2] += 1;
			TrackNode[MapTrk[M].X][MapTrk[M].Y] += 1;
			MapTrk[M].F0 = (unsigned char)(((MapTrk[M].K0 + 0x10000) / 0x80) % 2);
			MapTrk[M].F1 = (unsigned char)(((MapTrk[M].K1 + 0x10000) / 0x80) % 2);
			break;
		case 8:
			TrackNode[MapTrk[M].X][MapTrk[M].Y + 2] += 1;
			TrackNode[MapTrk[M].X + 4][MapTrk[M].Y] += 1;
			TrackNode[MapTrk[M].X + 4][MapTrk[M].Y + 4] += 1;
			MapTrk[M].F0 = (unsigned char)(((MapTrk[M].K1 + 0x10000) / 0x80) % 2);
			MapTrk[M].F1 = (unsigned char)(((MapTrk[M].K0 + 0x10000) / 0x80) % 2);
			MapTrk[M].F2 = (unsigned char)(((MapTrk[M].K0 + 0x10000) / 0x8000) % 2);
			break;
		case 9:
			TrackNode[MapTrk[M].X][MapTrk[M].Y] += 1;
			TrackNode[MapTrk[M].X][MapTrk[M].Y + 4] += 1;
			TrackNode[MapTrk[M].X + 4][MapTrk[M].Y + 2] += 1;
			MapTrk[M].F0 = (unsigned char)(((MapTrk[M].K1 + 0x10000) / 0x40) % 2);
			MapTrk[M].F1 = (unsigned char)(((MapTrk[M].K1 + 0x10000) / 0x2) % 2);
			MapTrk[M].F2 = (unsigned char)(((MapTrk[M].K0 + 0x10000) / 0x80) % 2);
			break;
		case 10:
			TrackNode[MapTrk[M].X][MapTrk[M].Y] += 1;
			TrackNode[MapTrk[M].X + 2][MapTrk[M].Y + 4] += 1;
			TrackNode[MapTrk[M].X + 4][MapTrk[M].Y] += 1;
			MapTrk[M].F0 = (unsigned char)(1 - ((MapTrk[M].K0 + 0x10000) / 0x4000) % 2);
			MapTrk[M].F1 = (unsigned char)(((MapTrk[M].K1 + 0x10000) / 0x40) % 2);
			MapTrk[M].F2 = (unsigned char)(((MapTrk[M].K0 + 0x10000) / 0x80) % 2);
			break;
		case 11:
			TrackNode[MapTrk[M].X + 2][MapTrk[M].Y] += 1;
			TrackNode[MapTrk[M].X][MapTrk[M].Y + 4] += 1;
			TrackNode[MapTrk[M].X + 4][MapTrk[M].Y + 4] += 1;
			MapTrk[M].F0 = (unsigned char)(((MapTrk[M].K0 + 0x10000) / 0x80) % 2);
			MapTrk[M].F1 = (unsigned char)(((MapTrk[M].K1 + 0x10000) / 0x2) % 2);
			MapTrk[M].F2 = (unsigned char)(((MapTrk[M].K1 + 0x10000) / 0x40) % 2);
			break;
		case 12:
			TrackNode[MapTrk[M].X][MapTrk[M].Y + 2] += 1;
			TrackNode[MapTrk[M].X + 4][MapTrk[M].Y] += 1;
			TrackNode[MapTrk[M].X + 4][MapTrk[M].Y + 4] += 1;
			MapTrk[M].F0 = (unsigned char)(((MapTrk[M].K1 + 0x10000) / 0x800) % 2);
			MapTrk[M].F1 = (unsigned char)(((MapTrk[M].K0 + 0x10000) / 0x80) % 2);
			MapTrk[M].F2 = (unsigned char)(((MapTrk[M].K0 + 0x10000) / 0x1000) % 2);
			break;
		case 13:
			TrackNode[MapTrk[M].X][MapTrk[M].Y] += 1;
			TrackNode[MapTrk[M].X][MapTrk[M].Y + 4] += 1;
			TrackNode[MapTrk[M].X + 4][MapTrk[M].Y + 2] += 1;
			MapTrk[M].F0 = (unsigned char)(((MapTrk[M].K1 + 0x10000) / 0x800) % 2);
			MapTrk[M].F1 = (unsigned char)(((MapTrk[M].K0 + 0x10000) / 0x1000) % 2);
			MapTrk[M].F2 = (unsigned char)(((MapTrk[M].K0 + 0x10000) / 0x80) % 2);
			break;
		case 14:
			TrackNode[MapTrk[M].X][MapTrk[M].Y] += 1;
			TrackNode[MapTrk[M].X + 4][MapTrk[M].Y] += 1;
			TrackNode[MapTrk[M].X + 2][MapTrk[M].Y + 4] += 1;
			MapTrk[M].F0 = (unsigned char)(((MapTrk[M].K0 + 0x10000) / 0x1000) % 2);
			MapTrk[M].F1 = (unsigned char)(((MapTrk[M].K1 + 0x10000) / 0x800) % 2);
			MapTrk[M].F2 = (unsigned char)(((MapTrk[M].K0 + 0x10000) / 0x80) % 2);
			break;
		case 15:
			TrackNode[MapTrk[M].X + 2][MapTrk[M].Y] += 1;
			TrackNode[MapTrk[M].X][MapTrk[M].Y + 4] += 1;
			TrackNode[MapTrk[M].X + 4][MapTrk[M].Y + 4] += 1;
			MapTrk[M].F0 = (unsigned char)(((MapTrk[M].K0 + 0x10000) / 0x80) % 2);
			MapTrk[M].F1 = (unsigned char)(((MapTrk[M].K0 + 0x10000) / 0x1000) % 2);
			MapTrk[M].F2 = (unsigned char)(((MapTrk[M].K1 + 0x10000) / 0x800) % 2);
			break;
		}
	}
	//冰块0x2CC74  0x4B0 (0x4 * 300)Icicle
	MapIce.resize(MapHdr.IceCount);
	for(M = 0; M < MapHdr.IceCount; M++) {
		fseek(levelPtr, Offset + 0x2CC74 + 0x0 + M * 0x4, SEEK_SET);
		fread(&MapIce[M].X, sizeof(MapIce[M].X), 1, levelPtr);
		fread(&MapIce[M].Y, sizeof(MapIce[M].Y), 1, levelPtr);
		fread(&MapIce[M].ID, sizeof(MapIce[M].ID), 1, levelPtr);
	}

	fclose(levelPtr);
}