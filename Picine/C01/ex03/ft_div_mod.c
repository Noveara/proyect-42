/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 11:55:48 by nsueiro-          #+#    #+#             */
/*   Updated: 2024/11/13 12:59:29 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0)
	{
		*div = a / b;
		*mod = a % b;
	}
}
/*
int	main()
	{
		int div, mod;
		int a = 10, b = 3;
		
		ft_div_mod(a, b, &div, &mod);
		printf("División: %d, Módulo: %d\n", div, mod);
		return 0;
	}
*/
