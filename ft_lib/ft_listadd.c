/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:36:52 by cyetta            #+#    #+#             */
/*   Updated: 2022/01/25 20:05:06 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cstack.h"
#include <stddef.h>

int	ft_lstaddfront(t_head *hd, t_list *lst)
{
	if (!hd || !lst)
		return (5);
	if (hd->lst_hd)
	{
		lst->prev = hd->lst_hd->prev;
		lst->next = hd->lst_hd;
		hd->lst_hd->prev->next = lst;
		hd->lst_hd->prev = lst;
	}
	hd->lst_hd = lst;
	hd->quantity++;
	return (0);
}

int	ft_lstaddback(t_head *hd, t_list *lst)
{
	if (!hd || !lst)
		return (5);
	lst->prev = hd->lst_hd->prev;
	lst->next = hd->lst_hd;
	hd->lst_hd->prev->next = lst;
	hd->lst_hd->prev = lst;
	hd->quantity++;
	return (0);
}

void	ft_lsthdinit(t_head *hd)
{
	hd->lst_hd = NULL;
	hd->quantity = 0;
}
