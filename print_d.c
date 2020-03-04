/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:11:12 by rel-bour          #+#    #+#             */
/*   Updated: 2020/03/02 21:05:48 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ifif_print_d(t_str *data)
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
	if (data->d < 0 && (data->d != (-2147483648)))
	{
		data->d = data->d * (-1);
		data->with -= 1;
		data->d_salib = 1;
	}
	if (data->d == (-2147483647 - 1))
	{
		data->u = 2147483648;
		data->max = 1;
		data->with -= 1;
		data->d_salib = 1;
	}
}

int		if_norm_print_d(t_str *data, int g)
{
	if (data->d == 0 && data->prec == 0 && data->with > 0)
		g = 1;
	else if (data->d == 0 && data->prec == 1 && data->with == 0)
		g = 2;
	if (data->d == 0)
		data->lend = 1;
	if (data->prec > data->with)
		data->with = 0;
	if (data->with < data->lend)
		data->with = 0;
	else if (data->with >= data->lend)
		data->with = data->with - data->lend;
	if (data->with > data->prec && data->prec < data->lend)
		data->prec = 0;
	if (data->prec > data->with && data->prec < data->lend)
		data->prec = 0;
	if (data->prec >= data->lend)
		data->prec = data->prec - data->lend;
	if (data->with >= data->prec)
		data->with = data->with - data->prec;
	return (g);
}

void	printing_norm_print_d(t_str *data, int g)
{
	if (!data->s_zero)
	{
		puts_d(data);
	}
	else if (data->d == 0 && data->prec == 0 && data->with > 0)
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

void	print_d(t_str *data, char *str2, int i, va_list st)
{
	int g;

	g = 0;
	data->d = va_arg(st, int);
	ifif_print_d(data);
	data->lend = lenr(data->d);
	g = if_norm_print_d(data, g);
	if (((str2[i - 1] == '.') && (data->prec == 0) && !data->prec_moin
	&& data->d == 0 && data->with == 0) || ((str2[i - 1] == '0')
	&& (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin &&
	data->d == 0 && data->with == 0) || ((str2[i - 1] == '*') &&
	(str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin
	&& data->d == 0 && data->with == 0))
		data->s_zero = 1;
	if ((str2[i - 1] == '.') || ((str2[i - 1] == '*') &&
	(str2[i - 2] == '.')) || ((str2[i - 1] == '0') &&
	(str2[i - 2] == '.')) || ((ft_isdigit(str2[i - 1]) == 1)
	&& (str2[i - 2] == '.')))
		data->point_d = 1;
	printing_norm_print_d(data, g);
}
