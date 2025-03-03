/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:19:27 by nsueiro-          #+#    #+#             */
/*   Updated: 2024/11/20 15:55:49 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strcpy(char *dest, const char *src)
{
	char	*original_dest;

	original_dest = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (original_dest);
}
/*
int main()
{
	char src[] = "¡Hello, World!";
	char dest[50];

	ft_strcpy(dest, src);
	printf("String copied: %s\n", dest);
	return 0;
}
*/
