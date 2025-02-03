/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_getter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 19:56:33 by isallali          #+#    #+#             */
/*   Updated: 2025/01/29 19:56:33 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	calculat_costs(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		a_size;
	int		b_size;

	tmp = *b;
	a_size = stack_len(*a);
	b_size = stack_len(tmp);
	while (tmp)
	{
		tmp->cost_b = tmp->pos;
		if (tmp->pos > b_size / 2)
			tmp->cost_b = -(b_size - tmp->pos);
		tmp->cost_a = tmp->targ_pos;
		if (tmp->targ_pos > a_size / 2)
			tmp->cost_a = -(a_size - tmp->targ_pos);
		tmp = tmp->next;
	}
}

void	rr_costs(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b, 1);
		(*cost_a)--;
		(*cost_b)--;
	}
}

void	rrr_costs(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b, 1);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	nearest_way(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		near;
	int		cost_a;
	int		cost_b;

	near = INT_MAX;
	tmp = *b;
	while (tmp)
	{
		if (abs_value(tmp->cost_a) + abs_value(tmp->cost_b) < near)
		{
			near = abs_value(tmp->cost_b) + abs_value(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_operation(a, b, cost_a, cost_b);
}

void	do_operation(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
		rr_costs(a, b, &cost_a, &cost_b);
	else if (cost_a < 0 && cost_b < 0)
		rrr_costs(a, b, &cost_a, &cost_b);
	while (cost_a > 0)
	{
		ra(a, 1);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a, 1);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(b, 1);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b, 1);
		cost_b++;
	}
	pa(a, b, 1);
}
