/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:17:01 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/06 02:31:30 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_cstack.h"
#include "ft_libft.h"

static void	ft_lstprnhd(t_head hd)
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

void	ft_lstprint(t_head hd)
{
	ft_lstprnhd(hd);
	while (hd.quantity--)
	{
		ft_itoan(hd.lst_hd->value);
		hd.lst_hd = hd.lst_hd->next;
	}
}

void	ft_lstrprint(t_head hd)
{
	ft_lstprnhd(hd);
	while (hd.quantity--)
	{
		hd.lst_hd = hd.lst_hd->prev;
		ft_itoan(hd.lst_hd->value);
	}
}
