/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:05:47 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/06 03:36:41 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_cstack.h"
#include "ft_errno.h"

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

/*
delete item N in list by modulo of quantity
min\max is not updated, call ft_lsthdminmax() additionally
*/
void	ft_lstdelhdelm(t_head *hd, int idx)
{
	t_list	*pnt;

	if (!hd || !hd->lst_hd || !hd->quantity)
		return ;
	idx = idx % hd->quantity;
	pnt = hd->lst_hd;
	while (idx--)
		pnt = pnt->next;
	if (hd->lst_hd == pnt)
		hd->lst_hd = pnt->next;
	ft_lstdelitm(pnt);
	if (!(--hd->quantity))
		hd->lst_hd = NULL;
}

/*
delete list at all
*/
int	ft_lsthdfree(t_head *hd)
{
	if (!hd || !hd->lst_hd || !hd->quantity)
		return (ERR_OK);
	ft_lstdellst(hd->lst_hd);
	ft_lsthdinit(hd);
	return (ERR_OK);
}
