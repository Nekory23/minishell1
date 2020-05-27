# minishell1

{EPITECH} | First year | Unix System programming project

You have to program a UNIX command interpreter.
The interpreter is expected to display a prompt ( $> , for example) and then wait for you to write a command
line, which must be validated by a newline.

The prompt must be displayed again only after the command execution.
Only basic command lines are expected to executed; no pipes, redirections or any other advanced features.
The executables should be those found in the path, as indicated in the PATH variable.

If the executable cannot be found, you must display an error message and display the prompt again.
Errors must be dealt with and must display the appropriate message on the error output.

You must correctly handle the PATH and the environment (by copying and restoring the initial env).
You must implement the following builtins: cd, setenv, unsetenv, env, exit.

See the subject for further details !

========================

1st semester Unix System programming (part II) unit

Grade : C | Mark : 1.5

Score : 21.6%

  - Basic tests : 40% --- 2/5
  - Path handling : 80% --- 4/5
  - Path handling eval : 100% --- 5/5
  - Setenv and unsetenv : 0% --- 0/2 (/!\ 2 crashed)
  - Setenv and unsetenv eval : 0% --- 0/2 (/!\ 2 crashed)
  - Builtin cd : 0% --- 0/3
  - Builtin cd eval : 0% --- 0/3
  - Line formatting (space and tabs) : 0% --- 0/8 (/!\ 1 crashed)
  - Line formatting (space and tabs) eval : 0% --- 0/8 (/!\ 2 crashed)
  - Error handling : 0% --- 0/5
  - Error handling : 0% --- 0/5

Beware of -42 Epitech students !!!
