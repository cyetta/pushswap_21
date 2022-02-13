/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:47:14 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/13 18:55:28 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lib/ft_libft.h"
#include "../ft_lib/ft_cstack.h"
#include "pushswap.h"

/*
	presort 3 element in stack
	st->min, ->max, ->med must be initialised
	stack contain 3 element, no more no less
*/
int	presort3sa(t_head *st)
{
	if ((st->lst_hd->value == st->min && st->lst_hd->next->value == st->max) || \
	(st->lst_hd->value == st->med && st->lst_hd->next->value == st->min) || \
	(st->lst_hd->value == st->max && st->lst_hd->next->value == st->med))
		sa(st);
	return (0);
}

int	pa_nextb(t_head *st_a, t_head *st_b)
{


	pa(st_a, st_b);
	return (0);
}

int	ft_stksort(t_head *st_a, t_head *st_b)
{
	while (st_a->quantity > 3)
	{
		if (st_a->lst_hd->value == st_a->max || \
		st_a->lst_hd->value == st_a->med || \
		st_a->lst_hd->value == st_a->min)
			ra(st_a);
		pb(st_a, st_b);
	}
	presort3sa(st_a);
	while (st_b->quantity > 0)
		pa_nextb(st_a, st_b);
	is_upsort(st_a);
	return (0);
}
