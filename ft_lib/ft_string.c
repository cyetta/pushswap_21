/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:15:33 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/05 20:11:43 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++)
		++len;
	return (len);
}

void	ft_strprn(const char *str)
{
	if (!str)
		return ;
	write(1, str, ft_strlen(str));
}
