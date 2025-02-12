/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:37:31 by isallali          #+#    #+#             */
/*   Updated: 2025/02/12 18:57:44 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iron_wire.h"

int	main(int ac, char **av)
{
	t_map	*map;
	t_mlx	mlx;

	if (ac != 2)
		pr_error(NULL, "Usage: ./fdf <filename>");
	validat_file(av[1]);
	map = init_map(av[1]);
	mlx.map = map;
	parse_map(&mlx);
	mlx_draw(&mlx);
	return (0);
}
