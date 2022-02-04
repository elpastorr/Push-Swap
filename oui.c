#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	swap_b(t_pile *lst)
{
	int	tmp;

	tmp = lst->b[0];
	lst->b[0] = lst->b[1];
	lst->b[1] = tmp;
}

void	swap_a(t_pile *lst)
{
	int	tmp;

	tmp = lst->a[0];
	lst->a[0] = lst->a[1];
	lst->a[1] = tmp;
}

void	rotate_a(t_pile *lst)
{
	int	i;
	int	tmp;

	i = -1;
	tmp = lst->a[0];
	while (++i < lst->max_a - 1)
		lst->a[i] = lst->a[i + 1];
	lst->a[i] = tmp;
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
}

void	rev_rotate_a(t_pile *lst)
{
	int	i;
	int	tmp;

	i = lst->max_a + 1;
	tmp = lst->a[lst->max_a - 1];
	while (--i > 0)
		lst->a[i] = lst->a[i - 1];
	lst->a[0] = tmp;
}

void	rev_rotate_b(t_pile *lst)
{
	int	i;
	int	tmp;

	i = lst->max_b + 1;
	tmp = lst->b[lst->max_b - 1];
	while (--i > 0)
		lst->b[i] = lst->b[i - 1];
	lst->b[0] = tmp;
}

void	push_a(t_pile *lst)
{
	int	i;
	int	tmp;

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
}

void	push_b(t_pile *lst)
{
	int	i;
	int	tmp;

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
}

int	main()
{
	t_pile	*lst;

	lst = malloc(sizeof(t_pile));
	lst->a = malloc(20 * sizeof(int));
	lst->b = malloc(20 * sizeof(int));
	int	i = -1;
	lst->a[0] = -2;
	lst->a[1] = 21;
	lst->a[2] = 5;
	lst->a[3] = 2;	
	lst->b[0] = -7;
	lst->b[1] = 42;
	lst->b[2] = 55;
	lst->b[3] = -21;	
	lst->max_a = 4;
	lst->max_b = 4;
	printf("a : ");
	while (++i < lst->max_a)
		printf("%d ", lst->a[i]);
	printf("\nb : ");
	i = -1;
	while (++i < lst->max_b)
		printf("%d ", lst->b[i]);
	printf("\n");
	rev_rotate_b(lst);
	i = -1;
	printf("\na : ");
	while (++i < lst->max_a)
		printf("%d ", lst->a[i]);
	printf("\nb : ");
	i = -1;
	while (++i < lst->max_b)
		printf("%d ", lst->b[i]);
}
