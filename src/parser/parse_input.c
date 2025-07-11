/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** parse_input.c
*/
#include "minishell.h"

static command_t *add_command_to_list(command_t **cmd_list,
    command_t **current_cmd, command_t *new_cmd)
{
    if (*cmd_list == NULL) {
        *cmd_list = new_cmd;
        *current_cmd = new_cmd;
    } else {
        (*current_cmd)->next = new_cmd;
        *current_cmd = new_cmd;
    }
    return *cmd_list;
}

static command_t *process_command_group(char *group,
    command_t **cmd_list, command_t **current_cmd)
{
    char *trimmed = trim_whitespace(group);
    command_t *cmd;

    if (!trimmed || my_strlen(trimmed) == 0)
        return *cmd_list;
    cmd = parse_command_group(group);
    if (!cmd)
        return NULL;
    return add_command_to_list(cmd_list, current_cmd, cmd);
}

command_t *parse_input(char *input)
{
    command_t *cmd_list = NULL;
    command_t *current_cmd = NULL;
    char **command_groups;
    int i = 0;

    command_groups = split_by_delimiter(input, ";");
    if (!command_groups)
        return NULL;
    while (command_groups[i]) {
        cmd_list = process_command_group(command_groups[i],
            &cmd_list, &current_cmd);
        if (!cmd_list) {
            free_array(command_groups);
            return NULL;
        }
        i++;
    }
    free_array(command_groups);
    return cmd_list;
}
