/*
** EPITECH PROJECT, 2025
** add variable name in enviroment
** File description:
** setenv
*/
#include "minishell.h"

static char *create_env_var(const char *key, const char *value)
{
    size_t key_len = my_strlen(key);
    size_t value_len = value ? my_strlen(value) : 0;
    char *new_var = malloc(key_len + value_len + 2);

    if (!new_var) {
        perror("malloc failed");
        return NULL;
    }
    my_strcpy(new_var, key);
    my_strcat(new_var, "=");
    if (value)
        my_strcat(new_var, value);
    return new_var;
}

static int update_existing_env(char **env, const char *key, char *new_var)
{
    int i = 0;
    size_t key_len = my_strlen(key);

    while (env[i]) {
        if (my_strncmp(env[i], key, key_len) == 0 && env[i][key_len] == '=') {
            free(env[i]);
            env[i] = new_var;
            return 1;
        }
        i++;
    }
    return 0;
}

static char **create_new_env(char **old_env, char *new_var, int size)
{
    char **new_env = malloc((size + 2) * sizeof(char *));

    if (!new_env) {
        perror("malloc failed");
        return NULL;
    }
    for (int j = 0; j < size; j++) {
        new_env[j] = old_env[j];
    }
    new_env[size] = new_var;
    new_env[size + 1] = NULL;
    return new_env;
}

void set_env(char *key, char *value, char ***env)
{
    char *new_var = create_env_var(key, value ? value : "");
    int env_size;
    char **new_env;

    if (!new_var)
        return;
    if (update_existing_env(*env, key, new_var)) {
        return;
    }
    env_size = 0;
    while ((*env)[env_size]) {
        env_size++;
    }
    new_env = create_new_env(*env, new_var, env_size);
    if (!new_env) {
        free(new_var);
        return;
    }
    free(*env);
    *env = new_env;
}
