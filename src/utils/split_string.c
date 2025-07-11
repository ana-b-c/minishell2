/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** split_string.c
*/
#include "minishell.h"

/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** strip_quotes.c (safe malloc version)
*/
#include "minishell.h"

static int is_wrapped_in_quotes(const char *str, int len)
{
    return (len >= 2 &&
        ((str[0] == '"' && str[len - 1] == '"') ||
        (str[0] == '\'' && str[len - 1] == '\'')));
}

static void calculate_bounds(const char *str, int len, int *start, int *end)
{
    if (is_wrapped_in_quotes(str, len)) {
        *start = 1;
        *end = len - 1;
    } else {
        *start = 0;
        *end = len;
    }
}

static char *copy_substring(const char *str, int start, int end)
{
    char *new_str = malloc(end - start + 1);
    int i;

    if (!new_str)
        return NULL;
    i = 0;
    while (start < end) {
        new_str[i] = str[start];
        new_str[i + 1] = '\0';
        i++;
        start++;
    }
    return new_str;
}

char *strip_quotes(char *str)
{
    int len;
    int start;
    int end;

    if (!str)
        return NULL;
    len = my_strlen(str);
    calculate_bounds(str, len, &start, &end);
    return copy_substring(str, start, end);
}

char **split_string(char *str, char *delimiter)
{
    char **result = malloc(sizeof(char *) * 10);
    int i;
    char *token;

    if (!result)
        return NULL;
    i = 0;
    token = strtok(str, delimiter);
    while (token) {
        result[i] = my_strdup(strip_quotes(token));
        i = i + 1;
        token = strtok(NULL, delimiter);
    }
    result[i] = NULL;
    return result;
}

char **tokenize_input_string(char *input_copy, char *delimiter, char **result)
{
    char *token;
    int i = 0;
    char *trimmed;

    token = strtok(input_copy, delimiter);
    while (token) {
        trimmed = trim_whitespace(token);
        result[i] = my_strdup(trimmed);
        i++;
        token = strtok(NULL, delimiter);
    }
    result[i] = NULL;
    return result;
}

char **split_by_delimiter(char *str, char *delimiter)
{
    char **result = malloc(sizeof(char *) * 100);
    char *input_copy;

    if (!result) {
        return NULL;
    }
    input_copy = my_strdup(str);
    if (!input_copy) {
        free(result);
        return NULL;
    }
    result = tokenize_input_string(input_copy, delimiter, result);
    free(input_copy);
    return result;
}
