/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:53:03 by elpastor          #+#    #+#             */
/*   Updated: 2022/03/11 17:15:30 by elpastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_pile *lst)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = lst->a[0];
	while (++i < lst->max_a - 1)
		lst->a[i] = lst->a[i + 1];
	lst->a[i] = tmp;
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_pile *lst)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = lst->b[0];
	while (++i < lst->max_b - 1)
		lst->b[i] = lst->b[i + 1];
	lst->b[i] = tmp;
	ft_putstr_fd("rb\n", 1);
}

void	rotate_ab(t_pile *lst)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = lst->a[0];
	while (++i < lst->max_a - 1)
		lst->a[i] = lst->a[i + 1];
	lst->a[i] = tmp;
	i = -1;
	tmp = lst->b[0];
	while (++i < lst->max_b - 1)
		lst->b[i] = lst->b[i + 1];
	lst->b[i] = tmp;
	ft_putstr_fd("rr\n", 1);
}
