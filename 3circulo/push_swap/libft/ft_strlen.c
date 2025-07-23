/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:18:00 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/01/15 21:30:33 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
int	main(void)
{
	char	str[] = "Hola mundo";
	int		n;

	n = strlen(str);
	printf("Longitud:	%d\n", n);
	n = ft_strlen(str);
	printf("Longitud mío: %d", n);
	return (0);
}*/