#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void    print_lst(t_pile *lst);

void    push_a(t_pile *lst)
{
        int     i;
        int     tmp;

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
        ft_printf("pa\n");
}

void    push_b(t_pile *lst)
{
        int     i;
        int     tmp;

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
        ft_printf("pb\n");
}

void    swap_a(t_pile *lst)
{
        int     tmp;

        tmp = lst->a[0];
        lst->a[0] = lst->a[1];
        lst->a[1] = tmp;
        ft_printf("sa\n");
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
        ft_printf("ra\n");
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
        ft_printf("rra\n");
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
        {
                j = -1;
                while (++j < lst->max_a)
                        if (lst->a[i] == copy[j])
                        {
                                lst->a[i] = j;
                                j = lst->max_a - 1;
                        }
        }
}

void    sort_small(t_pile *lst)
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

int     get_min(t_pile *lst)
{
        int     i;
        int     min;

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

void    sort_medium(t_pile *lst)
{
        int     i;
        int     min;

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

int     get_max_bit(t_pile *lst)
{
        int     max;
        int     i;

        i = 0;
        max = lst->max_a - 1;
        while (max)
        {
                max = max >> 1;
                i++;
        }
        return (i);
}

void    radix_sort(t_pile *lst)
{
        int     bit;
        int     i;
        int     max_bit;

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
        lst->max_b = 0;
        lst->b = malloc(sizeof(int) * ac);
        while (++i < ac)
        {
                lst->a[i - 1] = atoi(av[i]);
        }
        print_lst(lst);
        if (a_is_sorted(lst))
                return (0);
        simplify_a(lst);
        print_lst(lst);
        if (lst->max_a <= 3)
                sort_small(lst);
        else if (lst->max_a <= 64)
        {
                sort_medium(lst);
                printf("gang\n");
        }
        else
        {
                radix_sort(lst);
                printf("radixgang\n");
        }
        print_lst(lst);
}
