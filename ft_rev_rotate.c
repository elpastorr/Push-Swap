void    rev_rotate_a(t_pile *lst)
{

        int     i;
        int     tmp;

        i = lst->max_a + 1;
        tmp = lst->a[i - 2];
        while (--i > 0)
                lst->a[i] = lst->a[i - 1];
        lst->a[0] = tmp;
        ft_printf("rra\n");
}

void    rev_rotate_b(t_pile *lst)
{

        int     i;
        int     tmp;

        i = lst->max_b + 1;
        tmp = lst->b[i - 2];
        while (--i > 0)
                lst->b[i] = lst->b[i - 1];
        lst->b[0] = tmp;
        ft_printf("rrb\n");
}

void    rev_rotate_ab(t_pile *lst)
{

        int     i;
        int     tmp;

        i = lst->max_a + 1;
        tmp = lst->a[i - 2];
        while (--i > 0)
                lst->a[i] = lst->a[i - 1];
        lst->a[0] = tmp;
        i = lst->max_b + 1;
        tmp = lst->b[i - 2];
        while (--i > 0)
                lst->b[i] = lst->b[i - 1];
        lst->b[0] = tmp;
        ft_printf("rrr\n");
}
