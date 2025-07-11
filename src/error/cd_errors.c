/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** cd_errors.c
*/
#include "minishell.h"

int check_too_many_arguments(char **args)
{
    if (args[2]) {
        my_putstr_e("cd: Too many arguments.\n");
        return 1;
    }
    return 0;
}

int check_path_exists(char *path)
{
    struct stat path_stat;

    if (stat(path, &path_stat) == -1) {
        my_putstr_e(path);
        my_putstr_e(": No such file or directory.\n");
        return 1;
    }
    return 0;
}

int check_is_directory(char *path)
{
    struct stat path_stat;

    stat(path, &path_stat);
    if (!S_ISDIR(path_stat.st_mode)) {
        my_putstr_e(path);
        my_putstr_e(": Not a directory.\n");
        return 1;
    }
    return 0;
}

int check_permission(char *path)
{
    if (access(path, X_OK) != 0) {
        my_putstr_e("cd: ");
        my_putstr_e(path);
        my_putstr_e(": Permission denied.\n");
        return 1;
    }
    return 0;
}

int handle_cd_errors(char **args)
{
    if (check_too_many_arguments(args))
        return 1;
    if (check_path_exists(args[1]))
        return 1;
    if (check_is_directory(args[1]))
        return 1;
    if (check_permission(args[1]))
        return 1;
    return 0;
}
