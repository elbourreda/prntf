/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 14:48:55 by rel-bour          #+#    #+#             */
/*   Updated: 2020/03/02 10:02:27 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	while_putu(t_str *data, int int_prec)
{
	while (data->prec)
	{
		ft_putchar('0');
		data->prec--;
		int_prec = 1;
	}
	if (data->u == 0 && data->point_d == 1 && data->prec_moin == 0
			&& int_prec == 0)
		ft_putchar(' ');
	else
		ft_putnbr(data->u);
	while (data->with)
	{
		ft_putchar(' ');
		data->with--;
	}
}

void	while_put_norm(t_str *data, int int_prec)
{
	while (data->with)
	{
		ft_putchar(' ');
		data->with--;
	}
	while (data->prec)
	{
		ft_putchar('0');
		data->prec--;
		int_prec = 1;
	}
	if (data->u == 0 && data->point_d == 1 && data->prec_moin == 0
			&& int_prec == 0)
		ft_putchar(' ');
	else
		ft_putnbr(data->u);
}

void	puts_u(t_str *data)
{
	int int_with;
	int int_prec;

	int_with = 0;
	int_prec = 0;
	if (data->w_zero)
	{
		if (!data->point_d || (data->point_d && data->prec_moin && !data->moin))
		{
			data->prec = data->with;
			data->with = 0;
		}
	}
	if (data->moin == 1)
		while_putu(data, int_prec);
	else
		while_put_norm(data, int_prec);
}
