#pragma once

// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "kaitai/kaitaistruct.h"
#include <memory>
#include <stdint.h>
#include <vector>

#if KAITAI_STRUCT_VERSION < 9000L
#error "Incompatible Kaitai Struct C++/STL API: version 0.9 or later is required"
#endif
namespace MM2 {

	class level_t : public kaitai::kstruct {

	public:
		class map_t;
		class clear_pipe_node_t;
		class track_t;
		class track_block_node_t;
		class obj_t;
		class icicle_t;
		class snake_t;
		class clear_pipe_t;
		class exclamation_block_t;
		class ground_t;
		class snake_node_t;
		class sound_t;
		class track_block_t;
		class piranha_creeper_node_t;
		class piranha_creeper_t;
		class exclamation_block_node_t;

		enum autoscroll_speed_t { AUTOSCROLL_SPEED_X1 = 0, AUTOSCROLL_SPEED_X2 = 1, AUTOSCROLL_SPEED_X3 = 2 };

		enum clear_condition_t {
			CLEAR_CONDITION_NONE                                                      = 0,
			CLEAR_CONDITION_REACH_THE_GOAL_WITHOUT_LANDING_AFTER_LEAVING_THE_GROUND   = 137525990,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_MECHAKOOPA    = 199585683,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_CHEEP_CHEEP   = 272349836,
			CLEAR_CONDITION_REACH_THE_GOAL_WITHOUT_TAKING_DAMAGE                      = 375673178,
			CLEAR_CONDITION_REACH_THE_GOAL_AS_BOOMERANG_MARIO                         = 426197923,
			CLEAR_CONDITION_REACH_THE_GOAL_WHILE_WEARING_A_SHOE                       = 436833616,
			CLEAR_CONDITION_REACH_THE_GOAL_AS_FIRE_MARIO                              = 713979835,
			CLEAR_CONDITION_REACH_THE_GOAL_AS_FROG_MARIO                              = 744927294,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_LARRY         = 751004331,
			CLEAR_CONDITION_REACH_THE_GOAL_AS_RACCOON_MARIO                           = 900050759,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_BLOOPER       = 947659466,
			CLEAR_CONDITION_REACH_THE_GOAL_AS_PROPELLER_MARIO                         = 976173462,
			CLEAR_CONDITION_REACH_THE_GOAL_WHILE_WEARING_A_PROPELLER_BOX              = 994686866,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_SPIKE         = 998904081,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_BOOM_BOOM     = 1008094897,
			CLEAR_CONDITION_REACH_THE_GOAL_WHILE_HOLDING_A_KOOPA_SHELL                = 1051433633,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_PORCUPUFFER   = 1061233896,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_CHARVAARGH    = 1062253843,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_BULLET_BILL   = 1079889509,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_BULLY_BULLIES = 1080535886,
			CLEAR_CONDITION_REACH_THE_GOAL_WHILE_WEARING_A_GOOMBA_MASK                = 1151250770,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_HOP_CHOPS     = 1182464856,
			CLEAR_CONDITION_REACH_THE_GOAL_WHILE_HOLDING_A_RED_POW_BLOCK_OR_REACH_THE_GOAL_AFTER_ACTIVATING_AT_LEAST_ALL_RED_POW_BLOCK
			= 1219761531,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_BOB_OMB        = 1221661152,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_SPINY_SPINIES  = 1259427138,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_BOWSER_MEOWSER = 1268255615,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_ANT_TROOPER    = 1279580818,
			CLEAR_CONDITION_REACH_THE_GOAL_ON_A_LAKITUS_CLOUD                          = 1283945123,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_BOO            = 1344044032,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_ROY            = 1425973877,
			CLEAR_CONDITION_REACH_THE_GOAL_WHILE_HOLDING_A_TRAMPOLINE                  = 1429902736,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_MORTON         = 1431944825,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_FISH_BONE      = 1446467058,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_MONTY_MOLE     = 1510495760,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_PICKING_UP_AT_LEAST_ALL_1_UP_MUSHROOM = 1656179347,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_HAMMER_BRO     = 1665820273,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_HITTING_AT_LEAST_ALL_P_SWITCH_OR_REACH_THE_GOAL_WHILE_HOLDING_A_P_SWITCH
			= 1676924210,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_ACTIVATING_AT_LEAST_ALL_POW_BLOCK_OR_REACH_THE_GOAL_WHILE_HOLDING_A_POW_BLOCK
			= 1715960804,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_ANGRY_SUN        = 1724036958,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_POKEY            = 1730095541,
			CLEAR_CONDITION_REACH_THE_GOAL_AS_SUPERBALL_MARIO                            = 1780278293,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_POM_POM          = 1839897151,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_PEEPA            = 1969299694,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_LAKITU           = 2035052211,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_LEMMY            = 2038503215,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_LAVA_BUBBLE      = 2048033177,
			CLEAR_CONDITION_REACH_THE_GOAL_WHILE_WEARING_A_BULLET_BILL_MASK              = 2076496776,
			CLEAR_CONDITION_REACH_THE_GOAL_AS_BIG_MARIO                                  = 2089161429,
			CLEAR_CONDITION_REACH_THE_GOAL_AS_CAT_MARIO                                  = 2111528319,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_GOOMBA_GALOOMBA  = 2131209407,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_THWOMP           = 2139645066,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_IGGY             = 2259346429,
			CLEAR_CONDITION_REACH_THE_GOAL_WHILE_WEARING_A_DRY_BONES_SHELL               = 2549654281,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_SLEDGE_BRO       = 2694559007,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_ROCKY_WRENCH     = 2746139466,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_GRABBING_AT_LEAST_ALL_50_COIN           = 2749601092,
			CLEAR_CONDITION_REACH_THE_GOAL_AS_FLYING_SQUIRREL_MARIO                      = 2855236681,
			CLEAR_CONDITION_REACH_THE_GOAL_AS_BUZZY_MARIO                                = 3036298571,
			CLEAR_CONDITION_REACH_THE_GOAL_AS_BUILDER_MARIO                              = 3074433106,
			CLEAR_CONDITION_REACH_THE_GOAL_AS_CAPE_MARIO                                 = 3146932243,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_WENDY            = 3174413484,
			CLEAR_CONDITION_REACH_THE_GOAL_WHILE_WEARING_A_CANNON_BOX                    = 3206222275,
			CLEAR_CONDITION_REACH_THE_GOAL_AS_LINK                                       = 3314955857,
			CLEAR_CONDITION_REACH_THE_GOAL_WHILE_YOU_HAVE_SUPER_STAR_INVINCIBILITY       = 3342591980,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_GOOMBRAT_GOOMBUD = 3346433512,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_GRABBING_AT_LEAST_ALL_10_COIN           = 3348058176,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_BUZZY_BEETLE     = 3353006607,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_BOWSER_JR        = 3392229961,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_KOOPA_TROOPA     = 3437308486,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_CHAIN_CHOMP      = 3459144213,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_MUNCHER          = 3466227835,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_WIGGLER          = 3481362698,
			CLEAR_CONDITION_REACH_THE_GOAL_AS_SMB2_MARIO                                 = 3513732174,
			CLEAR_CONDITION_REACH_THE_GOAL_IN_A_KOOPA_CLOWN_CAR_JUNIOR_CLOWN_CAR         = 3649647177,
			CLEAR_CONDITION_REACH_THE_GOAL_AS_SPINY_MARIO                                = 3725246406,
			CLEAR_CONDITION_REACH_THE_GOAL_IN_A_KOOPA_TROOPA_CAR                         = 3730243509,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_PIRANHA_PLANT_JUMPING_PIRANHA_PLANT
			= 3748075486,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_DRY_BONES          = 3797704544,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_STINGBY_STINGBIES  = 3824561269,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_PIRANHA_CREEPER    = 3833342952,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_FIRE_PIRANHA_PLANT = 3842179831,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_BREAKING_AT_LEAST_ALL_CRATES              = 3874680510,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_LUDWIG             = 3974581191,
			CLEAR_CONDITION_REACH_THE_GOAL_AS_SUPER_MARIO                                  = 3977257962,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_SKIPSQUEAK         = 4042480826,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_GRABBING_AT_LEAST_ALL_COIN                = 4116396131,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_MAGIKOOPA          = 4117878280,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_GRABBING_AT_LEAST_ALL_30_COIN             = 4122555074,
			CLEAR_CONDITION_REACH_THE_GOAL_AS_BALLOON_MARIO                                = 4153835197,
			CLEAR_CONDITION_REACH_THE_GOAL_WHILE_WEARING_A_RED_POW_BOX                     = 4172105156,
			CLEAR_CONDITION_REACH_THE_GOAL_WHILE_RIDING_YOSHI                              = 4209535561,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_SPIKE_TOP          = 4269094462,
			CLEAR_CONDITION_REACH_THE_GOAL_AFTER_DEFEATING_AT_LEAST_ALL_BANZAI_BILL        = 4293354249
		};

		enum gamestyle_t {
			GAMESTYLE_SMB1  = 12621,
			GAMESTYLE_SMB3  = 13133,
			GAMESTYLE_NSMBW = 21847,
			GAMESTYLE_SM3DW = 22323,
			GAMESTYLE_SMW   = 22349
		};

		enum game_version_t {
			GAME_VERSION_V1_0_0 = 0,
			GAME_VERSION_V1_0_1 = 1,
			GAME_VERSION_V1_1_0 = 2,
			GAME_VERSION_V2_0_0 = 3,
			GAME_VERSION_V3_0_0 = 4,
			GAME_VERSION_V3_0_1 = 5,
			GAME_VERSION_UNK    = 33
		};

		enum clear_condition_category_t {
			CLEAR_CONDITION_CATEGORY_NONE    = 0,
			CLEAR_CONDITION_CATEGORY_PARTS   = 1,
			CLEAR_CONDITION_CATEGORY_STATUS  = 2,
			CLEAR_CONDITION_CATEGORY_ACTIONS = 3
		};

		level_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent = nullptr, level_t* p__root = nullptr);

	private:
		void _read();
		void _clean_up();

	public:
		~level_t();

		class map_t : public kaitai::kstruct {

		public:
			enum boundary_type_t { BOUNDARY_TYPE_BUILT_ABOVE_LINE = 0, BOUNDARY_TYPE_BUILT_BELOW_LINE = 1 };

			enum autoscroll_type_t {
				AUTOSCROLL_TYPE_NONE   = 0,
				AUTOSCROLL_TYPE_SLOW   = 1,
				AUTOSCROLL_TYPE_NORMAL = 2,
				AUTOSCROLL_TYPE_FAST   = 3,
				AUTOSCROLL_TYPE_CUSTOM = 4
			};

			enum orientation_t { ORIENTATION_HORIZONTAL = 0, ORIENTATION_VERTICAL = 1 };

			enum theme_t {
				THEME_OVERWORLD   = 0,
				THEME_UNDERGROUND = 1,
				THEME_CASTLE      = 2,
				THEME_AIRSHIP     = 3,
				THEME_UNDERWATER  = 4,
				THEME_GHOST_HOUSE = 5,
				THEME_SNOW        = 6,
				THEME_DESERT      = 7,
				THEME_SKY         = 8,
				THEME_FOREST      = 9
			};

			enum liquid_mode_t {
				LIQUID_MODE_STATIC             = 0,
				LIQUID_MODE_RISING_OR_FALLING  = 1,
				LIQUID_MODE_RISING_AND_FALLING = 2
			};

			enum liquid_speed_t {
				LIQUID_SPEED_NONE = 0,
				LIQUID_SPEED_X1   = 1,
				LIQUID_SPEED_X2   = 2,
				LIQUID_SPEED_X3   = 3
			};

			map_t(kaitai::kstream* p__io, level_t* p__parent = nullptr, level_t* p__root = nullptr);

		private:
			void _read();
			void _clean_up();

		public:
			~map_t();

		private:
			theme_t m_theme;
			autoscroll_type_t m_autoscroll_type;
			boundary_type_t m_boundary_type;
			orientation_t m_orientation;
			uint8_t m_liquid_end_height;
			liquid_mode_t m_liquid_mode;
			liquid_speed_t m_liquid_speed;
			uint8_t m_liquid_start_height;
			int32_t m_boundary_right;
			int32_t m_boundary_top;
			int32_t m_boundary_left;
			int32_t m_boundary_bottom;
			int32_t m_unk_flag;
			int32_t m_object_count;
			int32_t m_sound_effect_count;
			int32_t m_snake_block_count;
			int32_t m_clear_pipe_count;
			int32_t m_piranha_creeper_count;
			int32_t m_exclamation_mark_block_count;
			int32_t m_track_block_count;
			int32_t m_unk1;
			int32_t m_ground_count;
			int32_t m_track_count;
			int32_t m_ice_count;
			std::unique_ptr<std::vector<std::unique_ptr<obj_t>>> m_objects;
			std::unique_ptr<std::vector<std::unique_ptr<sound_t>>> m_sounds;
			std::unique_ptr<std::vector<std::unique_ptr<snake_t>>> m_snakes;
			std::unique_ptr<std::vector<std::unique_ptr<clear_pipe_t>>> m_clear_pipes;
			std::unique_ptr<std::vector<std::unique_ptr<piranha_creeper_t>>> m_piranha_creepers;
			std::unique_ptr<std::vector<std::unique_ptr<exclamation_block_t>>> m_exclamation_blocks;
			std::unique_ptr<std::vector<std::unique_ptr<track_block_t>>> m_track_blocks;
			std::unique_ptr<std::vector<std::unique_ptr<ground_t>>> m_ground;
			std::unique_ptr<std::vector<std::unique_ptr<track_t>>> m_tracks;
			std::unique_ptr<std::vector<std::unique_ptr<icicle_t>>> m_icicles;
			std::string m_unk2;
			level_t* m__root;
			level_t* m__parent;

		public:
			/**
			 * Map theme
			 */
			theme_t theme() const {
				return m_theme;
			}

			/**
			 * Autoscroll type
			 */
			autoscroll_type_t autoscroll_type() const {
				return m_autoscroll_type;
			}

			/**
			 * Boundary type
			 */
			boundary_type_t boundary_type() const {
				return m_boundary_type;
			}

			/**
			 * Orientation
			 */
			orientation_t orientation() const {
				return m_orientation;
			}

			/**
			 * Liquid end height
			 */
			uint8_t liquid_end_height() const {
				return m_liquid_end_height;
			}

			/**
			 * Liquid mode
			 */
			liquid_mode_t liquid_mode() const {
				return m_liquid_mode;
			}

			/**
			 * Liquid speed
			 */
			liquid_speed_t liquid_speed() const {
				return m_liquid_speed;
			}

			/**
			 * Liquid start height
			 */
			uint8_t liquid_start_height() const {
				return m_liquid_start_height;
			}

			/**
			 * Right boundary
			 */
			int32_t boundary_right() const {
				return m_boundary_right;
			}

			/**
			 * Top boundary
			 */
			int32_t boundary_top() const {
				return m_boundary_top;
			}

			/**
			 * Left boundary
			 */
			int32_t boundary_left() const {
				return m_boundary_left;
			}

			/**
			 * Bottom boundary
			 */
			int32_t boundary_bottom() const {
				return m_boundary_bottom;
			}

			/**
			 * Unknown flag
			 */
			int32_t unk_flag() const {
				return m_unk_flag;
			}

			/**
			 * Object count
			 */
			int32_t object_count() const {
				return m_object_count;
			}

			/**
			 * Sound effect count
			 */
			int32_t sound_effect_count() const {
				return m_sound_effect_count;
			}

			/**
			 * Snake block count
			 */
			int32_t snake_block_count() const {
				return m_snake_block_count;
			}

			/**
			 * Clear pipe count
			 */
			int32_t clear_pipe_count() const {
				return m_clear_pipe_count;
			}

			/**
			 * Piranha creeper count
			 */
			int32_t piranha_creeper_count() const {
				return m_piranha_creeper_count;
			}

			/**
			 * Exclamation mark block count
			 */
			int32_t exclamation_mark_block_count() const {
				return m_exclamation_mark_block_count;
			}

			/**
			 * Track block count
			 */
			int32_t track_block_count() const {
				return m_track_block_count;
			}
			int32_t unk1() const {
				return m_unk1;
			}

			/**
			 * Ground count
			 */
			int32_t ground_count() const {
				return m_ground_count;
			}

			/**
			 * Track count
			 */
			int32_t track_count() const {
				return m_track_count;
			}

			/**
			 * Ice count
			 */
			int32_t ice_count() const {
				return m_ice_count;
			}

			/**
			 * Objects
			 */
			std::vector<std::unique_ptr<obj_t>>* objects() const {
				return m_objects.get();
			}

			/**
			 * Sound effects
			 */
			std::vector<std::unique_ptr<sound_t>>* sounds() const {
				return m_sounds.get();
			}

			/**
			 * Snake blocks
			 */
			std::vector<std::unique_ptr<snake_t>>* snakes() const {
				return m_snakes.get();
			}

			/**
			 * Clear pipes
			 */
			std::vector<std::unique_ptr<clear_pipe_t>>* clear_pipes() const {
				return m_clear_pipes.get();
			}

			/**
			 * Piranha creepers
			 */
			std::vector<std::unique_ptr<piranha_creeper_t>>* piranha_creepers() const {
				return m_piranha_creepers.get();
			}

			/**
			 * Blocks
			 */
			std::vector<std::unique_ptr<exclamation_block_t>>* exclamation_blocks() const {
				return m_exclamation_blocks.get();
			}

			/**
			 * Track blocks
			 */
			std::vector<std::unique_ptr<track_block_t>>* track_blocks() const {
				return m_track_blocks.get();
			}

			/**
			 * Ground tiles
			 */
			std::vector<std::unique_ptr<ground_t>>* ground() const {
				return m_ground.get();
			}

			/**
			 * Tracks
			 */
			std::vector<std::unique_ptr<track_t>>* tracks() const {
				return m_tracks.get();
			}

			/**
			 * Icicles
			 */
			std::vector<std::unique_ptr<icicle_t>>* icicles() const {
				return m_icicles.get();
			}
			std::string unk2() const {
				return m_unk2;
			}
			level_t* _root() const {
				return m__root;
			}
			level_t* _parent() const {
				return m__parent;
			}
		};

		class clear_pipe_node_t : public kaitai::kstruct {

		public:
			clear_pipe_node_t(
				kaitai::kstream* p__io, level_t::clear_pipe_t* p__parent = nullptr, level_t* p__root = nullptr);

		private:
			void _read();
			void _clean_up();

		public:
			~clear_pipe_node_t();

		private:
			uint8_t m_type;
			uint8_t m_index;
			uint8_t m_x;
			uint8_t m_y;
			uint8_t m_width;
			uint8_t m_height;
			uint8_t m_unk1;
			uint8_t m_direction;
			level_t* m__root;
			level_t::clear_pipe_t* m__parent;

		public:
			/**
			 * Clear pipe node type
			 */
			uint8_t type() const {
				return m_type;
			}

			/**
			 * Clear pipe node index
			 */
			uint8_t index() const {
				return m_index;
			}

			/**
			 * Clear pipe node X position
			 */
			uint8_t x() const {
				return m_x;
			}

			/**
			 * Clear pipe node Y position
			 */
			uint8_t y() const {
				return m_y;
			}

			/**
			 * Clear pipe node width
			 */
			uint8_t width() const {
				return m_width;
			}

			/**
			 * Clear pipe node height
			 */
			uint8_t height() const {
				return m_height;
			}
			uint8_t unk1() const {
				return m_unk1;
			}

			/**
			 * Clear pipe node direction
			 */
			uint8_t direction() const {
				return m_direction;
			}
			level_t* _root() const {
				return m__root;
			}
			level_t::clear_pipe_t* _parent() const {
				return m__parent;
			}
		};

		class track_t : public kaitai::kstruct {

		public:
			track_t(kaitai::kstream* p__io, level_t::map_t* p__parent = nullptr, level_t* p__root = nullptr);

		private:
			void _read();
			void _clean_up();

		public:
			~track_t();

		private:
			uint16_t m_unk1;
			uint8_t m_flags;
			uint8_t m_x;
			uint8_t m_y;
			uint8_t m_type;
			uint16_t m_lid;
			uint16_t m_unk2;
			uint16_t m_unk3;
			level_t* m__root;
			level_t::map_t* m__parent;

		public:
			uint16_t unk1() const {
				return m_unk1;
			}

			/**
			 * Track flags
			 */
			uint8_t flags() const {
				return m_flags;
			}

			/**
			 * Track X position
			 */
			uint8_t x() const {
				return m_x;
			}

			/**
			 * Track Y position
			 */
			uint8_t y() const {
				return m_y;
			}

			/**
			 * Track type
			 */
			uint8_t type() const {
				return m_type;
			}

			/**
			 * Track LID
			 */
			uint16_t lid() const {
				return m_lid;
			}
			uint16_t unk2() const {
				return m_unk2;
			}
			uint16_t unk3() const {
				return m_unk3;
			}
			level_t* _root() const {
				return m__root;
			}
			level_t::map_t* _parent() const {
				return m__parent;
			}
		};

		class track_block_node_t : public kaitai::kstruct {

		public:
			track_block_node_t(
				kaitai::kstream* p__io, level_t::track_block_t* p__parent = nullptr, level_t* p__root = nullptr);

		private:
			void _read();
			void _clean_up();

		public:
			~track_block_node_t();

		private:
			uint8_t m_unk1;
			uint8_t m_direction;
			uint16_t m_unk2;
			level_t* m__root;
			level_t::track_block_t* m__parent;

		public:
			uint8_t unk1() const {
				return m_unk1;
			}

			/**
			 * Track block node direction
			 */
			uint8_t direction() const {
				return m_direction;
			}
			uint16_t unk2() const {
				return m_unk2;
			}
			level_t* _root() const {
				return m__root;
			}
			level_t::track_block_t* _parent() const {
				return m__parent;
			}
		};

		class obj_t : public kaitai::kstruct {

		public:
			enum obj_id_t {
				OBJ_ID_GOOMBA                  = 0,
				OBJ_ID_KOOPA                   = 1,
				OBJ_ID_PIRANHA_FLOWER          = 2,
				OBJ_ID_HAMMER_BRO              = 3,
				OBJ_ID_BLOCK                   = 4,
				OBJ_ID_QUESTION_BLOCK          = 5,
				OBJ_ID_HARD_BLOCK              = 6,
				OBJ_ID_GROUND                  = 7,
				OBJ_ID_COIN                    = 8,
				OBJ_ID_PIPE                    = 9,
				OBJ_ID_SPRING                  = 10,
				OBJ_ID_LIFT                    = 11,
				OBJ_ID_THWOMP                  = 12,
				OBJ_ID_BULLET_BILL_BLASTER     = 13,
				OBJ_ID_MUSHROOM_PLATFORM       = 14,
				OBJ_ID_BOB_OMB                 = 15,
				OBJ_ID_SEMISOLID_PLATFORM      = 16,
				OBJ_ID_BRIDGE                  = 17,
				OBJ_ID_P_SWITCH                = 18,
				OBJ_ID_POW                     = 19,
				OBJ_ID_SUPER_MUSHROOM          = 20,
				OBJ_ID_DONUT_BLOCK             = 21,
				OBJ_ID_CLOUD                   = 22,
				OBJ_ID_NOTE_BLOCK              = 23,
				OBJ_ID_FIRE_BAR                = 24,
				OBJ_ID_SPINY                   = 25,
				OBJ_ID_GOAL_GROUND             = 26,
				OBJ_ID_GOAL                    = 27,
				OBJ_ID_BUZZY_BEETLE            = 28,
				OBJ_ID_HIDDEN_BLOCK            = 29,
				OBJ_ID_LAKITU                  = 30,
				OBJ_ID_LAKITU_CLOUD            = 31,
				OBJ_ID_BANZAI_BILL             = 32,
				OBJ_ID_ONE_UP                  = 33,
				OBJ_ID_FIRE_FLOWER             = 34,
				OBJ_ID_SUPER_STAR              = 35,
				OBJ_ID_LAVA_LIFT               = 36,
				OBJ_ID_STARTING_BRICK          = 37,
				OBJ_ID_STARTING_ARROW          = 38,
				OBJ_ID_MAGIKOOPA               = 39,
				OBJ_ID_SPIKE_TOP               = 40,
				OBJ_ID_BOO                     = 41,
				OBJ_ID_CLOWN_CAR               = 42,
				OBJ_ID_SPIKES                  = 43,
				OBJ_ID_BIG_MUSHROOM            = 44,
				OBJ_ID_SHOE_GOOMBA             = 45,
				OBJ_ID_DRY_BONES               = 46,
				OBJ_ID_CANNON                  = 47,
				OBJ_ID_BLOOPER                 = 48,
				OBJ_ID_CASTLE_BRIDGE           = 49,
				OBJ_ID_JUMPING_MACHINE         = 50,
				OBJ_ID_SKIPSQUEAK              = 51,
				OBJ_ID_WIGGLER                 = 52,
				OBJ_ID_FAST_CONVEYOR_BELT      = 53,
				OBJ_ID_BURNER                  = 54,
				OBJ_ID_DOOR                    = 55,
				OBJ_ID_CHEEP_CHEEP             = 56,
				OBJ_ID_MUNCHER                 = 57,
				OBJ_ID_ROCKY_WRENCH            = 58,
				OBJ_ID_TRACK                   = 59,
				OBJ_ID_LAVA_BUBBLE             = 60,
				OBJ_ID_CHAIN_CHOMP             = 61,
				OBJ_ID_BOWSER                  = 62,
				OBJ_ID_ICE_BLOCK               = 63,
				OBJ_ID_VINE                    = 64,
				OBJ_ID_STINGBY                 = 65,
				OBJ_ID_ARROW                   = 66,
				OBJ_ID_ONE_WAY                 = 67,
				OBJ_ID_SAW                     = 68,
				OBJ_ID_PLAYER                  = 69,
				OBJ_ID_BIG_COIN                = 70,
				OBJ_ID_HALF_COLLISION_PLATFORM = 71,
				OBJ_ID_KOOPA_CAR               = 72,
				OBJ_ID_CINOBIO                 = 73,
				OBJ_ID_SPIKE_BALL              = 74,
				OBJ_ID_STONE                   = 75,
				OBJ_ID_TWISTER                 = 76,
				OBJ_ID_BOOM_BOOM               = 77,
				OBJ_ID_POKEY                   = 78,
				OBJ_ID_P_BLOCK                 = 79,
				OBJ_ID_SPRINT_PLATFORM         = 80,
				OBJ_ID_SMB2_MUSHROOM           = 81,
				OBJ_ID_DONUT                   = 82,
				OBJ_ID_SKEWER                  = 83,
				OBJ_ID_SNAKE_BLOCK             = 84,
				OBJ_ID_TRACK_BLOCK             = 85,
				OBJ_ID_CHARVAARGH              = 86,
				OBJ_ID_SLIGHT_SLOPE            = 87,
				OBJ_ID_STEEP_SLOPE             = 88,
				OBJ_ID_REEL_CAMERA             = 89,
				OBJ_ID_CHECKPOINT_FLAG         = 90,
				OBJ_ID_SEESAW                  = 91,
				OBJ_ID_RED_COIN                = 92,
				OBJ_ID_CLEAR_PIPE              = 93,
				OBJ_ID_CONVEYOR_BELT           = 94,
				OBJ_ID_KEY                     = 95,
				OBJ_ID_ANT_TROOPER             = 96,
				OBJ_ID_WARP_BOX                = 97,
				OBJ_ID_BOWSER_JR               = 98,
				OBJ_ID_ON_OFF_BLOCK            = 99,
				OBJ_ID_DOTTED_LINE_BLOCK       = 100,
				OBJ_ID_WATER_MARKER            = 101,
				OBJ_ID_MONTY_MOLE              = 102,
				OBJ_ID_FISH_BONE               = 103,
				OBJ_ID_ANGRY_SUN               = 104,
				OBJ_ID_SWINGING_CLAW           = 105,
				OBJ_ID_TREE                    = 106,
				OBJ_ID_PIRANHA_CREEPER         = 107,
				OBJ_ID_BLINKING_BLOCK          = 108,
				OBJ_ID_SOUND_EFFECT            = 109,
				OBJ_ID_SPIKE_BLOCK             = 110,
				OBJ_ID_MECHAKOOPA              = 111,
				OBJ_ID_CRATE                   = 112,
				OBJ_ID_MUSHROOM_TRAMPOLINE     = 113,
				OBJ_ID_PORKUPUFFER             = 114,
				OBJ_ID_CINOBIC                 = 115,
				OBJ_ID_SUPER_HAMMER            = 116,
				OBJ_ID_BULLY                   = 117,
				OBJ_ID_ICICLE                  = 118,
				OBJ_ID_EXCLAMATION_BLOCK       = 119,
				OBJ_ID_LEMMY                   = 120,
				OBJ_ID_MORTON                  = 121,
				OBJ_ID_LARRY                   = 122,
				OBJ_ID_WENDY                   = 123,
				OBJ_ID_IGGY                    = 124,
				OBJ_ID_ROY                     = 125,
				OBJ_ID_LUDWIG                  = 126,
				OBJ_ID_CANNON_BOX              = 127,
				OBJ_ID_PROPELLER_BOX           = 128,
				OBJ_ID_GOOMBA_MASK             = 129,
				OBJ_ID_BULLET_BILL_MASK        = 130,
				OBJ_ID_RED_POW_BOX             = 131,
				OBJ_ID_ON_OFF_TRAMPOLINE       = 132
			};

			obj_t(kaitai::kstream* p__io, level_t::map_t* p__parent = nullptr, level_t* p__root = nullptr);

		private:
			void _read();
			void _clean_up();

		public:
			~obj_t();

		private:
			int32_t m_x;
			int32_t m_y;
			int16_t m_unk1;
			uint8_t m_width;
			uint8_t m_height;
			int32_t m_flag;
			int32_t m_cflag;
			int32_t m_ex;
			obj_id_t m_id;
			int16_t m_cid;
			int16_t m_lid;
			int16_t m_sid;
			level_t* m__root;
			level_t::map_t* m__parent;

		public:
			/**
			 * X coordinate
			 */
			int32_t x() const {
				return m_x;
			}

			/**
			 * Y coordinate
			 */
			int32_t y() const {
				return m_y;
			}
			int16_t unk1() const {
				return m_unk1;
			}

			/**
			 * Width
			 */
			uint8_t width() const {
				return m_width;
			}

			/**
			 * Height
			 */
			uint8_t height() const {
				return m_height;
			}

			/**
			 * Flag
			 */
			int32_t flag() const {
				return m_flag;
			}

			/**
			 * CFlag
			 */
			int32_t cflag() const {
				return m_cflag;
			}

			/**
			 * Ex
			 */
			int32_t ex() const {
				return m_ex;
			}

			/**
			 * ID
			 */
			obj_id_t id() const {
				return m_id;
			}

			/**
			 * CID
			 */
			int16_t cid() const {
				return m_cid;
			}

			/**
			 * LID
			 */
			int16_t lid() const {
				return m_lid;
			}

			/**
			 * SID
			 */
			int16_t sid() const {
				return m_sid;
			}
			level_t* _root() const {
				return m__root;
			}
			level_t::map_t* _parent() const {
				return m__parent;
			}
		};

		class icicle_t : public kaitai::kstruct {

		public:
			icicle_t(kaitai::kstream* p__io, level_t::map_t* p__parent = nullptr, level_t* p__root = nullptr);

		private:
			void _read();
			void _clean_up();

		public:
			~icicle_t();

		private:
			uint8_t m_x;
			uint8_t m_y;
			uint8_t m_type;
			uint8_t m_unk1;
			level_t* m__root;
			level_t::map_t* m__parent;

		public:
			/**
			 * Icicle X position
			 */
			uint8_t x() const {
				return m_x;
			}

			/**
			 * Icicle Y position
			 */
			uint8_t y() const {
				return m_y;
			}

			/**
			 * Icicle type
			 */
			uint8_t type() const {
				return m_type;
			}
			uint8_t unk1() const {
				return m_unk1;
			}
			level_t* _root() const {
				return m__root;
			}
			level_t::map_t* _parent() const {
				return m__parent;
			}
		};

		class snake_t : public kaitai::kstruct {

		public:
			snake_t(kaitai::kstream* p__io, level_t::map_t* p__parent = nullptr, level_t* p__root = nullptr);

		private:
			void _read();
			void _clean_up();

		public:
			~snake_t();

		private:
			uint8_t m_index;
			uint8_t m_node_count;
			uint16_t m_unk1;
			std::unique_ptr<std::vector<std::unique_ptr<snake_node_t>>> m_nodes;
			level_t* m__root;
			level_t::map_t* m__parent;

		public:
			/**
			 * Snake block index
			 */
			uint8_t index() const {
				return m_index;
			}

			/**
			 * Snake block node count
			 */
			uint8_t node_count() const {
				return m_node_count;
			}
			uint16_t unk1() const {
				return m_unk1;
			}

			/**
			 * Snake block nodes
			 */
			std::vector<std::unique_ptr<snake_node_t>>* nodes() const {
				return m_nodes.get();
			}
			level_t* _root() const {
				return m__root;
			}
			level_t::map_t* _parent() const {
				return m__parent;
			}
		};

		class clear_pipe_t : public kaitai::kstruct {

		public:
			clear_pipe_t(kaitai::kstream* p__io, level_t::map_t* p__parent = nullptr, level_t* p__root = nullptr);

		private:
			void _read();
			void _clean_up();

		public:
			~clear_pipe_t();

		private:
			uint8_t m_index;
			uint8_t m_node_count;
			uint16_t m_unk;
			std::unique_ptr<std::vector<std::unique_ptr<clear_pipe_node_t>>> m_nodes;
			level_t* m__root;
			level_t::map_t* m__parent;

		public:
			/**
			 * Clear pipe index
			 */
			uint8_t index() const {
				return m_index;
			}

			/**
			 * Clear pipe node count
			 */
			uint8_t node_count() const {
				return m_node_count;
			}
			uint16_t unk() const {
				return m_unk;
			}

			/**
			 * Clear pipe nodes
			 */
			std::vector<std::unique_ptr<clear_pipe_node_t>>* nodes() const {
				return m_nodes.get();
			}
			level_t* _root() const {
				return m__root;
			}
			level_t::map_t* _parent() const {
				return m__parent;
			}
		};

		class exclamation_block_t : public kaitai::kstruct {

		public:
			exclamation_block_t(
				kaitai::kstream* p__io, level_t::map_t* p__parent = nullptr, level_t* p__root = nullptr);

		private:
			void _read();
			void _clean_up();

		public:
			~exclamation_block_t();

		private:
			uint8_t m_unk1;
			uint8_t m_index;
			uint8_t m_node_count;
			uint8_t m_unk2;
			std::unique_ptr<std::vector<std::unique_ptr<exclamation_block_node_t>>> m_nodes;
			level_t* m__root;
			level_t::map_t* m__parent;

		public:
			uint8_t unk1() const {
				return m_unk1;
			}

			/**
			 * block index
			 */
			uint8_t index() const {
				return m_index;
			}

			/**
			 * block node count
			 */
			uint8_t node_count() const {
				return m_node_count;
			}
			uint8_t unk2() const {
				return m_unk2;
			}

			/**
			 * block nodes
			 */
			std::vector<std::unique_ptr<exclamation_block_node_t>>* nodes() const {
				return m_nodes.get();
			}
			level_t* _root() const {
				return m__root;
			}
			level_t::map_t* _parent() const {
				return m__parent;
			}
		};

		class ground_t : public kaitai::kstruct {

		public:
			ground_t(kaitai::kstream* p__io, level_t::map_t* p__parent = nullptr, level_t* p__root = nullptr);

		private:
			void _read();
			void _clean_up();

		public:
			~ground_t();

		private:
			uint8_t m_x;
			uint8_t m_y;
			uint8_t m_id;
			uint8_t m_background_id;
			level_t* m__root;
			level_t::map_t* m__parent;

		public:
			/**
			 * Ground tile X position
			 */
			uint8_t x() const {
				return m_x;
			}

			/**
			 * Ground tile Y position
			 */
			uint8_t y() const {
				return m_y;
			}

			/**
			 * Ground tile id
			 */
			uint8_t id() const {
				return m_id;
			}

			/**
			 * Ground tile background tile
			 */
			uint8_t background_id() const {
				return m_background_id;
			}
			level_t* _root() const {
				return m__root;
			}
			level_t::map_t* _parent() const {
				return m__parent;
			}
		};

		class snake_node_t : public kaitai::kstruct {

		public:
			snake_node_t(kaitai::kstream* p__io, level_t::snake_t* p__parent = nullptr, level_t* p__root = nullptr);

		private:
			void _read();
			void _clean_up();

		public:
			~snake_node_t();

		private:
			uint16_t m_index;
			uint16_t m_direction;
			uint32_t m_unk1;
			level_t* m__root;
			level_t::snake_t* m__parent;

		public:
			/**
			 * Snake block node index
			 */
			uint16_t index() const {
				return m_index;
			}

			/**
			 * Snake block node direction
			 */
			uint16_t direction() const {
				return m_direction;
			}
			uint32_t unk1() const {
				return m_unk1;
			}
			level_t* _root() const {
				return m__root;
			}
			level_t::snake_t* _parent() const {
				return m__parent;
			}
		};

		class sound_t : public kaitai::kstruct {

		public:
			sound_t(kaitai::kstream* p__io, level_t::map_t* p__parent = nullptr, level_t* p__root = nullptr);

		private:
			void _read();
			void _clean_up();

		public:
			~sound_t();

		private:
			uint8_t m_id;
			uint8_t m_x;
			uint8_t m_y;
			uint8_t m_unk1;
			level_t* m__root;
			level_t::map_t* m__parent;

		public:
			/**
			 * Sound type
			 */
			uint8_t id() const {
				return m_id;
			}

			/**
			 * X position
			 */
			uint8_t x() const {
				return m_x;
			}

			/**
			 * Y position
			 */
			uint8_t y() const {
				return m_y;
			}
			uint8_t unk1() const {
				return m_unk1;
			}
			level_t* _root() const {
				return m__root;
			}
			level_t::map_t* _parent() const {
				return m__parent;
			}
		};

		class track_block_t : public kaitai::kstruct {

		public:
			track_block_t(kaitai::kstream* p__io, level_t::map_t* p__parent = nullptr, level_t* p__root = nullptr);

		private:
			void _read();
			void _clean_up();

		public:
			~track_block_t();

		private:
			uint8_t m_unk1;
			uint8_t m_index;
			uint8_t m_node_count;
			uint8_t m_unk2;
			std::unique_ptr<std::vector<std::unique_ptr<track_block_node_t>>> m_nodes;
			level_t* m__root;
			level_t::map_t* m__parent;

		public:
			uint8_t unk1() const {
				return m_unk1;
			}

			/**
			 * Track block index
			 */
			uint8_t index() const {
				return m_index;
			}

			/**
			 * Track block node count
			 */
			uint8_t node_count() const {
				return m_node_count;
			}
			uint8_t unk2() const {
				return m_unk2;
			}

			/**
			 * Track block nodes
			 */
			std::vector<std::unique_ptr<track_block_node_t>>* nodes() const {
				return m_nodes.get();
			}
			level_t* _root() const {
				return m__root;
			}
			level_t::map_t* _parent() const {
				return m__parent;
			}
		};

		class piranha_creeper_node_t : public kaitai::kstruct {

		public:
			piranha_creeper_node_t(
				kaitai::kstream* p__io, level_t::piranha_creeper_t* p__parent = nullptr, level_t* p__root = nullptr);

		private:
			void _read();
			void _clean_up();

		public:
			~piranha_creeper_node_t();

		private:
			uint8_t m_unk1;
			uint8_t m_direction;
			uint16_t m_unk2;
			level_t* m__root;
			level_t::piranha_creeper_t* m__parent;

		public:
			uint8_t unk1() const {
				return m_unk1;
			}

			/**
			 * Piranha creeper node direction
			 */
			uint8_t direction() const {
				return m_direction;
			}
			uint16_t unk2() const {
				return m_unk2;
			}
			level_t* _root() const {
				return m__root;
			}
			level_t::piranha_creeper_t* _parent() const {
				return m__parent;
			}
		};

		class piranha_creeper_t : public kaitai::kstruct {

		public:
			piranha_creeper_t(kaitai::kstream* p__io, level_t::map_t* p__parent = nullptr, level_t* p__root = nullptr);

		private:
			void _read();
			void _clean_up();

		public:
			~piranha_creeper_t();

		private:
			uint8_t m_unk1;
			uint8_t m_index;
			uint8_t m_node_count;
			uint8_t m_unk2;
			std::unique_ptr<std::vector<std::unique_ptr<piranha_creeper_node_t>>> m_nodes;
			level_t* m__root;
			level_t::map_t* m__parent;

		public:
			uint8_t unk1() const {
				return m_unk1;
			}

			/**
			 * Piranha creeper index
			 */
			uint8_t index() const {
				return m_index;
			}

			/**
			 * Piranha creeper node count
			 */
			uint8_t node_count() const {
				return m_node_count;
			}
			uint8_t unk2() const {
				return m_unk2;
			}

			/**
			 * Piranha creeper nodes
			 */
			std::vector<std::unique_ptr<piranha_creeper_node_t>>* nodes() const {
				return m_nodes.get();
			}
			level_t* _root() const {
				return m__root;
			}
			level_t::map_t* _parent() const {
				return m__parent;
			}
		};

		class exclamation_block_node_t : public kaitai::kstruct {

		public:
			exclamation_block_node_t(
				kaitai::kstream* p__io, level_t::exclamation_block_t* p__parent = nullptr, level_t* p__root = nullptr);

		private:
			void _read();
			void _clean_up();

		public:
			~exclamation_block_node_t();

		private:
			uint8_t m_unk1;
			uint8_t m_direction;
			uint16_t m_unk2;
			level_t* m__root;
			level_t::exclamation_block_t* m__parent;

		public:
			uint8_t unk1() const {
				return m_unk1;
			}

			/**
			 * block node direction
			 */
			uint8_t direction() const {
				return m_direction;
			}
			uint16_t unk2() const {
				return m_unk2;
			}
			level_t* _root() const {
				return m__root;
			}
			level_t::exclamation_block_t* _parent() const {
				return m__parent;
			}
		};

	private:
		uint8_t m_start_y;
		uint8_t m_goal_y;
		int16_t m_goal_x;
		int16_t m_timer;
		int16_t m_clear_condition_magnitude;
		int16_t m_year;
		int8_t m_month;
		int8_t m_day;
		int8_t m_hour;
		int8_t m_minute;
		autoscroll_speed_t m_autoscroll_speed;
		clear_condition_category_t m_clear_condition_category;
		clear_condition_t m_clear_condition;
		int32_t m_unk_gamever;
		int32_t m_unk_management_flags;
		int32_t m_clear_attempts;
		int32_t m_clear_time;
		uint32_t m_unk_creation_id;
		int64_t m_unk_upload_id;
		game_version_t m_game_version;
		std::string m_unk1;
		gamestyle_t m_gamestyle;
		uint8_t m_unk2;
		std::string m_name;
		std::string m_description;
		std::unique_ptr<map_t> m_overworld;
		std::unique_ptr<map_t> m_subworld;
		level_t* m__root;
		kaitai::kstruct* m__parent;

	public:
		/**
		 * Starting Y position of level
		 */
		uint8_t start_y() const {
			return m_start_y;
		}

		/**
		 * Y position of goal
		 */
		uint8_t goal_y() const {
			return m_goal_y;
		}

		/**
		 * X position of goal
		 */
		int16_t goal_x() const {
			return m_goal_x;
		}

		/**
		 * Starting timer
		 */
		int16_t timer() const {
			return m_timer;
		}

		/**
		 * Clear condition magnitude
		 */
		int16_t clear_condition_magnitude() const {
			return m_clear_condition_magnitude;
		}

		/**
		 * Year made
		 */
		int16_t year() const {
			return m_year;
		}

		/**
		 * Month made
		 */
		int8_t month() const {
			return m_month;
		}

		/**
		 * Day made
		 */
		int8_t day() const {
			return m_day;
		}

		/**
		 * Hour made
		 */
		int8_t hour() const {
			return m_hour;
		}

		/**
		 * Minute made
		 */
		int8_t minute() const {
			return m_minute;
		}

		/**
		 * Autoscroll speed
		 */
		autoscroll_speed_t autoscroll_speed() const {
			return m_autoscroll_speed;
		}

		/**
		 * Clear condition category
		 */
		clear_condition_category_t clear_condition_category() const {
			return m_clear_condition_category;
		}

		/**
		 * Clear condition
		 */
		clear_condition_t clear_condition() const {
			return m_clear_condition;
		}

		/**
		 * Unknown gamever
		 */
		int32_t unk_gamever() const {
			return m_unk_gamever;
		}

		/**
		 * Unknown management_flags
		 */
		int32_t unk_management_flags() const {
			return m_unk_management_flags;
		}

		/**
		 * Clear attempts
		 */
		int32_t clear_attempts() const {
			return m_clear_attempts;
		}

		/**
		 * Clear time
		 */
		int32_t clear_time() const {
			return m_clear_time;
		}

		/**
		 * Unknown creation_id
		 */
		uint32_t unk_creation_id() const {
			return m_unk_creation_id;
		}

		/**
		 * Unknown upload_id
		 */
		int64_t unk_upload_id() const {
			return m_unk_upload_id;
		}

		/**
		 * Game version level was made in
		 */
		game_version_t game_version() const {
			return m_game_version;
		}
		std::string unk1() const {
			return m_unk1;
		}

		/**
		 * Game style
		 */
		gamestyle_t gamestyle() const {
			return m_gamestyle;
		}
		uint8_t unk2() const {
			return m_unk2;
		}
		std::string name() const {
			return m_name;
		}
		std::string description() const {
			return m_description;
		}
		map_t* overworld() const {
			return m_overworld.get();
		}
		map_t* subworld() const {
			return m_subworld.get();
		}
		level_t* _root() const {
			return m__root;
		}
		kaitai::kstruct* _parent() const {
			return m__parent;
		}
	};
}
