/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conc_hex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 20:23:59 by rel-bour          #+#    #+#             */
/*   Updated: 2020/03/02 14:55:09 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	boucle_while(int i, int h, char *rs, char *rslt)
{
	while (i > 0)
	{
		rs[h] = rslt[i - 1];
		i--;
		h++;
	}
	rs[h] = '\0';
}

char	*conv_hex(unsigned int nb, int i)
{
	int		r;
	char	rslt[20];
	int		h;
	char	*rs;
	char	*reda;

	h = 0;
	while (nb > 0)
	{
		r = nb % 16;
		if (r < 10)
			rslt[i] = r + 48;
		else
			rslt[i] = r + 87;
		nb = nb / 16;
		i++;
	}
	rs = (char*)malloc(i * sizeof(char) + 1);
	boucle_while(i, h, rs, rslt);
	reda = rs;
	freee(reda, rs);
	free(rs);
	return (reda);
}

char	*conv_hexg(unsigned int nb, int i)
{
	int		r;
	char	rslt[20];
	int		h;
	char	*rs;
	char	*reda;

	h = 0;
	while (nb > 0)
	{
		r = nb % 16;
		if (r < 10)
			rslt[i] = r + 48;
		else
			rslt[i] = r + 55;
		nb = nb / 16;
		i++;
	}
	rs = (char*)malloc(i * sizeof(char) + 1);
	boucle_while(i, h, rs, rslt);
	reda = rs;
	freee(reda, rs);
	free(rs);
	return (reda);
}

int		if_else_hex_conv(unsigned long int nb, char *rslt, int i, int r)
{
	if (nb != 0)
	{
		while (nb > 0)
		{
			r = nb % 16;
			if (r < 10)
				rslt[i] = r + 48;
			else
				rslt[i] = r + 87;
			nb = nb / 16;
			i++;
		}
	}
	else
	{
		i = 1;
		rslt[0] = '0';
	}
	return (i);
}

char	*conv_hexp(unsigned long int nb, int i)
{
	int		r;
	char	rslt[20];
	int		h;
	char	*rs;
	char	*reda;

	h = 0;
	r = 0;
	i = if_else_hex_conv(nb, rslt, i, r);
	rs = (char*)malloc(i * sizeof(char) + 3);
	rs[0] = '0';
	rs[1] = 'x';
	h = 2;
	boucle_while(i, h, rs, rslt);
	reda = rs;
	freee(reda, rs);
	free(rs);
	return (reda);
}
