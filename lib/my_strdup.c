/*
** EPITECH PROJECT, 2025
** my_strdup
** File description:
** .c
*/
#include "minishell.h"

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *dup = malloc(sizeof(char) * (len + 1));

    if (!dup)
        return NULL;
    my_strcpy(dup, src);
    return dup;
}
