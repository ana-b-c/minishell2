/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** handle_heredoc.c
*/
#include "minishell.h"

static void read_heredoc_input(int fd, const char *delimiter)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while (1) {
        my_putstr("heredoc> ");
        read = getline(&line, &len, stdin);
        if (read == -1)
            break;
        line[read - 1] = '\0';
        if (my_strcmp(line, delimiter) == 0)
            break;
        write(fd, line, my_strlen(line));
        write(fd, "\n", 1);
    }
    free(line);
}

int handle_heredoc(char *raw_delimiter)
{
    int pipefd[2];
    char *delimiter = strip_quotes(raw_delimiter);

    if (pipe(pipefd) == -1) {
        perror("heredoc pipe error");
        return -1;
    }
    read_heredoc_input(pipefd[1], delimiter);
    close(pipefd[1]);
    if (dup2(pipefd[0], STDIN_FILENO) == -1) {
        perror("dup2 error in heredoc");
        close(pipefd[0]);
        return -1;
    }
    close(pipefd[0]);
    return 0;
}
