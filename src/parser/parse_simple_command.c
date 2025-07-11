/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** parse_simple_command.c
*/
#include "minishell.h"

simple_command_t *parse_simple_command(char *cmd_str)
{
    simple_command_t *cmd = malloc(sizeof(simple_command_t));

    if (!cmd)
        return NULL;
    cmd->redirections = NULL;
    cmd->args = NULL;
    parse_redirections(cmd_str, cmd);
    return cmd;
}
