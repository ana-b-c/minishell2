/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** unsetenv_errors.c
*/
#include "minishell.h"

int handle_unsetenv_errors(char **args)
{
    if (!args[1]) {
        my_putstr_e("unsetenv: Too few arguments.\n");
        return 1;
    }
    return 0;
}
