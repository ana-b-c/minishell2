/*
** EPITECH PROJECT, 2025
** cd
** File description:
** builtins
*/
#include "minishell.h"

int handle_no_path(char ***env, char **path)
{
    *path = get_env("HOME", *env);
    if (!*path) {
        my_putstr("cd: HOME not set\n");
        return 0;
    }
    return 1;
}

int handle_dash_path(char *prev_dir, char **path)
{
    if (prev_dir[0] == '\0') {
        my_putstr_e(": No such file or directory.\n");
        return 0;
    }
    *path = prev_dir;
    my_putstr(*path);
    my_putchar('\n');
    return 1;
}

int change_directory(char *path, char *prev_dir)
{
    char current_dir[1024];

    if (getcwd(current_dir, sizeof(current_dir)) == NULL) {
        perror("cd error: getcwd failed");
        return 0;
    }
    if (chdir(path) != 0) {
        perror("cd error");
        return 0;
    }
    my_strcpy(prev_dir, current_dir);
    return 1;
}

int handle_cd(char **args, char ***env)
{
    static char prev_dir[1024] = "";
    char *path = args[1];

    if (!path) {
        if (!handle_no_path(env, &path))
            return 1;
        set_env("OLDPWD", prev_dir, env);
        return change_directory(path, prev_dir);
    }
    if (my_strcmp(path, "-") == 0) {
        if (!handle_dash_path(prev_dir, &path))
            return 1;
        set_env("OLDPWD", prev_dir, env);
        return change_directory(path, prev_dir);
    }
    if (handle_cd_errors(args))
        return 1;
    set_env("OLDPWD", prev_dir, env);
    return change_directory(path, prev_dir);
}
