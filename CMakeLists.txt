cmake_minimum_required(VERSION 3.16)
project(Fractol C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")
set(LIBMLX ${CMAKE_SOURCE_DIR}/minilibx_macos/libmlx.a)

find_library(OPENGL OpenGL)
find_library(APPKIT AppKit)

include_directories(.)
include_directories(libft)
include_directories(minilibx_macos)
include_directories(includes)
include_directories(sources)
FILE(GLOB SOURCES *.c sources/*.c sources/*/*.c)
FILE(GLOB INCLUDES includes/*.h)

add_executable(Fractol ${SOURCES} ${INCLUDES})

add_subdirectory(libft)
target_link_libraries(Fractol lib)

add_library(mlx STATIC IMPORTED)
set_property(TARGET mlx PROPERTY
        IMPORTED_LOCATION ${LIBMLX})
target_link_libraries(Fractol mlx ${OPENGL} ${APPKIT})