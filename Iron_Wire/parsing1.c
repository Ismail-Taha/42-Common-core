/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:29:30 by isallali          #+#    #+#             */
/*   Updated: 2025/02/12 20:46:43 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iron_wire.h"

static void	process_map_line(t_mlx *mlx, char **split, int i)
{
	int	j;

	j = -1;
	while (split[++j] && j < mlx->map->width)
	{
		if (!parse_point(split[j], &mlx->map->points[i][j]))
		{
			free_split(split);
			pr_error(mlx->map, "Invalid point format");
		}
		mlx->map->points[i][j].x = j;
		mlx->map->points[i][j].y = i;
	}
}

static int	handle_empty_line(char *line)
{
	if (line[0] == '\n' || line[0] == '\0')
	{
		free(line);
		return (1);
	}
	return (0);
}

static char	**handle_split(t_mlx *mlx, char *line)
{
	char	**split;

	split = ft_split(line, 32);
	if (!split)
	{
		free(line);
		pr_error(mlx->map, "Split failed");
	}
	if (!*split)
	{
		free(line);
		free_split(split);
		return (NULL);
	}
	return (split);
}

void	parse_map(t_mlx *mlx)
{
	int		fd;
	char	*line;
	char	**split;
	int		i;

	get_map_dimensions(mlx->map);
	fd = open(mlx->map->file, O_RDONLY);
	if (fd < 0)
		pr_error(mlx->map, "Cannot open file");
	i = 0;
	line = get_next_line(fd);
	while (i < mlx->map->height && line)
	{
		if (handle_empty_line(line))
			continue ;
		split = handle_split(mlx, line);
		if (!split)
			continue ;
		process_map_line(mlx, split, i);
		free_split(split);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	gnl_cleanup(fd);
}

t_map	*init_map(char *file)
{
	t_map	*map;

	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		pr_error(NULL, "Memory allocation failed");
	map->file = file;
	return (map);
}
