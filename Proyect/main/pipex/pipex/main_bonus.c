/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 12:45:58 by noa               #+#    #+#             */
/*   Updated: 2025/06/08 13:25:25 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	parent(t_data *d)
{
	waitpid(d->pid, NULL, 0);
	close(d->pipe_fd[1]);
	dup2(d->pipe_fd[0], STDIN_FILENO);
	close(d->pipe_fd[0]);
}

void	children(t_data *d, char *cmd, char **envp)
{
	if (pipe(d->pipe_fd) < 0)
		err_msg(ERR_PIPE);
	d->pid = fork();
	if (d->pid < 0)
		err_msg(ERR_FORK);
	else if (d->pid == 0)
	{
		close(d->pipe_fd[0]);
		dup2(d->pipe_fd[1], STDOUT_FILENO);
		close(d->pipe_fd[1]);
		exec(d, cmd, envp);
	}
	else
		close(d->pipe_fd[1]);
		parent(d);
}

static void	write_heredoc_lines(t_data *d, char *limiter)
{
	while (1)
	{
		ft_putstr_fd("heredoc> ", 1);
		d->str = get_next_line(0);
		if (!d->str)
			break ;
		if (d->str && ft_strlen(d->str) > 0 && d->str[ft_strlen(d->str) - 1] == '\n')
    		d->str[ft_strlen(d->str) - 1] = '\0';
		if (ft_strncmp(d->str, limiter, ft_strlen(limiter)) == 0
			&& ft_strlen(d->str) == ft_strlen(limiter))
		{
			free(d->str);
			break ;
		}
		ft_putstr_fd(d->str, d->pipe_fd[1]);
		ft_putstr_fd("\n", d->pipe_fd[1]);
		free(d->str);
	}
	close(d->pipe_fd[1]);
	exit(EXIT_SUCCESS);
}

void	here_doc(t_data *d, char *limiter, int argc)
{
	if (argc < 6)
		err_msg(ERR_ARGC);
	if (pipe(d->pipe_fd) < 0)
		err_msg(ERR_PIPE);
	d->pid = fork();
	if (d->pid < 0)
		err_msg(ERR_FORK);
	if (d->pid == 0)
	{
		close(d->pipe_fd[0]);
		write_heredoc_lines(d, limiter);
	}
	parent(d);
}
int	main(int argc, char **argv, char **envp)
{
	t_data	d;

	d.str = NULL;
	if (argc < 5)
		err_msg(ERR_ARGC);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		d.i = 2;
		d.dst_fd = open_fd(argv[argc - 1], 3);
		here_doc(&d, argv[2], argc);
	}
	else
	{
		d.i = 1;
		d.src_fd = open_fd(argv[1], 1);
		d.dst_fd = open_fd(argv[argc - 1], 2);
		dup2(d.src_fd, STDIN_FILENO);
	}
	while (++d.i < argc - 2)
		children(&d, argv[d.i], envp);
	dup2(d.dst_fd, STDOUT_FILENO);
	exec(&d, argv[argc - 2], envp);
	return (0);
}
