/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 18:11:54 by rel-bour          #+#    #+#             */
/*   Updated: 2020/03/01 18:56:55 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isspec(int c)
{
	if (c == 'c' || c == 's' || c == 'p' ||
			c == 'd' || c == 'i' ||
			c == 'u' || c == 'x' || c == 'X')
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

int		ft_atoi(const char *str)
{
	long	rslt;
	int		sign;
	int		cnt;

	rslt = 0;
	sign = 1;
	cnt = 0;
	while (str[cnt] == 32 || (str[cnt] >= 9 && str[cnt] <= 13))
		cnt++;
	if (str[cnt] == '-')
	{
		cnt++;
		sign = -1;
	}
	else if (str[cnt] == '+')
		cnt++;
	while (str[cnt] >= '0' && str[cnt] <= '9')
	{
		rslt = rslt * 10 + (str[cnt] - '0');
		if (rslt < 0)
			return ((sign > 0) ? -1 : 0);
		cnt++;
	}
	return (rslt * sign);
}
