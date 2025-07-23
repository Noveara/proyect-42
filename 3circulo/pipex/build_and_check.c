/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_and_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:48:38 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/07/09 18:49:09 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*build_and_check(char *dir, char *cmd)
{
	char	*path_part;
	char	*full_path;

	path_part = ft_strjoin(dir, "/");
	if (!path_part)
		return (NULL);
	full_path = ft_strjoin(path_part, cmd);
	free(path_part);
	if (!full_path)
		return (NULL);
	if (access(full_path, F_OK | X_OK) == 0)
		return (full_path);
	free(full_path);
	return (NULL);
}
