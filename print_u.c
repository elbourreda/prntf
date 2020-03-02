/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:48:55 by rel-bour          #+#    #+#             */
/*   Updated: 2020/03/01 18:19:59 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"


void puts_u(t_str *data)
{
	int int_with = 0;
	int int_prec = 0;

	if (data->w_zero)
	{
		if (!data->point_d || (data->point_d && data->prec_moin && !data->moin))
		{
			data->prec = data->with;
			data->with = 0;
		}

	}

	if (data->moin == 1)
	{

		while (data->prec)
		{
			ft_putchar('0');
			data->prec--;
			int_prec = 1;
		}
		if (data->u == 0 && data->point_d == 1 && data->prec_moin == 0 && int_prec == 0)
			ft_putchar(' ');
		else
			ft_putnbr(data->u);
		while (data->with)
		{
			ft_putchar(' ');
			data->with--;
		}

	}
	else
	{
		while (data->with)
		{
			ft_putchar(' ');
			data->with--;
			int_with = 1;
		}

		while (data->prec)
		{
			ft_putchar('0');
			data->prec--;
			int_prec = 1;
		}
		if (data->u == 0 && data->point_d == 1 && data->prec_moin == 0 && int_prec == 0)
			ft_putchar(' ');
		else
			ft_putnbr(data->u);
	}

}

void print_u(t_str *data, char *str2, int i, va_list st)
{
	data->u = va_arg(st, unsigned long);
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


	data->lend = lenr(data->u);
	int g = 0;
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

	if (data->with > data->prec && data->prec < data->lend)
		data->prec = 0;

	if (data->prec > data->with && data->prec < data->lend)
		data->prec = 0;

	if (data->prec >= data->lend)
		data->prec = data->prec - data->lend;

	if (data->with >= data->prec)
		data->with = data->with - data->prec;


	if (((str2[i - 1] == '.') && (data->prec == 0) && !data->prec_moin && data->u == 0 && data->with == 0) 
			||((str2[i - 1] == '0') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->u == 0 && data->with == 0)
			|| ((str2[i - 1] == '*') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->u == 0 && data->with == 0 ) )
		data->s_zero = 1;


	if ((str2[i - 1] == '.') || ((str2[i - 1] == '*') && (str2[i - 2] == '.')) ||
			((str2[i - 1] == '0') && (str2[i - 2] == '.')) ||
			((ft_isdigit(str2[i - 1]) == 1) && (str2[i - 2] == '.')))
		data->point_d = 1;

	if (!data->s_zero)
	{
		puts_u(data);
	}
	else if (data->u == 0 && data->prec == 0 && data->with > 0)
	{
		while (data->with > 0)
		{
			ft_putchar(' ');
			data->with--;
		}
	}
	else if (g==1)
	{
		ft_putchar(' ');
	}
	else if (g == 2)
	{
		ft_putchar('0');
	}

}
