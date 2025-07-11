/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** parse_redirections.c
*/
#include "minishell.h"

static void handle_redirection(char *redir_type, simple_command_t *cmd)
{
    char *redir_file = strtok(NULL, " \t");

    if (!redir_file) {
        my_putstr_e("Missing name for redirect\n");
        return;
    }
    add_redirection(cmd, redir_type, redir_file);
}

static void build_cmd_without_redir(char *token,
    char *cmd_without_redir, int *cmd_len)
{
    my_strcat(cmd_without_redir, token);
    my_strcat(cmd_without_redir, " ");
    *cmd_len += my_strlen(token) + 1;
}

void parse_redirections(char *cmd_str, simple_command_t *cmd)
{
    char *token;
    char *remainder = my_strdup(cmd_str);
    char *cmd_without_redir = malloc(my_strlen(cmd_str) * 2 + 1);
    int cmd_len = 0;

    cmd_without_redir[0] = '\0';
    token = strtok(remainder, " \t");
    while (token) {
        if (is_redirection(token)) {
            handle_redirection(token, cmd);
            token = strtok(NULL, " \t");
            continue;
        }
        build_cmd_without_redir(token, cmd_without_redir, &cmd_len);
        token = strtok(NULL, " \t");
    }
    if (cmd_len > 0)
        cmd_without_redir[cmd_len - 1] = '\0';
    cmd->args = split_args_respecting_quotes(cmd_without_redir);
    free(remainder);
    free(cmd_without_redir);
}
