/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 04:11:17 by nsueiro-          #+#    #+#             */
/*   Updated: 2024/11/11 19:52:55 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_numbers(void)
{
	char	number;
	char	digit;

	number = 0;
	while (number <= 9)
	{
		digit = '0' + number;
		write (1, &digit, 1);
		number++;
	}
	return ;
}
/*
int	main(void)
{
	ft_print_numbers();
	return (0);
}
*/
