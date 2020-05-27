/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** exit the UNIX interpreter
*/

#include "minishell.h"

void my_exit(void)
{
    my_putstr("exit\n");
    exit(SUCCESS);
}
