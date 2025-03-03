/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:43:53 by nsueiro-          #+#    #+#             */
/*   Updated: 2024/11/20 11:36:42 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)

{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return ((unsigned char)*s1 - (unsigned char)*s2);
		}
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
/*
int	main()
{
	char se1[] = "Hola";
	char se2[] = "Hola";
	char se3[] = "holaa";

	printf("Resultado de comparar s1 con s2: %d\n", ft_strcmp(se1, se2));
	printf("Resultado de comparar s1 con s2: %d\n", ft_strcmp(se1, se3));
	printf("Resultado de comparar s1 con s2: %d\n", ft_strcmp(se3, se1));
	return 0;
}
*/