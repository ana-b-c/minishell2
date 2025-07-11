/*
** EPITECH PROJECT, 2025
** utils.c
** File description:
** helper functions
*/
#include "minishell.h"

int is_valid_env_var(const char *key)
{
    if (!key || !((key[0] >= 'A' && key[0] <= 'Z')
        || (key[0] >= 'a' && key[0] <= 'z'))) {
        my_putstr_e("setenv: Variable name must begin with a letter.\n");
        return 0;
    }
    for (int i = 1; key[i]; i++) {
        if (!((key[i] >= 'A' && key[i] <= 'Z')
            || (key[i] >= 'a' && key[i] <= 'z')
            || (key[i] >= '0' && key[i] <= '9'))) {
            my_putstr_e("setenv: Variable name must contain "
                "alphanumeric characters.\n");
            return 0;
        }
    }
    return 1;
}
