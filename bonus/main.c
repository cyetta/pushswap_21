/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 00:59:19 by cyetta            #+#    #+#             */
/*   Updated: 2022/01/24 04:12:56 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../ft_lib/libft.h"

int	main(int argv, char **argc)
{
	(void)argc;
	(void)argv;
	write(1, "Here will be a checker :) \n", 27);
}
