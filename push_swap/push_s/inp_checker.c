/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inp_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:25:38 by isallali          #+#    #+#             */
/*   Updated: 2025/02/05 20:10:39 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	valid_atoi(const char *str, char **arg, t_stack **st)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (ft_free(arg), free_stack(st), pr_err(), 1);
		if (check_overflow(res, sign, str[i]))
			return (ft_free(arg), free_stack(st), pr_err(), 1);
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}

void	stack_init(char **arg, t_stack **st)
{
	int	i;

	i = -1;
	while (arg[++i])
		add_back(st, new_stack(valid_atoi(arg[i], arg, st)));
}

int	duplicat(t_stack *st)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp = st;
	while (tmp)
	{
		tmp1 = tmp->next;
		while (tmp1)
		{
			if (cmp_value(tmp->value, tmp1->value))
				return (1);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	validat_inp(char **str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] == '-' || str[i][j] == '+')
				++j;
			if (str[i][j] == '-' || str[i][j] == '+' || !ft_isdigit(str[i][j]))
				return (1);
		}
	}
	return (0);
}

t_stack	*validat_arg(int ac, char **av)
{
	int		i;
	char	**splits;
	t_stack	*st;

	i = 0;
	st = NULL;
	while (i < ac)
	{
		splits = ft_split(av[i], ' ');
		if (!splits || split_size(splits) == 0)
			return (ft_free(splits), free_stack(&st), NULL);
		if (validat_inp(splits))
			return (ft_free(splits), free_stack(&st), NULL);
		stack_init(splits, &st);
		ft_free(splits);
		i++;
	}
	if (duplicat(st))
		return (free_stack(&st), NULL);
	set_index(&st);
	return (st);
}
