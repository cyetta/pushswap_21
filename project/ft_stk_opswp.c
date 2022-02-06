/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_opswp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 00:08:58 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/07 01:39:27 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../ft_lib/ft_cstack.h"

void	sa(t_head *a)
{
	ft_stk_opswap(a);
	write(1, "sa\n", 3);
}

void	sb(t_head *b)
{
	ft_stk_opswap(b);
	write(1, "sb\n", 3);
}

void	ss(t_head *a, t_head *b)
{
	ft_stk_opswap(a);
	ft_stk_opswap(b);
	write(1, "ss\n", 3);
}

/*
pb: push b - take the first element at the top of a and put it at the top of b.
    Do nothing if a is empty.
*/
void	pb(t_head *a, t_head *b)
{
	ft_stk_oppush(a, b);
	write(1, "pb\n", 3);
}

/*
pa : push a - take the first element at the top of b and put it at the top of a.
     Do nothing if b is empty.
*/
void	pa(t_head *a, t_head *b)
{
	ft_stk_oppush(b, a);
	write(1, "pa\n", 3);
}
