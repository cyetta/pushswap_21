/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 00:59:19 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/18 00:33:34 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_lib/ft_libft.h"
#include "../ft_lib/ft_cstack.h"
#include "../ft_lib/ft_errno.h"
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
	if (!is_upsort(&st_a))
		ft_stksort(&st_a, &st_b);
	return (clear_stks(&st_a, &st_b, 0));
}
