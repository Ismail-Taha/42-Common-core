/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:31:10 by isallali          #+#    #+#             */
/*   Updated: 2025/02/05 15:33:17 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	a = validat_arg(ac - 1, av + 1);
	if (!a)
		pr_err();
	if (!sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, 1);
		else if (stack_len(a) == 3)
			sort_rest(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
