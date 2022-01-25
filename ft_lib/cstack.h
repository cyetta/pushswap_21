/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstack.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:07:34 by cyetta            #+#    #+#             */
/*   Updated: 2022/01/25 01:51:12 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CSTACK_H
# define CSTACK_H

typedef struct s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_lsthead
{
	int		quantity;
	t_list	*lst_hd;
}	t_head;

int	load_list(t_head *head, int argc, char **argv);

#endif
