/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 02:32:16 by cyetta            #+#    #+#             */
/*   Updated: 2022/01/24 04:01:28 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
write error message to stderr, defined by err arg
*/
int	ft_errno(int err)
{
	char	*errstr[5];

	errstr[0] = "Error1\n";
	errstr[1] = "Error2\n";
	errstr[2] = "Error3\n";
	errstr[3] = "Error4\n";
	errstr[4] = "Error5\n";
	if (err > 5 || err < 0)
		write(2, "Undefined error\n", 16);
	else if (err > 0)
		write(2, errstr[err - 1], ft_strlen(errstr[err - 1]));
	return (err);
}
