cmake_minimum_required(VERSION 3.10)
project(MyGameEngine LANGUAGES CXX)

# 1) C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2) Include directories
include_directories(${PROJECT_SOURCE_DIR}/h)

# 3) Find OpenGL
find_package(OpenGL REQUIRED)

# 4) Find external libraries via pkg-config (if installed via Homebrew / apt)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)
pkg_check_modules(GLEW REQUIRED glew)

# Manually include the libraries and directories using pkg-config
include_directories(${GLFW_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

# 5) Manually link GLFW
link_directories(${GLFW_LIBRARY_DIRS} ${GLEW_LIBRARY_DIRS})

# ASan (must go before add_executable)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options(-g -fsanitize=address -fsanitize=undefined)
    add_link_options(-fsanitize=address -fsanitize=undefined)
endif()

# 6) Define your executable and its sources
add_executable(mygame
    main.cpp
    cpp/Engine.cpp
    cpp/Window.cpp
)

# 7) Link libraries
target_link_libraries(mygame
    ${OPENGL_LIBRARIES}
    ${GLFW_LIBRARIES}
    ${GLEW_LIBRARIES}
)
