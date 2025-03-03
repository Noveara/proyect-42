/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:57:38 by nsueiro-          #+#    #+#             */
/*   Updated: 2024/11/14 19:25:32 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp_a;

	if (b != 0)
	{
		temp_a = *a;
		{
			*a = temp_a / *b;
			*b = temp_a % *b;
		}
	}
}
/*
int	main()
	{
		int div, mod;
		int a = 10, b = 3;
		
		ft_ultimate_div_mod(&a, &b);
		printf("a: %d, b: %d\n", a, b);
		
		return 0;
	}
*/
