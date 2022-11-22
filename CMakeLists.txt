cmake_minimum_required(VERSION 3.22)
project(42_Cub3D C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(libft)
include_directories(libft/ft_printf)
include_directories(libft/mmalloc)
INCLUDE_DIRECTORIES(/System/Library/Frameworks)
SET(LIBS mlx ft)
if (APPLE)
    FIND_LIBRARY(OPENGL_LIBRARY OpenGL)
    FIND_LIBRARY(APPKIT_LIBRARY AppKit)
    SET(LIBS ${LIBS} ${OPENGL_LIBRARY} ${APPKIT_LIBRARY})
else ()
    SET(LIBS ${LIBS} Xext X11 m)
endif ()

include_directories(libft mlx)
link_directories(libft mlx)

add_executable(42_Cub3D
        srcs/parsing/0_parser_main.c
        srcs/parsing/A_error_manager.c
        srcs/parsing/A_height_calculator.c
        srcs/parsing/A_stock_arguments.c
        srcs/parsing/A_tools_fct.c
        srcs/parsing/C_checker_color.c
        srcs/parsing/C_parser_color.c
        srcs/parsing/M_parser_map.c
        srcs/parsing/M_stock_map.c
        srcs/parsing/S_checker_sprite.c
        srcs/parsing/S_parser_sprite.c
        srcs/draw_column.c
        srcs/draw_minimap.c
        srcs/error.c
        srcs/exit.c
        srcs/keyboard.c
        srcs/main.c
        srcs/move.c
        srcs/ray.c
        srcs/ray2.c
        srcs/render_column.c
        srcs/render_frame.c
        srcs/utils.c
        cub3d.h)

TARGET_LINK_LIBRARIES(42_Cub3D ${LIBS})