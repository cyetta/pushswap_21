/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_oprra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 00:09:06 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/06 19:17:31 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../ft_lib/ft_cstack.h"

void	ra(t_head *a)
{
	ft_stk_oprt(a);
	write(1, "ra\n", 3);
}

void	rra(t_head *a)
{
	ft_stk_oprr(a);
	write(1, "rra\n", 4);
}

void	rr(t_head *a, t_head *b)
{
	ft_stk_oprt(a);
	ft_stk_oprt(b);
	write(1, "rr\n", 3);
}
