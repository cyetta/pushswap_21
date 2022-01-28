/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:54:25 by cyetta            #+#    #+#             */
/*   Updated: 2022/01/28 03:18:11 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "errno.h"

/*
return
0 if no digit found
1 found fist symbol of digit and sign is positive
-1  found fist symbol of digit and sign is negative
str point to fist digit in the string or \0
*/
static int	ft_skip_to_dig(char **str)
{
	int	sign;

	sign = 1;
	while (ft_isspace(**str) && **str)
		(*str)++;
	if (**str == '-' || **str == '+' || ft_isdigit(**str))
	{
		if (ft_isdigit(**str))
			return (sign);
		else if (**str == '-')
			sign = -sign;
		(*str)++;
		if (ft_isdigit(**str))
			return (sign);
	}
	return (0);
}

/*
Converting ascii numbers in the string to integer
if no numbers found returned 2 and result=0
if int32 overflowed returned 1 and resault undefined.
if conversion no error returned 0 and int32 value.
conversion ends on last number in string or resault overflow,
rest symbols in string not parsed
*/
int	ft_atoi_ovfl(const char *str, int *resault)
{
	unsigned int	res;
	int				sign;
	char			*s;
	int				overflow;

	s = (char *)str;
	res = 0;
	*resault = 0;
	sign = ft_skip_to_dig(&s);
	if (sign == 0)
		return (2);
	overflow = ERR_OK;
	while (ft_isdigit(*s) && !overflow)
	{
		if ((res >= 214748364) && \
		((sign == 1 && *s > '7') || (sign == -1 && *s > '8')))
			overflow = ERR_ATOI_OVER;
		res = res * 10 + (unsigned int)(*s - '0');
		s++;
	}
	*resault = sign * (int)res;
	return (overflow);
}

int	ft_atoi(const char *str)
{
	long long int	res;
	int				sign;
	char			*s;

	s = (char *)str;
	res = 0;
	sign = ft_skip_to_dig(&s);
	if (sign == 0)
		return (res);
	while (ft_isdigit(*s))
	{
		res = res * 10 + (long long int)(*s - '0');
		s++;
	}
	return (sign * (int)res);
}
