/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnavalla <jnavalla@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 18:50:18 by jnavalla          #+#    #+#             */
/*   Updated: 2024/11/17 19:34:10 by jnavalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	g_matriz[24][4];
int		g_cont;
char	g_src[16];

void	swap(char *x, char *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}


void	almacenar(char	*array)
{
	g_matriz[g_cont][0] = array[0];
    g_matriz[g_cont][1] = array[1];
    g_matriz[g_cont][2] = array[2];
    g_matriz[g_cont][3] = array[3];
	g_cont++;
}

void	cambiador(char *array)
{
	almacenar(array);
	swap(&array[1], &array[2]);
	almacenar(array);
	swap(&array[2], &array[3]);
	almacenar(array);
	swap(&array[1], &array[2]);
	almacenar(array);
	swap(&array[2], &array[3]);
	almacenar(array);
	swap(&array[1], &array[2]);
	almacenar(array);
}

int	check_repeat_columns(char tablero[4][4])
{
	int	i;
	int	j;
	int column;

	column = 0;
	while (column < 4)
	{
    	j = 0;
		while(j < 3)
		{
			i = j + 1;
			while (i < 4)
			{
				if(tablero[j][column] == tablero[i][column])
				{
					return (1);
				}
				i++;
			}
			j++;
		}
		column++;
	}
	return (0);
}

void	ctr(char tablero[4][4], int num_column, char  *array)
{
	int	i;
	
	i = 0;
	while (i < 4)
	{
		array[i] = tablero[i][num_column];
		i++;
	}
}

int	check(char *row, char val)
{
	int		max_box;
	char	count;
	int		i;

	count = '1';
	max_box = row[0];
	i = 1;
	while (i < 4)
	{
		if (row[i] > max_box)
		{
			count++;
			max_box = row[i];
		}
		i++;
	}
	if (count == val)
		return (1);
	else
		return (0);
}

int check_rev(char *row, char val)
{
    int max_box;
    char count;
    int i;

    count = '1';
    max_box = row[3];
    i = 2;
    while (i >= 0)
    {
        if (row[i] > max_box)
        {
            count++;
            max_box = row[i];
        }
        i--;
    }
    if (count == val)
        return (1);	
	else
        return (0);
}

int verify(char tab[4][4])
{
	char array[4];

	if (check(tab[0],g_src[8]) == 0 || check_rev(tab[0], g_src[12]) == 0)
		return (0);
	if (check(tab[1], g_src[9]) == 0 || check_rev(tab[1], g_src[13]) == 0)
		return (0);
	if (check(tab[2], g_src[10]) == 0 || check_rev(tab[2], g_src[14]) == 0)
		return (0);
	if (check(tab[3], g_src[11]) == 0 || check_rev(tab[3], g_src[15]) == 0)
		return (0);
	ctr(tab, 0, array);
	if (check(array, g_src[0]) == 0 || check_rev(array, g_src[4]) == 0)
		return (0);
	ctr(tab, 1, array);
	if (check(array, g_src[1]) == 0 || check_rev(array, g_src[5]) == 0)
		return (0);
	ctr(tab, 2, array);
	if (check(array, g_src[2]) == 0 || check_rev(array, g_src[6]) == 0)
		return (0);
	ctr(tab, 3, array);
	if (check(array, g_src[3]) == 0 || check_rev(array, g_src[7]) == 0)
		return (0);
	return (1);
}
 
int	is_correct(char tablero[4][4])
{
	int i;
	int	j;

	if(check_repeat_columns(tablero) == 1)
	{
		return (0);
	}
	if(verify(tablero) == 0)
	{
		return (0);
	}
	else
	{
	i = 0;
		while(i < 4)
		{
			j = 0;
			while(j < 4)
			{
				write(1, &tablero[i][j], 1);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
		return(1);
	}

}

void    nueva_prueba(char tablero[4][4], int *prueba)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (j < 4)
    {
        while (i  < 4)
        {
            tablero[j][i] = g_matriz[prueba[j]][i];
            i++;
        }
		i = 0;
        j++;
    }
}

int	crea_pruebas()
{
	int		prueba[4];
	char	tablero[4][4];

	prueba[0] = 0;
	while (prueba[0] < 24)
	{
		prueba[1] = 0;
		while (prueba[1] < 24)
		{
			prueba[2] = 0;
			while (prueba[2] < 24)
			{
				prueba[3] = 0;
				while (prueba[3] < 24)
				{
					nueva_prueba(tablero, prueba);
					if(is_correct(tablero) == 1)
						return (0);
					prueba[3]++;
				}
				prueba[2]++;
			}
			prueba[1]++;
		}
		prueba[0]++;
	}
	return (1);
}

int main(int count, char **args)
{
	char	array[] = {'1', '2', '3', '4'};
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (count != 2)
    {
        write(1, "Error\n", 6);
        return (1);
    }
	while (i <= 31)
	{
		if((args[1][i] >= '1' && args[1][i] <= '4') && i % 2 == 0)
		{
			g_src[j] = args[1][i];
			j++;
		}
		i++;
	}
	i = 1;
	while (i <= 4)
	{
		cambiador(array);
		array[0] = '1';
		array[1] = '2';
		array[2] = '3';
		array[3] = '4';
		swap(&array[0], &array[i]);
		i++;
	}
	if(crea_pruebas() == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
