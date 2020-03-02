/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:11:04 by rel-bour          #+#    #+#             */
/*   Updated: 2020/03/01 18:09:54 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_data_help_norm(t_str *data, char *str2, int i, va_list st)
{
	if (str2[i] == '0' && str2[i + 1] == '*')
	{
		data->w_zero = 1;
		data->with = va_arg(st, int);
		i = i + 2;
	}
	else
		data->with = ft_atoi(&str2[i]);
	return (i);
}

int		get_data_help(t_str *data, char *str2, int i, va_list st)
{
	if (ft_isdigit(str2[i]) == 1)
	{
		if (str2[i] == '0' && ft_isdigit(str2[i + 1]) == 1)
		{
			data->w_zero = 1;
			i++;
		}
		i = get_data_help_norm(data, str2, i, st);
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
	return (i);
}

int		get_data_help2(t_str *data, char *str2, int i, va_list st)
{
	if (str2[i] == '.')
	{
		i++;
		if (ft_isdigit(str2[i]) == 1)
		{
			data->prec = ft_atoi(&str2[i]);
			while (ft_isdigit(str2[i]) == 1)
			{
				i++;
			}
		}
		else if (str2[i] == '*')
		{
			data->prec = va_arg(st, int);
			i++;
		}
	}
	return (i);
}
