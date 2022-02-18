/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:50:44 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/18 20:30:36 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "checker.h"

int	getnextln(char **str)
{
	int		i;
	int		rd;
	char	*buf;

	buf = malloc(10);
	if (!buf)
		return (0);
	*str = buf;
	i = 0;
	while (i < 9)
	{
		rd = read(0, &buf[i], 1);
		if (rd <= 0 || buf[i] == '\n')
			break ;
		i++;
	}
	buf[i] = '\0';
	return (rd);
}
