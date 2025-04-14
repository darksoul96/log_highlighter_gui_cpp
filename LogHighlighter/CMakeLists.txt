cmake_minimum_required(VERSION 3.14)
project(LogHighlighter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Release)

set(CMAKE_CXX_FLAGS_RELEASE "-O3")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# Add all .cpp and .h in your LogHighlighter directory
file(GLOB_RECURSE SOURCES
    LogHighlighter/*.cpp
    LogHighlighter/*.h
)

add_executable(LogHighlighter ${SOURCES})

# Include ImGui
target_include_directories(LogHighlighter PRIVATE
    LogHighlighter/imgui
    LogHighlighter/imgui/backends
)

# Link ImGui sources
file(GLOB IMGUI_SOURCES
    LogHighlighter/imgui/*.cpp
    LogHighlighter/imgui/backends/imgui_impl_glfw.cpp
    LogHighlighter/imgui/backends/imgui_impl_opengl3.cpp
)

target_sources(LogHighlighter PRIVATE ${IMGUI_SOURCES})

# Attempt to find system GLFW, otherwise use local
find_package(PkgConfig QUIET)
if(PkgConfig_FOUND)
    pkg_search_module(GLFW QUIET glfw3)
endif()

if (GLFW_FOUND)
    message(STATUS "Using system-installed GLFW")
    target_include_directories(LogHighlighter PRIVATE ${GLFW_INCLUDE_DIRS})
    target_link_libraries(LogHighlighter PRIVATE ${GLFW_LIBRARIES})
else()
    message(STATUS "System GLFW not found, using local version")
    set(GLFW_BUILD_DOCS OFF CACHE BOOL "")
    set(GLFW_BUILD_TESTS OFF CACHE BOOL "")
    set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
    add_subdirectory(extern/glfw)
    target_include_directories(LogHighlighter PRIVATE extern/glfw/include)
    target_link_libraries(LogHighlighter PRIVATE glfw)
endif()

# macOS-specific frameworks (needed by GLFW)
if(APPLE)
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -march=native")
    find_library(COCOA_LIB Cocoa)
    find_library(OPENGL_LIB OpenGL)
    find_library(IOKIT_LIB IOKit)
    find_library(QUARTZ_LIB QuartzCore)
    target_link_libraries(LogHighlighter PRIVATE ${COCOA_LIB} ${OPENGL_LIB} ${IOKIT_LIB} ${QUARTZ_LIB})
endif()
message(STATUS "C++ flags: ${CMAKE_CXX_FLAGS_RELEASE}")


# Optional: enable ImGui's OpenGL loader
add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLAD)


if(UNIX AND NOT APPLE)
    find_package(OpenGL REQUIRED)
    target_link_libraries(LogHighlighter PRIVATE OpenGL::GL)
endif()


