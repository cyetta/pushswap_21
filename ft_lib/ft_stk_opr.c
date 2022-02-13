/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_opr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 00:09:06 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/13 19:19:22 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"
#include "ft_cstack.h"

/*
shift up all elements of stack a by 1. The first element becomes the last one.
*/
void	ft_stk_oprt(t_head *st)
{
	if (!st || !st->lst_hd || st->quantity < 2)
		return ;
	st->lst_hd = st->lst_hd->next;
}

/*
shift down all elements of stack a by 1. The last element becomes the first one.
*/
void	ft_stk_oprr(t_head *st)
{
	if (!st || !st->lst_hd || st->quantity < 2)
		return ;
	st->lst_hd = st->lst_hd->prev;
}

/*
swap the first 2 elements at the top of stack. Do nothing if there is only one
or no elements).
*/
void	ft_stk_opswap(t_head *st)
{
	t_list	*t;

	if (!st || !st->lst_hd || st->quantity < 2)
		return ;
	t = st->lst_hd->next;
	ft_lstrmvitm(t);
	st->quantity--;
	ft_stkaddfront(st, t);
}

/*
take the first element at the top of src and put it at the top of dst. Do nothing
if src is empty.
*/
void	ft_stk_oppush(t_head *src, t_head *dst)
{
	t_list	*t;

	if (!src || !src->lst_hd || !src->quantity)
		return ;
	t = src->lst_hd;
	src->lst_hd = ft_lstrmvitm(t);
	src->quantity--;
	ft_stkaddfront(dst, t);
}
