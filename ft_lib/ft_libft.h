/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 01:43:55 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/18 21:53:44 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# include <stddef.h>

int		ft_atoi(const char *str);
int		ft_atoi_ovfl(const char *str, int *resault);
int		ft_isdigit(int c);
int		ft_isspace(char c);
void	ft_itoa(int a);
void	ft_itoan(int a);
size_t	ft_strlen(const char *s);
void	ft_strprn(const char *str);
#endif
