/*
** EPITECH PROJECT, 2025
** builtins.c
** File description:
** built in commands
*/
#include "minishell.h"

static int handle_exit(char ***env)
{
    my_putstr("Exiting shell...\n");
    free_env(*env);
    exit(0);
    return 1;
}

static int handle_env(char **env)
{
    print_env(env);
    return 1;
}

static int handle_setenv(char **args, char ***env)
{
    if (!args[1]) {
        print_env(*env);
        return 1;
    }
    if (handle_setenv_errors(args))
        return 1;
    if (!args[2]) {
        set_env(args[1], "", env);
    } else {
        set_env(args[1], args[2], env);
    }
    return 1;
}

static int handle_unsetenv(char **args, char ***env)
{
    if (handle_unsetenv_errors(args))
        return 1;
    unset_env(args[1], env);
    return 1;
}

static int handle_42 (char **args)
{
    (void)args;
    my_putstr("Life, the Universe and Everything");
    return 42;
}
int handle_builtin(char **args, char ***env)
{
    if (my_strcmp(args[0], "cd") == 0)
        return handle_cd(args, env);
    if (my_strcmp(args[0], "exit") == 0)
        return handle_exit(env);
    if (my_strcmp(args[0], "env") == 0)
        return handle_env(*env);
    if (my_strcmp(args[0], "setenv") == 0)
        return handle_setenv(args, env);
    if (my_strcmp(args[0], "unsetenv") == 0)
        return handle_unsetenv(args, env);
    if (my_strcmp(args[0], "42") == 0)
        return handle_42 (args);
    return 0;
}
