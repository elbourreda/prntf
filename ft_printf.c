/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 00:14:45 by rel-bour          #+#    #+#             */
/*   Updated: 2020/03/02 11:53:13 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	intialisation(t_str *data)
{
	data->with = 0;
	data->prec = 0;
	data->lens = 0;
	data->moin = 0;
	data->s_zero = 0;
	data->pre_zero = 0;
	data->prec_moin = 0;
	data->d = 0;
	data->d_salib = 0;
	data->lend = 0;
	data->w_zero = 0;
	data->max = 0;
	data->point_d = 0;
	data->u = 0;
	data->p = 0;
	data->c = '\0';
	data->s = NULL;
}

int		if_specef(t_str *data, char *str2, int i, va_list st)
{
	if (str2[i] == '%')
		i = print_pers(data, str2, i);
	else if (str2[i] == 'c')
		print_c(data, st);
	else if (str2[i] == 's')
		print_s(data, str2, i, st);
	else if (str2[i] == 'd' || str2[i] == 'i')
		print_d(data, str2, i, st);
	else if (str2[i] == 'u')
		print_u(data, str2, i, st);
	else if (str2[i] == 'x')
		print_x(data, str2, i, st);
	else if (str2[i] == 'X')
		print_xg(data, str2, i, st);
	else if (str2[i] == 'p')
		print_p(data, str2, i, st);
	return (i);
}

int		get_data(char *str2, int i, va_list st)
{
	t_str *data;

	data = malloc(sizeof(t_str));
	intialisation(data);
	while (ft_isspec(str2[i]) == 0 && str2[i] != '%')
	{
		while (str2[i] == '-')
		{
			data->moin = 1;
			i++;
		}
		i = get_data_help(data, str2, i, st);
		i = get_data_help2(data, str2, i, st);
	}
	data->prec0 = data->prec;
	data->with0 = data->with;
	i = if_specef(data, str2, i, st);
	free(data);
	return (i);
}

int		ft_printf(char *str, ...)
{
	va_list	s;
	int		i;

	g_r = 0;
	i = 0;
	va_start(s, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			i = get_data(str, i, s);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			i++;
		}
	}
	return (g_r);
}
