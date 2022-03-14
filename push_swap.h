/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elpastor <elpastor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:00:27 by elpastor          #+#    #+#             */
/*   Updated: 2022/03/11 17:16:55 by elpastor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct s_pile
{
	int	*a;
	int	*b;
	int	index;
	int	max_a;
	int	max_b;

}	t_pile;

void	push_a(t_pile *lst);
void	push_b(t_pile *lst);
void	swap_a(t_pile *lst);
void	swap_b(t_pile *lst);
void	swap_ab(t_pile *lst);

void	rotate_a(t_pile *lst);
void	rotate_b(t_pile *lst);
void	rotate_ab(t_pile *lst);

void	rev_rotate_a(t_pile *lst);
void	rev_rotate_b(t_pile *lst);
void	rev_rotate_ab(t_pile *lst);

int		a_is_sorted(t_pile *lst);
void	ft_sort_int_tab(int *tab, int size);
void	sort_small(t_pile *lst);
void	sort_medium(t_pile *lst);
void	radix_sort(t_pile *lst);

void	ft_putstr_fd(char *s, int fd);
int		check_double(t_pile *lst);
int		ft_exit(t_pile *lst, int error);
int		ftatoi(const char *nbr, t_pile *lst);
int		fill_pile_a(int ac, char **av, t_pile *lst);

void	ft_swap(int *a, int *b);
int		*copy_a(t_pile *lst);
int		get_min(t_pile *lst);
int		get_max_bit(t_pile *lst);
void	simplify_a(t_pile *lst);

#endif
