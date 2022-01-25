/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cstack.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:07:34 by cyetta            #+#    #+#             */
/*   Updated: 2022/01/25 19:57:56 by cyetta           ###   ########.fr       */
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

int		load_list(t_head *head, int argc, char **argv);
int		ft_lstaddfront(t_head *hd, t_list *lst);
int		ft_lstaddback(t_head *hd, t_list *lst);
void	ft_lsthdinit(t_head *hd);
t_list	*ft_lstnew(int val);
#endif
