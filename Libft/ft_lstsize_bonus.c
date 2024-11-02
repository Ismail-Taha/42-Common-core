#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*node;
	int		len;

	node = lst;
	len = 0;
	while (node)
	{
		len++;
		node = node->next;
	}
	return (len);
}
