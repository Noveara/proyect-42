/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:18:49 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/01/15 21:06:39 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*aux;
	int		count;

	aux = lst;
	count = 0;
	while (aux)
	{
		aux = aux->next;
		count++;
	}
	return (count);
}
