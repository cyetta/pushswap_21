/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 00:59:19 by cyetta            #+#    #+#             */
/*   Updated: 2022/01/24 04:04:35 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "../ft_lib/libft.h"

int	main(int argv, char **argc)
{
	int	val;
	int	overflow;

	(void)argc;
	(void)argv;
	overflow = ft_errno(ft_atoi_ovfl("9999999999", &val));
	printf("\n%12d over:%d\n", val, overflow);
	overflow = ft_errno(ft_atoi_ovfl("-2147483648", &val));
	printf("%12d over:%d\n", val, overflow);
	overflow = ft_atoi_ovfl("2147483647", &val);
	printf("%12d over:%d\n", val, overflow);
	overflow = ft_atoi_ovfl("-2147483649", &val);
	printf("%12d over:%d\n", val, overflow);
	overflow = ft_atoi_ovfl("2147483649", &val);
	printf("%12d over:%d\n", val, overflow);
}
