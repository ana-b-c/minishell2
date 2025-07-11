/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** calculate_token_length.c
*/
#include "minishell.h"

static int is_whitespace(char c)
{
    return c == ' ' || c == '\t';
}

static int is_quote(char c)
{
    return c == '"' || c == '\'';
}

static void handle_opening_quote(char c, int *in_quote, char *quote_char)
{
    *in_quote = 1;
    *quote_char = c;
}

static void handle_closing_quote(char c, int *in_quote, char *quote_char)
{
    if (c == *quote_char && *in_quote) {
        *in_quote = 0;
        *quote_char = '\0';
    }
}

int calculate_token_length(const char **str, int *in_quote, char *quote_char)
{
    const char *s = *str;
    int len = 0;

    while (*s && (*in_quote || !is_whitespace(*s))) {
        if (is_quote(*s) && !*in_quote) {
            handle_opening_quote(*s, in_quote, quote_char);
            s++;
            continue;
        }
        handle_closing_quote(*s, in_quote, quote_char);
        if (!*in_quote && *s == *quote_char) {
            s++;
            continue;
        }
        len++;
        s++;
    }
    *str = s;
    return len;
}
