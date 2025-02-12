/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:06:08 by isallali          #+#    #+#             */
/*   Updated: 2025/02/12 14:43:52 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iron_wire.h"

void ft_free(void *ptr)
{
    if (ptr)
        free(ptr);
}

void free_map(t_map *map)
{
    int i;

    if (!map)
        return;
        
    if (map->points)
    {
        i = 0;
        while (i < map->height)
        {
            if (map->points[i])
                free(map->points[i]);
            i++;
        }
        free(map->points);
    }
    
    if (map->row_widths)
        free(map->row_widths);
    
    if (map->boundries)
        free(map->boundries);
    
    if (map) 
        free(map);
}

void cleanup_all(t_mlx *mlx)
{
    if (!mlx)
        return;

    if (mlx->img)
        mlx_destroy_image(mlx->mlx, mlx->img);
    
    if (mlx->win)
        mlx_destroy_window(mlx->mlx, mlx->win);
        
    if (mlx->map)
        free_map(mlx->map);
    
    if (mlx->mlx)
    {
        mlx_destroy_display(mlx->mlx);
        free(mlx->mlx);
    }
}

int close_window(t_mlx *mlx)
{
    cleanup_all(mlx);
    exit(0);
}

int	close_window_x(t_mlx *mlx)
{
	cleanup_all(mlx);
	exit(0);
	return (0);
}

int	close_window_esc(int keycode, t_mlx *mlx)
{
    if (keycode == KEY_ESC)
    {
        cleanup_all(mlx);
        exit(0);
    }
    return (0);
}
void	mlx_hooks(t_mlx *mlx)
{
    mlx_hook(mlx->win, 2, 1L << 0, close_window_esc, mlx);
    mlx_hook(mlx->win, 17, 0, close_window_x, mlx);
}