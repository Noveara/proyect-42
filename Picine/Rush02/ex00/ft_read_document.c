/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_document.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:09:15 by nsueiro-          #+#    #+#             */
/*   Updated: 2024/11/23 18:09:19 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

char	*ft_read_document(char *filename)
{
	int		fd;
	char	*buffer;
	ssize_t	bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Dict error\n", 11);
		return (NULL);
	}
	buffer = malloc(1024 * sizeof(char));
	if (buffer == NULL)
	{
		close(fd);
		return (NULL);
	}
	bytes_read = read(fd, buffer, 1024 - 1);
	close(fd);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}

void	ft_print_number(char *dict, char *number)
{
	int		i;
	char	temp[100];
	int		k;

	i = -1;
	while (dict[++i] != '\0')
	{
		k = 0;
		while (dict[i] != ':' && dict[i] != '\n' && dict[i] != '\0')
			temp[k++] = dict[i++];
		temp[k] = '\0';
		if (ft_strcmp(temp, number) == 0)
		{
			while (dict[i] != '\n' && dict[i] != '\0')
			{
				write(1, &dict[i], 1);
				i++;
			}
			write(1, "\n", 1);
			return ;
		}
		while (dict[i] != '\n' && dict[i] != '\0')
			i++;
	}
	write(1, "Dict error\n", 11);
}

int	main(int argc, char **argv)
{
	char	*number;
	char	*dict;

	if (argc < 2)
	{
		write(2, "Usage: ./program <number>\n", 25);
		return (1);
	}
	dict = ft_read_document("numbers.dict");
	number = argv[1];
	if (dict == NULL)
		return (1);
	ft_print_number(dict, number);
	free(dict);
	return (0);
}
