/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** close_all_pipes.c
*/
#include "minishell.h"

void close_all_pipes(int pipes[][2], int count)
{
    for (int i = 0; i < count; i++) {
        close(pipes[i][0]);
        close(pipes[i][1]);
    }
}
