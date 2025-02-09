/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 18:17:04 by isallali          #+#    #+#             */
/*   Updated: 2025/02/09 21:50:15 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iron_wire.h"

void    f_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
    char    *dst;
    if (x < 0 || x >= 1000 || y < 0 || y >= 1000)
        return ;

    dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void    f_mlx_clear_window(t_mlx *mlx)
{
    int i;
    int j;

    i = 0;
    while (i < 1000)
    {
        j = 0;
        while (j < 1000)
        {
            f_mlx_pixel_put(mlx, i, j, 0x000000);
            j++;
        }
        i++;
    }
}

int     interpol_color(int start, int end, float percentage)
{
    int r;
    int g;
    int b;

    r = (start & 0xFF0000) * (1 - percentage) + (end & 0xFF0000) * percentage;
    g = (start & 0x00FF00) * (1 - percentage) + (end & 0x00FF00) * percentage;
    b = (start & 0x0000FF) * (1 - percentage) + (end & 0x0000FF) * percentage;
    return (r + g + b);
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

    dx = p2->x - p1->x;
    dy = p2->y - p1->y;
    steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    x_inc = dx / (float)steps;
    y_inc = dy / (float)steps;
    x = p1->x;
    y = p1->y;
    i = 0;
    while (i <= steps)
    {
        percentage = (float)i / steps;
        color = interpol_color(p1->color, p2->color, percentage);
        f_mlx_pixel_put(mlx, x, y, color);
        x += x_inc;
        y += y_inc;
        i++;
    }
}

void    mlx_draw_map(t_mlx *mlx, t_map *map)
{
    int i;
    int j;

    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            if (j + 1 < map->width)
                mlx_draw_line(mlx, &map->points[i][j], &map->points[i][j + 1]);
            if (i + 1 < map->height)
                mlx_draw_line(mlx, &map->points[i][j], &map->points[i + 1][j]);
            j++;
        }
        i++;
    }
}

void    mlx_draw(t_map *map)
{
    t_mlx   mlx;
    t_boundries *boundries;
    
    mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, 1000, 1000, "Iron_wire");
    mlx.img = mlx_new_image(mlx.mlx, 1000, 1000);
    mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length, &mlx.endian);
    f_mlx_clear_window(&mlx);
    boundries = get_boundires(map);
    scale(map, calcul_scale(boundries));
    // translate(map, 500, 500);
    iso_projection(map);
    put_map_center(map);
    mlx_draw_map(&mlx, map);
    mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
    mlx_loop(mlx.mlx);
}



t_boundries *get_boundires(t_map *map)
{
    t_boundries *boundries;
    int i;
    int j;

    boundries = (t_boundries *)ft_calloc(1, sizeof(t_boundries));
    if (!boundries)
        pr_error(map, "Memory allocation failed");
    boundries->min_x = INT_MAX;
    boundries->max_x = INT_MIN;
    boundries->min_y = INT_MAX;
    boundries->max_y = INT_MIN;
    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            if (map->points[i][j].x < boundries->min_x)
                boundries->min_x = map->points[i][j].x;
            if (map->points[i][j].x > boundries->max_x)
                boundries->max_x = map->points[i][j].x;
            if (map->points[i][j].y < boundries->min_y)
                boundries->min_y = map->points[i][j].y;
            if (map->points[i][j].y > boundries->max_y)
                boundries->max_y = map->points[i][j].y;
            j++;
        }
        i++;
    }
    boundries->width = boundries->max_x - boundries->min_x;
    boundries->height = boundries->max_y - boundries->min_y;
    return (boundries);
}

void put_map_center(t_map *map)
{
    t_boundries *boundries;
    int i;
    int j;

    boundries = get_boundires(map);
    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            printf("x = %d, y = %d\n", map->points[i][j].x, map->points[i][j].y);
            map->points[i][j].x += (1000  - (boundries->width)) / 2 - boundries->min_x;
            map->points[i][j].y += (1000 - (boundries->height)) / 2 - boundries->min_y;
            printf("x = %d, y = %d\n", map->points[i][j].x, map->points[i][j].y);
            j++;
        }
        i++;
    }
    free(boundries);
}

