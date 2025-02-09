/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:44:31 by isallali          #+#    #+#             */
/*   Updated: 2025/02/09 18:19:49 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iron_wire.h"

t_map   *init_map(char *file)
{
    t_map   *map;

    map = (t_map *)ft_calloc(1, sizeof(t_map));
    if (!map)
        pr_error(NULL, "Memory allocation failed");
    map->zoom = 1.0;
    map->rotation_x = 0.0;
    map->rotation_y = 0.0;
    map->rotation_z = 0.0;
    map->z_min = INT_MAX;
    map->z_max = INT_MIN;
    map->projection_type = 0;
    map->file = file;
    return (map);
}

static void get_map_dimensions(t_map *map)
{
    int     fd;
    char    *line;

    fd = open(map->file, O_RDONLY);
    if (fd < 0)
        pr_error(map, "Cannot open file");
    map->height = 0;
    map->width = 0;
    while ((line = get_next_line(fd)))
    {
        if (map->height == 0)
            map->width = count_word(line, 32);
        else if (count_word(line, 32) != map->width)
            pr_error(map, "Invalid map: lines have different lengths");
        map->height++;
        free(line);
    }
    close(fd);
    if (map->height == 0 || map->width == 0)
        pr_error(map, "Empty or invalid map");
}

static void allocate_points(t_map *map)
{
    int i;

    map->points = (t_point **)malloc(sizeof(t_point *) * map->height);
    if (!map->points)
        pr_error(map, "Memory allocation failed");

    i = -1;
    while (++i < map->height )
    {
        map->points[i] = (t_point *)malloc(sizeof(t_point) * map->width);
        if (!map->points[i])
            pr_error(map, "Memory allocation failed");
    }
}

void    parse_map(t_map *map)
{
    int     fd;
    char    *line;
    char    **split;
    int     i;
    int     j;

    get_map_dimensions(map);
    allocate_points(map);

    fd = open(map->file, O_RDONLY);
    if (fd < 0)
        pr_error(map, "Cannot open file");

    i = 0;
    while ((line = get_next_line(fd)) && i < map->height)
    {
        split = ft_split(line, 32);
        if (!split)
            pr_error(map, "Split failed");
        j = -1;
        while (split[++j] && j < map->width)
        {
            if (!parse_point(split[j], &map->points[i][j], map))
                pr_error(map, "Invalid point format");
            map->points[i][j].x = j;
            map->points[i][j].y = i;
            map->points[i][j].d_x = j;
            map->points[i][j].d_y = i;
        }
        free_split(split);
        free(line);
        i++;
    }
    close(fd);
}
