/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:24:47 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/07/09 18:52:28 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_handler(int n_exit)
{
	if (n_exit == 1)
		ft_putstr_fd("Usage: ./pipex infile cmd1 cmd2 outfile\n", 2);
	exit(n_exit);
}

int	open_file(char *file, int in_or_out)
{
	int	ret;

	if (in_or_out == 0)
		ret = open(file, O_RDONLY);
	else
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ret == -1)
	{
		perror(file);
		return (-1);
	}
	return (ret);
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	*my_getenv(char *name, char **env)
{
	int		i;
	char	*sub;
	int		j;

	j = 0;
	if (!name || !env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (sub && ft_strncmp(sub, name, ft_strlen(name)) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

static char	**get_path_dirs(char **env)
{
	char	*path_env;

	path_env = my_getenv("PATH", env);
	if (!path_env)
		return (NULL);
	return (ft_split(path_env, ':'));
}
