cmake_minimum_required(VERSION 3.5)
project(Fractol C)

set(CMAKE_C_STANDARD 99)

add_executable(Fractol main.c)

add_subdirectory(libft)
target_link_libraries(FdF lib)

add_library(mlx STATIC IMPORTED)
set_property(TARGET mlx PROPERTY
        IMPORTED_LOCATION ${LIBMLX})
target_link_libraries(FdF mlx ${OPENGL} ${APPKIT})