/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:22:13 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/07/02 17:42:24 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
	}
	while (src[i])
		i++;
	return (i);
}
/*
int	main(void)
{
	char src[] = "Hello, World";

	char dst1[15];
	char dst2[15]

	size_t n;

	n = ft_strlcpy(dst1, src, 14);
	printf("Mi strlcpy:	%zu cadena: %s\n", n, dst1);
	n = strlcpy(dst2, src, 14);
	printf("strlcpy : %zu cadena: %s", n, dst2);
	return (0);
}*/
