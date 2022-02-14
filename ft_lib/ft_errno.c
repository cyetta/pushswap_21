/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 02:32:16 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/14 22:28:18 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_libft.h"
#include "ft_errno.h"

/*
write error message to stderr, defined by err arg
0 - no error
1-5 defined error with text msg, other - undefided error
*/
int	ft_errno(int err)
{
	char	*errstr[6];

	errstr[ERR_OK] = "OK!\n";
	errstr[ERR_ATOI_OVER] = "Error\n";
	errstr[ERR_ATOI_NOTVALUE] = "Error\n";
	errstr[ERR_DUPLICATE_VALUE] = "Error\n";
	errstr[ERR_MEMORY_ALLOCATION] = "Error\n";
	errstr[ERR_NULL_POINTER] = "Error\n";
	if (err > 5 || err < 0)
		write(2, "Error\n", 16);
	else if (err > 0)
		write(2, errstr[err], ft_strlen(errstr[err]));
	return (err);
}
