/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:53:52 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/09 20:23:21 by cyetta           ###   ########.fr       */
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
int		is_upsort(t_head *st);
int		is_presortedup(t_head *st);
#endif
