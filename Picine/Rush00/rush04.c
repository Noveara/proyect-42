/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:47:43 by nsueiro-          #+#    #+#             */
/*   Updated: 2024/11/10 22:04:59 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_corner(int i, int j, int x, int y)
{
	if(i ==0 && j == 0)
		ft_putchar('A');
	else if(i == y - 1 && j == 0)
		ft_putchar('C');
	else if(i == 0 && j == x - 1)
		ft_putchar('C');
	else if(i == y - 1 && j == x - 1)
		ft_putchar('A');
	else if(i == 0 || i ==  y - 1 || j == 0 || j == x - 1)
		ft_putchar('B');
	else 
		ft_putchar(' ');
}
void	rush(int x, int y)
{
	int i;
	int j;

	i = 0;
	while(i < y)
	{
		j =  0;
		while (j < x)
		{
			print_corner(i, j, x, y);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
