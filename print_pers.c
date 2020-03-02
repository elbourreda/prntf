/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:15:47 by rel-bour          #+#    #+#             */
/*   Updated: 2020/03/02 11:30:03 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	if_print_pnorm(t_str *data, int int_prec, int h)
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
		print_pors(h);
	while (data->with)
	{
		ft_putchar(' ');
		data->with--;
	}
}

void	else_print_pnorm(t_str *data, int int_prec, int h)
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
		print_pors(h);
}

void	puts_pors(t_str *data, int h)
{
	int int_prec;

	int_prec = 0;
	if (data->w_zero)
	{
		if (!data->point_d || (data->point_d && data->prec_moin
					&& !data->moin))
		{
			data->prec = data->with;
			data->with = 0;
		}
	}
	if (data->moin == 1)
		if_print_pnorm(data, int_prec, h);
	else
		else_print_pnorm(data, int_prec, h);
}
