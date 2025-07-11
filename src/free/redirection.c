/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** redirection.c
*/
#include "minishell.h"

void free_redirection(redirection_t *redir)
{
    if (!redir)
        return;
    free(redir->type);
    free(redir->filename);
    free(redir);
}

void free_redirections_list(redirection_t *redir)
{
    redirection_t *current = redir;
    redirection_t *next;

    while (current) {
        next = current->next;
        free_redirection(current);
        current = next;
    }
}
