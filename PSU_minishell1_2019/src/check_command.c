/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** check the command
*/

#include "minishell.h"

char **commands(int nbr, char *buff, char **envp)
{
    switch (nbr) {
    case 0 : my_cd(buff, envp);
        break;
    case 1 : my_env(envp);
        break;
    case 2 : envp = my_setenv(envp, buff);
        break;
    case 3 : envp = my_unsetenv(envp, buff);
        break;
    case 4 : my_exit();
        break;
    }
    return (envp);
}

char *get_command(char *buff)
{
    int len = my_strlen(buff);
    int i = 0;
    int nbr = 0;
    char *command = malloc(sizeof(char) * len);

    for (; buff[i] != '\n'; i++)
        if (buff[i] == ' ')
            nbr++;
    if (nbr == len - 1)
        return (NULL);
    for (i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == ' ')
            break;
        if (buff[i] != '\n')
            command[i] = buff[i];
    }
    command[i] = '\0';
    return (command);
}

char **fill_commands(char **commands)
{
    commands[0] = "cd";
    commands[1] = "env";
    commands[2] = "setenv";
    commands[3] = "unsetenv";
    commands[4] = "exit";

    return (commands);
}

int check_command(char *command, char *buff, char **envp)
{
    char **commands = malloc(sizeof(char *) * 5);
    int i = 0;

    commands = fill_commands(commands);
    while (i != 5) {
        if (compare_str(command, commands[i]) == KNOWN)
            break;
        else
            i++;
    }
    free(commands);
    return (i);
}
