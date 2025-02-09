/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:37:31 by isallali          #+#    #+#             */
/*   Updated: 2025/02/09 18:30:00 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iron_wire.h"
#include <stdio.h>


int main(int ac, char **av)
{
    t_map   *map;

    if (ac != 2)
        pr_error(NULL, "Usage: ./Iron_wire <filename>");
    validat_file(av[1]);
    map = init_map(av[1]);
    parse_map(map);
    mlx_draw(map);
    return (0);
}