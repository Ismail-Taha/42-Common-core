/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 17:52:41 by isallali          #+#    #+#             */
/*   Updated: 2025/02/12 20:43:02 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Iron_wire.h"

void	translate(t_map *map, int x, int y)
{
	int	j;
	int	i;

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

void	scale(t_map *map)
{
	int		j;
	int		i;
	float	scale_x;
	float	scale_y;
	float	scale_base;

	scale_x = W_WIDTH / (map->width + map->height);
	scale_y = W_HEIGHT / (map->width + map->height);
	if (scale_x < scale_y)
		scale_base = (scale_x);
	else
		scale_base = (scale_y);
	i = -1;
	while (++i < map->height)
	{
		if (!map->points[i])
			continue ;
		j = -1;
		while (++j < map->width)
		{
			map->points[i][j].x *= scale_base;
			map->points[i][j].y *= scale_base;
			map->points[i][j].z *= scale_base;
		}
	}
}

float	height_factor(t_map *map)
{
	float	factor;

	factor = map->boundries->max_z - map->boundries->min_z;
	if (factor == 0)
		return (1.0);
	else if (factor > map->width)
		return (map->width / factor);
	else if (factor < map->width / 4)
		return (2.0);
	return (1.0);
}

void	apply_height_factor(t_map *map)
{
	float	factor;
	int		i;
	int		j;

	factor = height_factor(map);
	i = -1;
	while (++i < map->height)
	{
		if (!map->points[i])
			continue ;
		j = -1;
		while (++j < map->width)
			map->points[i][j].z *= factor;
	}
}
