/*
** EPITECH PROJECT, 2024
** my_strlen
** File description:
** strlen
*/
#include "minishell.h"

int my_strlen(char const *str)
{
    int length = 0;

    while (str[length] != '\0') {
    length++;
    }
    return length;
}
