#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void    swap_a(t_pile *lst)
{
        int     tmp;

        tmp = lst->a[0];
        lst->a[0] = lst->a[1];
        lst->a[1] = tmp;
}

void    rotate_a(t_pile *lst)
{
        int     i;
        int     tmp;

        i = -1;
        tmp = lst->a[0];
        while (++i < lst->max_a - 1)
                lst->a[i] = lst->a[i + 1];
        lst->a[i] = tmp;
}

void    rev_rotate_a(t_pile *lst)
{

        int     i;
        int     tmp;

        i = lst->max_a + 1;
        tmp = lst->a[lst->max_a - 1];
        while (--i > 0)
                lst->a[i] = lst->a[i - 1];
        lst->a[0] = tmp;
}

int     a_is_sorted(t_pile *lst)
{
        int     i;

        i = -1;
        while (++i < lst->max_a - 1)
                if (lst->a[i] > lst->a[i + 1])
                        return (0);
        return (1);
}

void    ft_swap(int *a, int *b)
{
        int     tmp;

        tmp = *a;
        *a = *b;
        *b = tmp;
}

void    ft_sort_int_tab(int *tab, int size)
{
        int     i;

        i = -1;
        while (++i < size)
        {
                if (tab[i] > tab[i + 1])
                {
                        ft_swap(&tab[i], &tab[i + 1]);
                        i = -1;
                }
                else
                        i++;
        }
}

int     *copy_a(t_pile *lst)
{
        int     *copy;
        int     i;

        copy = malloc(sizeof(int) * lst->max_a);
//      if (!copy)
        i = -1;
        while (++i < lst->max_a)
                copy[i] = lst->a[i];
        return (copy);
}

void    simplify_a(t_pile *lst)
{
        int     i;
        int     j;
        int     *copy;

        copy = copy_a(lst);
        ft_sort_int_tab(copy, lst->max_a);
        i = -1;
        while (++i < lst->max_a)
                printf("%d ", copy[i]);
        i = -1;
        while (++i < lst->max_a)
        {
                j = -1;
                while (++j < lst->max_a)
                        if (lst->a[i] == copy[j])
                                lst->a[i] = j;
        }
}

void    sort_small_stack(t_pile *lst) //if (ac <= 3)
{
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

void    print_lst(t_pile *lst)
{
        int     i;

        i = -1;
        printf("a : ");
        while (++i < lst->max_a)
                printf("%d ", lst->a[i]);
        printf("\n");
}

int     main(int ac, char **av)
{
        int     i;
        int     j;
        t_pile  *lst;

        i = 0;
        lst = malloc(sizeof(t_pile));
        lst->max_a = ac - 1;
        lst->a = malloc(sizeof(int) * ac);
        while (++i < ac)
        {
                lst->a[i - 1] = atoi(av[i]);
        }
        print_lst(lst);
        simplify_a(lst);
        print_lst(lst);
/*      if (a_is_sorted(lst))
                return (0);
        if (lst->max_a <= 3)
                sort_small_stack(lst);
        print_lst(lst);*/
}
