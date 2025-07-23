/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:27:33 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/07/02 18:39:14 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*
int	main(void)
{
	const char *str = "Hello, World!";
	int target_char = '';

	char *my_result = ft_strchr(str, target_char);
	printf("My ft_strchr result: 	%s\n", my_result ? my_result : "NULL");

	char *original_result = strchr(str, target_char);
	printf("Original strchr result: %s\n",
		original_result ? original_result : "NULL");

	if ((my_result == NULL && original_result == NULL) || (strcmp(my_result,
				original_result) == 0))
		printf("Results match!\n");
	else
		printf("Results do not match.\n");

	return (0);
}*/