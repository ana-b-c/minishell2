/*
** EPITECH PROJECT, 2025
** free env
** File description:
** free_env
*/
#include "minishell.h"

void free_env(char **env)
{
    for (int i = 0; env[i]; i++)
        free(env[i]);
    free(env);
}
