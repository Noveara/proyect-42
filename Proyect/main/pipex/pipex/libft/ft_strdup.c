/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:42:50 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/01/15 20:58:46 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*ptr;
	char	*result;

	i = ft_strlen(s1);
	ptr = malloc(i * sizeof(char) + 1);
	if (ptr)
	{
		result = ptr;
		while (*s1 != '\0')
		{
			*ptr = *s1;
			ptr++;
			s1++;
		}
		*ptr = '\0';
	}
	else
		return (NULL);
	return (result);
}
/*
int	main(void)
{
	const char *original_str = "Helloooooooooooooo";
	char *my_strdup_result;
	char *original_strdup_result;


	my_strdup_result = ft_strdup(original_str);
	printf("My ft_strdup result:	%s\n", my_strdup_result);


	original_strdup_result = strdup(original_str);
	printf("Original strdup result: %s\n", original_strdup_result);


	if (strcmp(my_strdup_result, original_strdup_result) == 0)
		printf("Results match!\n");
	else
		printf("Results do not match.\n");


	free(my_strdup_result);
	free(original_strdup_result);

	return (0);
}*/