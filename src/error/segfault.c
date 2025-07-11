/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** segfault.c
*/
#include "minishell.h"

void print_signal_name(int signal_num)
{
    if (signal_num == SIGSEGV) {
        my_putstr_e("Segmentation fault");
    } else if (signal_num == SIGFPE) {
        my_putstr_e("Floating exception");
    }
}

void print_core_dump_info(int status)
{
    if (WCOREDUMP(status)) {
        my_putstr_e(" (core dumped)");
    }
    my_putchar('\n');
}

void handle_signal_error(int status)
{
    int signal_num;

    if (WIFSIGNALED(status)) {
        signal_num = WTERMSIG(status);
        if (signal_num == SIGSEGV || signal_num == SIGFPE) {
            print_signal_name(signal_num);
            print_core_dump_info(status);
        }
    }
}
