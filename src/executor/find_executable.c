/*
** EPITECH PROJECT, 2025
** find executable
** File description:
** executor
*/
#include "minishell.h"

char *get_path_from_env(char **env)
{
    int i = 0;

    while (env[i]) {
        if (my_strncmp(env[i], "PATH=", 5) == 0) {
            return my_strdup(env[i] + 5);
        }
        i++;
    }
    return NULL;
}

char *build_and_check_path(char *token, char *command)
{
    struct stat st;
    char *full_path = malloc(my_strlen(token) + my_strlen(command) + 2);

    if (!full_path)
        return NULL;
    my_strcpy(full_path, token);
    my_strcat(full_path, "/");
    my_strcat(full_path, command);
    if (stat(full_path, &st) == 0 && (st.st_mode & S_IXUSR))
        return full_path;
    free(full_path);
    return NULL;
}

char *find_executable(char *command, char **env)
{
    char *path = get_path_from_env(env);
    char *token;
    char *full_path;

    if (!path || my_strchr(command, '/'))
        return command;
    token = strtok(path, ":");
    while (token) {
        full_path = build_and_check_path(token, command);
        if (full_path) {
            free(path);
            return full_path;
        }
        token = strtok(NULL, ":");
    }
    free(path);
    return command;
}
