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

t_stack	*stack_butm(t_stack *st)
{
	if (!st)
		return (NULL);
	while (st->next)
		st = st->next;
	return (st);
}

int	stack_len(t_stack *st)
{
	int	len;

	len = 0;
	while (st)
	{
		len++;
		st = st->next;
	}
	return (len);
}

t_stack	*new_stack(int value)
{
	t_stack	*new_st;

	new_st = malloc(sizeof(t_stack));
	if (!new_st)
		return (NULL);
	new_st->value = value;
	new_st->indx = 0;
	new_st->pos = -1;
	new_st->targ_pos = -1;
	new_st->cost_a = -1;
	new_st->cost_b = -1;
	new_st->next = NULL;
	return (new_st);
}

void	add_back(t_stack **a, t_stack *new)
{
	t_stack	*end;

	if (!new || !a)
		return ;
	if (!*a)
	{
		*a = new;
		return ;
	}
	end = stack_butm(*a);
	end->next = new;
}

void	free_stack(t_stack **a)
{
	t_stack	*tmp;

	if (!a || !(*a))
		return ;
	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
	*a = NULL;
}
