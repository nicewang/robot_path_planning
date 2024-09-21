cmake_minimum_required(VERSION 3.10)
project(mcts_project)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall")

# Load configs from config.properties
file(READ ${CMAKE_CURRENT_LIST_DIR}/config.properties CONFIG_CONTENT)

string(REGEX MATCH "CONFIG_WIDTH=[0-9]+" WIDTH_MATCH ${CONFIG_CONTENT})
string(REGEX MATCH "CONFIG_HEIGHT=[0-9]+" HEIGHT_MATCH ${CONFIG_CONTENT})
string(REGEX MATCH "CONFIG_START_X=[0-9]+" START_X_MATCH ${CONFIG_CONTENT})
string(REGEX MATCH "CONFIG_START_Y=[0-9]+" START_Y_MATCH ${CONFIG_CONTENT})
string(REGEX MATCH "CONFIG_GOAL_X=[0-9]+" GOAL_X_MATCH ${CONFIG_CONTENT})
string(REGEX MATCH "CONFIG_GOAL_Y=[0-9]+" GOAL_Y_MATCH ${CONFIG_CONTENT})

# config values
string(REPLACE "CONFIG_WIDTH=" "" CONFIG_WIDTH ${WIDTH_MATCH})
string(REPLACE "CONFIG_HEIGHT=" "" CONFIG_HEIGHT ${HEIGHT_MATCH})
string(REPLACE "CONFIG_START_X=" "" CONFIG_START_X ${START_X_MATCH})
string(REPLACE "CONFIG_START_Y=" "" CONFIG_START_Y ${START_Y_MATCH})
string(REPLACE "CONFIG_GOAL_X=" "" CONFIG_GOAL_X ${GOAL_X_MATCH})
string(REPLACE "CONFIG_GOAL_Y=" "" CONFIG_GOAL_Y ${GOAL_Y_MATCH})

# compile options
add_compile_definitions(
    CONFIG_WIDTH=${CONFIG_WIDTH}
    CONFIG_HEIGHT=${CONFIG_HEIGHT}
    CONFIG_START_X=${CONFIG_START_X}
    CONFIG_START_Y=${CONFIG_START_Y}
    CONFIG_GOAL_X=${CONFIG_GOAL_X}
    CONFIG_GOAL_Y=${CONFIG_GOAL_Y}
)

# Set dir of include, src and obj
set(INCDIR ${CMAKE_SOURCE_DIR}/include)
set(SRCDIR ${CMAKE_SOURCE_DIR}/src)
set(OBJDIR ${CMAKE_BINARY_DIR}/obj)

# Set obj files and src files
set(SRCFILES ${CMAKE_CURRENT_LIST_DIR}/src/astar.cpp ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp)
set(OBJFILES ${OBJDIR}/astar.o ${OBJDIR}/main.o)

# Include Dir
include_directories(${INCDIR})

# Add an object library to control the generation of object files
add_library(astar_objects OBJECT ${SRCFILES})

# Set the output directory to the obj folder
set_target_properties(astar_objects PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${OBJDIR}
    LIBRARY_OUTPUT_DIRECTORY ${OBJDIR}
    RUNTIME_OUTPUT_DIRECTORY ${OBJDIR}
)

# executable file
add_executable(astar.so $<TARGET_OBJECTS:astar_objects>)

# clean
add_custom_target(clean_astar
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${OBJDIR}
    COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_BINARY_DIR}/astar.so
)
