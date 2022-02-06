/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstack.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 00:07:34 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/06 19:50:22 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CSTACK_H
# define FT_CSTACK_H

typedef struct s_list
{
	int				value;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_lsthead
{
	int		quantity;
	int		min;
	int		max;
	int		med;
	t_list	*lst_hd;
}	t_head;

int		load_stack(t_head *head, int argc, char **argv);
t_list	*ft_lstdelitm(t_list *pnt);
void	ft_lstdellst(t_list *pnt);
t_list	*ft_lstnew(int val);
t_list	*ft_lstrmvitm(t_list *pnt);
int		ft_stkaddfront(t_head *hd, t_list *lst);
int		ft_stkaddback(t_head *hd, t_list *lst);
void	ft_stkdelelm(t_head *hd, int idx);
int		ft_stkfree(t_head *hd);
int		ft_stkinit(t_head *hd);
int		ft_stkminmax(t_head *hd);
void	ft_stkprint(t_head hd);
void	ft_stkprint2(t_head a, t_head b);
void	ft_stkrprint(t_head hd);
void	ft_stk_oprt(t_head *st);
void	ft_stk_oprr(t_head *st);
void	ft_stk_opswap(t_head *st);
void	ft_stk_oppush(t_head *src, t_head *dst);
#endif
