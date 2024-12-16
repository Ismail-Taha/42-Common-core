#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
#include "libft.h"

/* Mandatory functions */
void	error(void);
char	*extract_path(char *cmd, char **envp);
void	execution(char *av, char **envp);

/* Bonus functions */
int		open_f(char *argv, int i);
void	err_usage(void);

#endif
