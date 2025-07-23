/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:32:35 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/07/02 18:47:57 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (big == NULL && len == 0)
		return (NULL);
	if (little == NULL)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
		i++;
	return (&(((char *)big)[i]));
}

/*
int	main(void)
{
	char s1[30] = "aaabcabcd";
	char s2[] = "abcd";
	char *ptr;
	char *ptr2;

	ptr = strnstr(s1, s2, 11);
	ptr2 = ft_strnstr(s1, s2, 11);
	if (ptr == s1 +5 && ptr2 == s1 + 5)
	{
		printf("Mi strnstr:		%s", ptr);
		printf("Strnstr original :	%s\n", ptr);
	}
	else
	{
		printf("Mi strnstr 23:		%s\n", ptr);
		printf("Strnstr original  23:	%s\n", ptr);
	}
	return (0);
}*/
