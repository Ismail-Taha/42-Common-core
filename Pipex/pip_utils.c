#include "pipex.h"

char    *extract_path(char *cmd, char **envp)
{
    char    **path;
    char    *ppath
    char    *expath;
    int     i;

    i = 0;
    while(ft_strnstr(envp[i], "PATH", 4) == NULL)
        i++;
    path = ft_split(envp[i] + 5, ':');
    i = 0;
    while (path[i])
    {
        ppath = ft_strjoin(path[i], "/");
        expath = ft_strjoin(ppath, cmd);
        free(ppath);
        if (access(expath, F_OK))
            return (expath);
        free(expath);
        i++;
    }
    i = -1;
    while (path[++i])
        free(path[i]);
    free(path);
    return (0);
}

void    execution(char *av, char **envp)
{
    char    **cmd;
    int     i;
    char    *expath;

    i = -1;
    cmd = ft_split(av, " ");
    expath = extract_path(cmd[0], envp);
    if(!expath)
    {
        while (cmd[++i])
            free(cmd[i]);
        free(cmd);
        error();
    }
    if (execve(expath, cmd, envp) == -1)
        error();
}
void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}