/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:51:12 by nsueiro-          #+#    #+#             */
/*   Updated: 2024/11/20 18:51:14 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	char	*d;
	char	*s;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		d = str;
		s = to_find;
		while (*d && *s && *d == *s)
		{
			d++;
			s++;
		}
		if (*s == '\0')
		{
			return (str);
		}
		str++;
	}
	return (NULL);
}
/*
int main()
{
	char dest[100] = "Hello, world!";
	char to_find[] = "world";
	char *result = ft_strstr(dest, to_find);

	if (result)
	{
		printf("Cadena encontrada: %s\n", result);
	}
	else 
	{
		printf("Subcadena no encontrada.\n");
	}

	return 0;
}
*/