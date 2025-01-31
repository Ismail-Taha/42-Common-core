/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_instru1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:47:55 by isallali          #+#    #+#             */
/*   Updated: 2025/01/29 10:58:00 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void    push_save(t_stack **a, t_stack **b)
{
    int size;
    int opr;
    int i;

    size = stack_len(*a);
    opr = 0;
    i = 0;
    while (size > 6 && i < size && opr < size / 2)
    {
        if ((*a)->indx <= size / 2)
        {
            pb(a, b, 1);
            opr++;
        }
        else
            ra(a, 1);
        i++;
    }
    while (size - opr > 3)
    {
        pb(a, b, 1);
        opr++;
    }
}

void    sort_rest(t_stack **st)
{
    int max_idx;
    if (!(*st) || !(*st)->next || !(*st)->next->next)
        return ;
    max_idx = get_max_indx(*st);
    if ((*st)->indx == max_idx)
        ra(st, 1);
    else if ((*st)->next->indx == max_idx)
        rra(st, 1);
    if ((*st)->indx > (*st)->next->indx)
        sa(st, 1);
}

void    last_sort(t_stack **a)
{
    int min_pos;
    int size;

    size = stack_len(*a);
    min_pos = get_min_pos(a);

    if (min_pos > size / 2)
    {
        while (min_pos < size)
        {
            rra(a, 1);
            min_pos++;
        }
    }
    else
    {
        while (min_pos > 0)
        {
            ra(a, 1);
            min_pos--;
        }
    }
}

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
}

void	print_sorted_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		ft_putnbr(tmp->indx);
		if (tmp->next)
			write(1, " ", 1);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}
void    sort_stack(t_stack **a, t_stack **b)
{
    push_save(a, b);
    sort_rest(a);
    while(*b)
    {
        set_target(a, b);
        calculat_costs(a, b);
        nearest_way(a, b);
    }
    if (!sorted(*a))
        last_sort(a);
}
