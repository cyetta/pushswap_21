/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_prn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:17:01 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/06 20:09:51 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_cstack.h"
#include "ft_libft.h"

static void	ft_stkprnhd(t_head hd)
{
	ft_strprn("--- count ");
	ft_itoa(hd.quantity);
	ft_strprn(" min ");
	ft_itoa(hd.min);
	ft_strprn(" medium ");
	ft_itoa(hd.med);
	ft_strprn(" max ");
	ft_itoan(hd.max);
}

void	ft_stkprint(t_head hd)
{
	ft_stkprnhd(hd);
	while (hd.quantity--)
	{
		ft_itoan(hd.lst_hd->value);
		hd.lst_hd = hd.lst_hd->next;
	}
}

void	ft_stkrprint(t_head hd)
{
	ft_stkprnhd(hd);
	while (hd.quantity--)
	{
		hd.lst_hd = hd.lst_hd->prev;
		ft_itoan(hd.lst_hd->value);
	}
}

void	ft_stkprint2(t_head a, t_head b)
{
	write(1, "-sta-\t-stb-\n", 12);
	while (a.quantity || b.quantity)
	{
		if (a.quantity)
		{
			ft_itoa(a.lst_hd->value);
			a.lst_hd = a.lst_hd->next;
			a.quantity--;
		}
		if (b.quantity)
		{
			write(1, "\t", 1);
			ft_itoan(b.lst_hd->value);
			b.lst_hd = b.lst_hd->next;
			b.quantity --;
		}
		else
			write(1, "\n", 1);
	}
}
