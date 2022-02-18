/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:05:47 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/17 23:43:15 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_cstack.h"
#include "ft_errno.h"

/*
delete item N in list by modulo of quantity
min\max is not updated, call ft_lsthdminmax() additionally
*/
void	ft_stkdelelm(t_head *hd, int idx)
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
int	ft_stkfree(t_head *hd)
{
	if (!hd || !hd->lst_hd || !hd->quantity)
		return (ERR_OK);
	ft_lstdellst(hd->lst_hd);
	ft_stkinit(hd);
	return (ERR_OK);
}

int	clear_stks(t_head *st_a, t_head *st_b, int ft_errno)
{
	ft_stkfree(st_a);
	ft_stkfree(st_b);
	return (ft_errno);
}
