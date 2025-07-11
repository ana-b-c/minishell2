/*
** EPITECH PROJECT, 2025
** main
** File description:
** entry point
*/
#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
    int exit_code;

    (void)argc;
    (void)argv;
    exit_code = shell_loop(envp);
    return exit_code;
}
