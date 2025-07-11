/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** create_pipeline.c
*/
#include "minishell.h"

pipeline_t *create_pipeline(char **segments)
{
    pipeline_t *pipeline = malloc(sizeof(pipeline_t));
    int segment_count = 0;
    int i;

    while (segments[segment_count])
        segment_count++;
    pipeline->commands = malloc(sizeof
        (simple_command_t *) * (segment_count + 1));
    for (i = 0; i < segment_count; i++) {
        pipeline->commands[i] = parse_simple_command(segments[i]);
    }
    pipeline->commands[i] = NULL;
    pipeline->count = segment_count;
    return pipeline;
}
