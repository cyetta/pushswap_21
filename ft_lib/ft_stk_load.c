/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stk_load.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 01:07:47 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/06 18:30:24 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"
#include "ft_cstack.h"
#include "ft_errno.h"

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

static int	ld_valinstk(t_head *hd, int val)
{
	int		i;
	t_list	*t;

	i = -1;
	t = hd->lst_hd;
	while (++i < hd->quantity)
	{
		if (val == t->value)
			return (ERR_DUPLICATE_VALUE);
		t = t->next;
	}
	t = ft_lstnew(val);
	if (!t)
		return (ERR_MEMORY_ALLOCATION);
	ft_stkaddback(hd, t);
	return (ERR_OK);
}

int	load_stack(t_head *head, int argc, char **argv)
{
	int		i;
	int		val;
	int		err;
	char	*s_forsplit;
	char	*subs;

	i = 0;
	while (++i < argc)
	{
		s_forsplit = argv[i];
		subs = ft_splits(&s_forsplit);
		while (subs)
		{
			err = ft_atoi_ovfl(subs, &val);
			if (!err)
				err = ld_valinstk(head, val);
			if (!err)
				subs = ft_splits(&s_forsplit);
			else
				return (err + ft_stkfree(head));
		}
	}
	return (ERR_OK + ft_stkminmax(head));
}
