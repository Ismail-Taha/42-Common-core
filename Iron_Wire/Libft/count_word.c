/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 16:32:08 by isallali          #+#    #+#             */
/*   Updated: 2025/02/09 16:32:12 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	w_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != 0)
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}
