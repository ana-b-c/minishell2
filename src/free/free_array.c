/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** free_array.c
*/
#include "minishell.h"

void free_array(char **array)
{
    int i = 0;

    if (!array)
        return;
    while (array[i]) {
        free(array[i]);
        i++;
    }
    free(array);
}
