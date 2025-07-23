/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:15:56 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/01/15 21:04:41 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;

	if (!lst || !(*del))
		lst = NULL;
	else
	{
		while (*lst)
		{
			aux = (*lst)->next;
			(*del)((*lst)->content);
			free(*lst);
			*lst = aux;
		}
		free (*lst);
		*lst = NULL;
	}
}
