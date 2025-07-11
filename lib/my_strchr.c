/*
** EPITECH PROJECT, 2025
** str to chr
** File description:
** lib.c
*/
#include "minishell.h"

char *my_strchr(char const *str, int c)
{
    while (*str) {
        if (*str == c)
            return (char *)str;
        str++;
    }
    return NULL;
}
