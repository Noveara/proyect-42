/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:02:03 by nsueiro-          #+#    #+#             */
/*   Updated: 2024/11/13 19:24:39 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	start;
	int	end;

	start = 0;
	end = size - 1;
	while (start < end)
	{
		temp = tab[start];
		tab[start] = tab[end];
		tab [end] = temp;
		start++;
		end--;
	}
}
/*
int main()
{
	int tab[] = {-5, 0, -8, 8, 25};
	int size = sizeof(tab) / sizeof(tab[0]);
	
	printf("Array original: ");
	for (int i = 0; i < size; i++)
		printf("%d ", tab[i]);
	printf("\n");
	
	ft_rev_int_tab(tab, size);
	
	printf("Array invertido: ");
	for (int i = 0; i < size; i++)
		printf("%d ", tab[i]);
	printf("\n");
	return 0;
}
*/
