/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_weight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:40:03 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/17 15:15:47 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	ld_el_eq(t_elweigth *el)
{
	if (el->qnt_a >= 0)
	{
		el->cmd_a = OP_RRR;
		el->cmd_b = OP_RRB;
		el->qnt_b = 0;
	}
	else
	{
		el->cmd_a = OP_RR;
		el->qnt_a = -el->qnt_a;
		el->cmd_b = OP_RB;
		el->qnt_b = 0;
	}
}

static void	ld_el_pos(t_elweigth *el)
{
	if (el->qnt_a > el->qnt_b)
	{
		el->cmd_a = OP_RRA;
		el->qnt_a -= el->qnt_b;
		el->cmd_b = OP_RRR;
	}
	else
	{
		el->cmd_a = OP_RRR;
		el->cmd_b = OP_RRB;
		el->qnt_b -= el->qnt_a;
	}
}

static void	ld_el_neg(t_elweigth *el)
{
	if (el->qnt_a > el->qnt_b)
	{
		el->cmd_a = OP_RR;
		el->qnt_a = -el->qnt_a;
		el->cmd_b = OP_RB;
		el->qnt_b = -(el->qnt_b + el->qnt_a);
	}
	else
	{
		el->cmd_a = OP_RA;
		el->qnt_a = -(el->qnt_a - el->qnt_b);
		el->cmd_b = OP_RR;
		el->qnt_b = -el->qnt_b;
	}
}

void	fill_weight(t_elweigth *el, int val)
{
	if (el->qnt_a == el->qnt_b)
		ld_el_eq(el);
	else if (el->qnt_a > 0 && el->qnt_b > 0)
		ld_el_pos(el);
	else if (el->qnt_a < 0 && el->qnt_b < 0)
		ld_el_neg(el);
	else if (el->qnt_a >= 0 && el->qnt_b <= 0)
	{
		el->cmd_a = OP_RRA;
		el->cmd_b = OP_RB;
		el->qnt_b = -el->qnt_b;
	}
	else if (el->qnt_a <= 0 && el->qnt_b >= 0)
	{
		el->cmd_a = OP_RA;
		el->qnt_a = -el->qnt_a;
		el->cmd_b = OP_RRB;
	}
	el->opsum = el->qnt_a + el->qnt_b;
	el->val = val;
}
