/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:11:12 by rel-bour          #+#    #+#             */
/*   Updated: 2020/02/28 16:27:49 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void puts_d(t_str *data)
{
	int int_with = 0;
	int int_prec = 0;

	
    if (data->w_zero == 1)
    {
        data->prec = data->with;
        data->with = 0;
    }
    
    if (data->moin == 1)
			{
            if (data->d_salib == 1)
                    ft_putchar('-');
			while (data->prec)
				{
					ft_putchar('0');
					data->prec--;
					int_prec = 1;
				}
			if (data->d == 0 && data->point_d == 1 && data->prec_moin == 0 && int_prec == 0)
                ft_putchar(' ');
            else
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
					int_with = 1;
				}
                if (data->d_salib == 1)
                        ft_putchar('-');
				while (data->prec)
				{
					ft_putchar('0');
					data->prec--;
					int_prec = 1;
				}
                if (data->d == 0 && data->point_d == 1 && data->prec_moin == 0 && int_prec == 0)
                ft_putchar(' ');
                else
				data->max ?  ft_putnbr(data->u): ft_putnbr(data->d);
			}
    
}


void puts_u(t_str *data)
{
	int int_with = 0;
	int int_prec = 0;

	
    if (data->w_zero == 1)
    {
        data->prec = data->with;
        data->with = 0;
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