/*
** EPITECH PROJECT, 2024
** my_putstr
** File description:
** putstr
*/
#include "minishell.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
    my_putchar(str[i]);
    i++;
    }
    return 0;
}
