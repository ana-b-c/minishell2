/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** execute_simple_command_with_redir.c
*/
#include "minishell.h"

/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** execute_simple_command_with_redir.c (safe strip_quotes)
*/
#include "minishell.h"

int execute_simple_command_with_redir(simple_command_t *cmd, char ***env)
{
    int stdin_copy = dup(STDIN_FILENO);
    int stdout_copy = dup(STDOUT_FILENO);
    int status = 1;
    char *stripped;

    for (int i = 0; cmd->args[i]; i++) {
        stripped = strip_quotes(cmd->args[i]);
        free(cmd->args[i]);
        cmd->args[i] = stripped;
    }
    if (apply_redirections(cmd->redirections) == -1)
        status = 1;
    else
        status = execute_simple_command(cmd, env);
    dup2(stdin_copy, STDIN_FILENO);
    dup2(stdout_copy, STDOUT_FILENO);
    close(stdin_copy);
    close(stdout_copy);
    return status;
}
