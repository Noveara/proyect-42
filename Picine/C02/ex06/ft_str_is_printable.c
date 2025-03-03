/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 01:07:03 by nsueiro-          #+#    #+#             */
/*   Updated: 2024/11/20 01:33:04 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)

{
	int	i;

	i = 0;
	if (str[i] == '\0')
	{
		return (1);
	}
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
/*
int	main()
{
	char str[] = "$%-,ḉ&";
	printf("%d", ft_str_is_printable(str));
	return (0);
}
*/
