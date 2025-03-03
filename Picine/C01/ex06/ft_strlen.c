/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42madrid.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 12:00:47 by nsueiro-          #+#    #+#             */
/*   Updated: 2024/11/14 13:15:18 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}
/*
int main()
{
    char str[] = "Hola";  // Cadena de ejemplo
    int length = ft_strlen(str);   // Llamada a ft_strlen

    printf("La longitud de la cadena es: %d\n", length);  // Imprime la longitud
    return 0;
}
*/
