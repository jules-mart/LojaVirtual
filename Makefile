# Compiler and flags
CXX = g++
CXXFLAGS = -Iincludes -std=c++17 
# -Wall -Wextra -O2

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
BIN_DIR = bin

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Executable name
TARGET = $(BIN_DIR)/VirtualMarket

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	@$(TARGET)

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Phony targets (not actual files)
.PHONY: all run clean
