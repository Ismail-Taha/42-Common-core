/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:44:31 by isallali          #+#    #+#             */
/*   Updated: 2025/02/12 20:45:23 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iron_wire.h"

static void	init_map_arrays(t_map *map)
{
	map->points = (t_point **)malloc(sizeof(t_point *) * map->height);
	if (!map->points)
		pr_error(map, "Memory allocation failed");
	map->row_widths = (int *)malloc(sizeof(int) * map->height);
	if (!map->row_widths)
		pr_error(map, "Memory allocation failed");
}

static void	process_dimension_line(t_map *map, char *line, int *i)
{
	map->row_widths[*i] = count_word(line, 32);
	map->points[*i] = (t_point *)malloc(sizeof(t_point) * map->row_widths[*i]);
	if (!map->points[*i])
		pr_error(map, "Memory allocation failed");
	if (map->row_widths[*i] > map->width)
		map->width = map->row_widths[*i];
}

static void	calc_map_height(t_map *map, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n' || line[0] == '\0')
		{
			free(line);
			continue ;
		}
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
}

static void	map_dimension_helper(t_map *map, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (i <= map->height && line)
	{
		if (line[0] == '\n' || line[0] == '\0')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		process_dimension_line(map, line, &i);
		free(line);
		line = get_next_line(fd);
		i++;
	}
}

void	get_map_dimensions(t_map *map)
{
	int	fd;

	map->height = 0;
	map->width = 0;
	fd = open(map->file, O_RDONLY);
	if (fd < 0)
		pr_error(map, "Cannot open file");
	calc_map_height(map, fd);
	gnl_cleanup(fd);
	if (map->height == 0)
		pr_error(map, "Empty or invalid map");
	init_map_arrays(map);
	fd = open(map->file, O_RDONLY);
	if (fd < 0)
		pr_error(map, "Cannot open file");
	map_dimension_helper(map, fd);
	gnl_cleanup(fd);
	if (map->width == 0)
		pr_error(map, "Empty or invalid map");
}
