// #include <unistd.h>
#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

void mini_putnbr(int nb)
{
    char c;

    if (nb < 0)
    {
        write(1, "-", 1);
        nb = -nb;
    }
    c = nb + '0';
    write(1, &c, 1);
}

void ft_putnbr(int nb)
{
    if (nb == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }
    if (nb < 0)
    {
        write(1, "-", 1);
        nb = -nb;
    }
    if (nb >= 10)
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }
    else
    {
        mini_putnbr(nb);
    }
}

void ft_putstring(char* str)
{
    int i;

    if (str)
    {
        i = 0;
        while (str[i])
            i++;
        write(1, str, i);
    }
    write(1, "\n", 1);
}

void ft_show_tab(struct s_stock_str* par)
{
    int i;

    i = 0;
    while (par[i].str)
    {
        ft_putstring(par[i].str);
        ft_putnbr(par[i].size);
        write(1, "\n", 1);
        ft_putstring(par[i].copy);
        i++;
    }
}

int main(void)
{
    t_stock_str tab[3];

    tab[0].size = 5;
    tab[0].str = "Hello";
    tab[0].copy = "Hello";

    tab[1].size = 4;
    tab[1].str = "Test";
    tab[1].copy = "Test";

    tab[2].size = 0;
    tab[2].str = 0;
    tab[2].copy = 0;

    ft_show_tab(tab);
    return 0;
}