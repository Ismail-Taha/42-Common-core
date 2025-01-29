/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instru1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:47:55 by isallali          #+#    #+#             */
/*   Updated: 2025/01/29 10:58:00 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void    push_save(t_stack **a, t_stack **b)
{
    int size;
    int opr;
    int i;

    size = stack_len(a);
    opr = 0;
    i = 0;
    while (size > 6 && i < size && opr < size / 2)
    {
        if ((*a)->index < size / 2)
        {
            pb(a, b, 1);
            opr++;
        }
        else
            ra(a, 1);
        i++;
    }
    while (size - opr > 3)
    {
        pa(a, b, 1)
        opr++;
    }
}


