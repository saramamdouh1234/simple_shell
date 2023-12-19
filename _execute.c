#include "shell.h"
/**
* mypart - a part of code.
* @firstcmd: Pointer to a character string.
* @command: input2
* @fullpath: input2
* @argv: input2
* @envp: input2
* @counter: input2
* @tokens: input2
* Return: 0 or 1.
*/
int mypart(char *firstcmd, char *command, char *fullpath,
	char **argv, char **envp, int counter, char *tokens)
{
	pid_t pid;
	char *toks, *args[1024];
	int exitcode, x = 0, staus;

	if (fullpath == NULL)
	{
		print_not_found(argv[0], counter, tokens);
		free(firstcmd);
		return (127);
	}
	free(firstcmd);
	pid = fork();
	if (pid == -1)
		exit(1);
	else if (pid == 0)
	{
		toks = strtok((char *)command, " ");
		while (toks != NULL)
		{
			args[x++] = toks;
			toks = strtok(NULL, " ");
		}
		args[0] = fullpath;
		args[x] = NULL;
		exitcode = execve(args[0], args, envp);
		if (exitcode == -1)
		{
			free(fullpath);
			perror(argv[0]);
			exit(exitcode);
		}
	}
	else
	{
		free(fullpath);
		wait(&staus);
	}
	return (staus);
}

/**
* execute_command - a part of code.
* @command: Pointer to a character string.
* @argv: input2
* @envp: input2
* @lasterorr: input2
* @counter: input2
* Return: 0 or 1.
*/
int execute_command(char *command, char **argv, char **envp,
int lasterorr, int counter)
{
	int exit_code = 0;
	char *fullpath = NULL, *firstcmd = NULL, *tokens;

	firstcmd = duplicate_str(command);
	tokens = strtok(firstcmd, " ");
	if (tokens == 0)
	{
		free(firstcmd);
		return (lasterorr);
	}
	exit_code = is_exit(tokens, strtok(NULL, " "), lasterorr,
	command, argv[0], counter);
	if (exit_code)
	{
		lasterorr = 2;
		free(firstcmd);
		return (lasterorr);
	}
	if (tokens[0] != '/' && tokens[0] != '.')
		fullpath = is_in_path(tokens, envp);
	else
	{
		fullpath = duplicate_str(tokens);
		if (access(fullpath, X_OK) != 0)
		{
			print_not_found(argv[0], counter, tokens);
			free(fullpath);
			free(firstcmd);
			return (127);
		}
	}
	return (mypart(firstcmd, command, fullpath, argv, envp, counter, tokens));
}
