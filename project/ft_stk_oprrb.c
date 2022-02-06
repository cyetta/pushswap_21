/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_oprrb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 00:09:06 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/06 19:18:50 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../ft_lib/ft_cstack.h"

void	rb(t_head *b)
{
	ft_stk_oprt(b);
	write(1, "rb\n", 3);
}

void	rrb(t_head *b)
{
	ft_stk_oprr(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_head *a, t_head *b)
{
	ft_stk_oprr(a);
	ft_stk_oprr(b);
	write(1, "rrr\n", 4);
}
