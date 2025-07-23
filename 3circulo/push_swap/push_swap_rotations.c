/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 19:43:12 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/07/18 20:39:04 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotations(t_data *d, t_stack *min)
{
	t_stack	*forward;
	t_stack	*backward;
	int		numrotate;

	printf("%p\n", d->a->last);
	return (0);
	if (!d || !d->a || !d->a->nxt || !d->a->last || d->a == min)
		return (0);
	numrotate = 1;
	forward = d->a->nxt;
	backward = d->a->last;
	while (forward != min && backward != min)
	{
		forward = forward->nxt;
		backward = backward->last;
		numrotate++;
	}
	if (forward == min)
		return (numrotate);
	return (-numrotate);
}


t_stack	*get_ptr_min(t_stack *a, int opc)
{
	t_stack	*tmp;
	t_stack	*min1;
	t_stack	*min2;

	min1 = a;
	min2 = a;
	tmp = a->nxt;
	while (tmp)
	{
		if (tmp->num < min1->num)
		{
			min2 = min1;
			min1 = tmp;
		}
		tmp = tmp->nxt;
	}
	if (opc == 1)
		return (min1);
	return (min2);
}



