/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** whitespace.c
*/
#include "minishell.h"

static int my_isspace(int c)
{
    return (c == ' ' || c == '\t' || c == '\n' ||
            c == '\r' || c == '\f' || c == '\v');
}

char *trim_whitespace(char *str)
{
    char *end;

    while (my_isspace((unsigned char)*str))
        str++;
    if (*str == 0)
        return str;
    end = str + my_strlen(str) - 1;
    while (end > str && my_isspace((unsigned char)*end))
        end--;
    end[1] = '\0';
    return str;
}
