/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:21:09 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/07/02 18:37:04 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (src == NULL && dest == NULL)
		return (dest);
	if (dest > src)
	{
		i = n;
		while (i != 0)
		{
			((char *)dest)[i - 1] = ((char *)src)[i];
			i--;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
/*
int	main(void)
{
	char buffer[] = "0123456789101112";
	char *source = buffer;
	char *destination = buffer + 1;

	printf("Source original: %s\n", source);
	printf("Destino original: %s\n", destination);
	memmove(destination, source, 13);
	printf("Standard memmove: %s\n", buffer);

	strcpy(buffer, "0123456789101112");
	source = buffer;
	destination = buffer + 1;

	ft_memmove(destination, source, 13);
	printf("Your ft_memmove: %s\n", buffer);

	return (0);
}*/
