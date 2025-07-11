/*
** EPITECH PROJECT, 2025
** my_strcspn.c
** File description:
** .c
*/
#include "minishell.h"
#include <stdbool.h>

static bool is_char_in_reject(char c, const char *reject)
{
    for (int j = 0; reject[j] != '\0'; j++) {
        if (c == reject[j]) {
            return true;
        }
    }
    return false;
}

int my_strcspn(const char *str, const char *reject)
{
    int i = 0;

    while (str[i] != '\0') {
        if (is_char_in_reject(str[i], reject)) {
            return i;
        }
        i++;
    }
    return i;
}
