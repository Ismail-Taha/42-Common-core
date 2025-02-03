/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_getter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:59:34 by isallali          #+#    #+#             */
/*   Updated: 2025/02/02 20:15:32 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	target_position(t_stack **a, int indx, int targ_indx, int targ_pos)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->indx > indx && tmp->indx < targ_indx)
		{
			targ_indx = tmp->indx;
			targ_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	if (targ_indx != INT_MAX)
		return (targ_pos);
	tmp = *a;
	while (tmp)
	{
		if (tmp->indx < targ_indx)
		{
			targ_indx = tmp->indx;
			targ_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (targ_pos);
}

void	set_position(t_stack **st)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *st;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

void	set_target(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		targ_pos;

	tmp = *b;
	set_position(a);
	set_position(b);
	targ_pos = 0;
	while (tmp)
	{
		targ_pos = target_position(a, tmp->indx, INT_MAX, targ_pos);
		tmp->targ_pos = targ_pos;
		tmp = tmp->next;
	}
}

int	get_max_indx(t_stack *st)
{
	int	max_indx;

	if (!st)
		return (0);
	max_indx = st->indx;
	while (st)
	{
		if (st->indx > max_indx)
			max_indx = st->indx;
		st = st->next;
	}
	return (max_indx);
}

int	get_min_pos(t_stack **st)
{
	t_stack	*tmp;
	int		min_indx;
	int		min_pos;

	tmp = *st;
	min_indx = INT_MAX;
	min_pos = tmp->pos;
	set_position(st);
	while (tmp)
	{
		if (tmp->indx < min_indx)
		{
			min_indx = tmp->indx;
			min_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (min_pos);
}
