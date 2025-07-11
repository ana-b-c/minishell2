/*
** EPITECH PROJECT, 2025
** print env
** File description:
** print_env
*/
#include "minishell.h"

void print_env(char **env)
{
    int i = 0;

    while (env[i]) {
        my_putstr(env[i]);
        my_putchar('\n');
        i++;
    }
}
