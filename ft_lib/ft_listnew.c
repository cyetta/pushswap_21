/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:05:02 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/05 20:18:15 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_cstack.h"

/*
Allocates (with malloc(3)) and returns a new element t_list. The t_list->value
 is initialized by the parameter ’val’. The 'next’ and 'prev' point to created
 element.
Return: The pointer to new element.

*/
t_list	*ft_lstnew(int val)
{
	t_list	*newel;

	newel = (t_list *)malloc(sizeof(t_list));
	if (!newel)
		return (NULL);
	newel->value = val;
	newel->next = newel;
	newel->prev = newel;
	return (newel);
}
