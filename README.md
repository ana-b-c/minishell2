# minishell2
program a part of UNIX command interpreter based on TCSH

Authorized functions: malloc, free, exit, opendir, readdir, closedir, getcwd, chdir, fork, stat,
lstat, fstat, open, close, getline, strtok, strtok_r, read, write, execve, access, isatty, wait, waitpid, wait3, wait4, signal, kill, getpid, strerror, perror, strsignal, pipe, dup, dup2

# Goal

. Display a prompt ($> for example) and then wait for you to write a
command line, which must be validated by a newline.
The prompt must be displayed again only after the command execution.

. Implement the builtins: cd, setenv, unsetenv, env, exit.
env builtin must not take any argument and unsetenv builtin must not support the
“*” wildcard.

. Add semicolons (‘;’), pipes (‘|’),
and the four redirections (‘>’, ‘<’, ‘>>’, ‘<<’) management.

# Error case

. If the command cannot be found, you must display an error message and display the prompt
again.
Errors must be dealt with and must display the appropriate message on the error output

.Error output, standard input and standard output redirections will be considered as bonuses.
Such as 2>&1
