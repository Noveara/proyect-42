/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:41:29 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/01/16 13:56:42 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count != 0 && size != 0 && count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr)
		ft_bzero(ptr, count * size);
	return (ptr);
}
/*
int	main(void)
{
	size_t count;
	size_t size;
	size_t i;
	int *arr_ft_calloc;

	count = 15;
	size = sizeof(int);
	i = 0;
	arr_ft_calloc = (int *)ft_calloc(count, size);
	if (arr_ft_calloc)
	{
		printf("Memoria colocada usando ft_calloc:\n");
		while (i < count)
		{
			printf("%d ", arr_ft_calloc[i]);
			i++;
		}
		printf("\n");
		free(arr_ft_calloc);
	}
	else
	{
		printf("Error de memoria.\n");
	}


	int *arr_calloc = (int *)calloc(count, size);

	i = 0;
	if (arr_calloc)
	{
		printf("Memoria colocada con calloc:\n");
		while (i < count)
		{
			printf("%d ", arr_calloc[i]);
		}
		printf("\n");
		free(arr_calloc);
	}
	else
	{
		printf("Error de memoria.\n");
	}

	return (0);
}*/
