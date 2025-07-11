/*
** EPITECH PROJECT, 2025
** rm the variable of the enviroment
** File description:
** unsetenv
*/
#include "minishell.h"

static int find_env_var_index(char **env, const char *key)
{
    int i = 0;
    size_t key_len = my_strlen(key);

    while (env[i]) {
        if (my_strncmp(env[i], key, key_len) == 0 && env[i][key_len] == '=') {
            return i;
        }
        i++;
    }
    return -1;
}

static int count_remaining_env_vars(char **env, const char *key)
{
    int count = 0;
    size_t key_len = my_strlen(key);

    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], key, key_len) != 0 || env[i][key_len] != '=') {
            count++;
        }
    }
    return count;
}

static char **create_filtered_env(char **old_env,
    const char *key, int remaining_count)
{
    char **new_env = malloc((remaining_count + 1) * sizeof(char *));
    size_t key_len = my_strlen(key);
    int j = 0;

    if (!new_env) {
        perror("malloc failed");
        return NULL;
    }
    for (int i = 0; old_env[i]; i++) {
        if (my_strncmp(old_env[i], key, key_len) != 0
            || old_env[i][key_len] != '=') {
            new_env[j] = old_env[i];
            j = j + 1;
        } else {
            free(old_env[i]);
        }
    }
    new_env[j] = NULL;
    return new_env;
}

void unset_env(char *key, char ***env)
{
    int remaining_count;
    char **new_env;
    int var_index = find_env_var_index(*env, key);

    if (var_index == -1)
        return;
    remaining_count = count_remaining_env_vars(*env, key);
    new_env = create_filtered_env(*env, key, remaining_count);
    if (!new_env)
        return;
    free(*env);
    *env = new_env;
}
