/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:53:50 by nsueiro-          #+#    #+#             */
/*   Updated: 2024/11/13 09:59:09 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*
int	main(void)
{
	int	x;
	int	y;

	x = 5;
	y = 10;
	printf("Antes del intercambio: x = %d, y = %d\n", x, y);
	ft_swap(&x, &y);
	printf("Después del intercambio: x = %d, y = %d\n", x, y);
	return (0);
}
*/
