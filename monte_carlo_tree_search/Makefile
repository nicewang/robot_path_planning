CONFIG_FILE = config.properties

CONFIG_GRID_SIZE = $(shell grep ^CONFIG_GRID_SIZE $(CONFIG_FILE) | cut -d '=' -f2)
CONFIG_GOAL_X = $(shell grep ^CONFIG_GOAL_X $(CONFIG_FILE) | cut -d '=' -f2)
CONFIG_GOAL_Y = $(shell grep ^CONFIG_GOAL_Y $(CONFIG_FILE) | cut -d '=' -f2)
CONFIG_MAX_SIM_STEPS = $(shell grep ^CONFIG_MAX_SIM_STEPS $(CONFIG_FILE) | cut -d '=' -f2)
CONFIG_C = $(shell grep ^CONFIG_C $(CONFIG_FILE) | cut -d '=' -f2)

# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall -DCONFIG_GRID_SIZE=$(CONFIG_GRID_SIZE) -DCONFIG_GOAL_X=$(CONFIG_GOAL_X) -DCONFIG_GOAL_Y=$(CONFIG_GOAL_Y) -DCONFIG_MAX_SIM_STEPS=$(CONFIG_MAX_SIM_STEPS) -DCONFIG_C=$(CONFIG_C)

# Directories
INCDIR = include
SRCDIR = src
OBJDIR = obj

# Files
SRCFILES = $(SRCDIR)/state.cpp $(SRCDIR)/mcts.cpp $(SRCDIR)/main.cpp
OBJFILES = $(OBJDIR)/state.o $(OBJDIR)/mcts.o $(OBJDIR)/main.o
TARGET = mcts.so

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
