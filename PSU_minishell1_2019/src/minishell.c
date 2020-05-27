/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** UNIX command interpreter
*/

#include "minishell.h"

char **builtin(char **envp, char *buff, char *command)
{
    int nbr = 0;

    if (command == NULL)
        minishell(envp);
    nbr = check_command(command, buff, envp);
    if (nbr == 5) {
        my_putstr_error(command);
        my_putstr_error(": Command not found.\n");
    }
    envp = commands(nbr, buff, envp);
    return (envp);
}

int execute_bin(char **envp, char *buff, char *command)
{
    char *var = get_env(envp, "PATH");
    char **paths = get_path(var, command);
    char *const *args = get_args_bin(buff);
    int nbr = count_args(var, ':');
    int i = 0;
    pid_t pid = 0;
    int status = 0;

    if (status = (check_command(command, buff, envp) == KNOWN)) {
        commands(status, buff, envp);
        minishell(envp);
    }
    for (; i != nbr; i++)
        if (access(paths[i], F_OK) != -1)
            break;
    if (i == nbr) {
        return (ERROR);
    }
    if ((pid = fork()) == 0)
        execve(paths[i], args, envp);
    wait(&status);
    segfault_handling(status);
    return (SUCCESS);
}

int execute_prog(char **envp, char *buff, char *command)
{
    return (ERROR);
}

int minishell(char **envp)
{
    long unsigned size = 10;
    char *buff;
    char *command;

    while (1) {
        buff = malloc(sizeof(char) * size);
        my_putstr(PROMPT);
        if (getline(&buff, &size, stdin) == EOF) {
            my_putstr("exit\n");
            exit(SUCCESS);
        }
        buff = clean_str(buff);
        command = get_command(buff);
        if (execute_prog(envp, buff, command) == SUCCESS)
            minishell(envp);
        if (execute_bin(envp, buff, command) == SUCCESS)
            minishell(envp);
        envp = builtin(envp, buff, command);
    }
    return (SUCCESS);
}
