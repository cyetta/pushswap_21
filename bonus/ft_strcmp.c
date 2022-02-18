/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 13:11:06 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/18 20:58:49 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int	res;

	while (*s1 != '\0' && *s2 != '\0')
	{
		res = (*(unsigned char *)s1 - *(unsigned char *)s2);
		if (res)
			return (res);
		s1++;
		s2++;
	}
	res = (*(unsigned char *)s1 - *(unsigned char *)s2);
	return (res);
}
