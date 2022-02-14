/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyetta <cyetta@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:53:52 by cyetta            #+#    #+#             */
/*   Updated: 2022/02/14 18:43:44 by cyetta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define  PUSHSWAP_H
# include "../ft_lib/ft_cstack.h"

# define OP_RA 0
# define OP_RB 1
# define OP_RRA 2
# define OP_RRB 3
# define OP_RR 4
# define OP_RRR 5

typedef struct s_elweigth
{
	int	opsum;
	int	cmd_a;
	int	qnt_a;
	int	cmd_b;
	int	qnt_b;
}	t_elweigth;

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
void	fill_weight(t_elweigth *el);
int		is_upsort(t_head *st);
int		is_presortedup(t_head *st);
int		ra_rra(int idx, int quantity);
int		clear_stks(t_head *st_a, t_head *st_b, int ft_errno);
#endif
