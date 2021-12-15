UNAME := $(shell uname -o)

# mingw-w64-x86_64-SDL2 in pacman
# No extension for the executable
TARGET_EXEC ?= levelviewer

BUILD_DIR ?= ./bin
SRC_DIRS ?= ./src

# Set compilers to MinGW64 compilers
CC := gcc
CXX := c++

# C flags
CFLAGS := -std=gnu11
# C++ flags
# Single precision sets all defined floating point numbers to floats, saves on memory
CXXFLAGS := -std=gnu++20 -I./src/include -I./src $(shell pkg-config --cflags sdl2 glew glfw3 zlib cairo)
# C/C++ flags (no -pendantic)
CPPFLAGS := -Wall -Wextra -Wno-missing-field-initializers -Wno-cast-function-type

ifeq ($(BUILD),release)
	# "Release" build - optimization, and no debug symbols
	CPPFLAGS += -O3 -s -DNDEBUG
else
	# "Debug" build - no optimization, and debugging symbols
	CPPFLAGS += -Og -g -ggdb -DDEBUG
endif

# Linker flags (-lpthread needed for threads)
# Include Winsock for getting the IP address
# Can't use normal pkg config output because we don't want -mswindows
LDFLAGS := -lpthread -lopengl32 $(shell pkg-config --libs --static sdl2 glew glfw3 zlib cairo) -mconsole

ifeq ($(UNAME),Msys)
	# Needed for sockets on windows
	LDFLAGS += -lmingw32 -lws2_32 -lwsock32
else
	LDFLAGS += -ldl
endif

#SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
SRCS := ./src/main.cpp ./src/LevelParser.cpp ./src/Drawers.cpp ./src/imgui/imgui.cpp ./src/imgui/imgui_widgets.cpp ./src/imgui/imgui_tables.cpp ./src/imgui/imgui_impl_sdlrenderer.cpp ./src/imgui/imgui_impl_sdl.cpp ./src/imgui/imgui_impl_opengl3.cpp ./src/imgui/imgui_draw.cpp ./src/SMM2CourseDecryptor/aes.cpp ./src/SMM2CourseDecryptor/decrypt.cpp ./src/fmt/format.cpp ./src/fmt/os.cpp
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)
	# Copy required DLLs to folder, not copying the ones that are custom
	ldd $(BUILD_DIR)/$(TARGET_EXEC) | grep '\/mingw.*\.dll' -o | xargs -I{} cp -n "{}" $(BUILD_DIR)

# assembly
$(BUILD_DIR)/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p
