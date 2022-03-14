/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:52:10 by elpastor          #+#    #+#             */
/*   Updated: 2022/03/11 17:14:32 by elpastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_pile *lst)
{
	int		i;
	int		tmp;

	i = lst->max_a + 1;
	tmp = lst->b[0];
	while (--i > 0)
		lst->a[i] = lst->a[i - 1];
	lst->a[0] = tmp;
	i = -1;
	while (++i < lst->max_b)
		lst->b[i] = lst->b[i + 1];
	lst->max_a++;
	lst->max_b--;
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_pile *lst)
{
	int		i;
	int		tmp;

	i = lst->max_b + 1;
	tmp = lst->a[0];
	while (--i > 0)
		lst->b[i] = lst->b[i - 1];
	lst->b[0] = tmp;
	i = -1;
	while (++i < lst->max_a)
		lst->a[i] = lst->a[i + 1];
	lst->max_b++;
	lst->max_a--;
	ft_putstr_fd("pb\n", 1);
}

void	swap_a(t_pile *lst)
{
	int		tmp;

	tmp = lst->a[0];
	lst->a[0] = lst->a[1];
	lst->a[1] = tmp;
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_pile *lst)
{
	int		tmp;

	tmp = lst->b[0];
	lst->b[0] = lst->b[1];
	lst->b[1] = tmp;
	ft_putstr_fd("sb\n", 1);
}

void	swap_ab(t_pile *lst)
{
	int		tmp;

	tmp = lst->a[0];
	lst->a[0] = lst->a[1];
	lst->a[1] = tmp;
	tmp = lst->b[0];
	lst->b[0] = lst->b[1];
	lst->b[1] = tmp;
	ft_putstr_fd("ss\n", 1);
}
