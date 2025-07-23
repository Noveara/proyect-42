/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:23:20 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/07/02 18:11:49 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < dsize && dst[i])
		i++;
	if (i == dsize)
	{
		while (src[j])
			j++;
		return (dsize + j);
	}
	while (src[j] && (i + j) < dsize -1)
	{
		dst[i + j] = src[j];
		j++;
	}
	if ((i + j) < dsize)
		dst[i + j] = '\0';
	while (src[j])
		j++;
	return (i + j);
}
