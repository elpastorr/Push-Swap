/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:23:45 by elpastor          #+#    #+#             */
/*   Updated: 2022/03/11 17:23:47 by elpastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*copy_a(t_pile *lst)
{
	int	*copy;
	int	i;

	copy = malloc(sizeof(int) * lst->max_a);
	if (!copy)
		ft_exit(lst, 1);
	i = -1;
	while (++i < lst->max_a)
		copy[i] = lst->a[i];
	return (copy);
}

int	get_max_bit(t_pile *lst)
{
	int	max;
	int	i;

	i = 0;
	max = lst->max_a - 1;
	while (max)
	{
		max = max >> 1;
		i++;
	}
	return (i);
}

int	get_min(t_pile *lst)
{
	int	i;
	int	min;

	i = -1;
	min = 10;
	while (++i < lst->max_a)
		if (min > lst->a[i])
			min = lst->a[i];
	i = -1;
	while (++i < lst->max_a)
		if (lst->a[i] == min)
			return (i);
	return (0);
}

void	simplify_a(t_pile *lst)
{
	int	i;
	int	j;
	int	*copy;

	copy = copy_a(lst);
	ft_sort_int_tab(copy, lst->max_a);
	i = -1;
	while (++i < lst->max_a)
	{
		j = -1;
		while (++j < lst->max_a)
		{
			if (lst->a[i] == copy[j])
			{
				lst->a[i] = j;
				j = lst->max_a - 1;
			}
		}
	}
	free(copy);
}
