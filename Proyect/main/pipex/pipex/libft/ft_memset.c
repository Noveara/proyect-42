/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:18:43 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/01/15 20:06:11 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	unsigned char	*byte_ptr;
	size_t			i;

	byte_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < len)
	{
		*byte_ptr = (unsigned char)c;
		byte_ptr++;
		i++;
	}
	return (ptr);
}
