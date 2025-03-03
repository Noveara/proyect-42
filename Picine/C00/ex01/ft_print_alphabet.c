/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:18:33 by nsueiro-          #+#    #+#             */
/*   Updated: 2024/11/11 13:24:31 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	i;	

	i = 'a';
	while (i <= 'z')
	{
		write (1, &i, 1);
		i++;
	}
	return ;
}
/*
int main(void)
	{
	ft_print_alphabet();
	return (0)
	}
}
*/
