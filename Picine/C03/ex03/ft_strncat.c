/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:54:42 by nsueiro-          #+#    #+#             */
/*   Updated: 2024/11/20 16:54:45 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*d;	
	unsigned int	i;

	d = dest;
	i = 0;
	while (*d != '\0')
	{
		d++;
	}
	while (*src != '\0' && i < nb)
	{
		*d = *src;
		d++;
		src++;
		i++;
	}
	*d = '\0';
	return (dest);
}
/*
int main()
{
	char dest[50] = "Hello, ";
	char src[] = "world! ¿How are you?";
	
	ft_strncat(dest, src, 6);
	printf("Cadena resultante: %s\n", dest);
	return 0;
}
*/