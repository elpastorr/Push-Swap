/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:53:40 by elpastor          #+#    #+#             */
/*   Updated: 2022/03/11 17:16:15 by elpastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a(t_pile *lst)
{
	int	i;
	int	tmp;

	i = lst->max_a + 1;
	tmp = lst->a[i - 2];
	while (--i > 0)
		lst->a[i] = lst->a[i - 1];
	lst->a[0] = tmp;
	ft_putstr_fd("rra\n", 1);
}

void	rev_rotate_b(t_pile *lst)
{
	int	i;
	int	tmp;

	i = lst->max_b + 1;
	tmp = lst->b[i - 2];
	while (--i > 0)
		lst->b[i] = lst->b[i - 1];
	lst->b[0] = tmp;
	ft_putstr_fd("rrb\n", 1);
}

void	rev_rotate_ab(t_pile *lst)
{
	int	i;
	int	tmp;

	i = lst->max_a + 1;
	tmp = lst->a[i - 2];
	while (--i > 0)
		lst->a[i] = lst->a[i - 1];
	lst->a[0] = tmp;
	i = lst->max_b + 1;
	tmp = lst->b[i - 2];
	while (--i > 0)
		lst->b[i] = lst->b[i - 1];
	lst->b[0] = tmp;
	ft_putstr_fd("rrr\n", 1);
}
