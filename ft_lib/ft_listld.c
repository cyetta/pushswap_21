/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 01:07:47 by cyetta            #+#    #+#             */
/*   Updated: 2022/01/25 03:35:55 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cstack.h"

/*
Splits source string s on substrings by space symbol (look ft_isspace)
s - pointer to next space sequence, in the begining point to source string
Returns pointer to the non space sequence and modify s to point next space
symbol in the string, have use this pointer on next iteration.
If next substring not finded, returned NULL
*/
static char	*ft_splits(char **s)
{
	char	*dest;

	while (ft_isspace(**s))
		(*s)++;
	if (!**s)
		return (NULL);
	dest = *s;
	while (!ft_isspace(**s) && **s)
		(*s)++;
	return (dest);
}

int	load_list(t_head *head, int argc, char **argv)
{
	int		i;
	int		val;
	int		err;
	char	*s_forsplit;
	char	*subs;

	(void)head;
	i = 0;
	while (++i < argc)
	{
		s_forsplit = argv[i];
		subs = ft_splits(&s_forsplit);
		while (subs)
		{
			err = ft_atoi_ovfl(subs, &val);
			if (err)
				return (err);
			ft_itoan(val);
			subs = ft_splits(&s_forsplit);
		}
	}
	return (0);
}
