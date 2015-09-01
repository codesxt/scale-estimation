cmake_minimum_required(VERSION 2.8)
project( SCALE-ESTIMATION )
SET (CMAKE_CXX_COMPILER             "/usr/bin/g++")
SET (CMAKE_CXX_FLAGS                "-Wall -std=c++11")
SET (CMAKE_CXX_FLAGS_DEBUG          "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE        "-O4 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)
include_directories(src)
include_directories(include)
include_directories(${Boost_INCLUDE_DIR})
find_package(
	Boost 1.40
	COMPONENTS
		program_options
	REQUIRED)
add_executable(
  scale-estimation
  src/main.cpp
	src/random_walker.cpp
)
target_link_libraries(
	scale-estimation
	${Boost_LIBRARIES})
