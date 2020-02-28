/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:11:12 by rel-bour          #+#    #+#             */
/*   Updated: 2020/02/28 12:43:50 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void puts_d(t_str *data)
{
    if (data->w_zero == 1)
    {
        data->prec = data->with;
        data->with = 0;
    }
    
    if (data->moin == 1)
			{
            if (data->d_salib == 1)
                    ft_putchar('-');
			data->max ?  ft_putnbr(data->u): ft_putnbr(data->d);
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
                if (data->d_salib == 1)
                        ft_putchar('-');
				while (data->prec)
				{
					ft_putchar('0');
					data->prec--;
				}
                if (data->d == 0 && data->point_d == 1 && data->prec_moin == 0)
                ft_putchar(' ');
                else
				data->max ?  ft_putnbr(data->u): ft_putnbr(data->d);
			}
    
}