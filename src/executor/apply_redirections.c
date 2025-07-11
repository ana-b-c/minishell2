/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** apply_redirections.c
*/
#include "minishell.h"

int handle_output_redirection(const char *filename, int flags)
{
    char *clean_filename = strip_quotes((char *)filename);
    int fd = open(clean_filename, flags, 0644);

    if (fd == -1) {
        my_putstr_e(clean_filename);
        my_putstr_e(": No such file or directory.\n");
        return -1;
    }
    if (dup2(fd, STDOUT_FILENO) == -1) {
        perror("dup2 error (stdout)");
        close(fd);
        return -1;
    }
    close(fd);
    return 0;
}

int handle_input_redirection(const char *filename)
{
    char *clean_filename = strip_quotes((char *)filename);
    int fd = open(clean_filename, O_RDONLY);

    if (fd == -1) {
        my_putstr_e(clean_filename);
        my_putstr_e(": No such file or directory.\n");
        return -1;
    }
    if (dup2(fd, STDIN_FILENO) == -1) {
        perror("dup2 error (stdin)");
        close(fd);
        return -1;
    }
    close(fd);
    return 0;
}

int apply_redirection(redirection_t *redir)
{
    if (!redir)
        return 0;
    if (my_strcmp(redir->type, ">") == 0)
        return handle_output_redirection(redir->filename,
            O_WRONLY | O_CREAT | O_TRUNC);
    if (my_strcmp(redir->type, ">>") == 0)
        return handle_output_redirection(redir->filename,
            O_WRONLY | O_CREAT | O_APPEND);
    if (my_strcmp(redir->type, "<") == 0)
        return handle_input_redirection(redir->filename);
    if (my_strcmp(redir->type, "<<") == 0)
        return handle_heredoc(redir->filename);
    return 0;
}

int apply_redirections(redirection_t *redirs)
{
    for (redirection_t *cur = redirs; cur; cur = cur->next) {
        if (apply_redirection(cur) != 0)
            return -1;
    }
    return 0;
}
