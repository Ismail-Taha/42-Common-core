/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:41:00 by isallali          #+#    #+#             */
/*   Updated: 2025/01/24 16:39:25 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void    rra(t_stack **a, int opr)
{
    t_stack *butm;
    t_stack *bf_btm;

    if (!a || !(*a)->next)
        return;
    butm = *a;
    bf_btm = NULL;
    while (butm->next)
    {
        bf_btm = butm;
        butm = butm->next;
    }
    bf_btm->next = NULL;
    butm->next = *a;
    *a = butm;
    if (opr)
        write(1, "rra\n", 4);    
}

void    rrb(t_stack **b, int opr)
{
    t_stack *butm;
    t_stack *bf_butm;
    
    if (!a || !(*a)->next)
        return;
    butm = *b;
    bf_butm = NULL;
    while (butm->next)
    {
        bf_butm = butm;
        butm = butm->next;
    }
    bf_butm->next = NULL;
    butm->next = *b;
    *b = butm;
    if (opr)
        write(1, "rra\n", 4);
}

void    rrr(t_stack **a, t_stack **b, int opr)
{
    rra(a, 0);
    rrb(b, 0);
    if (opr)
        write(1, "rrr\n", 4);
}