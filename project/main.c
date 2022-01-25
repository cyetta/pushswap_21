/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 00:59:19 by cyetta            #+#    #+#             */
/*   Updated: 2022/01/25 01:52:46 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "../ft_lib/libft.h"
#include "../ft_lib/cstack.h"

int	main(int argc, char **argv)
{
	t_head	t_head;

	if (argc < 2)
		return (1);
	else if (ft_errno(load_list(&t_head, argc, argv)))
		return (2);
	return (0);
}
