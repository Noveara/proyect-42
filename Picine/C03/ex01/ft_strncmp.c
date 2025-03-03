/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:26:33 by nsueiro-          #+#    #+#             */
/*   Updated: 2024/11/20 15:00:04 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		if (s1[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (0);
}
/*
int main() 
{
	char str1[] = "hello";
	char str2[] = "hello1";

   
	int result = ft_strncmp(str1, str2, 8);
	printf("Resultado: %d\n", result);  
	result = ft_strncmp(str1, str2, 3);
	printf("Resultado: %d\n", result); 
	result = ft_strncmp(str1, str2, 5);
	printf("Resultado: %d\n", result);  
	return 0;
}
*/