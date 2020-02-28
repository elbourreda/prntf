/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_C.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 11:28:13 by rel-bour          #+#    #+#             */
/*   Updated: 2020/02/28 06:43:47 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_c(int moin, char c, int nb_with)
{
            if (moin == 1)
            {
                    ft_putchar(c);
                    while (nb_with > 1)
                    {
                        ft_putchar(' ');
                        nb_with--;
                    }
            }
            else
            {
                    while (nb_with > 1)
                    {
                        ft_putchar(' ');
                        nb_with--;
                    }
                    ft_putchar(c);
            }
  
}