/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:05:47 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/05 20:17:32 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_cstack.h"
#include "ft_errno.h"

/*
delete item from list
*/
void	ft_lstdelitm(t_list *pnt)
{
	if (!pnt)
		return ;
	pnt->prev->next = pnt->next;
	pnt->next->prev = pnt->prev;
	free(pnt);
}

/*
delete list at all
*/
void	ft_lstdellst(t_list *pnt)
{
	if (!pnt)
		return ;
	while (pnt->next != pnt)
		ft_lstdelitm(pnt);
	free(pnt);
}

/*
delete n - item in list by modulo of quantity
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
	t_list	*pnt;

	if (!hd || !hd->lst_hd || !hd->quantity)
		return (ERR_OK);
	pnt = hd->lst_hd;
	while (pnt->next != hd->lst_hd)
	{
		pnt = pnt->next;
		free(pnt->prev);
	}
	free(pnt);
	ft_lsthdinit(hd);
	return (ERR_OK);
}
