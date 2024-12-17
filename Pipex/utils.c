#include "pipex.h"

char    *extract_path(char *cmd, char **envp)
{
    char    **path;
    char    *ppath;
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
        if (access(expath, F_OK) == 0)
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
    cmd = ft_split(av, ' ');
	if (ft_strchr(cmd[0], '/'))
		expath = cmd[0];
	else
    	expath = extract_path(cmd[0], envp);
    if(!expath || access(expath, X_OK) == -1)
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
	perror(NULL);
	exit(EXIT_FAILURE);
}

int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	r = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		r = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (r);
}
