cmake_minimum_required(VERSION 3.15)
project(AlienDudes)

set(CMAKE_CXX_STANDARD 20)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif()


add_executable(AlienDudes main.cpp data_types/rgb.cpp data_types/rgb.hpp data_types/buffer.hpp data_types/window.hpp gl_helpers.hpp)

target_link_libraries(AlienDudes ${CONAN_LIBS_GLEW} ${CONAN_LIBS_GLFW})
