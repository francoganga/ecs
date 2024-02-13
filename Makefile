# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -Wall -Wextra -std=c++11

# ImGui source files directory
IMGUI_DIR := lib/imgui

# ImGui-SFML source files directory
IMGUI_SFML_DIR := lib/imgui-sfml

# Output directory for object files
BUILD_DIR := build

# Source files
IMGUI_SRCS := $(wildcard $(IMGUI_DIR)/*.cpp)
IMGUI_SFML_SRCS := $(wildcard $(IMGUI_SFML_DIR)/*.cpp)

# Object files
IMGUI_OBJS := $(patsubst $(IMGUI_DIR)/%.cpp,$(BUILD_DIR)/imgui_%.o,$(IMGUI_SRCS))
IMGUI_SFML_OBJS := $(patsubst $(IMGUI_SFML_DIR)/%.cpp,$(BUILD_DIR)/imgui-sfml_%.o,$(IMGUI_SFML_SRCS))

MAIN_OBJ := $(BUILD_DIR)/main.o

MAIN_SRC := src/main.cpp

TARGET := game

INCLUDE := -Ilib/imgui -Ilib/imgui-sfml

SRC_DIR := src
LIBS := -lsfml-window -lsfml-graphics -lsfml-system -lGL

SRCS := $(filter-out $(SRC_DIR)/main.cpp,$(wildcard $(SRC_DIR)/*.cpp))

OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))


# Rule to create the output directory
$(shell mkdir -p $(BUILD_DIR))

# Rule to build ImGui object files
$(BUILD_DIR)/imgui_%.o: $(IMGUI_DIR)/%.cpp
	@echo "Compiling $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to build ImGui-SFML object files
$(BUILD_DIR)/imgui-sfml_%.o: $(IMGUI_SFML_DIR)/%.cpp
	@echo "Compiling $<"
	$(CXX) $(CXXFLAGS) -Ilib/imgui -c $< -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "Compiling $<"
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@


$(MAIN_OBJ): $(MAIN_SRC) imgui imgui-sfml $(OBJS)
	@echo "Compiling $<"
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

# PHONY rule to build ImGui and ImGui-SFML
all: imgui imgui-sfml
	@echo "All dependencies built"

# Rule to build ImGui
imgui: $(IMGUI_OBJS)
	@echo "ImGui built successfully"

# Rule to build ImGui-SFML
imgui-sfml: $(IMGUI_SFML_OBJS)
	@echo "ImGui-SFML built successfully"

main: $(MAIN_OBJ)
	@echo "Building main"
	$(CXX) $(CXXFLAGS) $^ $(OBJS) $(IMGUI_OBJS) $(IMGUI_SFML_OBJS) $(LIBS) -o $(TARGET)



# Clean rule
clean:
	rm -rf $(BUILD_DIR)
