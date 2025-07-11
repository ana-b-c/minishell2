/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** structure.h
*/
#ifndef STRUCTURE_H
    #define STRUCTURE_H

    #include "minishell.h"

typedef struct redirection_s {
    char *type;
    char *filename;
    struct redirection_s *next;
} redirection_t;

typedef struct simple_command_s {
    char **args;
    redirection_t *redirections;
} simple_command_t;

typedef struct pipeline_s {
    simple_command_t **commands;
    int count;
} pipeline_t;

typedef enum {
    CMD_SIMPLE,
    CMD_PIPE
} command_type_t;

typedef struct command_s {
    command_type_t type;
    union {
        simple_command_t *simple_cmd;
        pipeline_t *pipe_cmd;
    };
    struct command_s *next;
} command_t;

#endif /* STRUCTURE_H */
