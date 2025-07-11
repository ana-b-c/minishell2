/*
** EPITECH PROJECT, 2025
** minishell.h
** File description:
** header file
*/
#ifndef MINISHELL_H
    #define MINISHELL_H

    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <sys/wait.h>
    #include <string.h>
    #include <sys/stat.h>
    #include <signal.h>
    #include <sys/stat.h>
    #include "structure.h"
    #include <fcntl.h>

int shell_loop(char **envp);
int handle_builtin(char **args, char ***env);
int handle_cd(char **args, char ***env);

void set_env(char *key, char *value, char ***env);
void unset_env(char *key, char ***env);
void print_env(char **env);
char **copy_env(char **envp);
void free_env(char **env);
char *get_env(char *name, char **env);

char *find_executable(char *command, char **env);
int check_command_exists(char *command, char **env);
int execute_commands(command_t *cmd_list, char ***env);
int execute_pipeline(pipeline_t *pipeline, char ***env);
int execute_simple_command_with_redir(simple_command_t *cmd, char ***env);
int apply_redirections(redirection_t *redirections);
int handle_heredoc(char *raw_delimiter);
int execute_simple_command(simple_command_t *cmd, char ***env);

int handle_unsetenv_errors(char **args);
int handle_setenv_errors(char **args);
int handle_cd_errors(char **args);
void handle_signal_error(int status);

void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strdup(char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
int my_strcspn(char const *str, char const *reject);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strchr(char const *str, int c);
int my_putstr_e(char const *str);

command_t *parse_input(char *input);
command_t *parse_command_group(char *command_str);
pipeline_t *create_pipeline(char **segments);
simple_command_t *parse_simple_command(char *cmd_str);
void parse_redirections(char *cmd_str, simple_command_t *cmd);

int is_redirection(char *token);
void add_redirection(simple_command_t *cmd, char *type, char *filename);
int is_valid_env_var(const char *key);
char *strip_quotes(char *str);
char **split_string(char *str, char *delimiter);
char **split_by_delimiter(char *str, char *delimiter);
char *trim_whitespace(char *str);
void close_all_pipes(int pipes[][2], int count);
char **split_args_respecting_quotes(const char *str);
int calculate_token_length(const char **str, int *in_quote, char *quote_char);
void copy_token_content(char *token, const char *start, int len);

void free_simple_command(simple_command_t *cmd);
void free_pipeline(pipeline_t *pipeline);
void free_command(command_t *cmd);
void free_command_list(command_t *cmd_list);
void free_redirection(redirection_t *redir);
void free_redirections_list(redirection_t *redir);
void free_array(char **array);

#endif /* MINISHELL_H */
