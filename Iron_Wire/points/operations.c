/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:52:41 by isallali          #+#    #+#             */
/*   Updated: 2025/02/12 12:08:19 by isallali         ###   ########.fr       */
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

void    scale(t_map *map)
{
    int j;
    int i;
    float scale_x;
    float scale_y;
    float scale_base;
    
    scale_x = W_WIDTH / (map->width + map->height);
    scale_y = W_HEIGHT / (map->width + map->height);
    if (scale_x < scale_y)
        scale_base = (scale_x);
    else
        scale_base =  (scale_y);
    i = -1;
    while (++i < map->height)
    {
        if (!map->points[i])
            continue;
        j = -1;
        while (++j < map->width)
        {
            map->points[i][j].x *= scale_base;
            map->points[i][j].y *= scale_base;
            map->points[i][j].z *= scale_base;
        }
    }
}

float height_factor(t_map *map)
{
    float factor;

    factor  = map->boundries->max_z - map->boundries->min_z;
printf("factor: %f\n", factor);
    if (factor == 0)
        return (1.0);
    else if (factor > map->width)
        return (map->width / factor);
    else if (factor < map->width / 4)
        return (2.0);
    return (1.0);
}
void apply_height_factor(t_map *map)
{
    float factor;
    int i ;
    int j;

    factor = height_factor(map);
    i = -1;
    while (++i < map->height)
    {
        if (!map->points[i])
            continue;
        j = -1;
        while (++j < map->width)
            map->points[i][j].z *= factor;
    }
printf("factor: %f\n", factor);
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
