/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:19:35 by mokhan            #+#    #+#             */
/*   Updated: 2025/07/16 21:42:33 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_lstmin(t_stack *lst)
{
	int	min;

	min = INT_MAX;
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

	max = INT_MIN;
	while (lst != NULL)
	{
		if (lst->i > max)
			max = lst->i;
		lst = lst->nxt;
	}
	return (max);
}
