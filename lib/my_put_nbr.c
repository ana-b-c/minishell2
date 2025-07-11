/*
** EPITECH PROJECT, 2025
** my_put_nbr
** File description:
** lib
*/
#include "minishell.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb == 0) {
        my_putchar('0');
        return 0;
    }
    if (nb / 10 != 0) {
        my_put_nbr(nb / 10);
    }
    my_putchar((nb % 10) + '0');
    return 0;
}
