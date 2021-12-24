#pragma once

#define RAPIDJSON_HAS_STDSTRING 1

#include <SMM2CourseDecryptor/decrypt.h>
#include <cmath>
#include <codecvt>
#include <cstdint>
#include <cstdio>
#include <filesystem>
#include <fmt/format.h>
#include <fstream>
#include <locale>
#include <memory>
#include <rapidjson/writer.h>
#include <string>
#include <unordered_map>
#include <vector>

class LevelParser {
public:
	struct Point {
		bool isEmpty = true;
		int32_t X    = 0;
		int32_t Y    = 0;

		Point(int x, int y)
			: X(x)
			, Y(y) {};

		Point() {};
	};

	struct LvlHeader {
		uint8_t StartY        = 0; //-
		uint8_t GoalY         = 0; //-
		int16_t GoalX         = 0; //-
		int16_t Timer         = 0; //-
		int16_t ClearCA       = 0; //-
		int16_t DateYY        = 0; //?
		int8_t DateMM         = 0; //?
		int8_t DateDD         = 0; //?
		int8_t DateH          = 0; //?
		int8_t DateM          = 0; //?
		uint8_t AutoscrollSpd = 0; //-
		uint8_t ClearCC       = 0; //-
		int32_t ClearCRC      = 0; //-
		int32_t GameVer       = 0; //-
		int32_t MFlag         = 0; //?
		int32_t ClearAttempts = 0; //-
		int32_t ClearTime     = 0; //-
		uint32_t CreationID   = 0; //?
		int64_t UploadID      = 0; //?
		int32_t ClearVer      = 0; //-
		int16_t GameStyle     = 0; //-
		std::string Name;          //-
		std::string Desc;          //-
	};

	struct MapHeader {
		uint8_t Theme          = 0; //-
		uint8_t AutoscrollType = 0; //-
		uint8_t BorFlag        = 0; //-
		uint8_t Ori            = 0; //-
		uint8_t LiqEHeight     = 0; //-
		uint8_t LiqMode        = 0; //-
		uint8_t LiqSpd         = 0; //-
		uint8_t LiqSHeight     = 0; //-
		int32_t BorR           = 0; //-
		int32_t BorT           = 0; //-
		int32_t BorL           = 0; //-
		int32_t BorB           = 0; //-
		int32_t Flag           = 0; //-
		int32_t ObjCount       = 0; //-
		int32_t SndCount       = 0; //-
		int32_t SnakeCount     = 0; //-
		int32_t ClearPipCount  = 0; //-
		int32_t CreeperCount   = 0; //-
		int32_t iBlkCount      = 0; //-
		int32_t TrackBlkCount  = 0; //-
		int32_t GroundCount    = 0; //-
		int32_t TrackCount     = 0; //-
		int32_t IceCount       = 0; //-
	};

	struct MapObject {
		int32_t X        = 0;
		int32_t Y        = 0;
		uint8_t W        = 0;
		uint8_t H        = 0;
		int32_t Flag     = 0;
		int32_t CFlag    = 0;
		int32_t Ex       = 0;
		int16_t ID       = 0;
		int16_t CID      = 0;
		int16_t LID      = 0;
		int16_t SID      = 0;
		uint8_t LinkType = 0;
	};

	struct MapGround {
		uint8_t X   = 0;
		uint8_t Y   = 0;
		uint8_t ID  = 0;
		uint8_t BID = 0;
	};

	struct MapTrack {
		int16_t UN   = 0;
		uint8_t Flag = 0;
		uint8_t X    = 0;
		uint8_t Y    = 0;
		uint8_t Type = 0;
		int16_t LID  = 0;
		int16_t K0   = 0;
		int16_t K1   = 0;
		uint8_t F0   = 0;
		uint8_t F1   = 0;
		uint8_t F2   = 0;
	};

	struct MapClearPipeNode {
		uint8_t type  = 0;
		uint8_t index = 0;
		uint8_t X     = 0;
		uint8_t Y     = 0;
		uint8_t W     = 0;
		uint8_t H     = 0;
		uint8_t Dir   = 0;
	};

	struct MapClearPipe {
		uint8_t Index     = 0;
		uint8_t NodeCount = 0;
		std::vector<MapClearPipeNode> Node;
	};

	struct MapSnakeBlockNode {
		uint8_t index = 0;
		uint8_t Dir   = 0;
	};

	struct MapSnakeBlock {
		uint8_t index     = 0;
		uint8_t NodeCount = 0;
		std::vector<MapSnakeBlockNode> Node;
	};

	struct MapMoveBlockNode {
		uint8_t p0 = 0;
		uint8_t p1 = 0;
		uint8_t p2 = 0;
	};

	struct MapMoveBlock {
		uint8_t index     = 0;
		int16_t NodeCount = 0;
		std::vector<MapMoveBlockNode> Node;
	};

	struct MapCreeper {
		uint8_t index     = 0;
		int16_t NodeCount = 0;
		std::vector<uint8_t> Node;
	};

	struct ObjStr {
		std::string Obj;
		std::string Flag;
		std::string State;
		std::string SubObj;
		std::string SubFlag;
		std::string SubState;
	};

	LvlHeader LH;
	std::vector<MapClearPipe> MapCPipe;
	std::vector<MapSnakeBlock> MapSnk;
	std::vector<std::vector<Point>> TrackYPt;
	std::vector<std::vector<int>> TrackNode;
	std::vector<std::vector<int>> GroundNode;
	std::vector<MapMoveBlock> MapMoveBlk;
	std::vector<MapMoveBlock> MapTrackBlk;
	std::vector<MapCreeper> MapCrp;
	std::vector<uint8_t> ObjLinkType = std::vector<uint8_t>(60000);
	//地图文件头H48
	// std::vector<MapHeader> MH = std::vector<MapHeader>(3);
	MapHeader MapHdr;
	std::vector<MapObject> MapObj;
	std::vector<MapGround> MapGrd;
	std::vector<MapGround> MapIce;
	std::vector<MapTrack> MapTrk;

	std::vector<std::vector<Point>> TileLoc;
	std::vector<std::vector<Point>> PipeLoc;
	std::vector<Point> GrdLoc = std::vector<Point>(258);
	std::vector<std::vector<std::vector<ObjStr>>> ObjLocData;
	bool isOverworld;

	LevelParser();
	// std::string GetItemName(int n, int v);
	static bool DecryptLevelData(const std::string& input, const std::string& output);
	void LoadLevelData(const std::string& P, bool overworld);
	void ExportToJSON(const std::string& outputPath);
};

/*
static const char* ObjEng3[] = { "Baby Chestnut", "Turtle Slowly", "Eat Flower", "Brother Hammer", "Soft Brick",
"? Brick", "Hard Brick", "Ground", "Gold Coin", "Water Pipe", "Spring", "Elevating Platform", "Dong Dong", "Fort",
"Mushroom Platform", "Bombman", "Half Collision Platform", "Bridge", "P Switch", "POW", "Mushroom", "Bamboo Wheel",
"Cloud Brick", "Musical Note", "Fire Rod", "Thorn Tortoise", "End Brick", "End Flag", "Helmet Turtle",
"Hidden Brick", "Ball game", "Ball Game Cloud", "Cannonball Assassin", "1UP Mushroom", "Flame Flower",
"Invincible Star", "Lava Table", "Starting Brick", "Starting Arrow", "Mage", "Spiked turtle", "Ghost",
"Clown Spaceship", "Thorn", "Super Leaf", "Shoe Chestnut", "Cracked Tortoise", "Cannon", "Squid", "Castle Bridge",
"Jumping Machine", "Jumping Mouse", "Flower Maomao", "Conveyor Belt", "Airbrush", "Door", "Bubble Fish",
"Black Flower", "Wrencher", "Track", "Flame Bubble", "Wow", "Kuba", "Ice Brick", "Tree Vine", "Ding Ding Bee",
"Arrow", "One-way Board", "Circular Saw", "Player", "10/30/50 Gold Coins", "Half Collision Platform",
"Slowly Turtle Car", "Cinobio", "Gabon/Iron Ball", "Stone", "Tornado", "Ben Ben", "Cactus", "P Brick",
"Sprint Brick", "Frog Pack", "Circle", "Mace", "Snake", "Mobile Brick", "Uka", "Steep Slope", "Slight Slope",
"Reel Camera", "Middle Flag", "Seesaw", "Red Coin", "Transparent Water Pipe", "Ramp Conveyor", "Key", "Ant Soldier",
"Transport Box", "Little Kuba", "Switch", "Dotted Brick", "Water Marker", "Mole", "Fishbone", "Sun/Moon",
"Swing Arm", "Tree", "Long swallows flowers", "Flashing Brick", "Sound", "Spiked Brick", "Mechanical Kuba",
"Wooden Box", "Mushroom Jumping Bed", "Spiked Pufferfish", "Cinobic", "Super Hammer", "Dou Dou", "Ice Cone",
"! Brick", "Remy", "Morton", "Larry", "Windy", "Egy", "Roy", "Rodwig", "Castle Box", "Propeller Box",
"Paper Chestnut Baby", "Paper Cannonball Assassin", "Red POW Box", "Switch Jumping on Bed" };
static const char*
ObjEngW[] = { "Li Bangbang", "Slowly Turtle", "Swallowing Flowers", "Hammer Brothers", "Soft Bricks",
"? Bricks", "Hard Bricks", "Grounds", "Gold Coin", "Water Pipe", "Spring", "Elevating Platform", "Dong Dong",
"Fort", "Mushroom Platform", "Bombman", "Half Collision Platform", "Bridge", "P Switch", "POW", "Mushroom",
"Bamboo Wheel", "Cloud Brick", "Musical Note", "Fire Rod", "Thorn Tortoise", "End Brick", "End Flag",
"Helmet Turtle", "Hidden Brick", "Ball game", "Ball Game Cloud", "Cannonball Assassin", "1UP Mushroom",
"Flame Flower", "Invincible Star", "Lava Table", "Starting Brick", "Starting Arrow", "Mage", "Spiked turtle",
"Ghost", "Clown Spaceship", "Thorn", "Cape Feather", "Yoshi", "Cracked Tortoise", "Cannon", "Squid",
"Castle Bridge", "Jumping Machine", "Jerboa", "Flower Maomao", "Conveyor Belt", "Airbrush", "Door", "Bubble Fish",
"Black Flower", "Wrencher", "Track", "Flame Bubble", "Wow", "Kuba", "Ice Brick", "Tree Vine", "Ding Ding Bee",
"Arrow", "One-way Board", "Circular Saw", "Player", "10/30/50 Gold Coins", "Half Collision Platform",
"Slowly Turtle Car", "Cinobio", "Gabon/Iron Ball", "Stone", "Tornado", "Boom", "Cactus", "P Brick", "Sprint Brick",
"Power Balloon", "Circle", "Mace", "Snake", "Mobile Brick", "Uka", "Steep Slope", "Slight Slope", "Reel Camera",
"Middle Flag", "Seesaw", "Red Coin", "Transparent Water Pipe", "Ramp Conveyor", "Key", "Ant Soldier",
"Transport Box", "Little Kuba", "Switch", "Dotted Brick", "Water Marker", "Mole", "Fishbone", "Sun/Moon",
"Swing Arm", "Tree", "Long swallows flowers", "Flashing Brick", "Sound", "Spiked Brick", "Mechanical Kuba",
"Wooden Box", "Mushroom Jumping Bed", "Spiked Pufferfish", "Cinobic", "Super Hammer", "Dou Dou", "Ice Cone",
"! Brick", "Remy", "Morton", "Larry", "Windy", "Egy", "Roy", "Rodwig", "Castle Box", "Propeller Box",
"Paper Chestnut Baby", "Paper Cannonball Assassin", "Red POW Box", "Switch Jumping on Bed" };
static const char*
ObjEngU[] = { "Baby Chestnut", "Turtle Slowly", "Eat Flower", "Brother Hammer", "Soft Brick",
"? Brick", "Hard Brick", "Ground", "Gold Coin", "Water Pipe", "Spring", "Elevating Platform", "Dong Dong", "Fort",
"Mushroom Platform", "Bombman", "Half Collision Platform", "Bridge", "P Switch", "POW", "Mushroom", "Bamboo Wheel",
"Cloud Brick", "Musical Note", "Fire Rod", "Thorn Tortoise", "End Brick", "End Flag", "Helmet Turtle",
"Hidden Brick", "Ball game", "Ball Game Cloud", "Cannonball Assassin", "1UP Mushroom", "Flame Flower",
"Invincible Star", "Lava Table", "Starting Brick", "Starting Arrow", "Mage", "Spiked turtle", "Ghost",
"Clown Spaceship", "Thorn", "Propeller Mushroom", "Yoshi", "Cracked Tortoise", "Cannon", "Squid", "Castle Bridge",
"Jumping Machine", "Jerboa", "Flower Maomao", "Conveyor Belt", "Airbrush", "Door", "Bubble Fish", "Black Flower",
"Wrencher", "Track", "Flame Bubble", "Wow", "Kuba", "Ice Brick", "Tree Vine", "Ding Ding Bee", "Arrow",
"One-way Board", "Circular Saw", "Player", "10/30/50 Gold Coins", "Half Collision Platform", "Slowly Turtle Car",
"Cinobio", "Gabon/Iron Ball", "Stone", "Tornado", "Ben Ben", "Cactus", "P Brick", "Sprint Brick",
"Super Oak Chestnut", "Circle", "Mace", "Snake", "Mobile Brick", "Uka", "Steep Slope", "Slight Slope",
"Reel Camera", "Middle Flag", "Seesaw", "Red Coin", "Transparent Water Pipe", "Ramp Conveyor", "Key", "Ant Soldier",
"Transport Box", "Little Kuba", "Switch", "Dotted Brick", "Water Marker", "Mole", "Fishbone", "Sun/Moon",
"Swing Arm", "Tree", "Long swallows flowers", "Flashing Brick", "Sound", "Spiked Brick", "Mechanical Kuba",
"Wooden Box", "Mushroom Jumping Bed", "Spiked Pufferfish", "Cinobic", "Super Hammer", "Dou Dou", "Ice Cone",
"! Brick", "Remy", "Morton", "Larry", "Windy", "Egy", "Roy", "Rodwig", "Castle Box", "Propeller Box",
"Paper Chestnut Baby", "Paper Cannonball Assassin", "Red POW Box", "Switch Jumping on Bed" };
static const char*
ObjEngD[] = { "Chestnut", "turtle slowly", "devouring flowers", "hammer brothers", "soft bricks",
"? bricks", "hard bricks", "ground", "gold coins", "Water Pipe", "Spring", "Elevating Platform", "Dong Dong",
"Fort", "Mushroom Platform", "Bomberman", "Half Collision Platform", "Bridge", "P Switch", "POW", "mushroom",
"Bamboo Wheel", "Cloud Brick", "Music Note", "Fire Rod", "Spike Turtle", "End Brick", "End Flag", "Helmet Turtle",
"Hidden Brick", "Ball Game", "Ball Gaim Cloud", "Cannonball Assassin", "1UP Mushroom", "Flame Flower",
"Invincible Star", "Lava Table", "Starting Brick", "Starting Arrow", "Magic", "Spiked Turtle", "Ghost",
"Joker Spaceship", "Thorn", "Super Bell", "Shoes/Yoshi", "Cracked Tortoise", "Cannon", "Squid", "Castle Bridge",
"Jumping Machine", "Jumping Rat", "Hua Mao Mao", "Conveyor Belt", "Airbrush", "Door", "Bubble Fish", "Black Flower",
"Wrench Boy", "Track", "Flame Bubble", "Wow", "Kuba", "Ice Brick", "Tree Vine", "Ding Ding Bee", "Arrow",
"One Way Board", "Circular Saw", "Player", "10/30/50 Gold Coins", "Semi-Collision Platform", "Slow Turtle Car",
"Chino Bio", "Gabon/Iron Ball", "Stone", "Tornado", "Boom", "Cactus", "P Brick", "Sprint Brick", "Boomerang Flower",
"Circle", "Mace", "Snake", "Mobile Brick", "Uka", "Steep Slope", "Slight Slope", "Reel Camera", "Middle Flag",
"Seesaw", "Red Coin", "Transparent Water Pipe", "Ramp Conveyor", "Key", "Ant Soldier", "Transport Box",
"Little Kuba", "Switch", "Dotted Brick", "Water Marker", "Mole", "Fishbone", "Sun/Moon", "Swing Arm", "Tree",
"Long swallows flowers", "Flashing Brick", "Sound", "Spiked Brick", "Mechanical Kuba", "Wooden Box",
"Mushroom Jumping Bed", "Spiked Pufferfish", "Cinobic", "Super Hammer", "Dou Dou", "Ice Cone", "! Brick", "Remy",
"Morton", "Larry", "Windy", "Egy", "Roy", "Rodwig", "Castle Box", "Propeller Box", "Paper Chestnut Baby",
"Paper Cannonball Assassin", "Red POW Box", "Switch Jumping on Bed" };
static
const char* Badges[]
= { "", "Gold ribbon", "Silver ribbon", "Copper ribbon", "Gold medal", "Silver medal", "Bronze medal" };
static
const char* BadgesType[] = { "Craftsman Points", "Endurance Challenge (Easy)", "Endurance Challenge (Normal)",
"Endurance Challenge (Difficult)", "Endurance Challenge (Extremely Difficult)", "Multiplayer Battle",
"Number of Passes", "Number of Passes First", "Number of Points in the int16_test Time", "Artisan Points (week)" };
*/

extern const char* ObjEng[];

class LevelParserMappings {
public:
	const std::unordered_map<int16_t, std::string> NumToGameStyle = {
		{ 12621, "SMB1" },
		{ 13133, "SMB3" },
		{ 22349, "SMW" },
		{ 21847, "NSMBU" },
		{ 22323, "SM3DW" },
	};

	const std::unordered_map<uint8_t, std::string> NumToClearConditionCategory = {
		{ 0, "None" },
		{ 1, "Parts" },
		{ 2, "Status" },
		{ 3, "Actions" },
	};

	const std::unordered_map<int32_t, std::string> NumToGameVersion = {
		{ 0, "1.0.0" },
		{ 1, "1.0.1" },
		{ 2, "1.1.0" },
		{ 3, "2.0.0" },
		{ 4, "3.0.0" },
		{ 5, "3.0.1" },
		{ 33, "What" },
	};

	const std::unordered_map<int32_t, std::string> NumToClearCondition = {
		{ 0, "None" },
		{ 137525990, "Reach the goal without landing after leaving the ground." },
		{ 199585683, "Reach the goal after defeating at least/all {} Mechakoopa(s)." },
		{ 272349836, "Reach the goal after defeating at least/all {} Cheep Cheep(s)." },
		{ 375673178, "Reach the goal without taking damage." },
		{ 426197923, "Reach the goal as Boomerang Mario." },
		{ 436833616, "Reach the goal while wearing a Shoe." },
		{ 713979835, "Reach the goal as Fire Mario." },
		{ 744927294, "Reach the goal as Frog Mario." },
		{ 751004331, "Reach the goal after defeating at least/all {} Larry(s)." },
		{ 900050759, "Reach the goal as Raccoon Mario." },
		{ 947659466, "Reach the goal after defeating at least/all {} Blooper(s)." },
		{ 976173462, "Reach the goal as Propeller Mario." },
		{ 994686866, "Reach the goal while wearing a Propeller Box." },
		{ 998904081, "Reach the goal after defeating at least/all {} Spike(s)." },
		{ 1008094897, "Reach the goal after defeating at least/all {} Boom Boom(s)." },
		{ 1051433633, "Reach the goal while holding a Koopa Shell." },
		{ 1061233896, "Reach the goal after defeating at least/all {} Porcupuffer(s)." },
		{ 1062253843, "Reach the goal after defeating at least/all {} Charvaargh(s)." },
		{ 1079889509, "Reach the goal after defeating at least/all {} Bullet Bill(s)." },
		{ 1080535886, "Reach the goal after defeating at least/all {} Bully/Bullies." },
		{ 1151250770, "Reach the goal while wearing a Goomba Mask." },
		{ 1182464856, "Reach the goal after defeating at least/all {} Hop-Chops." },
		{ 1219761531,
			"Reach the goal while holding a Red POW Block. OR Reach the goal after activating at least/all {} Red POW Block(s)." },
		{ 1221661152, "Reach the goal after defeating at least/all {} Bob-omb(s)." },
		{ 1259427138, "Reach the goal after defeating at least/all {} Spiny/Spinies." },
		{ 1268255615, "Reach the goal after defeating at least/all {} Bowser(s)/Meowser(s)." },
		{ 1279580818, "Reach the goal after defeating at least/all {} Ant Trooper(s)." },
		{ 1283945123, "Reach the goal on a Lakitu's Cloud." },
		{ 1344044032, "Reach the goal after defeating at least/all {} Boo(s)." },
		{ 1425973877, "Reach the goal after defeating at least/all {} Roy(s)." },
		{ 1429902736, "Reach the goal while holding a Trampoline." },
		{ 1431944825, "Reach the goal after defeating at least/all {} Morton(s)." },
		{ 1446467058, "Reach the goal after defeating at least/all {} Fish Bone(s)." },
		{ 1510495760, "Reach the goal after defeating at least/all {} Monty Mole(s)." },
		{ 1656179347, "Reach the goal after picking up at least/all {} 1-Up Mushroom(s)." },
		{ 1665820273, "Reach the goal after defeating at least/all {} Hammer Bro(s.)." },
		{ 1676924210,
			"Reach the goal after hitting at least/all {} P Switch(es). OR Reach the goal while holding a P Switch." },
		{ 1715960804,
			"Reach the goal after activating at least/all {} POW Block(s). OR Reach the goal while holding a POW Block." },
		{ 1724036958, "Reach the goal after defeating at least/all {} Angry Sun(s)." },
		{ 1730095541, "Reach the goal after defeating at least/all {} Pokey(s)." },
		{ 1780278293, "Reach the goal as Superball Mario." },
		{ 1839897151, "Reach the goal after defeating at least/all {} Pom Pom(s)." },
		{ 1969299694, "Reach the goal after defeating at least/all {} Peepa(s)." },
		{ 2035052211, "Reach the goal after defeating at least/all {} Lakitu(s)." },
		{ 2038503215, "Reach the goal after defeating at least/all {} Lemmy(s)." },
		{ 2048033177, "Reach the goal after defeating at least/all {} Lava Bubble(s)." },
		{ 2076496776, "Reach the goal while wearing a Bullet Bill Mask." },
		{ 2089161429, "Reach the goal as Big Mario." },
		{ 2111528319, "Reach the goal as Cat Mario." },
		{ 2131209407, "Reach the goal after defeating at least/all {} Goomba(s)/Galoomba(s)." },
		{ 2139645066, "Reach the goal after defeating at least/all {} Thwomp(s)." },
		{ 2259346429, "Reach the goal after defeating at least/all {} Iggy(s)." },
		{ 2549654281, "Reach the goal while wearing a Dry Bones Shell." },
		{ 2694559007, "Reach the goal after defeating at least/all {} Sledge Bro(s.)." },
		{ 2746139466, "Reach the goal after defeating at least/all {} Rocky Wrench(es)." },
		{ 2749601092, "Reach the goal after grabbing at least/all {} 50-Coin(s)." },
		{ 2855236681, "Reach the goal as Flying Squirrel Mario." },
		{ 3036298571, "Reach the goal as Buzzy Mario." },
		{ 3074433106, "Reach the goal as Builder Mario." },
		{ 3146932243, "Reach the goal as Cape Mario." },
		{ 3174413484, "Reach the goal after defeating at least/all {} Wendy(s)." },
		{ 3206222275, "Reach the goal while wearing a Cannon Box." },
		{ 3314955857, "Reach the goal as Link." },
		{ 3342591980, "Reach the goal while you have Super Star invincibility." },
		{ 3346433512, "Reach the goal after defeating at least/all {} Goombrat(s)/Goombud(s)." },
		{ 3348058176, "Reach the goal after grabbing at least/all {} 10-Coin(s)." },
		{ 3353006607, "Reach the goal after defeating at least/all {} Buzzy Beetle(s)." },
		{ 3392229961, "Reach the goal after defeating at least/all {} Bowser Jr.(s)." },
		{ 3437308486, "Reach the goal after defeating at least/all {} Koopa Troopa(s)." },
		{ 3459144213, "Reach the goal after defeating at least/all {} Chain Chomp(s)." },
		{ 3466227835, "Reach the goal after defeating at least/all {} Muncher(s)." },
		{ 3481362698, "Reach the goal after defeating at least/all {} Wiggler(s)." },
		{ 3513732174, "Reach the goal as SMB2 Mario." },
		{ 3649647177, "Reach the goal in a Koopa Clown Car/Junior Clown Car." },
		{ 3725246406, "Reach the goal as Spiny Mario." },
		{ 3730243509, "Reach the goal in a Koopa Troopa Car." },
		{ 3748075486, "Reach the goal after defeating at least/all {} Piranha Plant(s)/Jumping Piranha Plant(s)." },
		{ 3797704544, "Reach the goal after defeating at least/all {} Dry Bones." },
		{ 3824561269, "Reach the goal after defeating at least/all {} Stingby/Stingbies." },
		{ 3833342952, "Reach the goal after defeating at least/all {} Piranha Creeper(s)." },
		{ 3842179831, "Reach the goal after defeating at least/all {} Fire Piranha Plant(s)." },
		{ 3874680510, "Reach the goal after breaking at least/all {} Crates(s)." },
		{ 3974581191, "Reach the goal after defeating at least/all {} Ludwig(s)." },
		{ 3977257962, "Reach the goal as Super Mario." },
		{ 4042480826, "Reach the goal after defeating at least/all {} Skipsqueak(s)." },
		{ 4116396131, "Reach the goal after grabbing at least/all {} Coin(s)." },
		{ 4117878280, "Reach the goal after defeating at least/all {} Magikoopa(s)." },
		{ 4122555074, "Reach the goal after grabbing at least/all {} 30-Coin(s)." },
		{ 4153835197, "Reach the goal as Balloon Mario." },
		{ 4172105156, "Reach the goal while wearing a Red POW Box." },
		{ 4209535561, "Reach the Goal while riding Yoshi." },
		{ 4269094462, "Reach the goal after defeating at least/all {} Spike Top(s)." },
		{ 4293354249, "Reach the goal after defeating at least/all {} Banzai Bill(s)." },
	};

	const std::unordered_map<uint8_t, std::string> NumToTheme = {
		{ 0, "Overworld" },
		{ 1, "Underground" },
		{ 2, "Castle" },
		{ 3, "Airship" },
		{ 4, "Underwater" },
		{ 5, "Ghost house" },
		{ 6, "Snow" },
		{ 7, "Desert" },
		{ 8, "Sky" },
		{ 9, "Forest" },
	};

	const std::unordered_map<uint8_t, std::string> NumToAutoscrollSpeed = {
		{ 0, "x1" },
		{ 1, "x2" },
		{ 2, "x3" },
	};

	const std::unordered_map<uint8_t, std::string> NumToAutoscrollType = {
		{ 0, "None" },
		{ 1, "Slow" },
		{ 2, "Normal" },
		{ 3, "Fast" },
		{ 4, "Custom" },
	};

	const std::unordered_map<uint8_t, std::string> NumToBoundaryType = {
		{ 0, "Built Above Line" },
		{ 1, "Built Below Line" },
	};

	const std::unordered_map<uint8_t, std::string> NumToOrientation = {
		{ 0, "Horizontal" },
		{ 1, "Vertical" },
	};

	const std::unordered_map<uint8_t, std::string> NumToLiquidMode = {
		{ 0, "Static" },
		{ 1, "Rising or Falling" },
		{ 2, "Rising and Falling" },
	};

	const std::unordered_map<uint8_t, std::string> NumToLiquidSpeed = {
		{ 0, "None" },
		{ 1, "x1" },
		{ 2, "x2" },
		{ 3, "x3" },
	};

	const std::string FormatMillisecondTime(int32_t milliseconds) {
		int32_t seconds  = (milliseconds / 1000) % 60;
		int32_t minutes  = (milliseconds / 1000) / 60;
		milliseconds     = milliseconds % 1000;
		std::string time = fmt::format("{}:{:02}.{}", minutes, seconds, milliseconds);
		return time;
	}
};

extern LevelParserMappings* levelMappings;