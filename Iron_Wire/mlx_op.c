/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:17:04 by isallali          #+#    #+#             */
/*   Updated: 2025/02/11 16:25:18 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iron_wire.h"

void    f_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
    char    *dst;
    if (x < 0 || x >= W_WIDTH || y < 0 || y >= W_HEIGHT)
        return ;

    dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

int	interpolate_color(int color1, int color2, float fraction)
{
	int	red;
	int	green;
	int	blue;

	red = ((1 - fraction) * ((color1 >> 16) & 0xFF)) + (fraction
			* ((color2 >> 16) & 0xFF));
	green = ((1 - fraction) * ((color1 >> 8) & 0xFF)) + (fraction
			* ((color2 >> 8) & 0xFF));
	blue = ((1 - fraction) * (color1 & 0xFF)) + (fraction * (color2 & 0xFF));
	return ((red << 16) | (green << 8) | blue);
}

void    mlx_draw_line(t_mlx *mlx, t_point *p1, t_point *p2)
{
    int dx;
    int dy;
    int steps;
    int i;
    float x_inc;
    float y_inc;
    float x;
    float y;
    float percentage;
    int color;

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
        percentage = (float)i / steps;
        color = interpolate_color(p1->color, p2->color, percentage);
        f_mlx_pixel_put(mlx, x, y, p1->color);
        x += x_inc;
        y += y_inc;
        i++;
    }
}

void mlx_draw_map(t_mlx *mlx, t_map *map)
{
    int i;
    int j;
    

    // 3ard
    i = -1;
    while (++i < map->height)
    {
        j = -1;
        while (++j < map->row_widths[i] - 1)
            mlx_draw_line(mlx, &map->points[i][j], &map->points[i][j + 1]);
    }
    // toul
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

void    mlx_draw(t_map *map)
{
    t_mlx   mlx;

    mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, W_WIDTH, W_HEIGHT, "Iron_wire");
    mlx.img = mlx_new_image(mlx.mlx, W_WIDTH, W_HEIGHT);
    mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length, &mlx.endian);
    get_boundires(map);
    apply_height_factor(map);
    scale(map);
    iso_projection(map);
    put_map_center(map);
    mlx_draw_map(&mlx, map);
    mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
    free(map->boundries);
    map->boundries = NULL;
    mlx_loop(mlx.mlx);
}
void boundries_help(t_map *map, t_boundries *bn)
{
    int j;
    int i = 0;
    j = 0;
        while (j < map->width)
        {
            if (!&map->points[i][j])
                continue;
            if (map->points[i][j].x < bn->min_x)
                bn->min_x = map->points[i][j].x;
            if (map->points[i][j].x > bn->max_x)
                bn->max_x = map->points[i][j].x;
            if (map->points[i][j].y < bn->min_y)
                bn->min_y = map->points[i][j].y;
            if (map->points[i][j].y > bn->max_y)
                bn->max_y = map->points[i][j].y;
            if (map->points[i][j].z < bn->min_z)
                bn->min_z = map->points[i][j].z;
            if (map->points[i][j].z > bn->max_z)
                bn->max_z = map->points[i][j].z;
            j++;
        }
    bn->width = bn->max_x - bn->min_x;
    bn->height = bn->max_y - bn->min_y;
}
void get_boundires(t_map *map)
{
    t_boundries *boundries;
    int i;

    boundries = (t_boundries *)ft_calloc(1, sizeof(t_boundries));
    if (!boundries)
        pr_error(map, "Memory allocation failed");
    boundries->min_x = INT_MAX; 
    boundries->max_x = INT_MIN;
    boundries->min_y = INT_MAX;
    boundries->max_y = INT_MIN;
    boundries->min_z = INT_MAX;
    boundries->max_z = INT_MIN;
    i = 0;
    while (i < map->height)
    {
        boundries_help(map, boundries);
        i++;
    }
    boundries->width = boundries->max_x - boundries->min_x;
    boundries->height = boundries->max_y - boundries->min_y;
    map->boundries = boundries;
}

void put_map_center(t_map *map)
{
    float center_x = W_WIDTH / 2;
    float center_y = W_HEIGHT / 2;
    float map_center_x = 0;
    float map_center_y = 0;
    int count = 0;
    int i = 0, j = 0;

    while (i < map->height)
    {
        if (j < map->row_widths[i])
        {
            map_center_x += map->points[i][j].x;
            map_center_y += map->points[i][j].y;
            count++;
            j++;
        }
        else
        {
            j = 0;
            i++;
        }
    }
    if (count > 0)
    {
        map_center_x /= count;
        map_center_y /= count;
    }
    float offset_x = center_x - map_center_x;
    float offset_y = center_y - map_center_y;
    translate(map, (int)offset_x, (int)offset_y);
}
