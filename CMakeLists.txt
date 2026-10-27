cmake_minimum_required(VERSION 3.20)
project(csci1260_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()


file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

add_executable(app ${SOURCES})
target_include_directories(app PRIVATE include)


if(MSVC)
	target_compile_options(app PRIVATE /W4 /utf-8)
else()
  target_compile_options(app PRIVATE -Wall -Wextra -Wpedantic)
endif()


add_custom_target(run
  COMMAND $<TARGET_FILE:app>
  DEPENDS app
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
  USES_TERMINAL
)
