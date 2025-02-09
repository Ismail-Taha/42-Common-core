/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iron_wire.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:36:59 by isallali          #+#    #+#             */
/*   Updated: 2025/02/09 21:42:37 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef IRON_WIRE_H
# define IRON_WIRE_H


# include <mlx.h>
# include <math.h>
#include <stdint.h>
#include <limits.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "Libft/libft.h"

#define W_WIDTH 1000
#define W_HEIGHT 1000

typedef struct s_boundries
{
    int     min_x;
    int     max_x;
    int     min_y;
    int     max_y;
    int     width;
    int     height;
} t_boundries;



typedef struct s_point {
    int     d_x;
    int     d_y;
    int     d_z;
    int     x;
    int     y;
    int     z;
    int     color;
} t_point;

typedef struct s_mlx {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
} t_mlx;

typedef struct s_map {
    int     width;
    int     height;
    float   zoom;
    float   rotation_x;
    float   rotation_y;
    float   rotation_z;
    int     z_min;
    int     z_max;
    int     offset_x;
    int     offset_y;
    int     projection_type;
    t_point **points;
    char    *file;
} t_map;

t_map   *init_map(char *filename);
void    parse_map(t_map *map);
int     parse_point(char *str, t_point *point, t_map *map);
void    free_map(t_map *map);
void    pr_error(t_map *map, const char *message);
void    free_split(char **split);
int	    ft_atoi_base(char *str, int base);
void    validat_file(char *file);

//------------mlx_op.c----------------
void    mlx_draw_line(t_mlx *mlx, t_point *p1, t_point *p2);
void    mlx_draw_map(t_mlx *mlx, t_map *map);
void    mlx_draw(t_map *map);
void    f_mlx_clear_window(t_mlx *mlx);
void    f_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

//----------------operations.c----------------
void    translate(t_map *map, int x, int y);
void    scale(t_map *map, float factor);
void    rotate_z(t_map *map, float angle);
void    rotate_y(t_map *map, float angle);
void    rotate_x(t_map *map, float angle);
void    iso_projection(t_map *map);
void put_map_center(t_map *map);
t_boundries *get_boundires(t_map *map);
float   calcul_scale(t_boundries *boundries);

#endif /*IRON_WIRE_H*/