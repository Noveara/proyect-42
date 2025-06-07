/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:18:22 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/01/15 21:06:21 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*head;

	head = malloc(sizeof(t_list));
	if (!head)
		return (NULL);
	head->content = content;
	head->next = NULL;
	return (head);
}
/*
int main()
{
	char	s1[] = "Hola";
	char	s2[] = "Mundo";
	t_list	*new;

	new = ft_lstnew(s1);
	printf("Contenido: %s\n", new->content);
	free(new);
	new = ft_lstnew(s2);
	printf("Contenido: %s\n", new->content);
	free(new);
	return (0);
}*/