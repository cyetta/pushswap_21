/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:17:01 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/05 20:18:32 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_cstack.h"
#include "ft_libft.h"

void	ft_lstprint(t_head hd)
{
	while (hd.quantity--)
	{
		ft_itoan(hd.lst_hd->value);
		hd.lst_hd = hd.lst_hd->next;
	}
}

void	ft_lstrprint(t_head hd)
{
	while (hd.quantity--)
	{
		hd.lst_hd = hd.lst_hd->prev;
		ft_itoan(hd.lst_hd->value);
	}
}
