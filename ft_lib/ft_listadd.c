/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:36:52 by cyetta            #+#    #+#             */
/*   Updated: 2022/01/28 03:44:26 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "cstack.h"
#include "errno.h"

/*
add item *lst to list *hd at the begin
*/
int	ft_lstaddfront(t_head *hd, t_list *lst)
{
	if (!hd || !lst)
		return (ERR_NULL_POINTER);
	if (hd->lst_hd)
	{
		lst->prev = hd->lst_hd->prev;
		lst->next = hd->lst_hd;
		hd->lst_hd->prev->next = lst;
		hd->lst_hd->prev = lst;
	}
	hd->lst_hd = lst;
	hd->quantity++;
	return (ERR_OK);
}

/*
add item *lst to list *hd at the end
*/
int	ft_lstaddback(t_head *hd, t_list *lst)
{
	if (!hd || !lst)
		return (ERR_NULL_POINTER);
	if (hd->lst_hd)
	{
		lst->prev = hd->lst_hd->prev;
		lst->next = hd->lst_hd;
		hd->lst_hd->prev->next = lst;
		hd->lst_hd->prev = lst;
	}
	else
		hd->lst_hd = lst;
	hd->quantity++;
	return (ERR_OK);
}

/*
NULL head of list
*/
void	ft_lsthdinit(t_head *hd)
{
	hd->lst_hd = NULL;
	hd->quantity = 0;
}
