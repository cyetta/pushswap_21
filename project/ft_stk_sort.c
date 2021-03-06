/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:47:14 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/17 19:36:17 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../ft_lib/ft_libft.h"
#include "../ft_lib/ft_cstack.h"
#include "../ft_lib/ft_errno.h"
#include "pushswap.h"

/*
	presort 3 element in stack
	st->min, ->max, must be initialised
	stack contain 3 element, no more no less
*/
int	presort3sa(t_head *st)
{
	if ((st->lst_hd->value == st->min && st->lst_hd->next->value == st->max) || \
	(st->lst_hd->prev->value == st->max && st->lst_hd->next->value == st->min) \
	|| (st->lst_hd->value == st->max && st->lst_hd->prev->value == st->min))
		sa(st);
	return (0);
}

/*
return index of element that must be on top of stack
for insert element from stack b befor it
*/
int	get_stidxins(t_head *st, int val)
{
	t_list	*t;
	int		idx;

	idx = 0;
	t = st->lst_hd;
	idx = -1;
	while (++idx < st->quantity)
	{
		if ((t->next->value > val || t->next->value == st->min) && \
	t->value >= val && (t->prev->value < val || t->prev->value == st->max))
			break ;
		t = t->next;
	}
	return (idx);
}

/*
execute command cmd, qnt times for stacks
*/
void	write_cmd(t_head *st_a, t_head *st_b, int cmd, int qnt)
{
	int	i;

	i = -1;
	while (++i < qnt)
	{
		if (cmd == OP_RA)
			ra(st_a);
		else if (cmd == OP_RRA)
			rra(st_a);
		else if (cmd == OP_RR)
			rr(st_a, st_b);
		else if (cmd == OP_RB)
			rb(st_b);
		else if (cmd == OP_RRB)
			rrb(st_b);
		else if (cmd == OP_RRR)
			rrr(st_a, st_b);
	}
}

/*
put next element from stack b to stack a
*/
int	pa_nextb(t_head *st_a, t_head *st_b)
{
	t_elweigth	*wt;
	int			i;
	int			min_i;
	t_list		*t;

	wt = (t_elweigth *)malloc(sizeof(t_elweigth) * st_b->quantity);
	if (!wt)
		exit(ft_errno(clear_stks(st_a, st_b, ERR_MEMORY_ALLOCATION)));
	i = -1;
	min_i = 0;
	t = st_b->lst_hd;
	while (++i < st_b->quantity)
	{
		wt[i].qnt_b = ra_rra(i, st_b->quantity);
		wt[i].qnt_a = ra_rra(get_stidxins(st_a, t->value), st_a->quantity);
		fill_weight(&wt[i], t->value);
		if (wt[i].opsum < wt[min_i].opsum)
			min_i = i;
		t = t->next;
	}
	write_cmd(st_a, st_b, wt[min_i].cmd_a, wt[min_i].qnt_a);
	write_cmd(st_a, st_b, wt[min_i].cmd_b, wt[min_i].qnt_b);
	pa(st_a, st_b);
	free(wt);
	return (0);
}

int	ft_stksort(t_head *st_a, t_head *st_b)
{
	while (st_a->quantity > 3)
	{
		if (st_a->lst_hd->value == st_a->max || \
		st_a->lst_hd->value == st_a->min)
			ra(st_a);
		else
		{
			pb(st_a, st_b);
			if (st_b->lst_hd->value < st_a->med && \
			(st_a->quantity + st_b->quantity) > 10)
				rb(st_b);
		}
	}
	presort3sa(st_a);
	while (st_b->quantity > 0)
	{
		pa_nextb(st_a, st_b);
	}
	is_upsort(st_a);
	return (0);
}
