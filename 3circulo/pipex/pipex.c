/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:51:40 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/07/09 18:55:19 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(char *cmd, char **env)
{
	char	**s;
	char	*path;

	s = ft_split(cmd, ' ');
	if (!s || !s[0] || !ft_strlen(s[0]))
	{
		ft_putstr_fd("pipex: command not found\n", 2);
		exit(127);
	}
	*path = get_path(s[0], env);
	if (!path || execve(path, s, env) == -1)
	{
		ft_putstr_fd("pipex: command not found\n", 2);
		exit(127);
	}
}

void	proc(char **av, int *p_fd, char **env, int is_child)
{
	int	fd;

	if (is_child == 1)
		fd = open_file(av[1], 0);
	else
		fd = open_file(av[4], 1);
	if (fd == -1)
		exit(1);
	if (is_child == 1)
	{
		dup2(fd, 0);
		dup2(p_fd[1], 1);
	}
	else
	{
		dup2(fd, 1);
		dup2(p_fd[0], 0);
	}
	close(fd);
	close(p_fd[0]);
	close(p_fd[1]);
	if (is_child == 1)
		exec_cmd(av[2], env);
	else
		exec_cmd(av[3], env);
}

char	*get_path(char *cmd, char **env)
{
	char	**allpath;
	char	*full_path;
	int		i;

	if (!cmd || !cmd[0])
		return (NULL);
	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	allpath = get_path_dirs(env);
	if (!allpath)
		return (NULL);
	i = 0;
	while (allpath[i])
	{
		full_path = build_and_check(allpath[i], cmd);
		if (full_path)
		{
			ft_free_tab(allpath);
			return (full_path);
		}
		i++;
	}
	ft_free_tab(allpath);
	return (NULL);
}

int	main(int ac, char **av, char **env)
{
	int		p[2];
	pid_t	pid;

	if (ac != 5)
	{
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
		exit(1);
	}
	if (pipe(p) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
		proc(av, p, env, 1);
	waitpid(pid, NULL, 0);
	proc(av, p, env, 0);
	return (0);
}
