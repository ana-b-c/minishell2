/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** check_command_exists.c
*/
#include "minishell.h"

int check_command_exists(char *command, char **env)
{
    char *exec_path = find_executable(command, env);

    if (access(exec_path, X_OK) != 0) {
        my_putstr(command);
        my_putstr(": Command not found.\n");
        return 0;
    }
    return 1;
}
