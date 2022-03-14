/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:07:33 by elpastor          #+#    #+#             */
/*   Updated: 2022/03/11 17:21:28 by elpastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		write(fd, &s[i], 1);
}

int	check_double(t_pile *lst)
{
	int	i;
	int	j;

	i = -1;
	while (++i < lst->max_a)
	{
		j = i;
		while (++j < lst->max_a)
			if (lst->a[i] == lst->a[j])
				return (0);
	}
	return (1);
}

int	ft_exit(t_pile *lst, int error)
{
	if (lst)
	{
		if (lst->a)
			free(lst->a);
		if (lst->b)
			free(lst->b);
		free(lst);
	}
	if (error == 1)
		ft_putstr_fd("Error\n", 2);
	exit(error);
}

int	ftatoi(const char *nbr, t_pile *lst)
{
	unsigned long long	nb;
	int					neg;
	size_t				i;

	i = 0;
	nb = 0;
	neg = 1;
	while (nbr[i])
		i++;
	if (i > 11)
		ft_exit(lst, 1);
	i = 0;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
		i++;
	if (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			neg = -1;
		i++;
	}
	while (nbr[i] >= '0' && nbr[i] <= '9')
		nb = (nb * 10 + (nbr[i++] - '0'));
	if ((nb > 2147483647 && neg == 1) || (nb > 2147483648 && neg == -1))
		ft_exit(lst, 1);
	return (nb * neg);
}

int	fill_pile_a(int ac, char **av, t_pile *lst)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if ((j != 0 || av[i][j] != '-')
			&& (av[i][j] < '0' || av[i][j] > '9'))
				ft_exit(lst, 1);
		}
		lst->a[i - 1] = ftatoi(av[i], lst);
	}
	return (0);
}
