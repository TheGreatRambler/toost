// This is a generated file! Please edit source .ksy file and use kaitai-struct-compiler to rebuild

#include "level.h"
namespace MM2 {

	level_t::level_t(kaitai::kstream* p__io, kaitai::kstruct* p__parent, level_t* p__root)
		: kaitai::kstruct(p__io) {
		m__parent   = p__parent;
		m__root     = this;
		m_overworld = nullptr;
		m_subworld  = nullptr;
		_read();
	}

	void level_t::_read() {
		m_start_y                   = m__io->read_u1();
		m_goal_y                    = m__io->read_u1();
		m_goal_x                    = m__io->read_s2le();
		m_timer                     = m__io->read_s2le();
		m_clear_condition_magnitude = m__io->read_s2le();
		m_year                      = m__io->read_s2le();
		m_month                     = m__io->read_s1();
		m_day                       = m__io->read_s1();
		m_hour                      = m__io->read_s1();
		m_minute                    = m__io->read_s1();
		m_autoscroll_speed          = static_cast<level_t::autoscroll_speed_t>(m__io->read_u1());
		m_clear_condition_category  = static_cast<level_t::clear_condition_category_t>(m__io->read_u1());
		m_clear_condition           = static_cast<level_t::clear_condition_t>(m__io->read_s4le());
		m_unk_gamever               = m__io->read_s4le();
		m_unk_management_flags      = m__io->read_s4le();
		m_clear_attempts            = m__io->read_s4le();
		m_clear_time                = m__io->read_s4le();
		m_unk_creation_id           = m__io->read_u4le();
		m_unk_upload_id             = m__io->read_s8le();
		m_game_version              = static_cast<level_t::game_version_t>(m__io->read_s4le());
		m_unk1                      = m__io->read_bytes(189);
		m_gamestyle                 = static_cast<level_t::gamestyle_t>(m__io->read_s2le());
		m_unk2                      = m__io->read_u1();
		m_name                      = kaitai::kstream::bytes_to_str(m__io->read_bytes(66), std::string("UTF-16LE"));
		m_description               = kaitai::kstream::bytes_to_str(m__io->read_bytes(202), std::string("UTF-16LE"));
		m_overworld                 = std::unique_ptr<map_t>(new map_t(m__io, this, m__root));
		m_subworld                  = std::unique_ptr<map_t>(new map_t(m__io, this, m__root));
	}

	level_t::~level_t() {
		_clean_up();
	}

	void level_t::_clean_up() { }

	level_t::map_t::map_t(kaitai::kstream* p__io, level_t* p__parent, level_t* p__root)
		: kaitai::kstruct(p__io) {
		m__parent            = p__parent;
		m__root              = p__root;
		m_objects            = nullptr;
		m_sounds             = nullptr;
		m_snakes             = nullptr;
		m_clear_pipes        = nullptr;
		m_piranha_creepers   = nullptr;
		m_exclamation_blocks = nullptr;
		m_track_blocks       = nullptr;
		m_ground             = nullptr;
		m_tracks             = nullptr;
		m_icicles            = nullptr;
		_read();
	}

	void level_t::map_t::_read() {
		m_theme                        = static_cast<level_t::map_t::theme_t>(m__io->read_u1());
		m_autoscroll_type              = static_cast<level_t::map_t::autoscroll_type_t>(m__io->read_u1());
		m_boundary_type                = static_cast<level_t::map_t::boundary_type_t>(m__io->read_u1());
		m_orientation                  = static_cast<level_t::map_t::orientation_t>(m__io->read_u1());
		m_liquid_end_height            = m__io->read_u1();
		m_liquid_mode                  = static_cast<level_t::map_t::liquid_mode_t>(m__io->read_u1());
		m_liquid_speed                 = static_cast<level_t::map_t::liquid_speed_t>(m__io->read_u1());
		m_liquid_start_height          = m__io->read_u1();
		m_boundary_right               = m__io->read_s4le();
		m_boundary_top                 = m__io->read_s4le();
		m_boundary_left                = m__io->read_s4le();
		m_boundary_bottom              = m__io->read_s4le();
		m_unk_flag                     = m__io->read_s4le();
		m_object_count                 = m__io->read_s4le();
		m_sound_effect_count           = m__io->read_s4le();
		m_snake_block_count            = m__io->read_s4le();
		m_clear_pipe_count             = m__io->read_s4le();
		m_piranha_creeper_count        = m__io->read_s4le();
		m_exclamation_mark_block_count = m__io->read_s4le();
		m_track_block_count            = m__io->read_s4le();
		m_unk1                         = m__io->read_s4le();
		m_ground_count                 = m__io->read_s4le();
		m_track_count                  = m__io->read_s4le();
		m_ice_count                    = m__io->read_s4le();
		int l_objects                  = 2600;
		m_objects = std::unique_ptr<std::vector<std::unique_ptr<obj_t>>>(new std::vector<std::unique_ptr<obj_t>>());
		m_objects->reserve(l_objects);
		for(int i = 0; i < l_objects; i++) {
			m_objects->push_back(std::move(std::unique_ptr<obj_t>(new obj_t(m__io, this, m__root))));
		}
		int l_sounds = 300;
		m_sounds = std::unique_ptr<std::vector<std::unique_ptr<sound_t>>>(new std::vector<std::unique_ptr<sound_t>>());
		m_sounds->reserve(l_sounds);
		for(int i = 0; i < l_sounds; i++) {
			m_sounds->push_back(std::move(std::unique_ptr<sound_t>(new sound_t(m__io, this, m__root))));
		}
		int l_snakes = 5;
		m_snakes = std::unique_ptr<std::vector<std::unique_ptr<snake_t>>>(new std::vector<std::unique_ptr<snake_t>>());
		m_snakes->reserve(l_snakes);
		for(int i = 0; i < l_snakes; i++) {
			m_snakes->push_back(std::move(std::unique_ptr<snake_t>(new snake_t(m__io, this, m__root))));
		}
		int l_clear_pipes = 200;
		m_clear_pipes     = std::unique_ptr<std::vector<std::unique_ptr<clear_pipe_t>>>(
            new std::vector<std::unique_ptr<clear_pipe_t>>());
		m_clear_pipes->reserve(l_clear_pipes);
		for(int i = 0; i < l_clear_pipes; i++) {
			m_clear_pipes->push_back(std::move(std::unique_ptr<clear_pipe_t>(new clear_pipe_t(m__io, this, m__root))));
		}
		int l_piranha_creepers = 10;
		m_piranha_creepers     = std::unique_ptr<std::vector<std::unique_ptr<piranha_creeper_t>>>(
            new std::vector<std::unique_ptr<piranha_creeper_t>>());
		m_piranha_creepers->reserve(l_piranha_creepers);
		for(int i = 0; i < l_piranha_creepers; i++) {
			m_piranha_creepers->push_back(
				std::move(std::unique_ptr<piranha_creeper_t>(new piranha_creeper_t(m__io, this, m__root))));
		}
		int l_exclamation_blocks = 10;
		m_exclamation_blocks     = std::unique_ptr<std::vector<std::unique_ptr<exclamation_block_t>>>(
            new std::vector<std::unique_ptr<exclamation_block_t>>());
		m_exclamation_blocks->reserve(l_exclamation_blocks);
		for(int i = 0; i < l_exclamation_blocks; i++) {
			m_exclamation_blocks->push_back(
				std::move(std::unique_ptr<exclamation_block_t>(new exclamation_block_t(m__io, this, m__root))));
		}
		int l_track_blocks = 10;
		m_track_blocks     = std::unique_ptr<std::vector<std::unique_ptr<track_block_t>>>(
            new std::vector<std::unique_ptr<track_block_t>>());
		m_track_blocks->reserve(l_track_blocks);
		for(int i = 0; i < l_track_blocks; i++) {
			m_track_blocks->push_back(
				std::move(std::unique_ptr<track_block_t>(new track_block_t(m__io, this, m__root))));
		}
		int l_ground = 4000;
		m_ground
			= std::unique_ptr<std::vector<std::unique_ptr<ground_t>>>(new std::vector<std::unique_ptr<ground_t>>());
		m_ground->reserve(l_ground);
		for(int i = 0; i < l_ground; i++) {
			m_ground->push_back(std::move(std::unique_ptr<ground_t>(new ground_t(m__io, this, m__root))));
		}
		int l_tracks = 1500;
		m_tracks = std::unique_ptr<std::vector<std::unique_ptr<track_t>>>(new std::vector<std::unique_ptr<track_t>>());
		m_tracks->reserve(l_tracks);
		for(int i = 0; i < l_tracks; i++) {
			m_tracks->push_back(std::move(std::unique_ptr<track_t>(new track_t(m__io, this, m__root))));
		}
		int l_icicles = 300;
		m_icicles
			= std::unique_ptr<std::vector<std::unique_ptr<icicle_t>>>(new std::vector<std::unique_ptr<icicle_t>>());
		m_icicles->reserve(l_icicles);
		for(int i = 0; i < l_icicles; i++) {
			m_icicles->push_back(std::move(std::unique_ptr<icicle_t>(new icicle_t(m__io, this, m__root))));
		}
		m_unk2 = m__io->read_bytes(3516);
	}

	level_t::map_t::~map_t() {
		_clean_up();
	}

	void level_t::map_t::_clean_up() { }

	level_t::clear_pipe_node_t::clear_pipe_node_t(
		kaitai::kstream* p__io, level_t::clear_pipe_t* p__parent, level_t* p__root)
		: kaitai::kstruct(p__io) {
		m__parent = p__parent;
		m__root   = p__root;
		_read();
	}

	void level_t::clear_pipe_node_t::_read() {
		m_type      = m__io->read_u1();
		m_index     = m__io->read_u1();
		m_x         = m__io->read_u1();
		m_y         = m__io->read_u1();
		m_width     = m__io->read_u1();
		m_height    = m__io->read_u1();
		m_unk1      = m__io->read_u1();
		m_direction = m__io->read_u1();
	}

	level_t::clear_pipe_node_t::~clear_pipe_node_t() {
		_clean_up();
	}

	void level_t::clear_pipe_node_t::_clean_up() { }

	level_t::track_t::track_t(kaitai::kstream* p__io, level_t::map_t* p__parent, level_t* p__root)
		: kaitai::kstruct(p__io) {
		m__parent = p__parent;
		m__root   = p__root;
		_read();
	}

	void level_t::track_t::_read() {
		m_unk1  = m__io->read_u2le();
		m_flags = m__io->read_u1();
		m_x     = m__io->read_u1();
		m_y     = m__io->read_u1();
		m_type  = m__io->read_u1();
		m_lid   = m__io->read_u2le();
		m_unk2  = m__io->read_u2le();
		m_unk3  = m__io->read_u2le();
	}

	level_t::track_t::~track_t() {
		_clean_up();
	}

	void level_t::track_t::_clean_up() { }

	level_t::track_block_node_t::track_block_node_t(
		kaitai::kstream* p__io, level_t::track_block_t* p__parent, level_t* p__root)
		: kaitai::kstruct(p__io) {
		m__parent = p__parent;
		m__root   = p__root;
		_read();
	}

	void level_t::track_block_node_t::_read() {
		m_unk1      = m__io->read_u1();
		m_direction = m__io->read_u1();
		m_unk2      = m__io->read_u2le();
	}

	level_t::track_block_node_t::~track_block_node_t() {
		_clean_up();
	}

	void level_t::track_block_node_t::_clean_up() { }

	level_t::obj_t::obj_t(kaitai::kstream* p__io, level_t::map_t* p__parent, level_t* p__root)
		: kaitai::kstruct(p__io) {
		m__parent = p__parent;
		m__root   = p__root;
		_read();
	}

	void level_t::obj_t::_read() {
		m_x      = m__io->read_s4le();
		m_y      = m__io->read_s4le();
		m_unk1   = m__io->read_s2le();
		m_width  = m__io->read_u1();
		m_height = m__io->read_u1();
		m_flag   = m__io->read_s4le();
		m_cflag  = m__io->read_s4le();
		m_ex     = m__io->read_s4le();
		m_id     = static_cast<level_t::obj_t::obj_id_t>(m__io->read_s2le());
		m_cid    = m__io->read_s2le();
		m_lid    = m__io->read_s2le();
		m_sid    = m__io->read_s2le();
	}

	level_t::obj_t::~obj_t() {
		_clean_up();
	}

	void level_t::obj_t::_clean_up() { }

	level_t::icicle_t::icicle_t(kaitai::kstream* p__io, level_t::map_t* p__parent, level_t* p__root)
		: kaitai::kstruct(p__io) {
		m__parent = p__parent;
		m__root   = p__root;
		_read();
	}

	void level_t::icicle_t::_read() {
		m_x    = m__io->read_u1();
		m_y    = m__io->read_u1();
		m_type = m__io->read_u1();
		m_unk1 = m__io->read_u1();
	}

	level_t::icicle_t::~icicle_t() {
		_clean_up();
	}

	void level_t::icicle_t::_clean_up() { }

	level_t::snake_t::snake_t(kaitai::kstream* p__io, level_t::map_t* p__parent, level_t* p__root)
		: kaitai::kstruct(p__io) {
		m__parent = p__parent;
		m__root   = p__root;
		m_nodes   = nullptr;
		_read();
	}

	void level_t::snake_t::_read() {
		m_index      = m__io->read_u1();
		m_node_count = m__io->read_u1();
		m_unk1       = m__io->read_u2le();
		int l_nodes  = 120;
		m_nodes      = std::unique_ptr<std::vector<std::unique_ptr<snake_node_t>>>(
            new std::vector<std::unique_ptr<snake_node_t>>());
		m_nodes->reserve(l_nodes);
		for(int i = 0; i < l_nodes; i++) {
			m_nodes->push_back(std::move(std::unique_ptr<snake_node_t>(new snake_node_t(m__io, this, m__root))));
		}
	}

	level_t::snake_t::~snake_t() {
		_clean_up();
	}

	void level_t::snake_t::_clean_up() { }

	level_t::clear_pipe_t::clear_pipe_t(kaitai::kstream* p__io, level_t::map_t* p__parent, level_t* p__root)
		: kaitai::kstruct(p__io) {
		m__parent = p__parent;
		m__root   = p__root;
		m_nodes   = nullptr;
		_read();
	}

	void level_t::clear_pipe_t::_read() {
		m_index      = m__io->read_u1();
		m_node_count = m__io->read_u1();
		m_unk        = m__io->read_u2le();
		int l_nodes  = 36;
		m_nodes      = std::unique_ptr<std::vector<std::unique_ptr<clear_pipe_node_t>>>(
            new std::vector<std::unique_ptr<clear_pipe_node_t>>());
		m_nodes->reserve(l_nodes);
		for(int i = 0; i < l_nodes; i++) {
			m_nodes->push_back(
				std::move(std::unique_ptr<clear_pipe_node_t>(new clear_pipe_node_t(m__io, this, m__root))));
		}
	}

	level_t::clear_pipe_t::~clear_pipe_t() {
		_clean_up();
	}

	void level_t::clear_pipe_t::_clean_up() { }

	level_t::exclamation_block_t::exclamation_block_t(
		kaitai::kstream* p__io, level_t::map_t* p__parent, level_t* p__root)
		: kaitai::kstruct(p__io) {
		m__parent = p__parent;
		m__root   = p__root;
		m_nodes   = nullptr;
		_read();
	}

	void level_t::exclamation_block_t::_read() {
		m_unk1       = m__io->read_u1();
		m_index      = m__io->read_u1();
		m_node_count = m__io->read_u1();
		m_unk2       = m__io->read_u1();
		int l_nodes  = 10;
		m_nodes      = std::unique_ptr<std::vector<std::unique_ptr<exclamation_block_node_t>>>(
            new std::vector<std::unique_ptr<exclamation_block_node_t>>());
		m_nodes->reserve(l_nodes);
		for(int i = 0; i < l_nodes; i++) {
			m_nodes->push_back(std::move(
				std::unique_ptr<exclamation_block_node_t>(new exclamation_block_node_t(m__io, this, m__root))));
		}
	}

	level_t::exclamation_block_t::~exclamation_block_t() {
		_clean_up();
	}

	void level_t::exclamation_block_t::_clean_up() { }

	level_t::ground_t::ground_t(kaitai::kstream* p__io, level_t::map_t* p__parent, level_t* p__root)
		: kaitai::kstruct(p__io) {
		m__parent = p__parent;
		m__root   = p__root;
		_read();
	}

	void level_t::ground_t::_read() {
		m_x             = m__io->read_u1();
		m_y             = m__io->read_u1();
		m_id            = m__io->read_u1();
		m_background_id = m__io->read_u1();
	}

	level_t::ground_t::~ground_t() {
		_clean_up();
	}

	void level_t::ground_t::_clean_up() { }

	level_t::snake_node_t::snake_node_t(kaitai::kstream* p__io, level_t::snake_t* p__parent, level_t* p__root)
		: kaitai::kstruct(p__io) {
		m__parent = p__parent;
		m__root   = p__root;
		_read();
	}

	void level_t::snake_node_t::_read() {
		m_index     = m__io->read_u2le();
		m_direction = m__io->read_u2le();
		m_unk1      = m__io->read_u4le();
	}

	level_t::snake_node_t::~snake_node_t() {
		_clean_up();
	}

	void level_t::snake_node_t::_clean_up() { }

	level_t::sound_t::sound_t(kaitai::kstream* p__io, level_t::map_t* p__parent, level_t* p__root)
		: kaitai::kstruct(p__io) {
		m__parent = p__parent;
		m__root   = p__root;
		_read();
	}

	void level_t::sound_t::_read() {
		m_id   = m__io->read_u1();
		m_x    = m__io->read_u1();
		m_y    = m__io->read_u1();
		m_unk1 = m__io->read_u1();
	}

	level_t::sound_t::~sound_t() {
		_clean_up();
	}

	void level_t::sound_t::_clean_up() { }

	level_t::track_block_t::track_block_t(kaitai::kstream* p__io, level_t::map_t* p__parent, level_t* p__root)
		: kaitai::kstruct(p__io) {
		m__parent = p__parent;
		m__root   = p__root;
		m_nodes   = nullptr;
		_read();
	}

	void level_t::track_block_t::_read() {
		m_unk1       = m__io->read_u1();
		m_index      = m__io->read_u1();
		m_node_count = m__io->read_u1();
		m_unk2       = m__io->read_u1();
		int l_nodes  = 10;
		m_nodes      = std::unique_ptr<std::vector<std::unique_ptr<track_block_node_t>>>(
            new std::vector<std::unique_ptr<track_block_node_t>>());
		m_nodes->reserve(l_nodes);
		for(int i = 0; i < l_nodes; i++) {
			m_nodes->push_back(
				std::move(std::unique_ptr<track_block_node_t>(new track_block_node_t(m__io, this, m__root))));
		}
	}

	level_t::track_block_t::~track_block_t() {
		_clean_up();
	}

	void level_t::track_block_t::_clean_up() { }

	level_t::piranha_creeper_node_t::piranha_creeper_node_t(
		kaitai::kstream* p__io, level_t::piranha_creeper_t* p__parent, level_t* p__root)
		: kaitai::kstruct(p__io) {
		m__parent = p__parent;
		m__root   = p__root;
		_read();
	}

	void level_t::piranha_creeper_node_t::_read() {
		m_unk1      = m__io->read_u1();
		m_direction = m__io->read_u1();
		m_unk2      = m__io->read_u2le();
	}

	level_t::piranha_creeper_node_t::~piranha_creeper_node_t() {
		_clean_up();
	}

	void level_t::piranha_creeper_node_t::_clean_up() { }

	level_t::piranha_creeper_t::piranha_creeper_t(kaitai::kstream* p__io, level_t::map_t* p__parent, level_t* p__root)
		: kaitai::kstruct(p__io) {
		m__parent = p__parent;
		m__root   = p__root;
		m_nodes   = nullptr;
		_read();
	}

	void level_t::piranha_creeper_t::_read() {
		m_unk1       = m__io->read_u1();
		m_index      = m__io->read_u1();
		m_node_count = m__io->read_u1();
		m_unk2       = m__io->read_u1();
		int l_nodes  = 20;
		m_nodes      = std::unique_ptr<std::vector<std::unique_ptr<piranha_creeper_node_t>>>(
            new std::vector<std::unique_ptr<piranha_creeper_node_t>>());
		m_nodes->reserve(l_nodes);
		for(int i = 0; i < l_nodes; i++) {
			m_nodes->push_back(
				std::move(std::unique_ptr<piranha_creeper_node_t>(new piranha_creeper_node_t(m__io, this, m__root))));
		}
	}

	level_t::piranha_creeper_t::~piranha_creeper_t() {
		_clean_up();
	}

	void level_t::piranha_creeper_t::_clean_up() { }

	level_t::exclamation_block_node_t::exclamation_block_node_t(
		kaitai::kstream* p__io, level_t::exclamation_block_t* p__parent, level_t* p__root)
		: kaitai::kstruct(p__io) {
		m__parent = p__parent;
		m__root   = p__root;
		_read();
	}

	void level_t::exclamation_block_node_t::_read() {
		m_unk1      = m__io->read_u1();
		m_direction = m__io->read_u1();
		m_unk2      = m__io->read_u2le();
	}

	level_t::exclamation_block_node_t::~exclamation_block_node_t() {
		_clean_up();
	}

	void level_t::exclamation_block_node_t::_clean_up() { }
}
