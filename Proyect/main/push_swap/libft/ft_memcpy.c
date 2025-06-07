/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:20:26 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/01/15 20:06:15 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*source_ptr;
	size_t				i;

	if (dst == NULL && src == NULL)
		return (dst);
	dest_ptr = (unsigned char *)dst;
	source_ptr = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*dest_ptr = *source_ptr;
		dest_ptr++;
		source_ptr++;
		i++;
	}
	return (dst);
}
