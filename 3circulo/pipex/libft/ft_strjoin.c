/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:46:57 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/01/15 20:05:36 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	ptr = str;
	while (*s1 != '\0')
	{
		*ptr = *s1;
		s1++;
		ptr++;
	}
	while (*s2 != '\0')
	{
		*ptr = *s2;
		s2++;
		ptr++;
	}
	*ptr = '\0';
	return (str);
}
/*
int	main(void)
{
	char s1[] = "  Hola ";
	char s2[] = "Mun do";
	char *cat;

	cat = ft_strjoin(s1, s2);
	printf("Cadena resultante: %s", cat);
	free(cat);
	return (0);
}*/