/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:37:48 by nsueiro-          #+#    #+#             */
/*   Updated: 2024/11/20 16:37:58 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	char	*d;

	d = dest;
	while (*d != '\0')
	{
		d++;
	}
	while (*src != '\0')
	{
		*d = *src;
		d++;
		src++;
	}
	*d = '\0';
	return (dest);
}
/*
int main()
{
	char dest[100] = "Hello, ";
	char src[] = "world!";ft_strcat(dest, src);
	
	printf("Cadena resultante: %s\n", dest);
	return 0;
}
*/