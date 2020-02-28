/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_S.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:29:33 by rel-bour          #+#    #+#             */
/*   Updated: 2020/02/28 10:03:40 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void printSS(t_str *data)
{
  int i = 0;
  
		if (data->s_zero != 1)
		{
		
		 if (data->prec < ft_strlen(data->s) && data->prec != 0 && data->prec_moin == 0)
		{
		  while (data->prec > 0)
		  {
			ft_putchar(data->s[i]);
			i++;
			data->prec--;
		  } 
		}
		else if (data->with <= data->prec && data->with != 0 && !data->pre_zero && data->s[0] != '\0')
			ft_putstr(data->s);
			
		else
		  ft_putstr(data->s);
		}
}


void print_s(t_str *data, char *str2, int i)
{
		// if (data->prec < 0)
		// 			{
		// 	 		    data->prec =  data->prec * (-1);
		// 				//  _moin = 1;
		// 				data->prec_moin = 1;
		// 				// data->moin = 1;
		// 			}
	if (!data->s)
			data->s = "(null)";
	
		data->lenS = ft_strlen(data->s);
		if (((str2[i - 1] == '.') || ((str2[i - 1] == '0') && (str2[i - 2] == '.'))
			|| ((str2[i - 1] == '*') && (str2[i - 2] == '.') && (data->prec == 0))))
			data->s_zero = 1;
		if (data->with > data->prec && data->prec != 0 && data->s[0] != '\0')
		{
			data->pre_zero = 1;
			if (data->prec_moin == 1 ||(data->with > data->prec && data->prec > data->lenS))
				data->with = data->with - data->lenS;
			else
			data->with = data->with - data->prec;	
		}
		if (data->with <= data->lenS && data->pre_zero == 0 && data->s_zero != 1)
		  data->with = 0;
		if (data->with > data->lenS)
		{
			if (data->s_zero == 1 )
				data->with = data->with;
			else if (data->pre_zero == 0)
		  		data->with = data->with - data->lenS;
		}
			if (data->moin == 1)
			{
			printSS(data);
					while (data->with > 0)
					{
						ft_putchar(' ');
						data->with--;
					}
			}
			else
			{
					while (data->with > 0)
					{
						ft_putchar(' ');
						data->with--;
					}
			printSS(data);
			}
}