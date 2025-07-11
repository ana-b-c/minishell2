/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** split_args_respecting_quotes.c
*/
#include "minishell.h"

static void handle_quotes(char ch, int *in_quote, char *quote_char)
{
    if ((ch == '"' || ch == '\'') && (*quote_char == '\0')) {
        *in_quote = 1;
        *quote_char = ch;
    } else if (ch == *quote_char && *in_quote) {
        *in_quote = 0;
        *quote_char = '\0';
    }
}

static void skip_whitespace(const char **str)
{
    while (**str && (**str == ' ' || **str == '\t'))
        (*str)++;
}

static void process_argument(const char **str, int *in_quote, char *quote_char)
{
    while (**str && (*in_quote || (**str != ' ' && **str != '\t'))) {
        handle_quotes(**str, in_quote, quote_char);
        (*str)++;
    }
}

int count_args(const char *str)
{
    int count = 0;
    int in_quote = 0;
    char quote_char = '\0';

    while (*str) {
        skip_whitespace(&str);
        if (!*str)
            break;
        count++;
        process_argument(&str, &in_quote, &quote_char);
    }
    return count;
}

char *extract_token(const char **str)
{
    const char *s = *str;
    char *token;
    int in_quote = 0;
    char quote_char = '\0';
    int len = 0;
    const char *start;

    skip_whitespace(&s);
    start = s;
    len = calculate_token_length(&s, &in_quote, &quote_char);
    token = malloc(len + 1);
    if (!token)
        return NULL;
    copy_token_content(token, start, len);
    *str = s;
    return token;
}

static void cleanup_args(char **args, int count)
{
    if (count < 0)
        return;
    for (int i = 0; i < count; i++)
        free(args[i]);
    free(args);
}

char **split_args_respecting_quotes(const char *str)
{
    int count = count_args(str);
    char **args = malloc(sizeof(char *) * (count + 1));
    int i = 0;
    char *token;

    if (!args)
        return NULL;
    while (*str && i < count) {
        skip_whitespace(&str);
        if (!*str)
            break;
        token = extract_token(&str);
        if (!token) {
            cleanup_args(args, i);
            return NULL;
        }
        args[i++] = token;
    }
    args[i] = NULL;
    return args;
}
