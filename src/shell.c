/*
** EPITECH PROJECT, 2025
** shell.c
** File description:
** core shell loop
*/
/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** shell.c (fixed to track last_status)
*/
#include "minishell.h"

static void handle_eof(char *input, char **env, int last_status)
{
    my_putstr("\nExiting shell...\n");
    free(input);
    free_env(env);
    exit(last_status);
}

static void sanitize_input(char *input)
{
    input[my_strcspn(input, "\n")] = '\0';
}

static void handle_sigint(int sig)
{
    (void)sig;
    my_putstr("\n$> ");
}

char **setup_environment(char **envp)
{
    char **env = copy_env(envp);

    if (!env) {
        perror("Failed to copy environment");
        exit(84);
    }
    return env;
}

ssize_t read_input(char **input, size_t *len)
{
    if (isatty(STDIN_FILENO))
        my_putstr("$> ");
    return getline(input, len, stdin);
}

int process_input(char *input, char ***env)
{
    command_t *cmd_list;
    int status = 0;

    sanitize_input(input);
    if (my_strlen(input) > 0) {
        cmd_list = parse_input(input);
        status = execute_commands(cmd_list, env);
        free_command_list(cmd_list);
    }
    return status;
}

int shell_loop(char **envp)
{
    char *input = NULL;
    size_t len = 0;
    ssize_t read_status;
    char **env = setup_environment(envp);
    int last_status = 0;

    signal(SIGINT, handle_sigint);
    while (1) {
        read_status = read_input(&input, &len);
        if (read_status == -1)
            handle_eof(input, env, last_status);
        last_status = process_input(input, &env);
    }
    return last_status;
}
