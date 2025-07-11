/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** execute_simple_command.c
*/
#include "minishell.h"

static int is_valid_command(simple_command_t *cmd)
{
    return cmd && cmd->args && cmd->args[0];
}

int find_and_check_executable(simple_command_t *cmd, char **env)
{
    cmd->args[0] = find_executable(cmd->args[0], env);
    return check_command_exists(cmd->args[0], env);
}

int execute_child_process(simple_command_t *cmd, char **env)
{
    execve(cmd->args[0], cmd->args, env);
    perror(cmd->args[0]);
    exit(EXIT_FAILURE);
}

int execute_parent_process(pid_t pid)
{
    int status;

    waitpid(pid, &status, 0);
    if (WIFSIGNALED(status)) {
        handle_signal_error(status);
    }
    return WEXITSTATUS(status);
}

int execute_command(simple_command_t *cmd, char **env)
{
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork error");
        return 1;
    }
    if (pid == 0) {
        return execute_child_process(cmd, env);
    } else {
        return execute_parent_process(pid);
    }
}

int execute_simple_command(simple_command_t *cmd, char ***env)
{
    if (!is_valid_command(cmd)) {
        return 0;
    }
    for (int i = 0; cmd->args[i]; i++) {
        cmd->args[i] = strip_quotes(cmd->args[i]);
    }
    if (handle_builtin(cmd->args, env)) {
        return 0;
    }
    if (!find_and_check_executable(cmd, *env)) {
        return 1;
    }
    return execute_command(cmd, *env);
}
