/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:23:20 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/01/15 20:05:48 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	d;
	size_t	s;

	index = 0;
	if ((!dst || !src) && dstsize == 0)
		return (ft_strlen(src));
	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (d >= dstsize)
		d = dstsize;
	if (dst == 0 || dstsize == d)
		return (d + s);
	else
	{
		while (d + 1 + index < dstsize && src[index] != '\0')
		{
			dst[d + index] = src[index];
			index++;
		}
		dst[d + index] = '\0';
	}
	return (d + s);
}
