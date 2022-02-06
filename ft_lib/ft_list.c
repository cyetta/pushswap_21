/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:05:02 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/06 18:20:45 by cyetta           ###   ########.fr       */
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
	if (!pnt || pnt->next == pnt)
		return (NULL);
	pnt->prev->next = pnt->next;
	pnt->next->prev = pnt->prev;
	return (pnt->next);
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
