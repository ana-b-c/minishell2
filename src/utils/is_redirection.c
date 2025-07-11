/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** is_redirection.c
*/
#include "minishell.h"

int is_redirection(char *token)
{
    return (my_strcmp(token, ">") == 0 ||
            my_strcmp(token, ">>") == 0 ||
            my_strcmp(token, "<") == 0 ||
            my_strcmp(token, "<<") == 0);
}

void add_redirection(simple_command_t *cmd, char *type, char *filename)
{
    redirection_t *redir = malloc(sizeof(redirection_t));
    redirection_t *current;

    if (!redir)
        return;
    redir->type = my_strdup(type);
    redir->filename = my_strdup(filename);
    redir->next = NULL;
    if (!cmd->redirections) {
        cmd->redirections = redir;
    } else {
        current = cmd->redirections;
        while (current->next)
            current = current->next;
        current->next = redir;
    }
}
