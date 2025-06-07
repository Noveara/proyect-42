/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 14:57:11 by noa               #+#    #+#             */
/*   Updated: 2025/06/07 21:48:24 by noa              ###   ########.fr       */
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

extern char **environ;

char	*get_path_env(void);
char	*join_path(const char *dir, const char *command);
char	*find_executable(char *command);
char	**split_command(const char *command);
void	execute_child(const char *cmd, int input_fd, int output_fd);
pid_t	create_child(const char *cmd, int in_fd, int out_fd, int close_fd);
void	free_array2(char **array);

#endif

