/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:52:41 by isallali          #+#    #+#             */
/*   Updated: 2025/02/09 20:16:41 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../Iron_wire.h"

void    translate(t_map *map, int x, int y)
{
    int j;
    int i;

    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            map->points[i][j].x += x;
            map->points[i][j].y += y;
            j++;
        }
        i++;
    }
}
float   calcul_scale(t_boundries *boundries)
{
    float scale_x;
    float scale_y;
    float max_projection;
    
    max_projection = boundries->width + boundries->height;
    scale_x = W_WIDTH / max_projection;
    scale_y = W_HEIGHT / max_projection;
    if (scale_x < scale_y)
        return (scale_x);
    else
        return (scale_y);
}

void    scale(t_map *map, float factor)
{
    int j;
    int i;

    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            map->points[i][j].x *= factor;
            map->points[i][j].y *= factor;
            map->points[i][j].z *= factor;
            j++;
        }
        i++;
    }
}

void    rotate_z(t_map *map, float angle)
{
    int j;
    int i;
    float x;
    float y;

    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            x = map->points[i][j].x;
            y = map->points[i][j].y;
            map->points[i][j].x = x * cos(angle) - y * sin(angle);
            map->points[i][j].y = x * sin(angle) + y * cos(angle);
            j++;
        }
        i++;
    }
}

void    rotate_x(t_map *map, float angle)
{
    int j;
    int i;
    float y;
    float z;

    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            y = map->points[i][j].y;
            z = map->points[i][j].z;
            map->points[i][j].y = y * cos(angle) - z * sin(angle);
            map->points[i][j].z = y * sin(angle) + z * cos(angle);
            j++;
        }
        i++;
    }
}

void    rotate_y(t_map *map, float angle)
{
    int j;
    int i;
    float x;
    float z;

    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            x = map->points[i][j].x;
            z = map->points[i][j].z;
            map->points[i][j].x = x * cos(angle) + z * sin(angle);
            map->points[i][j].z = -x * sin(angle) + z * cos(angle);
            j++;
        }
        i++;
    }
}

void    iso_projection(t_map *map)
{
    rotate_z(map, 0.785398);
    rotate_x(map, 0.955316618);
}
