/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:22:06 by isallali          #+#    #+#             */
/*   Updated: 2025/01/24 15:40:38 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	ra(t_stack **a, int opr)
{
	t_stack	*tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	stack_butm(*a)->next = tmp;
	if (opr)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int opr)
{
	t_stack	*tmp;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	stack_butm(*b)->next = tmp;
	if (opr)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int opr)
{
	ra(a, 0);
	rb(b, 0);
	if (opr)
		write(1, "rr\n", 3);
}
