/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_op1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:25:10 by isallali          #+#    #+#             */
/*   Updated: 2025/02/12 20:42:28 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iron_wire.h"

void	boundries_help(t_map *map, t_boundries *bn, int i)
{
	int	j;

	j = 0;
	while (j < map->width)
	{
		if (!&map->points[i][j])
			continue ;
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

void	get_boundires(t_map *map)
{
	t_boundries	*boundries;
	int			i;

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
		boundries_help(map, boundries, i);
		i++;
	}
	boundries->width = boundries->max_x - boundries->min_x;
	boundries->height = boundries->max_y - boundries->min_y;
	map->boundries = boundries;
}

static void	calculate_map_center(t_map *map, float *center_x, float *center_y)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	*center_x = 0;
	*center_y = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->row_widths[i])
		{
			*center_x += map->points[i][j].x;
			*center_y += map->points[i][j].y;
			count++;
			j++;
		}
		i++;
	}
	if (count > 0)
	{
		*center_x /= count;
		*center_y /= count;
	}
}

void	put_map_center(t_map *map)
{
	float (center_x), (center_y), (map_center_x),
		(map_center_y), (offset_x), (offset_y);
	calculate_map_center(map, &map_center_x, &map_center_y);
	center_x = W_WIDTH / 2;
	center_y = W_HEIGHT / 2;
	offset_x = center_x - map_center_x;
	offset_y = center_y - map_center_y;
	translate(map, (int)offset_x, (int)offset_y);
}
