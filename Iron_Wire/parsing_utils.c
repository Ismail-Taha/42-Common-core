/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:57:46 by isallali          #+#    #+#             */
/*   Updated: 2025/02/11 13:57:06 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iron_wire.h"

int parse_point(char *str, t_point *point)
{
    char    **color_split;
    int     error;

    error = 0;
    color_split = ft_split(str, ',');
    if (!color_split)
        return (0);
    point->z = ft_atoi(color_split[0]);
    if (color_split[1])
        point->color = ft_atoi_base(color_split[1] + 2, 16);
    else
        point->color = 0xFFFFFF;
    free_split(color_split);
    return (1);
}

void    free_map(t_map *map)
{
    int i;

    if (!map)
        return ;
    if (map->points)
    {
        i = -1;
        while (++i < map->height)
            free(map->points[i]);
        free(map->points);
    }
    free(map->row_widths);
    free(map);
}

void    pr_error(t_map *map, const char *message)
{
    write(2, "Error: ", 7);
    write(2, message, ft_strlen(message));
    write(2, "\n", 1);
    
    if (map)
        free_map(map);
    exit(1);
}

static int	get_digit_value(char digit, int base)
{
	char	*lowercase_digits;
	char	*uppercase_digits;
	int		digit_index;

	lowercase_digits = "0123456789abcdef";
	uppercase_digits = "0123456789ABCDEF";
	digit_index = 0;
	while (digit_index < base)
	{
		if (digit == lowercase_digits[digit_index] || 
			digit == uppercase_digits[digit_index])
			return (digit_index);
		digit_index++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, int base)
{
	int	sign;
	int	pos;
	int	number;

	pos = 0;
	number = 0;
	sign = 1;
	while (ft_is_space(str[pos]))
		pos++;
	if (str[pos] && (str[pos] == '-' || str[pos] == '+'))
	{
		if (str[pos] == '-')
			sign = -1;
		pos++;
	}
	while (get_digit_value(str[pos], base) != -1)
	{
		number = number * base + get_digit_value(str[pos], base);
		if (number < 0)
			return ((sign != -1) * -1);
		pos++;
	}
	return (number * sign);
}

void free_split(char **split)
{
    int i;

    if (!split)
        return;
    i = -1;
    while (split[++i])
        free(split[i]);
    free(split);
}

void validat_file(char *file)
{
    int i;

    i = 0;
    while (file[i])
        i++;
    if (i < 4 || file[i - 1] != 'f' || file[i - 2] != 'd' || file[i - 3] != 'f' || file[i - 4] != '.')
        pr_error(NULL, "Invalid file extension");
}