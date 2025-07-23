/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:20:40 by mokhan            #+#    #+#             */
/*   Updated: 2025/07/23 18:38:59 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_nbr_min(t_stack *a, int opc)
{
	t_stack	*tmp;
	int		min1;
	int		min2;
	int		set;

	tmp = a;
	min1 = -1;
	min2 = -1;
	set = 0;
	while (tmp)
	{
		if (!set || tmp->i < min1)
		{
			min2 = min1;
			min1 = tmp->i;
			set = 1;
		}
		else if ((min2 == -1 || tmp->i < min2) && tmp->i > min1)
			min2 = tmp->i;
		tmp = tmp->nxt;
	}
	if (opc == 1)
		return (min1);
	return (min2);
}

void	sort3(t_data *d)
{
	int	x;
	int	y;
	int	z;

	x = d->a->i;
	y = d->a->nxt->i;
	z = d->a->nxt->nxt->i;
	if (x > y && y < z && x < z)
		cmd_sp(d, "sa");
	else if (x > y && y > z && x > z)
	{
		cmd_sp(d, "sa");
		cmd_sp(d, "rra");
	}
	else if (x < y && y > z && x < z)
	{
		cmd_sp(d, "sa");
		cmd_sp(d, "ra");
	}
	else if (x > y && y < z && x > z)
		cmd_sp(d, "ra");
	else if (x < y && y > z && x > z)
		cmd_sp(d, "rra");
}

void	sort5(t_data *d, t_stack *min)
{
	int		size;
	int		numrotations;

	size = ps_lstsize(d->a);
	while (ps_lstsize(d->a) > 3)
	{
		min = get_ptr_min(d->a, 1);
		if (d->a->num != min->num)
		{
			numrotations = rotations(d, min);
			while (numrotations < 0)
			{
				cmd_sp(d, "rra");
				++numrotations;
			}
			while (numrotations > 0)
			{
				cmd_sp(d, "rra");
				--numrotations;
			}
		}
		cmd_sp(d, "pb");
	}
	sort3(d);
	cmd_sp(d, "pa");
	cmd_sp(d, "pa");
}

int	steps_to_min(t_stack *a)
{
	int		steps;
	t_stack	*tmp;

	steps = 0;
	tmp = a;
	while (tmp->i != ps_lstmin(tmp))
	{
		tmp = tmp->nxt;
		steps++;
	}
	return (steps);
}

void	do_sort(t_data *d)
{
	int	min;

	if (d->size == 2 && d->a->i > d->a->nxt->i)
		cmd_sp(d, "sa");
	else if (d->size <= 3)
		sort3(d);
	else if (d->size <= 5)
		sort5(d, 0);
	else
	{
		pushb(d);
		sort3(d);
		pusha(d);
	}
	min = get_min(d->a);
	if (min <= ps_lstsize(d->a) / 2)
	{
		while (d->a->i != ps_lstmin(d->a))
			cmd_sp(d, "ra");
	}
	else
	{
		while (d->a->i != ps_lstmin(d->a))
			cmd_sp(d, "rra");
	}
}
