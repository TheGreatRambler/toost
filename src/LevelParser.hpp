#pragma once

#include <SMM2CourseDecryptor/decrypt.h>
#include <cmath>
#include <codecvt>
#include <cstdint>
#include <cstdio>
#include <fmt/format.h>
#include <locale>
#include <memory>
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
		uint8_t StartY        = 0;
		uint8_t GoalY         = 0;
		int16_t GoalX         = 0;
		int16_t Timer         = 0;
		int16_t ClearCA       = 0;
		int16_t DateYY        = 0;
		uint8_t DateMM        = 0;
		uint8_t DateDD        = 0;
		uint8_t DateH         = 0;
		uint8_t DateM         = 0;
		uint8_t AutoscrollSpd = 0;
		uint8_t ClearCC       = 0;
		int32_t ClearCRC      = 0;
		int32_t GameVer       = 0;
		int32_t MFlag         = 0;
		int32_t ClearAttempts = 0; //-
		int32_t ClearTime     = 0; //-
		uint32_t CreationID   = 0;
		int64_t UploadID      = 0;
		int32_t ClearVer      = 0;
		int16_t GameStyle     = 0; //-
		std::string Name;          //-
		std::string Desc;          //-
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

	struct MapHeader {
		uint8_t Theme          = 0;
		uint8_t AutoscrollType = 0;
		uint8_t BorFlag        = 0;
		uint8_t Ori            = 0;
		uint8_t LiqEHeight     = 0;
		uint8_t LiqMode        = 0;
		uint8_t LiqSpd         = 0;
		uint8_t LiqSHeight     = 0;
		int32_t BorR           = 0;
		int32_t BorT           = 0;
		int32_t BorL           = 0;
		int32_t BorB           = 0;
		int32_t Flag           = 0;
		int32_t ObjCount       = 0;
		int32_t SndCount       = 0;
		int32_t SnakeCount     = 0;
		int32_t ClearPipCount  = 0;
		int32_t CreeperCount   = 0;
		int32_t iBlkCount      = 0;
		int32_t TrackBlkCount  = 0;
		int32_t GroundCount    = 0;
		int32_t TrackCount     = 0;
		int32_t IceCount       = 0;
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

	std::vector<int> MapWidth  = std::vector<int>(3);
	std::vector<int> MapHeight = std::vector<int>(3);
	LvlHeader LH;
	std::vector<MapClearPipe> MapCPipe;
	std::vector<MapSnakeBlock> MapSnk;
	int32_t OSNK = 0;
	std::vector<std::vector<Point>> TrackYPt; // NEW
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

	/*
	std::vector<std::string> ObjEng = { "栗宝宝", "慢慢龟", "吞食花", "铁锤兄弟", "软砖", "？砖", "硬砖", "地面",
		"金币", "水管", "弹簧", "升降台", "咚咚", "炮台", "蘑菇平台", "炸弹兵", "半碰撞平台", "桥", "P开关", "POW",
		"蘑菇", "竹轮", "云砖", "音符", "火焰棒", "刺刺龟", "终点砖", "终点旗", "钢盔龟", "隐藏砖", "球盖姆",
		"球盖姆云", "炮弹刺客", "1UP蘑菇", "火焰花", "无敌星", "熔岩台", "起点砖", "起点箭头", "魔法师", "尖刺龟",
		"幽灵", "小丑飞船", "刺", "大蘑菇", "鞋子栗宝宝", "碎碎龟", "加农炮", "鱿鱿", "城堡桥", "跳跳机", "跳跳鼠",
		"花毛毛", "传送带", "喷枪", "门", "泡泡鱼", "黑花", "扳手仔", "轨道", "火焰泡泡", "汪汪", "库巴", "冰砖",
		"树藤", "叮叮蜂", "箭头", "单向板", "圆锯", "Player", "10/30/50金币", "半碰撞平台", "慢慢龟汽车", "奇诺比奥",
		"加邦/铁球", "石头", "龙卷风", "奔奔", "仙人掌", "P砖", "冲刺砖", "USA蘑菇", "圈圈", "狼牙棒", "蛇", "机动砖",
		"乌卡", "陡坡", "缓坡", "卷轴相机", "中间旗", "跷跷板", "红币", "透明水管", "斜坡传送带", "钥匙", "蚂蚁兵",
		"传送箱", "小库巴", "开关", "虚线砖", "水面标记", "鼹鼠", "鱼骨", "太阳/月亮", "摇摆吊臂", "树", "长长吞食花",
		"闪烁砖", "声音", "尖刺砖", "机械库巴", "木箱", "蘑菇跳跳床", "尖刺河豚", "奇诺比珂", "超级锤子", "斗斗",
		"冰锥", "！砖", "雷米", "莫顿", "拉里", "温缇", "伊吉", "罗伊", "洛德威格", "炮台箱", "螺旋桨箱", "纸糊栗宝宝",
		"纸糊炮弹刺客", "红色POW箱", "开关跳跳床" };
	std::vector<std::string> ObjEng3 = { "栗宝宝", "慢慢龟", "吞食花", "铁锤兄弟", "软砖", "？砖", "硬砖", "地面",
		"金币", "水管", "弹簧", "升降台", "咚咚", "炮台", "蘑菇平台", "炸弹兵", "半碰撞平台", "桥", "P开关", "POW",
		"蘑菇", "竹轮", "云砖", "音符", "火焰棒", "刺刺龟", "终点砖", "终点旗", "钢盔龟", "隐藏砖", "球盖姆",
		"球盖姆云", "炮弹刺客", "1UP蘑菇", "火焰花", "无敌星", "熔岩台", "起点砖", "起点箭头", "魔法师", "尖刺龟",
		"幽灵", "小丑飞船", "刺", "超级树叶", "鞋子栗宝宝", "碎碎龟", "加农炮", "鱿鱿", "城堡桥", "跳跳机", "跳跳鼠",
		"花毛毛", "传送带", "喷枪", "门", "泡泡鱼", "黑花", "扳手仔", "轨道", "火焰泡泡", "汪汪", "库巴", "冰砖",
		"树藤", "叮叮蜂", "箭头", "单向板", "圆锯", "Player", "10/30/50金币", "半碰撞平台", "慢慢龟汽车", "奇诺比奥",
		"加邦/铁球", "石头", "龙卷风", "奔奔", "仙人掌", "P砖", "冲刺砖", "青蛙装", "圈圈", "狼牙棒", "蛇", "机动砖",
		"乌卡", "陡坡", "缓坡", "卷轴相机", "中间旗", "跷跷板", "红币", "透明水管", "斜坡传送带", "钥匙", "蚂蚁兵",
		"传送箱", "小库巴", "开关", "虚线砖", "水面标记", "鼹鼠", "鱼骨", "太阳/月亮", "摇摆吊臂", "树", "长长吞食花",
		"闪烁砖", "声音", "尖刺砖", "机械库巴", "木箱", "蘑菇跳跳床", "尖刺河豚", "奇诺比珂", "超级锤子", "斗斗",
		"冰锥", "！砖", "雷米", "莫顿", "拉里", "温缇", "伊吉", "罗伊", "洛德威格", "炮台箱", "螺旋桨箱", "纸糊栗宝宝",
		"纸糊炮弹刺客", "红色POW箱", "开关跳跳床" };
	std::vector<std::string> ObjEngW = { "栗邦邦", "慢慢龟", "吞食花", "铁锤兄弟", "软砖", "？砖", "硬砖", "地面",
		"金币", "水管", "弹簧", "升降台", "咚咚", "炮台", "蘑菇平台", "炸弹兵", "半碰撞平台", "桥", "P开关", "POW",
		"蘑菇", "竹轮", "云砖", "音符", "火焰棒", "刺刺龟", "终点砖", "终点旗", "钢盔龟", "隐藏砖", "球盖姆",
		"球盖姆云", "炮弹刺客", "1UP蘑菇", "火焰花", "无敌星", "熔岩台", "起点砖", "起点箭头", "魔法师", "尖刺龟",
		"幽灵", "小丑飞船", "刺", "斗篷羽毛", "耀西", "碎碎龟", "加农炮", "鱿鱿", "城堡桥", "跳跳机", "跳跳鼠",
		"花毛毛", "传送带", "喷枪", "门", "泡泡鱼", "黑花", "扳手仔", "轨道", "火焰泡泡", "汪汪", "库巴", "冰砖",
		"树藤", "叮叮蜂", "箭头", "单向板", "圆锯", "Player", "10/30/50金币", "半碰撞平台", "慢慢龟汽车", "奇诺比奥",
		"加邦/铁球", "石头", "龙卷风", "奔奔", "仙人掌", "P砖", "冲刺砖", "力量气球", "圈圈", "狼牙棒", "蛇", "机动砖",
		"乌卡", "陡坡", "缓坡", "卷轴相机", "中间旗", "跷跷板", "红币", "透明水管", "斜坡传送带", "钥匙", "蚂蚁兵",
		"传送箱", "小库巴", "开关", "虚线砖", "水面标记", "鼹鼠", "鱼骨", "太阳/月亮", "摇摆吊臂", "树", "长长吞食花",
		"闪烁砖", "声音", "尖刺砖", "机械库巴", "木箱", "蘑菇跳跳床", "尖刺河豚", "奇诺比珂", "超级锤子", "斗斗",
		"冰锥", "！砖", "雷米", "莫顿", "拉里", "温缇", "伊吉", "罗伊", "洛德威格", "炮台箱", "螺旋桨箱", "纸糊栗宝宝",
		"纸糊炮弹刺客", "红色POW箱", "开关跳跳床" };
	std::vector<std::string> ObjEngU = { "栗宝宝", "慢慢龟", "吞食花", "铁锤兄弟", "软砖", "？砖", "硬砖", "地面",
		"金币", "水管", "弹簧", "升降台", "咚咚", "炮台", "蘑菇平台", "炸弹兵", "半碰撞平台", "桥", "P开关", "POW",
		"蘑菇", "竹轮", "云砖", "音符", "火焰棒", "刺刺龟", "终点砖", "终点旗", "钢盔龟", "隐藏砖", "球盖姆",
		"球盖姆云", "炮弹刺客", "1UP蘑菇", "火焰花", "无敌星", "熔岩台", "起点砖", "起点箭头", "魔法师", "尖刺龟",
		"幽灵", "小丑飞船", "刺", "螺旋桨蘑菇", "耀西", "碎碎龟", "加农炮", "鱿鱿", "城堡桥", "跳跳机", "跳跳鼠",
		"花毛毛", "传送带", "喷枪", "门", "泡泡鱼", "黑花", "扳手仔", "轨道", "火焰泡泡", "汪汪", "库巴", "冰砖",
		"树藤", "叮叮蜂", "箭头", "单向板", "圆锯", "Player", "10/30/50金币", "半碰撞平台", "慢慢龟汽车", "奇诺比奥",
		"加邦/铁球", "石头", "龙卷风", "奔奔", "仙人掌", "P砖", "冲刺砖", "超级橡栗", "圈圈", "狼牙棒", "蛇", "机动砖",
		"乌卡", "陡坡", "缓坡", "卷轴相机", "中间旗", "跷跷板", "红币", "透明水管", "斜坡传送带", "钥匙", "蚂蚁兵",
		"传送箱", "小库巴", "开关", "虚线砖", "水面标记", "鼹鼠", "鱼骨", "太阳/月亮", "摇摆吊臂", "树", "长长吞食花",
		"闪烁砖", "声音", "尖刺砖", "机械库巴", "木箱", "蘑菇跳跳床", "尖刺河豚", "奇诺比珂", "超级锤子", "斗斗",
		"冰锥", "！砖", "雷米", "莫顿", "拉里", "温缇", "伊吉", "罗伊", "洛德威格", "炮台箱", "螺旋桨箱", "纸糊栗宝宝",
		"纸糊炮弹刺客", "红色POW箱", "开关跳跳床" };
	std::vector<std::string> ObjEngD = { "板栗", "慢慢龟", "吞食花", "铁锤兄弟", "软砖", "？砖", "硬砖", "地面", "金币",
		"水管", "弹簧", "升降台", "咚咚", "炮台", "蘑菇平台", "炸弹兵", "半碰撞平台", "桥", "P开关", "POW", "蘑菇",
		"竹轮", "云砖", "音符", "火焰棒", "刺刺龟", "终点砖", "终点旗", "钢盔龟", "隐藏砖", "球盖姆", "球盖姆云",
		"炮弹刺客", "1UP蘑菇", "火焰花", "无敌星", "熔岩台", "起点砖", "起点箭头", "魔法师", "尖刺龟", "幽灵",
		"小丑飞船", "刺", "超级铃铛", "鞋/耀西", "碎碎龟", "加农炮", "鱿鱿", "城堡桥", "跳跳机", "跳跳鼠", "花毛毛",
		"传送带", "喷枪", "门", "泡泡鱼", "黑花", "扳手仔", "轨道", "火焰泡泡", "汪汪", "库巴", "冰砖", "树藤",
		"叮叮蜂", "箭头", "单向板", "圆锯", "Player", "10/30/50金币", "半碰撞平台", "慢慢龟汽车", "奇诺比奥",
		"加邦/铁球", "石头", "龙卷风", "奔奔", "仙人掌", "P砖", "冲刺砖", "回旋镖花", "圈圈", "狼牙棒", "蛇", "机动砖",
		"乌卡", "陡坡", "缓坡", "卷轴相机", "中间旗", "跷跷板", "红币", "透明水管", "斜坡传送带", "钥匙", "蚂蚁兵",
		"传送箱", "小库巴", "开关", "虚线砖", "水面标记", "鼹鼠", "鱼骨", "太阳/月亮", "摇摆吊臂", "树", "长长吞食花",
		"闪烁砖", "声音", "尖刺砖", "机械库巴", "木箱", "蘑菇跳跳床", "尖刺河豚", "奇诺比珂", "超级锤子", "斗斗",
		"冰锥", "！砖", "雷米", "莫顿", "拉里", "温缇", "伊吉", "罗伊", "洛德威格", "炮台箱", "螺旋桨箱", "纸糊栗宝宝",
		"纸糊炮弹刺客", "红色POW箱", "开关跳跳床" };
	std::vector<std::string> Badges  = { "", "金缎带", "银缎带", "铜缎带", "金牌", "银牌", "铜牌" };
	std::vector<std::string> BadgesType = { "工匠点数", "耐力挑战(简单)", "耐力挑战(普通)", "耐力挑战(困难)",
		"耐力挑战(极难)", "多人对战", "过关关卡数", "最先通过关卡数", "最短时间关卡数", "工匠点数(周)" };
*/

	std::vector<std::string> ObjEng  = { "Baby Chestnut", "Turtle Slowly", "Eat Flower", "Brother Hammer", "Soft Brick",
        "? Brick", "Hard Brick", "Ground", "Gold Coin", "Water Pipe", "Spring", "Elevating Platform", "Dong Dong",
        "Fort", "Mushroom Platform", "Bombman", "Half Collision Platform", "Bridge", "P Switch", "POW", "Mushroom",
        "Bamboo Wheel", "Cloud Brick", "Musical Note", "Fire Rod", "Thorn Tortoise", "End Brick", "End Flag",
        "Helmet Turtle", "Hidden Brick", "Ball game", "Ball Game Cloud", "Cannonball Assassin", "1UP Mushroom",
        "Flame Flower", "Invincible Star", "Lava Table", "Starting Brick", "Starting Arrow", "Mage", "Spiked turtle",
        "Ghost", "Clown Spaceship", "Thorn", "Big Mushroom", "Shoe Chestnut", "Cracked Tortoise", "Cannon", "Squid",
        "Castle Bridge", "Jumping Machine", "Jumping Mouse", "Flower Maomao", "Conveyor Belt", "Airbrush", "Door",
        "Bubble Fish", "Black Flower", "Wrencher", "Track", "Flame Bubble", "Wow", "Kuba", "Ice Brick", "Tree Vine",
        "Ding Ding Bee", "Arrow", "One-way Board", "Circular Saw", "Player", "10/30/50 Gold Coins",
        "Half Collision Platform", "Slowly Turtle Car", "Cinobio", "Gabon/Iron Ball", "Stone", "Tornado", "Ben Ben",
        "Cactus", "P Brick", "Sprint Brick", "USA Mushroom", "Circle", "Mace", "Snake", "Mobile Brick", "Uka",
        "Steep Slope", "Slight Slope", "Reel Camera", "Middle Flag", "Seesaw", "Red Coin", "Transparent Water Pipe",
        "Ramp Conveyor", "Key", "Ant Soldier", "Transport Box", "Little Kuba", "Switch", "Dotted Brick", "Water Marker",
        "Mole", "Fishbone", "Sun/Moon", "Swing Arm", "Tree", "Long swallows flowers", "Flashing Brick", "Sound",
        "Spiked Brick", "Mechanical Kuba", "Wooden Box", "Mushroom Jumping Bed", "Spiked Pufferfish", "Cinobic",
        "Super Hammer", "Dou Dou", "Ice Cone", "! Brick", "Remy", "Morton", "Larry", "Windy", "Egy", "Roy", "Rodwig",
        "Castle Box", "Propeller Box", "Paper Chestnut Baby", "Paper Cannonball Assassin", "Red POW Box",
        "Switch Jumping on Bed" };
	std::vector<std::string> ObjEng3 = { "Baby Chestnut", "Turtle Slowly", "Eat Flower", "Brother Hammer", "Soft Brick",
		"? Brick", "Hard Brick", "Ground", "Gold Coin", "Water Pipe", "Spring", "Elevating Platform", "Dong Dong",
		"Fort", "Mushroom Platform", "Bombman", "Half Collision Platform", "Bridge", "P Switch", "POW", "Mushroom",
		"Bamboo Wheel", "Cloud Brick", "Musical Note", "Fire Rod", "Thorn Tortoise", "End Brick", "End Flag",
		"Helmet Turtle", "Hidden Brick", "Ball game", "Ball Game Cloud", "Cannonball Assassin", "1UP Mushroom",
		"Flame Flower", "Invincible Star", "Lava Table", "Starting Brick", "Starting Arrow", "Mage", "Spiked turtle",
		"Ghost", "Clown Spaceship", "Thorn", "Super Leaf", "Shoe Chestnut", "Cracked Tortoise", "Cannon", "Squid",
		"Castle Bridge", "Jumping Machine", "Jumping Mouse", "Flower Maomao", "Conveyor Belt", "Airbrush", "Door",
		"Bubble Fish", "Black Flower", "Wrencher", "Track", "Flame Bubble", "Wow", "Kuba", "Ice Brick", "Tree Vine",
		"Ding Ding Bee", "Arrow", "One-way Board", "Circular Saw", "Player", "10/30/50 Gold Coins",
		"Half Collision Platform", "Slowly Turtle Car", "Cinobio", "Gabon/Iron Ball", "Stone", "Tornado", "Ben Ben",
		"Cactus", "P Brick", "Sprint Brick", "Frog Pack", "Circle", "Mace", "Snake", "Mobile Brick", "Uka",
		"Steep Slope", "Slight Slope", "Reel Camera", "Middle Flag", "Seesaw", "Red Coin", "Transparent Water Pipe",
		"Ramp Conveyor", "Key", "Ant Soldier", "Transport Box", "Little Kuba", "Switch", "Dotted Brick", "Water Marker",
		"Mole", "Fishbone", "Sun/Moon", "Swing Arm", "Tree", "Long swallows flowers", "Flashing Brick", "Sound",
		"Spiked Brick", "Mechanical Kuba", "Wooden Box", "Mushroom Jumping Bed", "Spiked Pufferfish", "Cinobic",
		"Super Hammer", "Dou Dou", "Ice Cone", "! Brick", "Remy", "Morton", "Larry", "Windy", "Egy", "Roy", "Rodwig",
		"Castle Box", "Propeller Box", "Paper Chestnut Baby", "Paper Cannonball Assassin", "Red POW Box",
		"Switch Jumping on Bed" };
	std::vector<std::string> ObjEngW = { "Li Bangbang", "Slowly Turtle", "Swallowing Flowers", "Hammer Brothers",
		"Soft Bricks", "? Bricks", "Hard Bricks", "Grounds", "Gold Coin", "Water Pipe", "Spring", "Elevating Platform",
		"Dong Dong", "Fort", "Mushroom Platform", "Bombman", "Half Collision Platform", "Bridge", "P Switch", "POW",
		"Mushroom", "Bamboo Wheel", "Cloud Brick", "Musical Note", "Fire Rod", "Thorn Tortoise", "End Brick",
		"End Flag", "Helmet Turtle", "Hidden Brick", "Ball game", "Ball Game Cloud", "Cannonball Assassin",
		"1UP Mushroom", "Flame Flower", "Invincible Star", "Lava Table", "Starting Brick", "Starting Arrow", "Mage",
		"Spiked turtle", "Ghost", "Clown Spaceship", "Thorn", "Cape Feather", "Yoshi", "Cracked Tortoise", "Cannon",
		"Squid", "Castle Bridge", "Jumping Machine", "Jerboa", "Flower Maomao", "Conveyor Belt", "Airbrush", "Door",
		"Bubble Fish", "Black Flower", "Wrencher", "Track", "Flame Bubble", "Wow", "Kuba", "Ice Brick", "Tree Vine",
		"Ding Ding Bee", "Arrow", "One-way Board", "Circular Saw", "Player", "10/30/50 Gold Coins",
		"Half Collision Platform", "Slowly Turtle Car", "Cinobio", "Gabon/Iron Ball", "Stone", "Tornado", "Boom",
		"Cactus", "P Brick", "Sprint Brick", "Power Balloon", "Circle", "Mace", "Snake", "Mobile Brick", "Uka",
		"Steep Slope", "Slight Slope", "Reel Camera", "Middle Flag", "Seesaw", "Red Coin", "Transparent Water Pipe",
		"Ramp Conveyor", "Key", "Ant Soldier", "Transport Box", "Little Kuba", "Switch", "Dotted Brick", "Water Marker",
		"Mole", "Fishbone", "Sun/Moon", "Swing Arm", "Tree", "Long swallows flowers", "Flashing Brick", "Sound",
		"Spiked Brick", "Mechanical Kuba", "Wooden Box", "Mushroom Jumping Bed", "Spiked Pufferfish", "Cinobic",
		"Super Hammer", "Dou Dou", "Ice Cone", "! Brick", "Remy", "Morton", "Larry", "Windy", "Egy", "Roy", "Rodwig",
		"Castle Box", "Propeller Box", "Paper Chestnut Baby", "Paper Cannonball Assassin", "Red POW Box",
		"Switch Jumping on Bed" };
	std::vector<std::string> ObjEngU = { "Baby Chestnut", "Turtle Slowly", "Eat Flower", "Brother Hammer", "Soft Brick",
		"? Brick", "Hard Brick", "Ground", "Gold Coin", "Water Pipe", "Spring", "Elevating Platform", "Dong Dong",
		"Fort", "Mushroom Platform", "Bombman", "Half Collision Platform", "Bridge", "P Switch", "POW", "Mushroom",
		"Bamboo Wheel", "Cloud Brick", "Musical Note", "Fire Rod", "Thorn Tortoise", "End Brick", "End Flag",
		"Helmet Turtle", "Hidden Brick", "Ball game", "Ball Game Cloud", "Cannonball Assassin", "1UP Mushroom",
		"Flame Flower", "Invincible Star", "Lava Table", "Starting Brick", "Starting Arrow", "Mage", "Spiked turtle",
		"Ghost", "Clown Spaceship", "Thorn", "Propeller Mushroom", "Yoshi", "Cracked Tortoise", "Cannon", "Squid",
		"Castle Bridge", "Jumping Machine", "Jerboa", "Flower Maomao", "Conveyor Belt", "Airbrush", "Door",
		"Bubble Fish", "Black Flower", "Wrencher", "Track", "Flame Bubble", "Wow", "Kuba", "Ice Brick", "Tree Vine",
		"Ding Ding Bee", "Arrow", "One-way Board", "Circular Saw", "Player", "10/30/50 Gold Coins",
		"Half Collision Platform", "Slowly Turtle Car", "Cinobio", "Gabon/Iron Ball", "Stone", "Tornado", "Ben Ben",
		"Cactus", "P Brick", "Sprint Brick", "Super Oak Chestnut", "Circle", "Mace", "Snake", "Mobile Brick", "Uka",
		"Steep Slope", "Slight Slope", "Reel Camera", "Middle Flag", "Seesaw", "Red Coin", "Transparent Water Pipe",
		"Ramp Conveyor", "Key", "Ant Soldier", "Transport Box", "Little Kuba", "Switch", "Dotted Brick", "Water Marker",
		"Mole", "Fishbone", "Sun/Moon", "Swing Arm", "Tree", "Long swallows flowers", "Flashing Brick", "Sound",
		"Spiked Brick", "Mechanical Kuba", "Wooden Box", "Mushroom Jumping Bed", "Spiked Pufferfish", "Cinobic",
		"Super Hammer", "Dou Dou", "Ice Cone", "! Brick", "Remy", "Morton", "Larry", "Windy", "Egy", "Roy", "Rodwig",
		"Castle Box", "Propeller Box", "Paper Chestnut Baby", "Paper Cannonball Assassin", "Red POW Box",
		"Switch Jumping on Bed" };
	std::vector<std::string> ObjEngD = { "Chestnut", "turtle slowly", "devouring flowers", "hammer brothers",
		"soft bricks", "? bricks", "hard bricks", "ground", "gold coins", "Water Pipe", "Spring", "Elevating Platform",
		"Dong Dong", "Fort", "Mushroom Platform", "Bomberman", "Half Collision Platform", "Bridge", "P Switch", "POW",
		"mushroom", "Bamboo Wheel", "Cloud Brick", "Music Note", "Fire Rod", "Spike Turtle", "End Brick", "End Flag",
		"Helmet Turtle", "Hidden Brick", "Ball Game", "Ball Gaim Cloud", "Cannonball Assassin", "1UP Mushroom",
		"Flame Flower", "Invincible Star", "Lava Table", "Starting Brick", "Starting Arrow", "Magic", "Spiked Turtle",
		"Ghost", "Joker Spaceship", "Thorn", "Super Bell", "Shoes/Yoshi", "Cracked Tortoise", "Cannon", "Squid",
		"Castle Bridge", "Jumping Machine", "Jumping Rat", "Hua Mao Mao", "Conveyor Belt", "Airbrush", "Door",
		"Bubble Fish", "Black Flower", "Wrench Boy", "Track", "Flame Bubble", "Wow", "Kuba", "Ice Brick", "Tree Vine",
		"Ding Ding Bee", "Arrow", "One Way Board", "Circular Saw", "Player", "10/30/50 Gold Coins",
		"Semi-Collision Platform", "Slow Turtle Car", "Chino Bio", "Gabon/Iron Ball", "Stone", "Tornado", "Boom",
		"Cactus", "P Brick", "Sprint Brick", "Boomerang Flower", "Circle", "Mace", "Snake", "Mobile Brick", "Uka",
		"Steep Slope", "Slight Slope", "Reel Camera", "Middle Flag", "Seesaw", "Red Coin", "Transparent Water Pipe",
		"Ramp Conveyor", "Key", "Ant Soldier", "Transport Box", "Little Kuba", "Switch", "Dotted Brick", "Water Marker",
		"Mole", "Fishbone", "Sun/Moon", "Swing Arm", "Tree", "Long swallows flowers", "Flashing Brick", "Sound",
		"Spiked Brick", "Mechanical Kuba", "Wooden Box", "Mushroom Jumping Bed", "Spiked Pufferfish", "Cinobic",
		"Super Hammer", "Dou Dou", "Ice Cone", "! Brick", "Remy", "Morton", "Larry", "Windy", "Egy", "Roy", "Rodwig",
		"Castle Box", "Propeller Box", "Paper Chestnut Baby", "Paper Cannonball Assassin", "Red POW Box",
		"Switch Jumping on Bed" };
	std::vector<std::string> Badges
		= { "", "Gold ribbon", "Silver ribbon", "Copper ribbon", "Gold medal", "Silver medal", "Bronze medal" };
	std::vector<std::string> BadgesType = { "Craftsman Points", "Endurance Challenge (Easy)",
		"Endurance Challenge (Normal)", "Endurance Challenge (Difficult)", "Endurance Challenge (Extremely Difficult)",
		"Multiplayer Battle", "Number of Passes", "Number of Passes First", "Number of Points in the int16_test Time",
		"Artisan Points (week)" };

	// Application startup path, should be taken out of LevelParser
	std::string PT = ".";
	std::vector<std::vector<Point>> TileLoc;
	std::vector<std::vector<Point>> PipeLoc;
	std::vector<Point> GrdLoc = std::vector<Point>(258);
	std::vector<std::vector<std::vector<ObjStr>>> ObjLocData;

	LevelParser();
	std::string GetItemName(int n, int v);
	void SetAssetsFolder(std::string path);
	bool DecryptLevelData(const std::string& input, const std::string& output);
	void LoadLevelData(const std::string& P, bool overworld);
};

namespace LevelParserMappings {
	const std::unordered_map<int16_t, std::string> NumToGameStyle = {
		{ 12621, "SMB1" },
		{ 13133, "SMB3" },
		{ 22349, "SMW" },
		{ 21847, "NSMBU" },
		{ 22323, "SM3DW" },
	};

	const std::string FormatMillisecondTime(int milliseconds);
}