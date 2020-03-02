/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_gx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:25:28 by rel-bour          #+#    #+#             */
/*   Updated: 2020/03/02 09:12:40 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

void	print_gr_x(t_str *data, int g)
{
	if (!data->s_zero)
	{
		puts_xg(data);
	}
	else if (data->u == 0 && data->prec == 0 && data->with > 0)
	{
		while (data->with > 0)
		{
			ft_putchar(' ');
			data->with--;
		}
	}
	else if (g == 1)
	{
		ft_putchar(' ');
	}
	else if (g == 2)
	{
		ft_putchar('0');
	}
}

int		if_printgxx(t_str *data, int g)
{
	if (data->u == 0 && data->prec == 0 && data->with > 0)
		g = 1;
	else if (data->u == 0 && data->prec == 1 && data->with == 0)
		g = 2;
	if (data->u == 0)
		data->lend = 1;
	if (data->prec > data->with)
		data->with = 0;
	if (data->with < data->lend)
		data->with = 0;
	else if (data->with >= data->lend)
		data->with = data->with - data->lend;
	if (data->with >= data->prec && data->prec < data->lend)
		data->prec = 0;
	if (data->prec > data->with && data->prec < data->lend)
		data->prec = 0;
	if (data->prec >= data->lend)
		data->prec = data->prec - data->lend;
	if (data->with >= data->prec)
		data->with = data->with - data->prec;
	return (g);
}

void	prec_with_iffpxg(t_str *data)
{
	if (data->prec < 0)
	{
		data->prec = 0;
		data->prec_moin = 1;
	}
	if (data->with < 0)
	{
		data->with = (data->with * (-1));
		data->moin = 1;
	}
}

void	print_xg(t_str *data, char *str2, int i, va_list st)
{
	char	*hex;
	int		g;

	g = 0;
	data->u = va_arg(st, unsigned long);
	hex = conv_hexg(data->u);
	prec_with_iffpxg(data);
	data->lend = ft_strlen(hex);
	g = if_printgxx(data, g);
	if (((str2[i - 1] == '.') && (data->prec == 0) && !data->prec_moin
	&& data->u == 0 && data->with == 0) || ((str2[i - 1] == '0')
	&& (str2[i - 2] == '.') && (data->prec == 0) &&
	!data->prec_moin && data->u == 0 && data->with == 0) ||
	((str2[i - 1] == '*') && (str2[i - 2] == '.') && (data->prec == 0)
	&& !data->prec_moin && data->u == 0 && data->with == 0))
		data->s_zero = 1;
	if ((str2[i - 1] == '.') || ((str2[i - 1] == '*') && (str2[i - 2] == '.'))
	|| ((str2[i - 1] == '0') && (str2[i - 2] == '.')) ||
	((ft_isdigit(str2[i - 1]) == 1) && (str2[i - 2] == '.')))
		data->point_d = 1;
	print_gr_x(data, g);
}
