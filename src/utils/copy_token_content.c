/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** copy_token_content.c
*/
#include "minishell.h"

static int is_quote_char(char c)
{
    return (c == '"' || c == '\'');
}

static void handle_opening_quote(char c, int *in_quote, char *quote_char)
{
    *in_quote = 1;
    *quote_char = c;
}

static void handle_closing_quote(char c, int *in_quote, char *quote_char)
{
    if (*in_quote && c == *quote_char) {
        *in_quote = 0;
        *quote_char = '\0';
    }
}

static void copy_character(char *dest, int *index, char src)
{
    dest[*index] = src;
    (*index)++;
}

void copy_token_content(char *token, const char *start, int len)
{
    int i = 0;
    int in_quote = 0;
    char quote_char = '\0';

    while (*start && i < len) {
        if (is_quote_char(*start) && !in_quote) {
            handle_opening_quote(*start, &in_quote, &quote_char);
            start++;
            continue;
        }
        if (in_quote && *start == quote_char) {
            handle_closing_quote(*start, &in_quote, &quote_char);
            start++;
            continue;
        }
        copy_character(token, &i, *start);
        start++;
    }
    token[i] = '\0';
}
