/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 00:14:45 by rel-bour          #+#    #+#             */
/*   Updated: 2020/02/28 10:22:33 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// struct dt data;
void intialisation(t_str *data)
{
	data->with = 0;
    data->prec = 0;
    data->lenS = 0;
    data->moin = 0;
    data->s_zero = 0;
    data->pre_zero = 0;
    data->prec_moin = 0;
    data->d = 0;
    data->lenD = 0;
	data->u = 0;
    data->p = 0;
    data->c = '\0';
    data->s = NULL;
}

int get_data(char *str2, int i, va_list st)
{
	// struct dt data;
	t_str *data;
	data = malloc(sizeof(t_str));
	intialisation(data);

	//int r = i;
	// int _moin = 0;

	i = i - 1;



	//&& str2[r] != '%' %
	while (ft_isspec(str2[i]) == 0)
	{
		i++;
		if (str2[i] == '-')
		{
			data->moin = 1;
			i++;
		}
		if (ft_isdigit(str2[i]) == 1)
		{
			data->with = atoi(&str2[i]);
			while (ft_isdigit(str2[i]) == 1)
				i++;
		}
		else if (str2[i] == '*')
		{
			data->with = va_arg(st, int);
			if (data->with < 0)
			{
			  data->with = (data->with * (-1));
			  data->moin = 1;
			}
			i++;
		}   
	   if (str2[i] == '.')
		{
			i++;
			if (ft_isdigit(str2[i]) == 1)
			{
				data->prec = atoi(&str2[i]);
				while (ft_isdigit(str2[i]) == 1)
				i++;
			}             
			else if (str2[i] == '*')
			{
			  data->prec = va_arg(st, int);
				// if (data->prec < 0)
				// 	{
			 	// 	    data->prec = 0;
				// 		//  _moin = 1;
				// 		data->prec_moin = 1;
				// 		// data->moin = 1;
				// 	}
			  i++;
			}
		}
		// r++;
	}


//////////////////////////////////////////////////////
	if (str2[i] == 'c')
    {
        data->c = va_arg(st, int);
               print_c(data->moin, data->c, data->with);
    }	
//////////////////////////////////////////////////////
	else if (str2[i] == 's')
	{
		if (data->prec < 0)
		{
		    data->prec = (data->prec * -1);
			//  _moin = 1;
			data->prec_moin = 1;
			// data->moin = 1;
		}	
		data->s = va_arg(st, char *);
		print_s(data, str2, i);
	}
//////////////////////////////////////////////////////
	else if (str2[i] == 'd' || str2[i] == 'i')
	{
		if (data->prec < 0)
			{
		    	data->prec = 0;
				data->prec_moin = 1;
			}
		data->d = va_arg(st, int);
		data->lenD = lenR(data->d);
		if (data->d == 0)
			data->lenD = 1;

		if (data->with >= data->lenD)
			data->with = data->with - data->lenD;
		
		if (data->prec > data->lenD)
			data->prec = data->prec - data->lenD;



		if (((str2[i - 1] == '.') && data->d == 0) || ((str2[i - 1] == '0') && (str2[i - 2] == '.') && data->d == 0)
			|| ((str2[i - 1] == '*') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->d == 0) )
			data->s_zero = 1;
				
		if (!data->s_zero)
		{
			puts_d(data);
		}



	}
//////////////////////////////////////////////////////

	free(data);
	return i;
}

int ft_printf(char *str, ...)
{
	g_r = 0;
	va_list s;
	int i = 0;
	va_start(s, str);
	while(str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			i = get_data(str, i, s);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	return (g_r);
}