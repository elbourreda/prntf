/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:32:09 by rel-bour          #+#    #+#             */
/*   Updated: 2020/02/28 17:49:42 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <assert.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
// #include "./libft/libft.h"
int g_r;
int     ft_printf( char *str, ...);
void	ft_putchar_fd(char c, int fd);
int    ft_isdigit(int c);
int        lenR(long nb);
void print_c(int moin, char c, int nb_with);
// void printSS(char *s, int prec, int zero, int with, int pre_zero);
// void printSS(struct dt data);
char *conv_hex(unsigned int nb);
char *conv_hexg(unsigned int nb);
char *conv_hexp(unsigned long nb);
void puts_d();
void puts_u();

// void printSS();
void printSS();
void print_s();


/////libft
void ft_putchar(char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup2(char *string);
int	ft_strlen(const char *str);
void        ft_putstr(char *s);
int    ft_isspec(int c);
void	ft_putnbr(long n);


typedef struct 
{
           
           int with;
           int with0;
           int prec;
           int prec0;
           int lenS;
           int moin;
           int s_zero;
           int pre_zero;
           int prec_moin;
           int d;
           int d_salib;
           int point_d;
           int w_zero;
           int max;
           int lenD;
           unsigned int u;
           unsigned long int p;
           char c;
           char *s;
}t_str;
// str data;

#endif