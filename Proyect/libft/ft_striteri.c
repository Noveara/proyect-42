/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:53:57 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/01/15 20:05:53 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !(*f))
		s = NULL;
	else
	{
		i = 0;
		while (s[i] != '\0')
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
}
