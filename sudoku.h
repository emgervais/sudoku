#ifndef SUDOKU_H
# define SUDOKU_H

# include "../../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

# define HEIGHT 900
# define WIDTH 900
# define ERROR -1

typedef struct s_case
{
	mlx_image_t *img;
    int x;
    int y;
    int pos;
    int number;
	struct s_case	*next;
    struct s_case   *right;
    struct s_case   *down;
}					t_case;

typedef struct s_img
{
    mlx_image_t *back;
    mlx_texture_t *backt;
    mlx_image_t *select;
    mlx_texture_t *sel;
    mlx_texture_t *one;
    mlx_texture_t *two;
    mlx_texture_t *three;
    mlx_texture_t *four;
    mlx_texture_t *five;
    mlx_texture_t *six;
    mlx_texture_t *seven;
    mlx_texture_t *eight;
    mlx_texture_t *nine;
} t_img;

typedef struct s_sud
{
    t_img *img;
    mlx_t *mlx;
    t_case *list;
    int x;
    int y;
    int selected;
    int *locked;
}               t_sud;

void set_map(t_sud *sud, bool reset);

#endif