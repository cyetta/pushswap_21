/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 00:59:19 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/10 00:55:04 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "../ft_lib/ft_libft.h"
#include "../ft_lib/ft_cstack.h"
#include "pushswap.h"

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
	ft_stkprint2(st_a, st_b);
	if (is_upsort(&st_a))
		ft_strprn("stack a is sorted\n");
	else
		ft_strprn("stack a is unsorted\n");
	ft_stkprint2(st_a, st_b);
	ft_stkfree(&st_a);
	ft_stkfree(&st_b);
	return (0);
}

	// ft_stkrprint(st_a);
	// ft_stkdelelm(&st_a, 0);
	// ft_stkdelelm(&st_a, 2);
	// ft_stkprint(st_a);
	// ft_stkdelelm(&st_a, 7);
	// ft_stkprint(st_a);
	// ft_stkdelelm(&st_a, 0);
	// ft_stkdelelm(&st_a, 0);
	// ft_stkprint(st_a);
	// pb(&st_a, &st_b);
	// pb(&st_a, &st_b);
	// pb(&st_a, &st_b);
	// ft_stkprint2(st_a, st_b);
	// ra(&st_a);
	// rb(&st_b);
	// ft_stkprint2(st_a, st_b);
	// sa(&st_a);
	// sb(&st_b);
	// ft_stkprint2(st_a, st_b);
	// rr(&st_a, &st_b);
	// ft_stkprint2(st_a, st_b);
	// ss(&st_a, &st_b);
	// ft_stkprint2(st_a, st_b);
	// pa(&st_a, &st_b);
	// ft_stkprint2(st_a, st_b);
	// rrr(&st_a, &st_b);
	// ft_stkprint2(st_a, st_b);
	// pb(&st_a, &st_b);
	// pb(&st_a, &st_b);
	// ft_stkprint2(st_a, st_b);
	// rra(&st_a);
	// rrb(&st_b);
	// ft_stkprint2(st_a, st_b);
	// ft_stkfree(&st_a);
	// ft_stkfree(&st_b);
