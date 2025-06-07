/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:49:50 by mpico-bu          #+#    #+#             */
/*   Updated: 2025/06/07 21:47:00 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_command(const char *command)
{
	char	**args;

	args = ft_split(command, ' ');
	if (!args)
	{
		perror("malloc");
		exit(1);
	}
	return (args);
}

void	execute_child(const char *cmd, int input_fd, int output_fd)
{
	char	**args;
	char	*executable;

	if (input_fd != STDIN_FILENO)
		dup2(input_fd, STDIN_FILENO);
	if (output_fd != STDOUT_FILENO)
		dup2(output_fd, STDOUT_FILENO);
	args = split_command(cmd);
	if (!args || !args[0])
		exit(1);
	executable = find_executable(args[0]);
	if (!executable)
	{
		write(STDERR_FILENO, "command not found\n", 18);
		free_array2(args);
		exit(127);
	}
	execve(executable, args, environ);
	perror("execve");
	free(executable);
	free_array2(args);
	exit(127);
}

pid_t	create_child(const char *cmd, int in_fd, int out_fd, int close_fd)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		close(close_fd);
		execute_child(cmd, in_fd, out_fd);
	}
	return (pid);
}
void	free_array2(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
