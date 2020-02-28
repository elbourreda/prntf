/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_gx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:25:28 by rel-bour          #+#    #+#             */
/*   Updated: 2020/02/26 11:26:52 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char *conv_hex(unsigned int nb)
{
    int i;
    int r;
    char rslt[20];
    int h = 0;
    char *rs;
    // char *reda;
    
    i = 0;
    while (nb > 0)
    {
        r = nb % 16;
        if ( r < 10)
            rslt[i] = r + 48;
        else
            rslt[i] = r + 87;
            
        nb = nb / 16;
        i++;
    }
    rs = (char*)malloc(i * sizeof(char));
    while (i > 0)
    {
        rs[h] = rslt[i - 1]; 
     i--;
     h++;
    }
    // reda = rs;
    // free(rs);
    return rs;    
}

char *conv_hexg(unsigned int nb)
{
    int i;
    int r;
    char rslt[20];
    int h = 0;
    char *rs;
    // char *reda;
    
    i = 0;
    while (nb > 0)
    {
        r = nb % 16;
        if ( r < 10)
            rslt[i] = r + 48;
        else
            rslt[i] = r + 55;
            
        nb = nb / 16;
        i++;
    }
    rs = (char*)malloc(i * sizeof(char));
    while (i > 0)
    {
        rs[h] = rslt[i - 1]; 
     i--;
     h++;
    }
    // reda = rs;
    // free(rs);
    return rs;    
}


char *conv_hexp(unsigned long nb)
{
    int i;
    int r;
    char rslt[20];
    int h = 0;
    char *rs;
    // char *reda;
    
    i = 0;
    while (nb > 0)
    {
        r = nb % 16;
        if ( r < 10)
            rslt[i] = r + 48;
        else
            rslt[i] = r + 87;
            
        nb = nb / 16;
        i++;
    }
    rs = (char*)malloc(i * sizeof(char) + 1);
    while (i > 0)
    {
        rs[h] = rslt[i - 1]; 
     i--;
     h++;
    }
    rs[h] = '\0';
    // reda = rs;
    // free(rs);
    return rs;    
}