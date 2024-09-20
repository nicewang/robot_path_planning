CONFIG_FILE = config.properties

CONFIG_GRID_SIZE = $(shell grep ^CONFIG_GRID_SIZE $(CONFIG_FILE) | cut -d '=' -f2)
CONFIG_GOAL_X = $(shell grep ^CONFIG_GOAL_X $(CONFIG_FILE) | cut -d '=' -f2)
CONFIG_GOAL_Y = $(shell grep ^CONFIG_GOAL_Y $(CONFIG_FILE) | cut -d '=' -f2)
CONFIG_MAX_SIM_STEPS = $(shell grep ^CONFIG_MAX_SIM_STEPS $(CONFIG_FILE) | cut -d '=' -f2)
CONFIG_C = $(shell grep ^CONFIG_C $(CONFIG_FILE) | cut -d '=' -f2)

CXX = g++
CXXFLAGS = -std=c++11 -Wall -DCONFIG_GRID_SIZE=$(CONFIG_GRID_SIZE) -DCONFIG_GOAL_X=$(CONFIG_GOAL_X) -DCONFIG_GOAL_Y=$(CONFIG_GOAL_Y) -DCONFIG_MAX_SIM_STEPS=$(CONFIG_MAX_SIM_STEPS) -DCONFIG_C=$(CONFIG_C)

# exe file name
TARGET = mcts.so

# source file
SRC = src/main.cpp src/mcts.cpp src/state.cpp

# header file
HDR = include/mcts.h include/state.h

# compile rules
all: $(TARGET)

$(TARGET): $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# clear all out files
clean:
	rm -f $(TARGET)
