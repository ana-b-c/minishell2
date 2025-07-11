/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** command.c
*/
#include "minishell.h"

void free_simple_command(simple_command_t *cmd)
{
    if (!cmd)
        return;
    free_array(cmd->args);
    free_redirections_list(cmd->redirections);
    free(cmd);
}

void free_pipeline(pipeline_t *pipeline)
{
    if (!pipeline)
        return;
    for (int i = 0; i < pipeline->count; i++) {
        free_simple_command(pipeline->commands[i]);
    }
    free(pipeline->commands);
    free(pipeline);
}

void free_command(command_t *cmd)
{
    if (!cmd)
        return;
    if (cmd->type == CMD_SIMPLE) {
        free_simple_command(cmd->simple_cmd);
    } else if (cmd->type == CMD_PIPE) {
        free_pipeline(cmd->pipe_cmd);
    }
    free(cmd);
}

void free_command_list(command_t *cmd_list)
{
    command_t *current = cmd_list;
    command_t *next;

    while (current) {
        next = current->next;
        free_command(current);
        current = next;
    }
}
