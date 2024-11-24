# Run args: make run-app arg1 arg2

# Compiler selection
CC = g++
EXT = cpp

# Compilation flags
CFLAGS ?= -Wall -Wextra -O0
LDFLAGS ?= -lglut -lGL -lGLU -lm

# Directories
APP_DIR = app
SRC_DIR = src
INC_DIR = inc
LIB_DIR = lib
BUILD_DIR = build
BIN_DIR = $(BUILD_DIR)/bin
OBJ_DIR = $(BUILD_DIR)/obj

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.$(EXT))
OBJECTS = $(patsubst $(SRC_DIR)/%.$(EXT), $(OBJ_DIR)/%.o, $(SOURCES))
# LIBRARIES = $(wildcard $(LIB_DIR)/*)

# Applications
APPS = $(patsubst $(APP_DIR)/%.$(EXT), $(BIN_DIR)/%, $(wildcard $(APP_DIR)/*.$(EXT)))

# Default target: Build all applications
all: $(APPS) | $(BIN_DIR) $(OBJ_DIR)
	@echo "Build complete."

# Create build and bin directories if they don't exist
$(BIN_DIR) $(OBJ_DIR):
	@mkdir -p $@

# Compile sources: Compile each source file into an object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(EXT) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Link applications: Link object files and source files into executables
$(BIN_DIR)/%: $(APP_DIR)/%.$(EXT) $(OBJECTS) | $(BIN_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) $< $(OBJECTS) $(LDFLAGS) -o $@
	@echo "Compiled $(notdir $@)"

# Run application: Run the specified application with arguments
run-%:
	@$(BIN_DIR)/$* $(filter-out $@,$(MAKECMDGOALS))

run:
	@$(BIN_DIR)/*

# # Describe the functionality of the keys and the program
# describe:
# 	@echo "Program Capabilities and Key Bindings:"
# 	@echo "--------------------------------------"
# 	@echo "ESC: Exit the program"
# 	@echo "R, Insert: Reset the parameters of the current instance"
# 	@echo "C, F1: Create a new instance and select it"
# 	@echo "1, Page Down: Select the previous instance"
# 	@echo "3, Page Up: Select the next instance"
# 	@echo "Arrow Keys, WASD: Move the current instance"
# 	@echo "Q, F2: Increment the angle of the current instance"
# 	@echo "E, F3: Decrement the angle of the current instance"
# 	@echo "F, F5: Increment the scale of the current instance"
# 	@echo "G, F6: Decrement the scale of the current instance"

# Clean build files: Remove build directory and object files
clean:
	@rm -rf $(BUILD_DIR)
	@echo "Clean complete."

.PHONY: all clean run run-%
.PRECIOUS: $(OBJECTS)
