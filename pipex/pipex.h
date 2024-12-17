#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
#include "inclibft/libft.h"

typedef struct s_path_info {
    char    **path;
    char    *ppath;
    char    *expath;
}   t_path_info;

/* Mandatory functions */
void	error(char *msg, int status);
char	*extract_path(char *cmd, char **envp);
void	execution(char *av, char **envp);

/* Bonus functions */
int	get_next_line(char **line);
int		open_f(char *argv, int i);
void	err_usage(void);

#endif
