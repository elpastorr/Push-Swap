/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:59:32 by elpastor          #+#    #+#             */
/*   Updated: 2022/03/11 17:10:13 by elpastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_pile	*lst;

	if (ac < 2)
		return (0);
	lst = malloc(sizeof(t_pile));
	lst->max_a = ac - 1;
	lst->a = malloc(sizeof(int) * ac);
	lst->max_b = 0;
	lst->b = malloc(sizeof(int) * ac);
	fill_pile_a(ac, av, lst);
	if (!check_double(lst))
		ft_exit(lst, 1);
	if (a_is_sorted(lst))
		ft_exit(lst, 0);
	simplify_a(lst);
	if (lst->max_a <= 3)
		sort_small(lst);
	else if (lst->max_a <= 32)
		sort_medium(lst);
	else
		radix_sort(lst);
	ft_exit(lst, 0);
}
