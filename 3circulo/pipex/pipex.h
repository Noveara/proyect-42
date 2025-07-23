/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:07:47 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/07/09 18:27:25 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>
# include "libft/libft.h"

void	exec(char *cmd, char **env);
void	child(char **av, int *p_fd, char **env);
void	parent(char **av, int *p_fd, char **env);
char	*build_and_check(char *dir, char *cmd);
int		main(int ac, char **av, char **env);
void	exit_handler(int n_exit);
int		open_file(char *file, int in_or_out);
void	ft_free_tab(char **tab);
char	*my_getenv(char *name, char **env);
char	*get_path(char *cmd, char **env);

#endif
