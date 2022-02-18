/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 02:20:11 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/18 03:11:05 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRNO_H
# define FT_ERRNO_H
# define ERR_OK 0
# define ERR_ATOI_OVER 1
# define ERR_ATOI_NOTVALUE 2
# define ERR_DUPLICATE_VALUE 3
# define ERR_MEMORY_ALLOCATION 4
# define ERR_NULL_POINTER 5
# define ERR_NOT_A_COMMAND 6

int		ft_errno(int err);
#endif
