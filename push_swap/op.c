/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:04:18 by isallali          #+#    #+#             */
/*   Updated: 2025/01/27 17:06:56 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void    sa(t_stack **a, int opr)
{
    t_stack *tmp;

    if (!a || !*a || !(*a)->next)
        return ;
    tmp = (*a)->next;
    (*a)->next = tmp->next;
    tmp->next = *a;
    *a = tmp;
    if (opr)
        write(1, "sa\n", 3);
}

void    sb(t_stack **b, int opr)
{
    t_stack *tmp;
    
    if(!b || !*b || !(*b)->next)
        return ;
    tmp = (*b)->next;
    (*b)->next = tmp->next;
    tmp->next = *b;
    *b = tmp;
    if (opr)
        write(1, "sb\n", 3);
}

void    ss(t_stack **a, t_stack **b, int opr)
{
    sa(a, 0);
    sb(b, 0);
    if (opr)
        write(1, "ss\n", 3);
}

void    pa(t_stack **a, t_stack **b, int opr)
{
    t_stack *tmp;

    if (!b || !*b)
        return;
    tmp = *b;
    *b = (*b)->next;
    tmp->next = *a;
    *a = tmp;
    if (opr)
        write(1, "pa\n", 3);
}
void    pb(t_stack **a, t_stack **b, int opr)
{
    t_stack *tmp;
    
    if (!a || !*a)
        return;
    tmp = *a;
    *a = (*a)->next;
    tmp->next = *b;
    *b = tmp;
    if (opr)
        write(1, "pb\n", 3);
}
t_stack *new(int val)
{
    t_stack *node = malloc(sizeof(t_stack));
    if (!node)
        return NULL;
    node->value = val;
    node->next = NULL;
    return node;
}
void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("%d -> ", stack->value);
        stack = stack->next;
    }
    printf("NULL\n");
}

int main(void)
{
    t_stack *st = new(4);
    st->next = new(2);
    st->next->next = new(5);
    t_stack *b = NULL;
    
    sa(&st, 1);
    print_stack(st);
    pb(&st, &b, 1);
    print_stack(st);
    print_stack(b);
    pa(&st, &b, 1);
    print_stack(st);
    print_stack(b);
    pb(&st, &b, 1);
    print_stack(st);
    print_stack(b);
    ss(&st, &b, 1);
    print_stack(st);
    print_stack(b);
    pb(&st, &b, 1);
    sb(&b, 1);
    pb(&st, &b, 1);
    print_stack(st);
    print_stack(b);
    
    return 0;
}