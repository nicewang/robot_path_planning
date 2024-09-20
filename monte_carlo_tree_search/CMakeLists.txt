cmake_minimum_required(VERSION 3.10)
project(mcts_project)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall")

# Load configs from config.properties
file(READ ${CMAKE_CURRENT_LIST_DIR}/config.properties CONFIG_CONTENT)

string(REGEX MATCH "CONFIG_GRID_SIZE=[0-9]+" GRID_SIZE_MATCH ${CONFIG_CONTENT})
string(REGEX MATCH "CONFIG_GOAL_X=[0-9]+" GOAL_X_MATCH ${CONFIG_CONTENT})
string(REGEX MATCH "CONFIG_GOAL_Y=[0-9]+" GOAL_Y_MATCH ${CONFIG_CONTENT})
string(REGEX MATCH "CONFIG_MAX_SIM_STEPS=[0-9]+" MAX_SIM_STEPS_MATCH ${CONFIG_CONTENT})
string(REGEX MATCH "CONFIG_C=[0-9.]+" CONFIG_C_MATCH ${CONFIG_CONTENT})

# config values
string(REPLACE "CONFIG_GRID_SIZE=" "" CONFIG_GRID_SIZE ${GRID_SIZE_MATCH})
string(REPLACE "CONFIG_GOAL_X=" "" CONFIG_GOAL_X ${GOAL_X_MATCH})
string(REPLACE "CONFIG_GOAL_Y=" "" CONFIG_GOAL_Y ${GOAL_Y_MATCH})
string(REPLACE "CONFIG_MAX_SIM_STEPS=" "" CONFIG_MAX_SIM_STEPS ${MAX_SIM_STEPS_MATCH})
string(REPLACE "CONFIG_C=" "" CONFIG_C ${CONFIG_C_MATCH})

# compile options
add_compile_definitions(
    CONFIG_GRID_SIZE=${CONFIG_GRID_SIZE}
    CONFIG_GOAL_X=${CONFIG_GOAL_X}
    CONFIG_GOAL_Y=${CONFIG_GOAL_Y}
    CONFIG_MAX_SIM_STEPS=${CONFIG_MAX_SIM_STEPS}
    CONFIG_C=${CONFIG_C}
)

# source
set(SRC
    src/main.cpp
    src/mcts.cpp
    src/state.cpp
)

# header
include_directories(include)

# executable file
add_executable(mcts.so ${SRC})

# clean
add_custom_target(clean_mcts
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/mcts.so
)
