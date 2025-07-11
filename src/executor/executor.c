/*
** EPITECH PROJECT, 2025
** executor.c
** File description:
** command execution
*/
#include "minishell.h"

int execute_simple_command_with_redirections(command_t *cmd, char ***env)
{
    if (cmd->simple_cmd->redirections) {
        return execute_simple_command_with_redir(cmd->simple_cmd, env);
    } else {
        return execute_simple_command(cmd->simple_cmd, env);
    }
}

int handle_command(command_t *cmd, char ***env)
{
    if (cmd->type == CMD_SIMPLE) {
        return execute_simple_command_with_redirections(cmd, env);
    }
    if (cmd->type == CMD_PIPE) {
        return execute_pipeline(cmd->pipe_cmd, env);
    }
    return -1;
}

int execute_commands(command_t *cmd_list, char ***env)
{
    command_t *current = cmd_list;
    int status = 0;

    while (current) {
        status = handle_command(current, env);
        current = current->next;
    }
    return status;
}
