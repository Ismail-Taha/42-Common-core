/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iron_wire.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:36:59 by isallali          #+#    #+#             */
/*   Updated: 2025/02/12 20:32:23 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRON_WIRE_H
# define IRON_WIRE_H

# include "Libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define KEY_ESC 65307
# define W_WIDTH 1600
# define W_HEIGHT 1600

typedef struct s_boundries
{
	int			min_x;
	int			max_x;
	int			min_y;
	int			max_y;
	int			min_z;
	int			max_z;
	int			width;
	int			height;
}				t_boundries;

typedef struct s_point
{
	float		x;
	float		y;
	float		z;
	int			color;
}				t_point;

typedef struct s_map
{
	int			width;
	int			height;
	int			offset_x;
	int			offset_y;
	int			*row_widths;
	char		*file;
	t_point		**points;
	t_boundries	*boundries;
}				t_map;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_map		*map;
}				t_mlx;

t_map			*init_map(char *filename);
void			parse_map(t_mlx *mlx);
int				parse_point(char *str, t_point *point);
void			free_map(t_map *map);
void			cleanup_all(t_mlx *mlx);
void			pr_error(t_map *map, const char *message);
void			free_split(char **split);
int				ft_atoi_base(char *str, int base);
void			validat_file(char *file);
void			gnl_cleanup(int fd);

//-----------------parsing.c----------------
void			get_map_dimensions(t_map *map);
void			parse_map(t_mlx *mlx);

//----------------parsing_utils.c----------------
int				parse_point(char *str, t_point *point);
void			pr_error(t_map *map, const char *message);
int				ft_atoi_base(char *str, int base);

//------------mlx_op.c----------------
void			mlx_draw_line(t_mlx *mlx, t_point *p1, t_point *p2);
void			mlx_hooks(t_mlx *mlx);
void			mlx_draw_map(t_mlx *mlx, t_map *map);
void			mlx_draw(t_mlx *mlx);
void			f_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);

//----------------operations.c----------------
void			translate(t_map *map, int x, int y);
void			scale(t_map *map);
void			rotate_z(t_map *map, float angle);
void			rotate_x(t_map *map, float angle);
void			iso_projection(t_map *map);
void			put_map_center(t_map *map);
void			get_boundires(t_map *map);
void			apply_height_factor(t_map *map);

#endif /*IRON_WIRE_H*/