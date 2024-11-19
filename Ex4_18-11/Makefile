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

# Find all source files (.$(EXTSRC))
SOURCES := $(wildcard $(SRCDIR)/*.$(EXTSRC)) $(wildcard $(APPDIR)/*.$(EXTSRC))

# Generate a list of object files (.o) from the source file names
OBJECTS := $(patsubst $(SRCDIR)/%.$(EXTSRC), $(OBJDIR)/%.o, $(filter $(SRCDIR)/%.$(EXTSRC), $(SOURCES))) \
           $(patsubst $(APPDIR)/%.$(EXTSRC), $(OBJDIR)/%.o, $(filter $(APPDIR)/%.$(EXTSRC), $(SOURCES)))

# Find all library files (.a) in the library directory
LIBRARIES := $(wildcard $(LIBDIR)/*.a)

# Executes make
.PHONY: all
all: folder $(APPS)

# Create directory
folder:
	@ mkdir -p $(BUILDDIR) $(BINDIR) $(OBJDIR)

# Compile objects
$(OBJDIR)/%.o: $(SRCDIR)/%.$(EXTSRC)
	@ $(CC) $(CFLAGS) -c $< -I $(INCDIR) -o $@

$(OBJDIR)/%.o: $(APPDIR)/%.$(EXTSRC)
	@ $(CC) $(CFLAGS) -c $< -I $(INCDIR) -o $@

# Link object files to create the executables
$(APPS): %: folder $(OBJECTS) $(OBJDIR)/%.o
	@ $(CC) $(OBJECTS) $(OBJDIR)/$@.o $(LDFLAGS) -o $(BINDIR)/$@
	@ echo "$@ Compiled"

# Run targets with arguments
run: 
	@ ./$(BINDIR)/$(APP)

# Clean build files
clean:
	@ rm -rf $(BUILDDIR)
	@ echo "Cleaned build files"
