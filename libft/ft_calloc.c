/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:15:19 by isallali          #+#    #+#             */
/*   Updated: 2024/10/23 22:46:43 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_calloc(size_t count, size_t size)
{
	size_t	len;
	void	*c;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	len = count * size;
	c = malloc(len);
	if (c == NULL)
		return (NULL);
	else
		ft_bzero(c, len);
	return (c);
}
