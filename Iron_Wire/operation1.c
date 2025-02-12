/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:26:11 by isallali          #+#    #+#             */
/*   Updated: 2025/02/12 20:26:21 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iron_wire.h"

void	rotate_z(t_map *map, float angle)
{
	int		j;
	int		i;
	float	x;
	float	y;

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

void	rotate_x(t_map *map, float angle)
{
	int		j;
	int		i;
	float	y;
	float	z;

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

void	iso_projection(t_map *map)
{
	rotate_z(map, 0.785398);
	rotate_x(map, 0.955316618);
}
