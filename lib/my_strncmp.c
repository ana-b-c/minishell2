/*
** EPITECH PROJECT, 2025
** my_strncmp
** File description:
** lib
*/
#include "minishell.h"


int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (i < n && s1[i] && s1[i] == s2[i]) {
        i++;
    }
    if (i == n) {
        return 0;
    }
    return s1[i] - s2[i];
}
