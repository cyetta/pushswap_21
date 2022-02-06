/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 00:59:19 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/06 03:36:35 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "../ft_lib/ft_libft.h"
#include "../ft_lib/ft_cstack.h"

int	main(int argc, char **argv)
{
	t_head	lst_hda;
	t_head	lst_hdb;

	ft_lsthdinit(&lst_hda);
	ft_lsthdinit(&lst_hdb);

	if (argc < 2)
		return (1);
	if (ft_errno(load_list(&lst_hda, argc, argv)))
		return (2);
	ft_lstprint(lst_hda);
	ft_lstrprint(lst_hda);
	ft_lstdelhdelm(&lst_hda, 0);
	ft_lstprint(lst_hda);
	ft_lstdelhdelm(&lst_hda, 2);
	ft_lstprint(lst_hda);
	ft_lstdelhdelm(&lst_hda, 7);
	ft_lstprint(lst_hda);
	ft_lstdelhdelm(&lst_hda, 0);
	ft_lstdelhdelm(&lst_hda, 0);
	ft_lstprint(lst_hda);
	ft_lsthdfree(&lst_hda);
	return (0);
}
