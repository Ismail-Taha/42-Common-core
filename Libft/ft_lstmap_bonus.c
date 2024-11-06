/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 21:38:00 by isallali          #+#    #+#             */
/*   Updated: 2024/11/06 00:23:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content;

	new_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		content = f(lst->content);
		if (!content)
			return (ft_lstclear(&new_list, del), NULL);
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			del(content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/**void deleg(void *content)
{
	free(content);
}
void *increment(void *content)
{
    int *val = (int *)content;
    *val = *val + 1;
    return val;
}
#include <stdio.h>
int main ()
{
	int *val1 = malloc(sizeof(int));
    *val1 = 5;
    t_list *node1 = ft_lstnew(val1);

	int *val2 = malloc(sizeof(int));
	*val2 = 10;
	t_list *node2 = ft_lstnew(val2);
	ft_lstadd_back(&node1, node2);

	int *val3 = malloc(sizeof(int));
	*val3 = 14;
	t_list *node3 = ft_lstnew(val3);
	ft_lstadd_back(&node1, node3);

	ft_lstmap(node1, increment, deleg);

	while (node1 != NULL)
    {
        printf("%d -> ", *((int *)node1->content));
        node1 = node1->next;
    }
    printf("NULL\n");

	return 0;
}*/