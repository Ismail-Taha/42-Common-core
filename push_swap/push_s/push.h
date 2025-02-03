/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:08:14 by isallali          #+#    #+#             */
/*   Updated: 2025/02/03 11:53:29 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_H
# define PUSH_H

#include "../Libft/libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				indx;
	int				pos;
	int				targ_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

// helpers
void				print_sorted_stack(t_stack *stack);
void				ft_putnbr(int n);

t_stack				*stack_butm(t_stack *st);
int					stack_len(t_stack *st);
void				add_back(t_stack **a, t_stack *new);
t_stack				*new_stack(int value);
void				free_stack(t_stack **a);

t_stack				*validat_arg(int ac, char **av);
void				sort_rest(t_stack **st);
void				sort_stack(t_stack **a, t_stack **b);

int					abs_value(int n);

void				sa(t_stack **a, int opr);
void				sb(t_stack **b, int opr);
void				ss(t_stack **a, t_stack **b, int opr);
void				pa(t_stack **a, t_stack **b, int opr);
void				pb(t_stack **a, t_stack **b, int opr);
void				ra(t_stack **a, int opr);
void				rb(t_stack **b, int opr);
void				rr(t_stack **a, t_stack **b, int opr);
void				rra(t_stack **a, int opr);
void				rrb(t_stack **b, int opr);
void				rrr(t_stack **a, t_stack **b, int opr);

int					get_min_pos(t_stack **st);
int					get_max_indx(t_stack *st);
void				set_position(t_stack **st);
void				set_target(t_stack **a, t_stack **b);
void				set_index(t_stack **st);
int					target_position(t_stack **a, int indx, int targ_indx,
						int targ_pos);
int					sorted(t_stack *st);

void				calculat_costs(t_stack **a, t_stack **b);
void				do_operation(t_stack **a, t_stack **b, int cost_a,
						int cost_b);
void				nearest_way(t_stack **a, t_stack **b);

int					cmp_value(int a, int b);
void				ft_free(char **str);
void				pr_err(void);

#endif /*PUSH_H*/