/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 00:59:19 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/05 21:02:45 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "../ft_lib/ft_libft.h"
#include "../ft_lib/ft_cstack.h"

int	main(int argc, char **argv)
{
	t_head	lst_hd;

	ft_lsthdinit(&lst_hd);
	if (argc < 2)
		return (1);
	if (ft_errno(load_list(&lst_hd, argc, argv)))
		return (2);
	// ft_lstprint(lst_hd);
	// ft_lstrprint(lst_hd);
	// ft_lstdelhdelm(&lst_hd, 0);
	// ft_lstprint(lst_hd);
	// ft_lstdelhdelm(&lst_hd, 2);
	// ft_lstprint(lst_hd);
	// ft_lstdelhdelm(&lst_hd, 7);
	// ft_lstprint(lst_hd);
	ft_strprn("---\nmin ");
	ft_itoan(lst_hd.min);
	ft_strprn("\nmed ");
	ft_itoan(lst_hd.med);
	ft_strprn("\nmax ");
	ft_itoan(lst_hd.max);
	ft_lsthdfree(&lst_hd);
	return (0);
}
