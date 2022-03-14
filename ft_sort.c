/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:50:22 by elpastor          #+#    #+#             */
/*   Updated: 2022/03/14 18:16:18 by elpastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	a_is_sorted(t_pile *lst)
{
	int		i;

	i = -1;
	while (++i < lst->max_a - 1)
		if (lst->a[i] > lst->a[i + 1])
			return (0);
	return (1);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int		i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

void	sort_small(t_pile *lst)
{
	if (a_is_sorted(lst))
		return ;
	if (lst->max_a == 2)
		swap_a(lst);
	else if (lst->a[0] < lst->a[1])
	{
		if (lst->a[0] > lst->a[2])
			rev_rotate_a(lst);
		else
		{
			swap_a(lst);
			rotate_a(lst);
		}
	}
	else if (lst->a[1] > lst->a[2])
	{
		swap_a(lst);
		rev_rotate_a(lst);
	}
	else if (lst->a[0] < lst->a[2])
		swap_a(lst);
	else
		rotate_a(lst);
}

void	sort_medium(t_pile *lst)
{
	int		min;

	min = 0;
	while (!a_is_sorted(lst) && min < (lst->max_a + lst->max_b) - 3)
	{
		while (lst->a[0] != min)
		{
			if (get_min(lst) <= lst->max_a / 2)
				rotate_a(lst);
			else
				rev_rotate_a(lst);
		}
		push_b(lst);
		min++;
	}
	sort_small(lst);
	while (min--)
		push_a(lst);
}

void	radix_sort(t_pile *lst)
{
	int		bit;
	int		i;
	int		max_bit;

	bit = -1;
	max_bit = get_max_bit(lst);
	while (++bit < max_bit)
	{
		if (a_is_sorted(lst))
			return ;
		i = 0;
		while (i < lst->max_a)
		{
			if ((lst->a[0] >> bit) % 2 == 0)
				push_b(lst);
			else
			{
				rotate_a(lst);
				i++;
			}
		}
		while (lst->max_b > 0)
			push_a(lst);
	}
}
