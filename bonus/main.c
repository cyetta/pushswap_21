/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 00:59:19 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/18 18:26:32 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../ft_lib/ft_libft.h"
#include "../ft_lib/ft_cstack.h"
#include "../ft_lib/ft_errno.h"
#include "checker.h"

/*
check stack for upsort,
return 1, what means that the stack is sorted
else return 0
*/
int	is_upsort(t_head *st)
{
	int		i;
	t_list	*t;

	if (st->quantity < 2)
		return (2);
	t = st->lst_hd;
	i = -1;
	while (++i < st->quantity - 1 && t->next->value >= t->value)
		t = t->next;
	if (i == st->quantity - 1)
		return (1);
	return (0);
}

int	is_rr(char *str, t_head *st_a, t_head *st_b)
{
	if (!ft_strcmp(str, "ra"))
		ft_stk_oprt(st_a);
	else if (!ft_strcmp(str, "rb"))
		ft_stk_oprt(st_b);
	else if (!ft_strcmp(str, "rra"))
		ft_stk_oprr(st_a);
	else if (!ft_strcmp(str, "rrb"))
		ft_stk_oprr(st_b);
	else if (!ft_strcmp(str, "rr"))
	{
		ft_stk_oprt(st_a);
		ft_stk_oprt(st_b);
	}
	else if (!ft_strcmp(str, "rrr"))
	{
		ft_stk_oprr(st_a);
		ft_stk_oprr(st_b);
	}
	else
		return (0);
	return (1);
}

int	is_ss(char *str, t_head *st_a, t_head *st_b)
{
	if (!ft_strcmp(str, "pa"))
		ft_stk_oppush(st_b, st_a);
	else if (!ft_strcmp(str, "pb"))
		ft_stk_oppush(st_a, st_b);
	else if (!ft_strcmp(str, "sa"))
		ft_stk_opswap(st_a);
	else if (!ft_strcmp(str, "sb"))
		ft_stk_opswap(st_b);
	else if (!ft_strcmp(str, "ss"))
	{
		ft_stk_opswap(st_a);
		ft_stk_opswap(st_b);
	}
	else
		return (0);
	return (1);
}

int	execute(t_head *st_a, t_head *st_b)
{
	char	*s_op;

	s_op = NULL;
	while (getnextln(&s_op))
	{
		if (!is_rr(s_op, st_a, st_b) && !is_ss(s_op, st_a, st_b))
		{
			ft_strprn("Error\n");
			exit(clear_stks(st_a, st_b, 1));
		}
		free(s_op);
	}
	if (*s_op != '\0' || s_op == NULL)
	{
		ft_strprn("Error\n");
		exit(clear_stks(st_a, st_b, 1));
	}
	free(s_op);
	return (0);
}

int	main(int argc, char **argv)
{
	t_head	st_a;
	t_head	st_b;

	ft_stkinit(&st_a);
	ft_stkinit(&st_b);
	if (argc < 2)
		return (1);
	if (ft_errno(load_stack(&st_a, argc, argv)))
		return (2);
	if (ft_errno(execute(&st_a, &st_b)))
		return (clear_stks(&st_a, &st_b, 2));
	if (is_upsort(&st_a) && st_b.quantity == 0)
		ft_strprn("OK\n");
	else
		ft_strprn("KO\n");
	return (clear_stks(&st_a, &st_b, 0));
}
