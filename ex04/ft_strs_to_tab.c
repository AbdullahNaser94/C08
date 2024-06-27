// #include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	while (str[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	if (!(dest))
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stock;
	int		i;

	stock = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!(stock))
		return (NULL);
	i = 0;
	while (i < ac)
	{
		stock[i].size = ft_strlen(av[i]);
		stock[i].str = av[i];
		stock[i].copy = ft_strcpy(av[i]);
		i++;
	}
	stock[i].size = 0;
	stock[i].str = 0;
	stock[i].copy = 0;
	return (stock);
}


int main(int argc, char **argv)
{
    t_stock_str *result = ft_strs_to_tab(argc, argv);

    if (result == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    int i = 0;
    while (i < argc)
    {
        printf("String %d: %s (Size: %d, Copy: %s)\n", i, result[i].str, result[i].size, result[i].copy);
        i++;
    }

    i = 0;
    while (i < argc)
    {
        free(result[i].copy);
        i++;
    }
    free(result);

    return 0;
}