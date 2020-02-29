/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 00:34:33 by rel-bour          #+#    #+#             */
/*   Updated: 2020/02/29 17:50:58 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int        lenR(long nb)
{
    if (!nb)
        return (0);
    return (1 + lenR(nb / 10));
}

int    ft_isdigit(int c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

void ft_putchar(char c)
{
    write(1, &c, 1);
    g_r++;
}

int	ft_strlen(const char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void        ft_putstr(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			ft_putchar(s[i]);
			i++;
		}
	}
}

int    ft_isspec(int c)
{
    if (c == 'c' || c == 's' ||c == 'p' ||
    c == 'd' ||c == 'i' ||
    c == 'u' || c == 'x' || c == 'X' || c == '%')
        return (1);
    else
        return (0);
}

void	ft_putnbr(long n)
{
	long red;

	red = n;
	if (red < 0)
	{
		ft_putchar('-');
		red = red * (-1);
	}
	if (red > 9)
	{
		ft_putnbr(red / 10);
		ft_putchar(((red % 10) + 48));
	}
	else
	{
		ft_putchar(red + 48);
	}
}