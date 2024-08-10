cmake_minimum_required(VERSION 3.15)
project(underground CXX)

# Variables
set(CMAKE_CXX_STANDARD 11) # I want learn modern C++
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)
set(SOURCE_FILES
	./src/main.cpp
	./src/player.cpp
)

# Libraries
## Raylib
find_library(raylib 5.0)
if (NOT raylib)
	include(FetchContent)
	FetchContent_Declare(
		raylib
		GIT_REPOSITORY https://github.com/raysan5/raylib.git
		GIT_TAG master
	)
	FetchContent_MakeAvailable(raylib)
endif(NOT raylib)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} raylib)
