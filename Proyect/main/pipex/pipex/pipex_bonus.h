/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 12:42:34 by noa               #+#    #+#             */
/*   Updated: 2025/06/08 12:44:12 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft/libft.h"
# include <errno.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/wait.h>

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
	int		i;
	char	*str;

}			t_data;
void		err_msg(char *err_msg);
void		exec(t_data *d, char *cmd, char **envp);
int			open_fd(char *file, int n);

#endif