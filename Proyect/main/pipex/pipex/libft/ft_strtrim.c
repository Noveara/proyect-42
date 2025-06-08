/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:48:31 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/01/16 14:16:48 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_findch(char s, const char *set)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (s == set[j])
			return (1);
		j++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		start;
	int		end;
	char	*s2;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_findch(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_findch(s1[end - 1], set))
		end--;
	s2 = ft_calloc(end - start + 1, sizeof(char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s1 + start, end - start + 1);
	return (s2);
}
