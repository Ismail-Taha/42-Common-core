/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iron_wire.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:36:59 by isallali          #+#    #+#             */
/*   Updated: 2025/02/09 16:10:56 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef IRON_WIRE_H
# define IRON_WIRE_H


# include <mlx.h>
# include <math.h>
#include <stdint.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "Libft/libft.h"

typedef struct s_point {
    int     x;
    int     y;
    int     z;
    int     color;
    float   projected_x;
    float   projected_y;
} t_point;

typedef struct s_map {
    int     width;
    int     height;
    float   zoom;
    float   z_scale;
    float   rotation;
    int     z_min;
    int     z_max;
    float   offset_x;
    float   offset_y;
    int     projection_type;
    t_point **points;
    char    *filename;
} t_map;

// Function prototypes
t_map   *init_map(char *filename);
void    parse_map(t_map *map);
int     parse_point(char *str, t_point *point, t_map *map);
void    free_map(t_map *map);
void    pr_error(t_map *map, const char *message);

#endif /*IRON_WIRE_H*/