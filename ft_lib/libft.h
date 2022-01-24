/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 01:43:55 by cyetta            #+#    #+#             */
/*   Updated: 2022/01/24 01:50:25 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

int		ft_atoi(const char *str);
int		ft_atoi_ovfl(const char *str, int *overflow);
int		ft_errno(int err);
int		ft_isdigit(int c);
int		ft_isspace(char c);
size_t	ft_strlen(const char *s);
#endif
