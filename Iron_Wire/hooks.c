/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:06:08 by isallali          #+#    #+#             */
/*   Updated: 2025/02/12 21:06:33 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iron_wire.h"

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
