/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 02:32:16 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/05 20:49:59 by cyetta           ###   ########.fr       */
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
	errstr[ERR_ATOI_OVER] = "Error(1) integer overflow\n";
	errstr[ERR_ATOI_NOTVALUE] = "Error(2) not int value\n";
	errstr[ERR_DUPLICATE_VALUE] = "Error(3) duplicate value\n";
	errstr[ERR_MEMORY_ALLOCATION] = "Error(4) Memory allocation error\n";
	errstr[ERR_NULL_POINTER] = "Error(5) NULL Pointer used\n";
	if (err > 5 || err < 0)
		write(2, "Undefined error\n", 16);
	else if (err > 0)
		write(2, errstr[err], ft_strlen(errstr[err]));
	return (err);
}
