/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noa <noa@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:19:35 by mokhan            #+#    #+#             */
/*   Updated: 2025/06/07 15:09:18 by noa              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_lstmin(t_stack *lst)
{
	int	min;

	min = 2147483647;
	while (lst != NULL)
	{
		if (lst->i < min)
			min = lst->i;
		lst = lst->nxt;
	}
	return (min);
}

int	ps_lstmax(t_stack *lst)
{
	int	max;

	max = -2147483648;
	while (lst != NULL)
	{
		if (lst->i > max)
			max = lst->i;
		lst = lst->nxt;
	}
	return (max);
}
