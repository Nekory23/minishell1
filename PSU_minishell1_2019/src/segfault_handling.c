/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** segfault handling
*/

#include "minishell.h"

void segfault_handling(int status)
{
    if (WIFSIGNALED(status)) {
        if (WCOREDUMP(status))
            my_putstr_error("Segmentation fault (core dumped)\n");
        if (SIGFPE == status)
            my_putstr_error("Floating exception (coredumped)\n");
        if (SIGFPE == status && WCOREDUMP(status)) {
            my_putstr_error("Segmentation fault (core dumped) ");
            my_putstr_error("&& Floating Point");
            my_putstr_error("Floating exception.\n");
        }
    }
}
