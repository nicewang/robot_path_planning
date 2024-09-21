CONFIG_FILE = config.properties

CONFIG_WIDTH = $(shell grep ^CONFIG_WIDTH $(CONFIG_FILE) | cut -d '=' -f2)
CONFIG_HEIGHT = $(shell grep ^CONFIG_HEIGHT $(CONFIG_FILE) | cut -d '=' -f2)
CONFIG_START_X = $(shell grep ^CONFIG_START_X $(CONFIG_FILE) | cut -d '=' -f2)
CONFIG_START_Y = $(shell grep ^CONFIG_START_Y $(CONFIG_FILE) | cut -d '=' -f2)
CONFIG_GOAL_X = $(shell grep ^CONFIG_GOAL_X $(CONFIG_FILE) | cut -d '=' -f2)
CONFIG_GOAL_Y = $(shell grep ^CONFIG_GOAL_Y $(CONFIG_FILE) | cut -d '=' -f2)

# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall -DCONFIG_WIDTH=$(CONFIG_WIDTH) -DCONFIG_HEIGHT=$(CONFIG_HEIGHT) -DCONFIG_START_X=$(CONFIG_START_X) -DCONFIG_START_Y=$(CONFIG_START_Y) -DCONFIG_GOAL_X=$(CONFIG_GOAL_X) -DCONFIG_GOAL_Y=$(CONFIG_GOAL_Y)

# Directories
INCDIR = include
SRCDIR = src
OBJDIR = obj

# Files
SRCFILES = $(SRCDIR)/astar.cpp $(SRCDIR)/main.cpp
OBJFILES = $(OBJDIR)/astar.o $(OBJDIR)/main.o
TARGET = astar.so

# Ensure the object directory exists and compile target
$(TARGET): $(OBJFILES)
	$(CXX) $(OBJFILES) -o $(TARGET)

# Create object directory if not exists and compile source files into objects
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# Create object directory
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Clean up
clean:
	rm -rf $(OBJDIR) $(TARGET)