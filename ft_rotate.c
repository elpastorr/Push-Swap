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

void    rotate_b(t_pile *lst)
{
        int     i;
        int     tmp;

        i = -1;
        tmp = lst->b[0];
        while (++i < lst->max_b - 1)
                lst->b[i] = lst->b[i + 1];
        lst->b[i] = tmp;
        ft_printf("rb\n");
}

void    rotate_ab(t_pile *lst)
{
        int     i;
        int     tmp;

        i = -1;
        tmp = lst->a[0];
        while (++i < lst->max_a - 1)
                lst->a[i] = lst->a[i + 1];
        lst->a[i] = tmp;
        i = -1;
        tmp = lst->b[0];
        while (++i < lst->max_b - 1)
                lst->b[i] = lst->b[i + 1];
        lst->b[i] = tmp;
        ft_printf("rr\n");
}
