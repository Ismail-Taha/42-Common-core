#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#define ERR_FATAL "error: fatal\n"
#define ERR_CD_ARGS "error: cd: bad arguments\n"
#define ERR_CD_CANNOT "error: cd: cannot change directory to "
#define ERR_EXEC "error: cannot execute "

void    fatal(void)
{
    write(2, ERR_FATAL, strlen(ERR_FATAL));
    exit(1);
}

int ft_strlen(char *s)
{
    int i = 0;
    while (s && s[i])
        i++;
    return i;
}

void    putstr2(char *s)
{
    write(2, s, ft_strlen(s));
}

void    cd(char **argv, int argc)
{
    if (argc != 2)
    {
        putstr2(ERR_CD_ARGS);
        return;
    }
    if (chdir(argv[1]) != 0)
    {
        putstr2(ERR_CD_CANNOT);
        putstr2(argv[1]);
        putstr2("\n");
    }
}

int exec_cmd(char **argv, char **env, int in_fd, int out_fd)
{
    pid_t pid = fork();
    if (pid < 0)
        fatal();
    if (pid == 0)
    {
        if (dup2(in_fd, 0) < 0)
            fatal();
        if (dup2(out_fd, 1) < 0)
            fatal();
        close(in_fd);
        close(out_fd);
        execve(argv[0], argv, env);
        putstr2(ERR_EXEC);
        putstr2(argv[0]);
        putstr2("\n");
        exit(1);
    }
    return pid;
}

int main(int argc, char **argv, char **env)
{
    int i = 1, in_fd = 0, fd[2];
    pid_t pids[1024];
    int pid_count = 0, status;

    while (i < argc)
    {
        int j = i;
        while (j < argc && strcmp(argv[j], ";") && strcmp(argv[j], "|"))
            j++;

        if (j > i)
        {
            argv[j] = NULL;
            if (!strcmp(argv[i], "cd"))
                cd(&argv[i], j - i);
            else
            {
                int is_pipe = (j < argc && !strcmp(argv[j], "|"));
                if (is_pipe)
                {
                    if (pipe(fd) < 0)
                        fatal();
                }
                else
                {
                    fd[1] = 1;
                }
                pids[pid_count++] = exec_cmd(&argv[i], env, in_fd, fd[1]);
                if (in_fd != 0)
                    close(in_fd);
                if (is_pipe)
                {
                    close(fd[1]);
                    in_fd = fd[0];
                }
                else
                {
                    if (fd[1] != 1)
                        close(fd[1]);
                    in_fd = 0;
                }
            }
        }
        if (j == argc || !strcmp(argv[j], ";"))
        {
            for (int k = 0; k < pid_count; k++)
                waitpid(pids[k], &status, 0);
            pid_count = 0;
            in_fd = 0;
        }
        i = j + 1;
    }
    return 0;
}
