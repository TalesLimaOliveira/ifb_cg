# Vars
APPS = parte1 parte2
APP ?= parte1
CC = g++
EXTSRC = cpp
EXTINC = h

# Flags
CFLAGS ?= -O0 -Wall -Wextra
LDFLAGS = -lglut -lGL -lGLU -lm

# Directories
APPDIR = app
INCDIR = inc
LIBDIR = lib
SRCDIR = src
BUILDDIR = build
BINDIR = $(BUILDDIR)/bin
OBJDIR = $(BUILDDIR)/obj

# Find all source files in src and app
SOURCES := $(wildcard $(SRCDIR)/*.$(EXTSRC)) $(wildcard $(APPDIR)/*.$(EXTSRC))

# Create object lists for each app
APP_OBJECTS = $(foreach app, $(APPS), $(OBJDIR)/$(app).o)
COMMON_OBJECTS = $(patsubst $(SRCDIR)/%.$(EXTSRC), $(OBJDIR)/%.o, $(filter $(SRCDIR)/%.$(EXTSRC), $(SOURCES)))

# Find all library files (.a) in the library directory
LIBRARIES := $(wildcard $(LIBDIR)/*.a)

# Executes make
.PHONY: all
all: folder $(APPS)

# Create build directories
folder:
	@ mkdir -p $(BUILDDIR) $(BINDIR) $(OBJDIR)

# Compile common objects
$(OBJDIR)/%.o: $(SRCDIR)/%.$(EXTSRC)
	@ $(CC) $(CFLAGS) -c $< -I $(INCDIR) -o $@
	@ echo "Compiled $<"

# Compile app-specific objects
$(OBJDIR)/%.o: $(APPDIR)/%.$(EXTSRC)
	@ $(CC) $(CFLAGS) -c $< -I $(INCDIR) -o $@
	@ echo "Compiled $<"

# Build each app
$(APPS): %: folder $(COMMON_OBJECTS) $(OBJDIR)/%.o
	@ $(CC) $(COMMON_OBJECTS) $(OBJDIR)/$@.o $(LDFLAGS) -o $(BINDIR)/$@
	@ echo "$@ compiled to $(BINDIR)/$@"

# Run targets with arguments
run: 
	@ ./$(BINDIR)/$(APP)

# Clean build files
clean:
	@ rm -rf $(BUILDDIR)
	@ echo "Cleaned build files"
