/*
** EPITECH PROJECT, 2025
** getenv
** File description:
** env
*/
#include "minishell.h"

char *get_env(char *name, char **env)
{
    int i = 0;
    size_t name_len = my_strlen(name);

    while (env[i]) {
        if (my_strncmp(env[i], name, name_len) == 0
        && env[i][name_len] == '=') {
            return env[i] + name_len + 1;
        }
        i++;
    }
    return NULL;
}
