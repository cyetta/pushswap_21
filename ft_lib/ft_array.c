/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 19:43:39 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/05 20:15:55 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libft.h"
/*
Buble sort int array
 */
void	ft_arrsort(int *arr, int len)
{
	int	i;
	int	j;
	int	t;

	if (len < 2)
		return ;
	i = -1;
	while (++i < len)
	{
		j = i;
		while (++j < len)
		{
			if (arr[i] > arr[j])
			{
				t = arr[j];
				arr[j] = arr[i];
				arr[i] = t;
			}
		}
	}
}

/*
print len items of array to stdout
*/
void	ft_arrprnt(int *arr, int len)
{
	int	i;

	if (len < 1)
		return ;
	i = -1;
	while (++i < len)
	{
		ft_itoan(arr[i]);
	}
}
