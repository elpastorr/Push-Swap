#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *nbr)
{
	int		nb;
	int		neg;
	size_t	i;

	i = 0;
	nb = 0;
	neg = 1;
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
	return (nb * neg);
}

void	printlst(t_pile *lst)
{
	int	i;

	i = -1;
	printf("a : ");
	while (++i < lst->max_a)
		printf("%d ", lst->a[i]);
	printf("\n");
	i = -1;
	printf("b : ");
	while (++i < lst->max_b)
		printf("%d ", lst->b[i]);
	printf("\n");
}

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}



int	ft_free(t_pile *lst)
{
	free(lst);
}

int	main(int ac,char **av)
{
	int		i;
	int		j;
	t_pile	*lst;

	if (ac < 2)
		return (0);
	i = 0;
	lst = malloc(sizeof(t_pile));
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if ((j != 0 || av[i][j] != '-') && (av[i][j] < '0' || av[i][j] > '9'))
			{	
				ft_putstr("Error\n");
				return (ft_free(lst));
			}
		}
	}
	lst->max_a = i - 1;
	lst->max_b = 0;
	lst->a = malloc(sizeof(int) * i);
	lst->b = malloc(sizeof(int) * i);
	i = 0;
	while (++i < ac)
	{
		lst->a[i - 1] = ft_atoi(av[i]);
	}
	printlst(lst);
}
