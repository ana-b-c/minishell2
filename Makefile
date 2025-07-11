##
## EPITECH PROJECT, 2025
## make
## File description:
## file
##
CC	=	gcc

CFLAGS	=	-Wall -Wextra -Werror -Iinclude

SRC	=	lib/my_putchar.c\
		lib/my_strcat.c\
		lib/my_strcpy.c\
		lib/my_strlen.c\
		lib/my_putstr.c\
		lib/my_strcmp.c\
		lib/my_strdup.c\
		lib/my_strcspn.c\
		lib/my_put_nbr.c\
		lib/my_strncmp.c\
		lib/my_strchr.c\
		lib/my_putstr_error.c\
		src/main.c\
		src/shell.c\
		src/builtins.c\
		src/cd.c\
		src/env/copy_env.c\
		src/env/free_env.c\
		src/env/print_env.c\
		src/env/set_env.c\
		src/env/get_env.c\
		src/env/unset_env.c\
		src/executor/execute_pipeline.c\
		src/executor/executor.c\
		src/executor/find_executable.c\
		src/executor/apply_redirections.c\
		src/executor/execute_simple_command_with_redir.c\
		src/executor/execute_simple_command.c\
		src/executor/handle_heredoc.c\
		src/executor/check_command_exists.c\
		src/error/setenv_errors.c\
		src/error/unsetenv_errors.c\
		src/error/cd_errors.c\
		src/error/segfault.c\
		src/parser/create_pipeline.c\
		src/parser/parse_command_group.c\
		src/parser/parse_input.c\
		src/parser/parse_redirections.c\
		src/parser/parse_simple_command.c\
		src/free/command.c\
		src/free/redirection.c\
		src/free/free_array.c\
		src/utils/is_redirection.c\
		src/utils/split_string.c\
		src/utils/valid_env_var.c\
		src/utils/close_all_pipes.c\
		src/utils/whitespace.c\
		src/utils/split_args_respecting_quotes.c\
		src/utils/calculate_token_length.c\
		src/utils/copy_token_content.c\

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
