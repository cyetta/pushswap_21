/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:06:04 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/09 21:12:40 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lib/ft_libft.h"
#include "../ft_lib/ft_cstack.h"
#include "pushswap.h"

static int	ra_rra(int idx, int quantity)
{
	if (idx > quantity / 2)
		return (quantity - idx);
	else
		return (-idx);
}

/*
check stack for presort, it's mean that in stack exists upworth sequece,
return stack.quantity, if no exists one.
else return +N ra command, or  -N rra command
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

/*
check stack for upsort, if stack presorted, write last ra/rra command
and return 1, what means that the stack is sorted
else return 0
*/
int	is_upsort(t_head *st)
{
	int		i;
	int		j;

	i = is_presortedup(st);
	if (i == st->quantity)
		return (0);
	if (i >= 0)
	{
		j = -1;
		while (++j < i)
			ra(st);
	}
	else
	{
		j = i;
		while (++j < 0)
			rra(st);
	}
	return (1);
}
