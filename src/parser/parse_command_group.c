/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** parse_command_group.c
*/
#include "minishell.h"

static int validate_pipeline_segments(char **segments)
{
    char *trimmed;

    if (!segments || !segments[0]) {
        my_putstr_e("Invalid null command.\n");
        return 0;
    }
    for (int i = 0; segments[i]; i++) {
        trimmed = trim_whitespace(segments[i]);
        if (!trimmed || trimmed[0] == '\0') {
            my_putstr_e("Invalid null command.\n");
            return 0;
        }
    }
    return 1;
}

static command_t *init_command(void)
{
    command_t *cmd = malloc(sizeof(command_t));

    if (!cmd)
        return NULL;
    cmd->type = CMD_SIMPLE;
    cmd->next = NULL;
    cmd->pipe_cmd = NULL;
    return cmd;
}

static void handle_pipeline_command(command_t *cmd, char **segments)
{
    cmd->type = CMD_PIPE;
    cmd->pipe_cmd = create_pipeline(segments);
}

static void handle_simple_command(command_t *cmd, char *segment)
{
    if (!segment || my_strlen(trim_whitespace(segment)) == 0) {
        cmd->simple_cmd = NULL;
        return;
    }
    cmd->simple_cmd = parse_simple_command(segment);
}

command_t *parse_command_group(char *command_str)
{
    command_t *cmd = init_command();
    char **pipeline_segments;

    if (!cmd)
        return NULL;
    pipeline_segments = split_by_delimiter(command_str, "|");
    if (!pipeline_segments || !validate_pipeline_segments(pipeline_segments)) {
        free_array(pipeline_segments);
        free(cmd);
        return NULL;
    }
    if (pipeline_segments[1] != NULL)
        handle_pipeline_command(cmd, pipeline_segments);
    else
        handle_simple_command(cmd, pipeline_segments[0]);
    free_array(pipeline_segments);
    return cmd;
}
