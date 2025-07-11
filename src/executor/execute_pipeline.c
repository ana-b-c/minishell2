/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** execute_pipeline.c
*/
#include "minishell.h"

static void close_unused_pipes(int pipes[][2], int pipe_count, int exclude_fd)
{
    for (int i = 0; i < pipe_count; i++) {
        if (pipes[i][0] != exclude_fd && pipes[i][0] != -1)
            close(pipes[i][0]);
        if (pipes[i][1] != exclude_fd && pipes[i][1] != -1)
            close(pipes[i][1]);
    }
}

static void setup_child_pipes(int pipes[][2], int cmd_index, int pipe_count)
{
    if (cmd_index > 0) {
        dup2(pipes[cmd_index - 1][0], STDIN_FILENO);
        close(pipes[cmd_index - 1][0]);
    }
    if (cmd_index < pipe_count) {
        dup2(pipes[cmd_index][1], STDOUT_FILENO);
        close(pipes[cmd_index][1]);
    }
    close_unused_pipes(pipes, pipe_count, -1);
}

static int fork_and_execute_commands(int pipes[][2],
    pid_t pids[], pipeline_t *pipeline, char ***env)
{
    int status;

    for (int i = 0; i < pipeline->count; i++) {
        pids[i] = fork();
        if (pids[i] == -1) {
            perror("fork error");
            return 1;
        }
        if (pids[i] == 0) {
            setup_child_pipes(pipes, i, pipeline->count - 1);
            status = execute_simple_command_with_redir(pipeline->commands[i],
                env);
            exit(status);
        }
    }
    return 0;
}

static void wait_for_children(pid_t pids[], int count, int *status)
{
    int tmp_status;

    for (int i = 0; i < count; i++) {
        waitpid(pids[i], &tmp_status, 0);
        if (WIFSIGNALED(tmp_status)) {
            handle_signal_error(tmp_status);
        }
        if (i == count - 1)
            *status = tmp_status;
    }
}

int execute_pipeline(pipeline_t *pipeline, char ***env)
{
    int pipes[pipeline->count - 1][2];
    pid_t pids[pipeline->count];
    int status = 0;

    for (int i = 0; i < pipeline->count - 1; i++) {
        if (pipe(pipes[i]) == -1) {
            perror("pipe error");
            return 1;
        }
    }
    if (fork_and_execute_commands(pipes, pids, pipeline, env) != 0)
        return 1;
    close_unused_pipes(pipes, pipeline->count - 1, -1);
    wait_for_children(pids, pipeline->count, &status);
    return WEXITSTATUS(status);
}
