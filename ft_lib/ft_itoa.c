/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 01:24:17 by cyetta            #+#    #+#             */
/*   Updated: 2022/01/25 01:27:59 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_itoa(int a)
{
	unsigned int	n;
	char			ch;

	if (a < 0)
	{
		write(1, "-", 1);
		n = -a;
	}
	else
		n = a;
	if (a == 0)
		write(1, "0", 1);
	else
	{
		if (n / 10)
			ft_itoa(n / 10);
		ch = '0' + n % 10;
		write(1, &ch, 1);
	}
}

void	ft_itoan(int a)
{
	ft_itoa(a);
	write(1, "\n", 1);
}
