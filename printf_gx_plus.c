/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_gx_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:57:13 by rel-bour          #+#    #+#             */
/*   Updated: 2020/03/02 12:49:17 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	else_print_xgnorm(t_str *data, int int_prec, char *hex)
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
	{
		if (data->u <= 9)
			ft_putnbr(data->u);
		else
			ft_putstr(hex);
	}
}

void	if_print_xgnorm(t_str *data, int int_prec, char *hex)
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
	{
		if (data->u <= 9)
			ft_putnbr(data->u);
		else
			ft_putstr(hex);
	}
	while (data->with)
	{
		ft_putchar(' ');
		data->with--;
	}
}

void	puts_xg(t_str *data)
{
	int		int_prec;
	char	*hex;
	int		i;

	i = 0;
	hex = conv_hexg(data->u, i);
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
		if_print_xgnorm(data, int_prec, hex);
	else
		else_print_xgnorm(data, int_prec, hex);
}
