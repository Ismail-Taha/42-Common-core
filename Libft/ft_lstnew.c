/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:47:48 by isallali          #+#    #+#             */
/*   Updated: 2024/11/01 18:16:27 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list  new_n;

    new_n = malloc(sizeof(t_list));
    if (!new_n)
        return (NULL);
    new_n->content = content;
    new_n->next = NULL;
    return (new_n);
}