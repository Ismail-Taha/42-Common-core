/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:15:36 by isallali          #+#    #+#             */
/*   Updated: 2025/01/28 15:10:54 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_stack *stack_butm(t_stack *st)
{
    if (!st)
        return (NULL);
    if (!st->next)
        return (st);
    return (stack_butm(st->next));
}

int stack_len(t_stack *st)
{
    int len;
    
    len = 0;
    while(st)
    {
        len++;
        st = st->next;
    }
    return (len);
}