/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isallali <isallali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 12:15:30 by isallali          #+#    #+#             */
/*   Updated: 2025/02/01 14:34:27 by isallali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "./../push_s/push.h"
# include "./../Libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		f_strchr(char *s, char c);
size_t	f_strlen(char *s);
char	*f_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
void	*f_calloc(size_t count, size_t size);

#endif /*CHECKER_H*/
