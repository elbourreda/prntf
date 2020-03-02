/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 20:35:35 by rel-bour          #+#    #+#             */
/*   Updated: 2020/03/02 20:51:44 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	norm_if_putsd(t_str *data, int int_prec)
{
	if (data->d_salib == 1)
		ft_putchar('-');
	while (data->prec)
	{
		ft_putchar('0');
		data->prec--;
		int_prec = 1;
	}
	if (data->d == 0 && data->point_d == 1 && data->prec_moin == 0
			&& int_prec == 0)
		ft_putchar(' ');
	else
		data->max ? ft_putnbr(data->u) : ft_putnbr(data->d);
	while (data->with)
	{
		ft_putchar(' ');
		data->with--;
	}
}

void	norm_else_putsd(t_str *data, int int_prec)
{
	while (data->with)
	{
		ft_putchar(' ');
		data->with--;
	}
	if (data->d_salib == 1)
		ft_putchar('-');
	while (data->prec)
	{
		ft_putchar('0');
		data->prec--;
		int_prec = 1;
	}
	if (data->d == 0 && data->point_d == 1 && data->prec_moin == 0
			&& int_prec == 0)
		ft_putchar(' ');
	else
		data->max ? ft_putnbr(data->u) : ft_putnbr(data->d);
}

void	puts_d(t_str *data)
{
	int int_prec;

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
		norm_if_putsd(data, int_prec);
	else
		norm_else_putsd(data, int_prec);
}
