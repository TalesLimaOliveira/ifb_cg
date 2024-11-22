# Run args: make run-app arg1 arg2

# Compiler selection
CC = gcc
EXT = c

# Compilation flags
CFLAGS ?= -Wall -Wextra -O0
LDFLAGS ?= -lglut -lGL -lGLU -lm

# Directories
APP_DIR = app
SRC_DIR = src
INC_DIR = inc
LIB_DIR = lib
BUILD_DIR = build

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.$(EXT))
OBJECTS = $(patsubst $(SRC_DIR)/%.$(EXT), $(BUILD_DIR)/%.o, $(SOURCES))
LIBRARIES = $(wildcard $(LIB_DIR)/*.a)

# Applications
APPS = $(wildcard $(APP_DIR)/*.$(EXT))

# Default target: Build all applications
all: $(APPS)
	@echo "Build complete."

# Compile sources: Compile each source file into an object file
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(EXT)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Link applications: Link object files and source files into executables
$(APP_DIR)/%: $(APP_DIR)/%.$(EXT) $(OBJECTS)
	$(CC) $(CFLAGS) -I$(INC_DIR) $< $(OBJECTS) $(LIBRARIES) $(LDFLAGS) -o $@
	@echo "Compiled $@"

# Run application: Run the specified application with arguments
run-%:
	@$(APP_DIR)/$* $(filter-out $@,$(MAKECMDGOALS))

# Clean build files: Remove build directory and object files
clean:
	rm -rf $(BUILD_DIR)/*
	@echo "Clean complete."

.PHONY: all clean run-%
