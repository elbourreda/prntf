/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:11:12 by rel-bour          #+#    #+#             */
/*   Updated: 2020/02/28 10:12:51 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void puts_d(t_str *data)
{
    if (data->moin == 1)
			{
			ft_putnbr(data->d);
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
				}
				while (data->prec)
				{
					ft_putchar('0');
					data->prec--;
				}
				ft_putnbr(data->d);
			}
    
}