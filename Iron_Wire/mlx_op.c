/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:17:04 by isallali          #+#    #+#             */
/*   Updated: 2025/02/12 20:40:42 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iron_wire.h"

void	f_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
		return ;
	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mlx_draw_line(t_mlx *mlx, t_point *p1, t_point *p2)
{
	int (dx), (dy), (steps), (i);
	float (x_inc), (y_inc), (x), (y);
	if (!p1 || !p2)
		return ;
	dx = p2->x - p1->x;
	dy = p2->y - p1->y;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	x_inc = dx / (float)steps;
	y_inc = dy / (float)steps;
	x = p1->x;
	y = p1->y;
	i = 0;
	while (i <= steps)
	{
		f_mlx_pixel_put(mlx, x, y, p1->color);
		x += x_inc;
		y += y_inc;
		i++;
	}
}

void	mlx_draw_map(t_mlx *mlx, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->row_widths[i] - 1)
			mlx_draw_line(mlx, &map->points[i][j], &map->points[i][j + 1]);
	}
	j = -1;
	while (++j < map->width)
	{
		i = -1;
		while (++i < map->height - 1)
		{
			if (j < map->row_widths[i] && j < map->row_widths[i + 1])
				mlx_draw_line(mlx, &map->points[i][j], &map->points[i + 1][j]);
		}
	}
}

void	mlx_draw(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, W_WIDTH, W_HEIGHT, "Iron_wire");
	mlx->img = mlx_new_image(mlx->mlx, W_WIDTH, W_HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	get_boundires(mlx->map);
	apply_height_factor(mlx->map);
	scale(mlx->map);
	iso_projection(mlx->map);
	put_map_center(mlx->map);
	mlx_draw_map(mlx, mlx->map);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_hooks(mlx);
	mlx_loop(mlx->mlx);
}
