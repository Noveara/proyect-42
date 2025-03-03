/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- < nsueiro-@student.42madrid.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:11:49 by nsueiro-          #+#    #+#             */
/*   Updated: 2024/11/19 23:25:28 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str [i]
				<= 'Z') || (str[i] >= 'a' && str [i] <= 'z'))
			i++;
		else
		{
			return (0);
		}
	}
	return (1);
}
/*
int	main(void)
{
	char	str[] = "hello";
	ft_str_is_alpha(str);
	printf("%i", ft_str_is_alpha(str));
	return(0);
}
*/
