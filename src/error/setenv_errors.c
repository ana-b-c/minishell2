/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** setenv_errors.c
*/
#include "minishell.h"

int handle_setenv_errors(char **args)
{
    if (!args[1]) {
        my_putstr_e("setenv: missing variable name.\n");
        return 1;
    }
    if (!is_valid_env_var(args[1])) {
        return 1;
    }
    if (args[3]) {
        my_putstr_e("setenv: too many arguments.\n");
        return 1;
    }
    return 0;
}
