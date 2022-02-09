/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:06:04 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/10 00:51:16 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lib/ft_libft.h"
#include "../ft_lib/ft_cstack.h"
#include "pushswap.h"

/*
if idx in the first half of stack, returns -N ra command
else returns +N rra command
idx in range 0..(quantity-1)
*/
static int	ra_rra(int idx, int quantity)
{
	if (idx > quantity / 2)
		return (quantity - idx);
	else
		return (-idx);
}

/*
check stack for presort, this means that if an ascending sequence from min to
max exists in the stack, +N rra or -N ra commands will be returned for rotate
stack on min, or the value of stack.quantity if sequence does not exist.
*/
int	is_presortedup(t_head *st)
{
	int		min_idx;
	int		i;
	t_list	*t;

	ft_stkminmax(st);
	t = st->lst_hd;
	min_idx = -1;
	while (++min_idx < st->quantity && t->value != st->min)
		t = t->next;
	i = -1;
	while (++i < st->quantity - 1 && t->next->value >= t->value)
		t = t->next;
	if (i == st->quantity - 1)
		return (ra_rra(min_idx, st->quantity));
	return (st->quantity);
}

int	sort2up(t_head *st)
{
	if (st->lst_hd->value > st->lst_hd->next->value)
		sa(st);
	return (1);
}

/*
check stack for upsort, if stack presorted, write last ra/rra command
and return 1, what means that the stack is sorted
else return 0
*/
int	is_upsort(t_head *st)
{
	int		i;
	int		j;

	if (st->quantity < 2)
		return (2);
	else if (st->quantity == 2)
		return (sort2up(st));
	i = is_presortedup(st);
	if (i == st->quantity)
		return (0);
	if (i >= 0)
	{
		j = -1;
		while (++j < i)
			rra(st);
	}
	else
	{
		j = i;
		while (++j <= 0)
			ra(st);
	}
	return (1);
}
