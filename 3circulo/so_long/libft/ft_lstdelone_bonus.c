/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:16:23 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/01/15 21:04:58 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst && (*del))
	{
		(*del)(lst->content);
		free(lst);
	}
	else
		lst = NULL;
}
/*
void	del(void *ptr)
{
	free(ptr);
}
int main()
{
	t_list	*new;
	int	*n;

	n = malloc(sizeof(int));
	*n = 6;
	if (!n)
		return (1);
	new = ft_lstnew(n);
	printf("Contenido antes de del: %d\n", *((int *)new->content));
	ft_lstdelone(new, del);
	return (0);
}*/
