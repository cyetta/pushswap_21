/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:05:02 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/13 19:18:33 by cyetta           ###   ########.fr       */
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

/*
Removes item from list, not memory frees, simple updates links in the list.
BE CAREFULLY, don`t loses pointer to item.
for full delete item use ft_lstdelitm() istead
Returns pointer to next item. If item is last, returns NULL
*/
t_list	*ft_lstrmvitm(t_list *pnt)
{
	t_list	*t;

	if (!pnt || pnt->next == pnt)
		return (NULL);
	t = pnt->next;
	pnt->prev->next = pnt->next;
	pnt->next->prev = pnt->prev;
	pnt->next = pnt;
	pnt->prev = pnt;
	return (t);
}

/*
Deletes item from list.
Returns pointer to next item. If item is last, returns NULL
*/
t_list	*ft_lstdelitm(t_list *pnt)
{
	t_list	*t;

	if (!pnt)
		return (NULL);
	t = ft_lstrmvitm(pnt);
	free(pnt);
	return (t);
}

/*
delete list at all
*/
void	ft_lstdellst(t_list *pnt)
{
	t_list	*hd;

	if (!pnt)
		return ;
	hd = pnt;
	while (pnt->next != hd)
	{
		pnt = pnt->next;
		free(pnt->prev);
	}
	free(pnt);
}

/*
returns index of min element in stack relativ pnt. *pnt points to min
min, max, med must be initialized before.
if returned quantity of stack element, stack head have not initialized
*/
int	ft_lst_min(t_list *pnt)
{
	int		min_idx;
	int		i;
	t_list	*t;

	min_idx = 0;
	if (!pnt || pnt->next == pnt)
		return (min_idx);
	i = 0;
	t = pnt;
	while (t->next != t)
	{
		t = t->next;
		i++;
		if (t->value < pnt->value)
		{
			pnt = t;
			min_idx = i;
		}
	}
	return (min_idx);
}
