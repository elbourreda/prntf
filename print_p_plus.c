/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 10:14:20 by rel-bour          #+#    #+#             */
/*   Updated: 2020/03/02 12:49:53 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	norm_p_if(t_str *data, int int_prec, char *hex)
{
	while (data->prec)
	{
		ft_putchar('0');
		data->prec--;
		int_prec = 1;
	}
	if (data->p == 0 && data->point_d == 1 && data->prec_moin == 0
			&& int_prec == 0)
	{
		ft_putstr("0x");
		ft_putchar(' ');
	}
	else
		ft_putstr(hex);
	while (data->with)
	{
		ft_putchar(' ');
		data->with--;
	}
}

void	norm_p_else(t_str *data, int int_prec, char *hex)
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
	if (data->p == 0 && data->point_d == 1 && data->prec_moin == 0
			&& int_prec == 0)
	{
		ft_putchar(' ');
		ft_putstr("0x");
	}
	else
		ft_putstr(hex);
}

void	puts_p(t_str *data)
{
	int		int_prec;
	char	*hex;
	int		i;

	i = 0;
	hex = conv_hexp(data->p, i);
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
		norm_p_if(data, int_prec, hex);
	else
		norm_p_else(data, int_prec, hex);
}
