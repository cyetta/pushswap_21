/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:05:47 by cyetta            #+#    #+#             */
/*   Updated: 2022/01/25 21:47:46 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstack.h"
#include <stdlib.h>

/*
delete element from list
*/
void	ft_lstdelelm(t_list *pnt)
{
	if (!pnt)
		return (4);
	pnt->prev->next = pnt->next;
	pnt->next->prev = pnt->prev;
	free(pnt);
}

void	ft_lstdelhdelm(t_head *hd, int idx)
{
	t_list	*pnt;

	if (!hd || !hd->lst_hd || !hd->quantity)
		return (5);
	idx = idx % hd->quantity;
	pnt = hd->lst_hd;
	while (idx--)
		pnt = pnt->next;
	if (hd->lst_hd == pnt)
		hd->lst_hd = pnt->next;
	ft_lstdelelm(pnt);
	if (!(--hd->quantity))
		hd->lst_hd = NULL;
}
!!!!!
void	ft_lstfree(t_head *hd)
{
	t_list	*pnt;

	if (!pnt || !hd->lst_hd || hd->quantity)
		return (4);
	pnt = hd->lst_hd;
	while (pnt != hd->lst_hd)
	{
		/* code */
	}




	pnt->prev->next = pnt->next;
	pnt->next->prev = pnt->prev;
	if (hd->lst_hd == pnt)
		hd->lst_hd = pnt->next;
	hd->quantity--;
	free(pnt);
}
