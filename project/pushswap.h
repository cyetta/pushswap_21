/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:53:52 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/13 17:09:23 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define  PUSHSWAP_H
# include "../ft_lib/ft_cstack.h"

void	ra(t_head *a);
void	rra(t_head *a);
void	rr(t_head *a, t_head *b);
void	rb(t_head *b);
void	rrb(t_head *b);
void	rrr(t_head *a, t_head *b);
void	sa(t_head *a);
void	sb(t_head *b);
void	ss(t_head *a, t_head *b);
void	pb(t_head *a, t_head *b);
void	pa(t_head *a, t_head *b);
int		ft_stksort(t_head *st_a, t_head *st_b);
int		is_upsort(t_head *st);
int		is_presortedup(t_head *st);
int		ra_rra(int idx, int quantity);
#endif
