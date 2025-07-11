/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** my_putstr_error.c
*/
#include "minishell.h"

int my_putstr_e(char const *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;
    return write(2, str, len);
}
