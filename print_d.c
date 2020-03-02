/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:11:12 by rel-bour          #+#    #+#             */
/*   Updated: 2020/03/01 18:21:11 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void puts_d(t_str *data)
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

void print_d(t_str *data, char *str2, int i, va_list st)
{
	data->d = va_arg(st, int);
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
		
		
		if (data->d < 0 && data-> d != (-2147483648))
		{
			data->d = data->d * -1;
			data->with -= 1;
			data->d_salib = 1;
		}
		if (data->d == (-2147483647 - 1))
		{
				data->u = 2147483648;
				data->max = 1;
				data->with -= 1;
				data->d_salib = 1;
		}
		data->lend = lenr(data->d);
		int g = 0;
		if (data->d == 0 && data->prec == 0 && data->with > 0)
			g = 1;
		else if (data->d == 0 && data->prec == 1 && data->with == 0)
			g = 2;
		if (data->d == 0)
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
		if (((str2[i - 1] == '.') && (data->prec == 0) && !data->prec_moin && data->d == 0 && data->with == 0) 
			||((str2[i - 1] == '0') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->d == 0 && data->with == 0)
				|| ((str2[i - 1] == '*') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->d == 0 && data->with == 0 ) )
			data->s_zero = 1;
		if ((str2[i - 1] == '.') || ((str2[i - 1] == '*') && (str2[i - 2] == '.')) ||
		 ((str2[i - 1] == '0') && (str2[i - 2] == '.')) ||
		  ((ft_isdigit(str2[i - 1]) == 1) && (str2[i - 2] == '.')))
				data->point_d = 1;
			
		if (!data->s_zero)
		{
			puts_d(data);
		}
		else if (data->d == 0 && data->prec == 0 && data->with > 0)
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



























void puts_x(t_str *data)
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
			{
					char *hex;
					if (data->u <= 9)
						ft_putnbr(data->u);
					else
						{
							hex = conv_hex(data->u);
							ft_putstr(hex);
						}
				}
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
				{
					char *hex;
					if (data->u <= 9)
						ft_putnbr(data->u);
					else
						{
							hex = conv_hex(data->u);
							ft_putstr(hex);
						}
				}
			}
    
}

void puts_xg(t_str *data)
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
			{
					char *hex;
					if (data->u <= 9)
						ft_putnbr(data->u);
					else
						{
							hex = conv_hexg(data->u);
							ft_putstr(hex);
						}
				}
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
				{
					char *hex;
					if (data->u <= 9)
						ft_putnbr(data->u);
					else
						{
							hex = conv_hexg(data->u);
							ft_putstr(hex);
						}
				}
			}
    
}

void puts_p(t_str *data)
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
			if (data->p == 0 && data->point_d == 1 && data->prec_moin == 0 && int_prec == 0)
            {
				ft_putstr("0x");
				ft_putchar(' ');
				}
            else
			{
					char *hex;
					// if (data->p <= 9)
					// 	ft_putnbr(data->p);
					// else
					// 	{
							hex = conv_hexp(data->p);
							ft_putstr(hex);
						// }
				}
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
                if (data->p == 0 && data->point_d == 1 && data->prec_moin == 0 && int_prec == 0)
				{
                ft_putchar(' ');
				ft_putstr("0x");
				}
				else
				{
					char *hex;
					// if (data->p <= 9)
					// 	ft_putnbr(data->p);
					// else
					// 	{
							hex = conv_hexp(data->p);
							ft_putstr(hex);
						// }
				}
			}
    
}


void puts_pors(t_str *data, int h)
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
				print_pors(h);
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
				print_pors(h);
			}
    
}