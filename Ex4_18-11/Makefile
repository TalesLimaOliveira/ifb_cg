# Vars
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

# Sources and objects
SOURCES := $(wildcard $(SRCDIR)/*.$(EXTSRC)) $(wildcard $(APPDIR)/*.$(EXTSRC))
OBJECTS := $(patsubst $(SRCDIR)/%.$(EXTSRC), $(OBJDIR)/%.o, $(filter $(SRCDIR)/%.$(EXTSRC), $(SOURCES)))
APP_SOURCES := $(wildcard $(APPDIR)/*.$(EXTSRC))
APPS := $(patsubst $(APPDIR)/%.$(EXTSRC), %, $(APP_SOURCES))
LIBRARIES := $(wildcard $(LIBDIR)/*.a)

# Build all
.PHONY: all
all: folder $(foreach app,$(APPS),$(BINDIR)/$(app))

# Compile objects
$(OBJDIR)/%.o: $(SRCDIR)/%.$(EXTSRC)
	@ $(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

# Link applications
$(BINDIR)/%: $(APPDIR)/%.$(EXTSRC) $(OBJECTS)
	@ $(CC) $^ $(LDFLAGS) -o $@
	@ echo "Compiled $@"

# Run applications
run-%: $(BINDIR)/%
	@ ./$(BINDIR)/$*

# Create directories
.PHONY: folder
folder:
	@ mkdir -p $(BUILDDIR) $(BINDIR) $(OBJDIR)

# Clean
.PHONY: clean
clean:
	@ rm -rf $(BUILDDIR)
	@ echo "Cleaned build files"
