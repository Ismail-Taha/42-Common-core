#include "pipex.h"

void    c_process(char **av, char **envp, int *fd)
{
    int infile;

    infile = open(av[1], O_RDONLY);
    if (infile == -1)
        error();
    dup2(fd[1], STDOUT_FILENO);
    dup2(infile, STDIN_FILENO);
    close(fd[0]);
    execution(av[2], envp);
}

void    p_process(char **av, char **envp, int *fd)
{
    int outfile;

    outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (outfile == -1)
        error();
    dup2(fd[0], STDIN_FILENO);
    dup2(outfile, STDOUT_FILENO);
    close(fd[1]);
    execution(av[3], envp);
}

int main(int ac, char **av, char **envp)
{
    int fd[2];
    pid_t   c_pid;

    if (ac == 5)
    {
        if (pipe(fd) == -1)
            error();
        c_pid = fork();
        if (c_pid == -1)
            error();
        if (c_pid == 0)
            c_process(av, envp, fd);
        waitpid(c_pid, NULL, 0);
        p_process(av, envp, fd);
    }
    else
    {
        ft_putstr_fd("error", 2);
        ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
    }
    return (0);
}