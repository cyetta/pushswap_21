/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:36:52 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/06 18:36:51 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "ft_cstack.h"
#include "ft_errno.h"
#include "ft_array.h"

/*
add item *lst to list *hd at the begin
*/
int	ft_stkaddfront(t_head *hd, t_list *lst)
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
int	ft_stkaddback(t_head *hd, t_list *lst)
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
reset head of list to NULL
*/
int	ft_stkinit(t_head *hd)
{
	hd->lst_hd = NULL;
	hd->quantity = 0;
	hd->max = 0;
	hd->min = 0;
	hd->med = 0;
	return (ERR_OK);
}

/*
init variable min, max, med in head of list
*/
int	ft_stkminmax(t_head *hd)
{
	t_list	*pnt;
	int		i;
	int		*arr;

	if (!hd)
		return (ERR_NULL_POINTER);
	else if (!hd->lst_hd || !hd->quantity)
		return (ft_stkinit(hd));
	arr = malloc(sizeof(int) * hd->quantity);
	if (!arr)
		return (ERR_NULL_POINTER);
	pnt = hd->lst_hd;
	i = -1;
	while (++i < hd->quantity)
	{
		arr[i] = pnt->value;
		pnt = pnt->next;
	}
	ft_arrsort(arr, hd->quantity);
	hd->min = arr[0];
	hd->max = arr[hd->quantity - 1];
	hd->med = arr[hd->quantity / 2];
	free (arr);
	return (ERR_OK);
}
