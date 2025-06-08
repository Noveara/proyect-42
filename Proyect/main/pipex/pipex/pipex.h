/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:57:11 by noa               #+#    #+#             */
/*   Updated: 2025/06/08 14:04:49 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

# define ERR_ARGC "Invalid number of arguments"
# define ERR_PIPE "Failed to open pipe"
# define ERR_FORK "Failed to forking"
# define ERR_CMD "Command not found"

typedef struct s_data
{
	int		src_fd;
	int		dst_fd;
	int		pipe_fd[2];
	char	**paths;
	char	**cmd_args;
	char	*cmd;
	pid_t	pid;

}			t_data;

void		child(t_data *d, char **argv, char **envp);
void		parent(t_data *d, int argc, char **argv, char **envp);
int			main(int argc, char **argv, char **envp);
void		err_msg(char *err_msg);
char	*find_path(char **envp);
char	*get_cmd(char **paths, char *cmd);
void		exec(t_data *d, char *cmd, char **envp);
void		ft_memfree_all(char **arr);
void		ft_memfree(void *ptr);

#endif

