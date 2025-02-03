/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:42:27 by isallali          #+#    #+#             */
/*   Updated: 2025/02/02 20:41:12 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_checker(t_stack **a, t_stack **b, char *opr)
{
	if (!ft_strcmp(opr, "pa\n"))
		pa(a, b, 0);
	else if (!ft_strcmp(opr, "pb\n"))
		pb(a, b, 0);
	else if (!ft_strcmp(opr, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(opr, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(opr, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(opr, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(opr, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(opr, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(opr, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(opr, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(opr, "rrr\n"))
		rrr(a, b, 0);
	else
		(free(opr), free_stack(a), free_stack(b), pr_err());
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*opr;

	b = NULL;
	if (ac == 1)
		return (1);
	a = validat_arg(ac, av);
	if (!a)
		pr_err();
	opr = get_next_line(STDIN_FILENO);
	while (opr)
	{
		push_checker(&a, &b, opr);
		free(opr);
		opr = get_next_line(STDIN_FILENO);
	}
	if (sorted(a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
