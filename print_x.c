/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:24:15 by rel-bour          #+#    #+#             */
/*   Updated: 2020/03/02 08:58:09 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	priint_ppp(t_str *data, int g)
{
	if (!data->s_zero)
		puts_x(data);
	else if (data->u == 0 && data->prec == 0 && data->with > 0)
	{
		while (data->with > 0)
		{
			ft_putchar(' ');
			data->with--;
		}
	}
	else if (g == 1)
		ft_putchar(' ');
	else if (g == 2)
		ft_putchar('0');
}

int		if_print_p(t_str *data, int g)
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

void	prec_with_if(t_str *data)
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

void	print_x(t_str *data, char *str2, int i, va_list st)
{
	int		g;
	char	*hex;

	g = 0;
	data->u = va_arg(st, unsigned long);
	hex = conv_hex(data->u);
	prec_with_if(data);
	data->lend = ft_strlen(hex);
	g = if_print_p(data, g);
	if (((str2[i - 1] == '.') && (data->prec == 0) && !data->prec_moin
	&& data->u == 0 && data->with == 0) || ((str2[i - 1] == '0') &&
	(str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin &&
	data->u == 0 && data->with == 0)
	|| ((str2[i - 1] == '*') && (str2[i - 2] == '.') && (data->prec == 0) &&
	!data->prec_moin && data->u == 0 && data->with == 0))
		data->s_zero = 1;
	if ((str2[i - 1] == '.') || ((str2[i - 1] == '*') && (str2[i - 2] == '.'))
	|| ((str2[i - 1] == '0') && (str2[i - 2] == '.')) ||
	((ft_isdigit(str2[i - 1]) == 1) && (str2[i - 2] == '.')))
		data->point_d = 1;
	priint_ppp(data, g);
}
