/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_gx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:25:28 by rel-bour          #+#    #+#             */
/*   Updated: 2020/03/01 14:20:11 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

// void freee(char *s)
// {
//     free(s);
// }

char *conv_hex(unsigned int nb)
{
    int i;
    int r;
    char rslt[20];
    int h = 0;
    char *rs;
    char *reda;
    
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
    reda = rs;
    rs = NULL;
    free(rs);
    return reda;    
}

char *conv_hexg(unsigned int nb)
{
    int i;
    int r;
    char rslt[20];
    int h = 0;
    char *rs;
    char *reda;
    
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
    rs = (char*)malloc(i * sizeof(char) + 1);
    while (i > 0)
    {
        rs[h] = rslt[i - 1]; 
     i--;
     h++;
    }
    rs[h] = '\0';
     reda = rs;
    rs = NULL;
    free(rs);
    return reda;   
}


char *conv_hexp(unsigned long int nb)
{
    int i;
    int r;
    char rslt[20];
    int h = 0;
    char *rs;
    char *reda;
    
    i = 0;
    if (nb != 0)
    {
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
    }
    else
    {
        i = 1;
        rslt[0] = '0';
    }
    
    rs = (char*)malloc(i * sizeof(char) + 3);
    rs[0] = '0';
    rs[1] = 'x';
    h = 2;
    while (i > 0)
    {
        rs[h] = rslt[i - 1]; 
     i--;
     h++;
    }
    rs[h] = '\0';
    reda = rs;
    rs = NULL;
    free(rs);
    return reda;
}