/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:08:14 by isallali          #+#    #+#             */
/*   Updated: 2025/01/29 12:35:23 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
    int value;
    int indx;
    int pos;
    int targ_pos;
    int cost_a;
    int cost_b;
    struct s_stack  *next;
}   t_stack;

t_stack *stack_butm(t_stack *st);
int stack_len(t_stack *st);
int get_max_indx(t_stack *st);
int abs_value(int n);
int get_min_pos(t_stack **st);
void    sa(t_stack **a, int opr);
void    sb(t_stack **b, int opr);
void    ss(t_stack **a, t_stack **b, int opr);
void    pa(t_stack **a, t_stack **b, int opr);
void    pb(t_stack **a, t_stack **b, int opr);
void    ra(t_stack **a, int opr);
void    rb(t_stack **b, int opr);
void    rr(t_stack **a, t_stack **b, int opr);
void    rra(t_stack **a, int opr);
void    rrb(t_stack **b, int opr);
void    rrr(t_stack **a, t_stack **b, int opr);