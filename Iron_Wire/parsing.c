/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:44:31 by isallali          #+#    #+#             */
/*   Updated: 2025/02/11 17:08:28 by isallali         ###   ########.fr       */
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
    map->projection_type = 0;
    map->file = file;
    return (map);
}

static void get_map_dimensions(t_map *map)
{
    int     fd;
    char    *line;
    int     i;

    map->height = 0;
    map->width = 0;
    fd = open(map->file, O_RDONLY);
    if (fd < 0)
        pr_error(map, "Cannot open file");
    //calc height
    while ((line = get_next_line(fd)))
    {
        map->height++;
        free(line); // Ensure line is freed
    }
    close(fd);

    if (map->height == 0)
        pr_error(map, "Empty or invalid map");

    //alloc memory for points array
    map->points = (t_point **)malloc(sizeof(t_point *) * map->height);
    if (!map->points)
        pr_error(map, "Memory allocation failed");

    map->row_widths = (int *)malloc(sizeof(int) * map->height);
    if (!map->row_widths)
        pr_error(map, "Memory allocation failed");

    fd = open(map->file, O_RDONLY);
    if (fd < 0)
        pr_error(map, "Cannot open file");

    i = 0;
    while (i < map->height && (line = get_next_line(fd)))
    {
        map->row_widths[i] = count_word(line, 32);
        map->points[i] = (t_point *)malloc(sizeof(t_point) * map->row_widths[i]);
        if (!map->points[i])
            pr_error(map, "Memory allocation failed");
        if (map->row_widths[i] > map->width)
            map->width = map->row_widths[i];
        free(line);
        i++;
    }
    close(fd);

    if (map->width == 0)
        pr_error(map, "Empty or invalid map");
}

void    parse_map(t_map *map)
{
    int     fd;
    char    *line;
    char    **split;
    int     i;
    int     j;

    get_map_dimensions(map);
    fd = open(map->file, O_RDONLY);
    if (fd < 0)
        pr_error(map, "Cannot open file");

    i = 0;
    while (i < map->height && (line = get_next_line(fd)))
    {
        split = ft_split(line, 32);
        if (!split)
        {
            free(line);
            pr_error(map, "Split failed");
        }
        j = -1;
        while (split[++j] && j < map->width)
        {
            if (!parse_point(split[j], &map->points[i][j]))
            {
                free_split(split);
                free(line);
                pr_error(map, "Invalid point format");
            }
            map->points[i][j].x = j;
            map->points[i][j].y = i;
        }
        free_split(split);
        free(line);
        i++;
    }
    close(fd);
}
