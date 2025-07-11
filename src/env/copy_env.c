/*
** EPITECH PROJECT, 2025
** copy env
** File description:
** copy_env
*/
#include "minishell.h"

char **copy_env(char **envp)
{
    int count = 0;
    char **env;

    while (envp[count])
        count++;
    env = malloc(sizeof(char *) * (count + 1));
    if (!env)
        return NULL;
    for (int i = 0; i < count; i++)
        env[i] = my_strdup(envp[i]);
    env[count] = NULL;
    return env;
}
