/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:19:19 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/01/16 13:49:30 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*byte_ptr;
	size_t			i;

	if (n == 0)
		return ;
	i = 0;
	byte_ptr = (unsigned char *)str;
	while (i < n)
	{
		*byte_ptr = 0;
		byte_ptr++;
		i++;
	}
}
