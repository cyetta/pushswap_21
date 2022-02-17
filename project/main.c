/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 00:59:19 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/17 19:31:37 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "../ft_lib/ft_libft.h"
#include "../ft_lib/ft_cstack.h"
#include "pushswap.h"

int	clear_stks(t_head *st_a, t_head *st_b, int ft_errno)
{
	ft_stkfree(st_a);
	ft_stkfree(st_b);
	return (ft_errno);
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
	if (!is_upsort(&st_a))
		ft_stksort(&st_a, &st_b);
	return (clear_stks(&st_a, &st_b, 0));
}
