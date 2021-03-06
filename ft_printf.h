/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 10:32:09 by rel-bour          #+#    #+#             */
/*   Updated: 2020/03/02 21:18:32 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <assert.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct			s_str
{
	int					with;
	int					with0;
	int					prec;
	int					prec0;
	int					lens;
	int					moin;
	int					s_zero;
	int					pre_zero;
	int					prec_moin;
	int					d;
	int					d_salib;
	int					point_d;
	int					w_zero;
	int					max;
	int					lend;
	unsigned int		u;
	unsigned long int	p;
	char				c;
	char				*s;
}						t_str;

int						g_r;
int						ft_printf(char *str, ...);
void					ft_putchar_fd(char c, int fd);
int						ft_isdigit(int c);
int						lenr(long nb);
void					print_c();
char					*conv_hex(unsigned int nb, int i);
char					*conv_hexg(unsigned int nb, int i);
char					*conv_hexp(unsigned long nb, int i);
void					puts_d();
void					puts_u();
void					puts_x();
void					puts_xg();
void					puts_p();
void					printss();
void					print_s();
void					print_d();
void					print_u();
int						print_pers();
void					print_x();
void					print_xg();
void					print_p();
int						get_data_help();
int						get_data_help2();
void					print_pors(int h);
void					print_pors2(int h);
void					puts_pors();
void					ft_putchar(char c);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strdup2(char *string);
int						ft_strlen(const char *str);
void					ft_putstr(char *s);
int						ft_isspec(int c);
void					ft_putnbr(long n);
int						ft_atoi(const char *str);
void					freee(char *reda, char *rs);

#endif
