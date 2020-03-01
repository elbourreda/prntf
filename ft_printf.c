/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 00:14:45 by rel-bour          #+#    #+#             */
/*   Updated: 2020/03/01 13:12:09 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int case_pers(int h)
{
	// if (h % 2 == 0)
	// 	return 0;
	// else 
	return h;
}

void  print_pors(int h)
{
	// int h1 = h;
	if (h % 2 == 0)
		{
            h = h / 2;
		}
		else 
        {
            h = h - 1;
            h = h / 2;
        }
		// h1 = h;
        while (h > 0)
        {
            ft_putchar('%');
            h--;
        }
		// return (h1);
}

void print_pors2(int h)
{
		if (h % 2 == 0)
		{
            h = h / 2;
		}
		else 
        {
            h = h - 1;
            h = h / 2;
        }
		h = h -1;
        while (h > 0)
        {
            ft_putchar('%');
            h--;
        }
}
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
	data->d_salib = 0;
    data->lenD = 0;
	data->w_zero = 0;
	data->max = 0;
	data->point_d = 0;
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
	int r = i;
	// int _moin = 0;

	// i = i - 1;



	//&& str2[r] != '%' %
	while (ft_isspec(str2[i]) == 0 && str2[i] != '%')
	{

		// i++;
		while (str2[i] == '-')
		{
			data->moin = 1;
			i++;
			r++;
		}
		if (ft_isdigit(str2[i]) == 1)
		{
			if (str2[i] == '0' && ft_isdigit(str2[i + 1]) == 1)
			{
				data->w_zero = 1;
				i++;
				r++;
			}
			if (str2[i] == '0' && str2[i + 1] == '*')
			{
				data->w_zero = 1;
				data->with = va_arg(st, int);
				i = i + 2;
				r++;
				
			}
			else
				data->with = atoi(&str2[i]);
			while (ft_isdigit(str2[i]) == 1)
			{
				i++;
				r++;
			}
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
			r++;
		}   
	   if (str2[i] == '.')
		{
			i++;
			r++;
			if (ft_isdigit(str2[i]) == 1)
			{
				data->prec = atoi(&str2[i]);
				while (ft_isdigit(str2[i]) == 1)
				{
					i++;
					r++;
				}				
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
			  r++;
			}
		}
		// r++;
	}
	// r = i + 1;
	
		data->prec0 = data->prec;
		data->with0 = data->with;

//////////////////////////////////////////////////////




	if (str2[i] == '%')
	{
		int h = 1;
		// printf("reda");
		while (str2[i] == '%')
		{
			i++;
			h++;
		}
		if (data->with < 0)
			{
			  data->with = (data->with * (-1));
			  data->moin = 1;
			}
	
		data->with = data->with - 1;
		if (data->moin == 1)
			{
			ft_putchar('%');
			
					while (data->with > 0)
					{
						ft_putchar(' ');
						data->with--;
					}
			print_pors2(h);
			}
			else
			{
					while (data->with > 0)
					{
						if (data->w_zero)
							ft_putchar('0');
						else
						ft_putchar(' ');
						data->with--;
					}
			print_pors(h);
			}
		case_pers(h);
		if (h % 2 != 0)
			i = i - 2;
		else
			i = i - 1;
		// print_pors(h);
		// i = r - 1;
		// i++;
		// i = i + h - 1;
		// i = r;
		
	}
//////////////////////////////////////////////////////
	else if (str2[i] == 'c')
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
			if (data->with < 0)
			{
			  data->with = (data->with * (-1));
			  data->moin = 1;
			}
		data->d = va_arg(st, int);
		


		if (data->d < 0 && data-> d != (-2147483648))
		{
			data->d = data->d * -1;
			data->with -= 1;
			data->d_salib = 1;
			// if (data->d_salib == 1 && data->w_zero == 1)
			// {
			// 	data->w_zero = 0;
			// }
		}
		if (data->d == (-2147483647 - 1))
		{
				data->u = 2147483648;
				data->max = 1;
				data->with -= 1;
				data->d_salib = 1;
		}
		data->lenD = lenR(data->d);
		int g = 0;
		if (data->d == 0 && data->prec == 0 && data->with > 0)
			g = 1;
		else if (data->d == 0 && data->prec == 1 && data->with == 0)
			g = 2;
		
		if (data->d == 0)
			data->lenD = 1;
		if (data->prec > data->with)
			data->with = 0;
		if (data->with < data->lenD)
			data->with = 0;
		else if (data->with >= data->lenD)
			data->with = data->with - data->lenD;

		
		

		if (data->with > data->prec && data->prec < data->lenD)
			data->prec = 0;
			
		if (data->prec > data->with && data->prec < data->lenD)
			data->prec = 0;
		
		
			
		if (data->prec >= data->lenD)
			data->prec = data->prec - data->lenD;
		
		if (data->with >= data->prec)
			data->with = data->with - data->prec;


		


		
		if (((str2[i - 1] == '.') && (data->prec == 0) && !data->prec_moin && data->d == 0 && data->with == 0) 
			||((str2[i - 1] == '0') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->d == 0 && data->with == 0)
				|| ((str2[i - 1] == '*') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->d == 0 && data->with == 0 ) )
			data->s_zero = 1;
		
		// else if (!data->w_zero && !data->prec_moin && data->d == 0)
		// 	data->s_zero = 1;
			
		if ((str2[i - 1] == '.') || ((str2[i - 1] == '*') && (str2[i - 2] == '.')) ||
		 ((str2[i - 1] == '0') && (str2[i - 2] == '.')) ||
		  ((ft_isdigit(str2[i - 1]) == 1) && (str2[i - 2] == '.')))
				data->point_d = 1;
				
		if (!data->s_zero)
		{
			puts_d(data);
		}
		else if (data->d == 0 && data->prec == 0 && data->with > 0)
		{
			while (data->with > 0)
			{
				ft_putchar(' ');
				data->with--;
			}
		}
		else if (g==1)
		{
			ft_putchar(' ');
		}
		else if (g == 2)
		{
			ft_putchar('0');
		}


	}
//////////////////////////////////////////////////////

	else if (str2[i] == 'u')
	{
		
		if (data->prec < 0)
			{
		    	data->prec = 0;
				data->prec_moin = 1;
			}
		if (data->with < 0)
			{
			  data->with = (data->with * (-1));
			  data->moin = 1;
			}
		data->u = va_arg(st, unsigned long);
	
		data->lenD = lenR(data->u);
		int g = 0;
		if (data->u == 0 && data->prec == 0 && data->with > 0)
			g = 1;
		else if (data->u == 0 && data->prec == 1 && data->with == 0)
			g = 2;
		
		if (data->u == 0)
			data->lenD = 1;
		if (data->prec > data->with)
			data->with = 0;
		if (data->with < data->lenD)
			data->with = 0;
		else if (data->with >= data->lenD)
			data->with = data->with - data->lenD;

		if (data->with > data->prec && data->prec < data->lenD)
			data->prec = 0;
			
		if (data->prec > data->with && data->prec < data->lenD)
			data->prec = 0;

		if (data->prec >= data->lenD)
			data->prec = data->prec - data->lenD;
		
		if (data->with >= data->prec)
			data->with = data->with - data->prec;

		
		if (((str2[i - 1] == '.') && (data->prec == 0) && !data->prec_moin && data->u == 0 && data->with == 0) 
			||((str2[i - 1] == '0') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->u == 0 && data->with == 0)
				|| ((str2[i - 1] == '*') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->u == 0 && data->with == 0 ) )
			data->s_zero = 1;
		
			
		if ((str2[i - 1] == '.') || ((str2[i - 1] == '*') && (str2[i - 2] == '.')) ||
		 ((str2[i - 1] == '0') && (str2[i - 2] == '.')) ||
		  ((ft_isdigit(str2[i - 1]) == 1) && (str2[i - 2] == '.')))
				data->point_d = 1;
				
		if (!data->s_zero)
		{
			puts_u(data);
		}
		else if (data->u == 0 && data->prec == 0 && data->with > 0)
		{
			while (data->with > 0)
			{
				ft_putchar(' ');
				data->with--;
			}
		}
		else if (g==1)
		{
			ft_putchar(' ');
		}
		else if (g == 2)
		{
			ft_putchar('0');
		}
	}

//////////////////////////////////////////////////////

else if (str2[i] == 'x')
{
		data->u = va_arg(st, unsigned long);

		char *hex;
		// if (data->u <= 9)
		// 	ft_putnbr(data->u);
		// else
		// {
			hex = conv_hex(data->u);
			// ft_putstr(hex);
		// }

		////////////////////////


		if (data->prec < 0)
			{
		    	data->prec = 0;
				data->prec_moin = 1;
			}
		if (data->with < 0)
			{
			  data->with = (data->with * (-1));
			  data->moin = 1;
			}	
		data->lenD = ft_strlen(hex);
		int g = 0;
		if (data->u == 0 && data->prec == 0 && data->with > 0)
			g = 1;
		else if (data->u == 0 && data->prec == 1 && data->with == 0)
			g = 2;
		
		if (data->u == 0)
			data->lenD = 1;
		if (data->prec > data->with)
			data->with = 0;
		if (data->with < data->lenD)
			data->with = 0;
		else if (data->with >= data->lenD)
			data->with = data->with - data->lenD;

		if (data->with >= data->prec && data->prec < data->lenD)
			data->prec = 0;
			
		if (data->prec > data->with && data->prec < data->lenD)
			data->prec = 0;

		if (data->prec >= data->lenD)
			data->prec = data->prec - data->lenD;
		
		if (data->with >= data->prec)
			data->with = data->with - data->prec;

		
		if (((str2[i - 1] == '.') && (data->prec == 0) && !data->prec_moin && data->u == 0 && data->with == 0) 
			||((str2[i - 1] == '0') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->u == 0 && data->with == 0)
				|| ((str2[i - 1] == '*') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->u == 0 && data->with == 0 ) )
			data->s_zero = 1;
		
			
		if ((str2[i - 1] == '.') || ((str2[i - 1] == '*') && (str2[i - 2] == '.')) ||
		 ((str2[i - 1] == '0') && (str2[i - 2] == '.')) ||
		  ((ft_isdigit(str2[i - 1]) == 1) && (str2[i - 2] == '.')))
				data->point_d = 1;
				
		if (!data->s_zero)
		{
			puts_x(data);
		}
		else if (data->u == 0 && data->prec == 0 && data->with > 0)
		{
			while (data->with > 0)
			{
				ft_putchar(' ');
				data->with--;
			}
		}
		else if (g==1)
		{
			ft_putchar(' ');
		}
		else if (g == 2)
		{
			ft_putchar('0');
		}
}
//////////////////////////////////////////////////////

else if (str2[i] == 'X')
{
		data->u = va_arg(st, unsigned long);

		char *hex;
		// if (data->u <= 9)
		// 	ft_putnbr(data->u);
		// else
		// {
			hex = conv_hexg(data->u);
			// ft_putstr(hex);
		// }

		////////////////////////


		if (data->prec < 0)
			{
		    	data->prec = 0;
				data->prec_moin = 1;
			}
		if (data->with < 0)
			{
			  data->with = (data->with * (-1));
			  data->moin = 1;
			}	
		data->lenD = ft_strlen(hex);
		int g = 0;
		if (data->u == 0 && data->prec == 0 && data->with > 0)
			g = 1;
		else if (data->u == 0 && data->prec == 1 && data->with == 0)
			g = 2;
		
		if (data->u == 0)
			data->lenD = 1;
		if (data->prec > data->with)
			data->with = 0;
		if (data->with < data->lenD)
			data->with = 0;
		else if (data->with >= data->lenD)
			data->with = data->with - data->lenD;

		if (data->with >= data->prec && data->prec < data->lenD)
			data->prec = 0;
			
		if (data->prec > data->with && data->prec < data->lenD)
			data->prec = 0;

		if (data->prec >= data->lenD)
			data->prec = data->prec - data->lenD;
		
		if (data->with >= data->prec)
			data->with = data->with - data->prec;

		
		if (((str2[i - 1] == '.') && (data->prec == 0) && !data->prec_moin && data->u == 0 && data->with == 0) 
			||((str2[i - 1] == '0') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->u == 0 && data->with == 0)
				|| ((str2[i - 1] == '*') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->u == 0 && data->with == 0 ) )
			data->s_zero = 1;
		
			
		if ((str2[i - 1] == '.') || ((str2[i - 1] == '*') && (str2[i - 2] == '.')) ||
		 ((str2[i - 1] == '0') && (str2[i - 2] == '.')) ||
		  ((ft_isdigit(str2[i - 1]) == 1) && (str2[i - 2] == '.')))
				data->point_d = 1;
				
		if (!data->s_zero)
		{
			puts_xg(data);
		}
		else if (data->u == 0 && data->prec == 0 && data->with > 0)
		{
			while (data->with > 0)
			{
				ft_putchar(' ');
				data->with--;
			}
		}
		else if (g==1)
		{
			ft_putchar(' ');
		}
		else if (g == 2)
		{
			ft_putchar('0');
		}
}
//////////////////
else if (str2[i] == 'p')
{
		data->p = va_arg(st, unsigned long);

		char *hex;
		// if (data->p <= 9)
		// 	ft_putnbr(data->p);
		// else
		// {
			hex = conv_hexp(data->p);
			// ft_putstr(hex);
		// }

		////////////////////////


		if (data->prec < 0)
			{
		    	data->prec = 0;
				data->prec_moin = 1;
			}
		if (data->with < 0)
			{
			  data->with = (data->with * (-1));
			  data->moin = 1;
			}	
		data->lenD = ft_strlen(hex);
		int g = 0;
		if (data->p == 0 && data->prec == 0 && data->with > 0)
			g = 1;
		else if (data->p == 0 && data->prec == 1 && data->with == 0)
			g = 2;
		
		// if (data->p == 0)
		// 	data->lenD = 1;
		if (data->prec > data->with)
			data->with = 0;
		if (data->with < data->lenD)
			data->with = 0;
		else if (data->with >= data->lenD)
			data->with = data->with - data->lenD;

		if (data->with >= data->prec && data->prec < data->lenD)
			data->prec = 0;
			
		if (data->prec > data->with && data->prec < data->lenD)
			data->prec = 0;

		if (data->prec >= data->lenD)
			data->prec = data->prec - data->lenD;
		
		if (data->with >= data->prec)
			data->with = data->with - data->prec;

		
		if (((str2[i - 1] == '.') && (data->prec == 0) && !data->prec_moin && data->p == 0 && data->with == 0) 
			||((str2[i - 1] == '0') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->p == 0 && data->with == 0)
				|| ((str2[i - 1] == '*') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->p == 0 && data->with == 0 ) )
			data->s_zero = 1;
		
			
	if ((str2[i - 1] == '.') || ((str2[i - 1] == '*') && (str2[i - 2] == '.')) ||
		 ((str2[i - 1] == '0') && (str2[i - 2] == '.')) ||
		  (data->prec > 0 && (str2[i - data->lenD] == '.')))
				data->point_d = 1;

		// if (g==1)
		// {
		// 	data->with0 = data->with0 - 2;
		// 	while (data->with0)
		// 	{
		// 		ft_putchar(' ');
		// 		data->with0--;
		// 	}
		// 	ft_putstr("0x");
		// }	
		if (!data->s_zero)
		{
			puts_p(data);
		}
		else if (data->p == 0 && data->prec == 0 && data->with > 0)
		{
			while (data->with > 0)
			{
				ft_putchar(' ');
				data->with--;
			}
		}
		else if (g==1)
		{
			if (data->with0 == 1)
			{
				data->with0 = data->with0 - 1;
			}
			else
			data->with0 = data->with0 - 2;
			while (data->with0)
			{
				ft_putchar(' ');
				data->with0--;
			}
			ft_putstr("0x");
		}
		else if (g == 2)
		{
			ft_putchar('0');
		}
		else  //if (data->p == 0 && data->with == 0 && data->prec == 0)
		{
			ft_putstr("0x");
		}
}

	free(data);
	return i;
}


/*
// struct dt data;


int get_data(char *str2, int i, va_list st)
{
	// struct dt data;
	t_str *data;
	data = malloc(sizeof(t_str));
	intialisation(data);
	
	// int _moin = 0;
	// int r = i;
	i = i - 1;
	


	//&& str2[r] != '%' %
	while (ft_isspec(str2[i]))
	{
			i++;
			if (str2[i] == '-')
			{
				data->moin = 1;
				i++;
			}
			if (ft_isdigit(str2[i]) == 1)
			{
				if (str2[i] == '0' && ft_isdigit(str2[i + 1]) == 1)
				{
					data->w_zero = 1;
					i++;
				}
				if (str2[i] == '0' && str2[i + 1] == '*')
				{
					data->w_zero = 1;
					data->with = va_arg(st, int);
					
				}
				else
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
			// r = r + i - 1;
			// r++;
		
	}
		data->prec0 = data->prec;
		data->with0 = data->with;

//////////////////////////////////////////////////////
	if (str2[i] == 'c')
    {
        data->c = va_arg(st, int);
               print_c(data->moin, data->c, data->with);
    }	
//////////////////////////////////////////////////////
	else if (str2[i] == '%')
	{
		int h = 1;
		// printf("reda");
		while (str2[i] == '%')
		{
			i++;
			h++;
		}
		print_pors(h);
		// i = r - 1;
	}

//////////////////////////////////////////////////////

// else if (str2[r] == '%')
// 	{
// 		int h = 1;
// 		while (str2[r] == '%')
// 		{
// 			r++;
// 			h++;
// 		}
		
// 		if (data->prec < 0)
// 			{
// 		    	data->prec = 0;
// 				data->prec_moin = 1;
// 			}
// 		if (data->with < 0)
// 			{
// 			  data->with = (data->with * (-1));
// 			  data->moin = 1;
// 			}	
// 		data->lenD = print_pors2(h);
// 		int g = 0;
// 		if (data->u == 0 && data->prec == 0 && data->with > 0)
// 			g = 1;
// 		else if (data->u == 0 && data->prec == 1 && data->with == 0)
// 			g = 2;
		
// 		if (data->u == 0)
// 			data->lenD = 1;
// 		if (data->prec > data->with)
// 			data->with = 0;
// 		if (data->with < data->lenD)
// 			data->with = 0;
// 		else if (data->with >= data->lenD)
// 			data->with = data->with - data->lenD;

// 		if (data->with > data->prec && data->prec < data->lenD)
// 			data->prec = 0;
			
// 		if (data->prec > data->with && data->prec < data->lenD)
// 			data->prec = 0;

// 		if (data->prec >= data->lenD)
// 			data->prec = data->prec - data->lenD;
		
// 		if (data->with >= data->prec)
// 			data->with = data->with - data->prec;

		
// 		if (((str2[i - 1] == '.') && (data->prec == 0) && !data->prec_moin && data->u == 0 && data->with == 0) 
// 			||((str2[i - 1] == '0') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->u == 0 && data->with == 0)
// 				|| ((str2[i - 1] == '*') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->u == 0 && data->with == 0 ) )
// 			data->s_zero = 1;
		
			
// 		if ((str2[i - 1] == '.') || ((str2[i - 1] == '*') && (str2[i - 2] == '.')) ||
// 		 ((str2[i - 1] == '0') && (str2[i - 2] == '.')) ||
// 		  ((ft_isdigit(str2[i - 1]) == 1) && (str2[i - 2] == '.')))
// 				data->point_d = 1;
				
// 		if (!data->s_zero)
// 		{
// 			puts_pors(data, h);
// 		}
// 		else if (data->u == 0 && data->prec == 0 && data->with > 0)
// 		{
// 			while (data->with > 0)
// 			{
// 				ft_putchar(' ');
// 				data->with--;
// 			}
// 		}
// 		else if (g==1)
// 		{
// 			ft_putchar(' ');
// 		}
// 		else if (g == 2)
// 		{
// 			ft_putchar('0');
// 		}
// 		i = r - 1;
// 	}



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
			if (data->with < 0)
			{
			  data->with = (data->with * (-1));
			  data->moin = 1;
			}
		data->d = va_arg(st, int);
		


		if (data->d < 0 && data-> d != (-2147483648))
		{
			data->d = data->d * -1;
			data->with -= 1;
			data->d_salib = 1;
			// if (data->d_salib == 1 && data->w_zero == 1)
			// {
			// 	data->w_zero = 0;
			// }
		}
		if (data->d == (-2147483647 - 1))
		{
				data->u = 2147483648;
				data->max = 1;
				data->with -= 1;
				data->d_salib = 1;
		}
		data->lenD = lenR(data->d);
		int g = 0;
		if (data->d == 0 && data->prec == 0 && data->with > 0)
			g = 1;
		else if (data->d == 0 && data->prec == 1 && data->with == 0)
			g = 2;
		
		if (data->d == 0)
			data->lenD = 1;
		if (data->prec > data->with)
			data->with = 0;
		if (data->with < data->lenD)
			data->with = 0;
		else if (data->with >= data->lenD)
			data->with = data->with - data->lenD;

		
		

		if (data->with > data->prec && data->prec < data->lenD)
			data->prec = 0;
			
		if (data->prec > data->with && data->prec < data->lenD)
			data->prec = 0;
		
		
			
		if (data->prec >= data->lenD)
			data->prec = data->prec - data->lenD;
		
		if (data->with >= data->prec)
			data->with = data->with - data->prec;


		


		
		if (((str2[i - 1] == '.') && (data->prec == 0) && !data->prec_moin && data->d == 0 && data->with == 0) 
			||((str2[i - 1] == '0') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->d == 0 && data->with == 0)
				|| ((str2[i - 1] == '*') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->d == 0 && data->with == 0 ) )
			data->s_zero = 1;
		
		// else if (!data->w_zero && !data->prec_moin && data->d == 0)
		// 	data->s_zero = 1;
			
		if ((str2[i - 1] == '.') || ((str2[i - 1] == '*') && (str2[i - 2] == '.')) ||
		 ((str2[i - 1] == '0') && (str2[i - 2] == '.')) ||
		  ((ft_isdigit(str2[i - 1]) == 1) && (str2[i - 2] == '.')))
				data->point_d = 1;
				
		if (!data->s_zero)
		{
			puts_d(data);
		}
		else if (data->d == 0 && data->prec == 0 && data->with > 0)
		{
			while (data->with > 0)
			{
				ft_putchar(' ');
				data->with--;
			}
		}
		else if (g==1)
		{
			ft_putchar(' ');
		}
		else if (g == 2)
		{
			ft_putchar('0');
		}


	}
//////////////////////////////////////////////////////

	else if (str2[i] == 'u')
	{
		
		if (data->prec < 0)
			{
		    	data->prec = 0;
				data->prec_moin = 1;
			}
		if (data->with < 0)
			{
			  data->with = (data->with * (-1));
			  data->moin = 1;
			}
		data->u = va_arg(st, unsigned long int);
	
		data->lenD = lenR(data->u);
		int g = 0;
		if (data->u == 0 && data->prec == 0 && data->with > 0)
			g = 1;
		else if (data->u == 0 && data->prec == 1 && data->with == 0)
			g = 2;
		
		if (data->u == 0)
			data->lenD = 1;
		if (data->prec > data->with)
			data->with = 0;
		if (data->with < data->lenD)
			data->with = 0;
		else if (data->with >= data->lenD)
			data->with = data->with - data->lenD;

		if (data->with > data->prec && data->prec < data->lenD)
			data->prec = 0;
			
		if (data->prec > data->with && data->prec < data->lenD)
			data->prec = 0;

		if (data->prec >= data->lenD)
			data->prec = data->prec - data->lenD;
		
		if (data->with >= data->prec)
			data->with = data->with - data->prec;

		
		if (((str2[i - 1] == '.') && (data->prec == 0) && !data->prec_moin && data->u == 0 && data->with == 0) 
			||((str2[i - 1] == '0') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->u == 0 && data->with == 0)
				|| ((str2[i - 1] == '*') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->u == 0 && data->with == 0 ) )
			data->s_zero = 1;
		
			
		if ((str2[i - 1] == '.') || ((str2[i - 1] == '*') && (str2[i - 2] == '.')) ||
		 ((str2[i - 1] == '0') && (str2[i - 2] == '.')) ||
		  ((ft_isdigit(str2[i - 1]) == 1) && (str2[i - 2] == '.')))
				data->point_d = 1;
				
		if (!data->s_zero)
		{
			puts_u(data);
		}
		else if (data->u == 0 && data->prec == 0 && data->with > 0)
		{
			while (data->with > 0)
			{
				ft_putchar(' ');
				data->with--;
			}
		}
		else if (g==1)
		{
			ft_putchar(' ');
		}
		else if (g == 2)
		{
			ft_putchar('0');
		}
	}

//////////////////////////////////////////////////////

else if (str2[i] == 'x')
{
		data->u = va_arg(st, unsigned long);

		char *hex;
		// if (data->u <= 9)
		// 	ft_putnbr(data->u);
		// else
		// {
			hex = conv_hex(data->u);
			// ft_putstr(hex);
		// }

		////////////////////////


		if (data->prec < 0)
			{
		    	data->prec = 0;
				data->prec_moin = 1;
			}
		if (data->with < 0)
			{
			  data->with = (data->with * (-1));
			  data->moin = 1;
			}	
		data->lenD = ft_strlen(hex);
		int g = 0;
		if (data->u == 0 && data->prec == 0 && data->with > 0)
			g = 1;
		else if (data->u == 0 && data->prec == 1 && data->with == 0)
			g = 2;
		
		if (data->u == 0)
			data->lenD = 1;
		if (data->prec > data->with)
			data->with = 0;
		if (data->with < data->lenD)
			data->with = 0;
		else if (data->with >= data->lenD)
			data->with = data->with - data->lenD;

		if (data->with >= data->prec && data->prec < data->lenD)
			data->prec = 0;
			
		if (data->prec > data->with && data->prec < data->lenD)
			data->prec = 0;

		if (data->prec >= data->lenD)
			data->prec = data->prec - data->lenD;
		
		if (data->with >= data->prec)
			data->with = data->with - data->prec;

		
		if (((str2[i - 1] == '.') && (data->prec == 0) && !data->prec_moin && data->u == 0 && data->with == 0) 
			||((str2[i - 1] == '0') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->u == 0 && data->with == 0)
				|| ((str2[i - 1] == '*') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->u == 0 && data->with == 0 ) )
			data->s_zero = 1;
		
			
		if ((str2[i - 1] == '.') || ((str2[i - 1] == '*') && (str2[i - 2] == '.')) ||
		 ((str2[i - 1] == '0') && (str2[i - 2] == '.')) ||
		  ((ft_isdigit(str2[i - 1]) == 1) && (str2[i - 2] == '.')))
				data->point_d = 1;
				
		if (!data->s_zero)
		{
			puts_x(data);
		}
		else if (data->u == 0 && data->prec == 0 && data->with > 0)
		{
			while (data->with > 0)
			{
				ft_putchar(' ');
				data->with--;
			}
		}
		else if (g==1)
		{
			ft_putchar(' ');
		}
		else if (g == 2)
		{
			ft_putchar('0');
		}
}
//////////////////////////////////////////////////////

else if (str2[i] == 'X')
{
		data->u = va_arg(st, unsigned long);

		char *hex;
		// if (data->u <= 9)
		// 	ft_putnbr(data->u);
		// else
		// {
			hex = conv_hexg(data->u);
			// ft_putstr(hex);
		// }

		////////////////////////


		if (data->prec < 0)
			{
		    	data->prec = 0;
				data->prec_moin = 1;
			}
		if (data->with < 0)
			{
			  data->with = (data->with * (-1));
			  data->moin = 1;
			}	
		data->lenD = ft_strlen(hex);
		int g = 0;
		if (data->u == 0 && data->prec == 0 && data->with > 0)
			g = 1;
		else if (data->u == 0 && data->prec == 1 && data->with == 0)
			g = 2;
		
		if (data->u == 0)
			data->lenD = 1;
		if (data->prec > data->with)
			data->with = 0;
		if (data->with < data->lenD)
			data->with = 0;
		else if (data->with >= data->lenD)
			data->with = data->with - data->lenD;

		if (data->with >= data->prec && data->prec < data->lenD)
			data->prec = 0;
			
		if (data->prec > data->with && data->prec < data->lenD)
			data->prec = 0;

		if (data->prec >= data->lenD)
			data->prec = data->prec - data->lenD;
		
		if (data->with >= data->prec)
			data->with = data->with - data->prec;

		
		if (((str2[i - 1] == '.') && (data->prec == 0) && !data->prec_moin && data->u == 0 && data->with == 0) 
			||((str2[i - 1] == '0') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->u == 0 && data->with == 0)
				|| ((str2[i - 1] == '*') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->u == 0 && data->with == 0 ) )
			data->s_zero = 1;
		
			
		if ((str2[i - 1] == '.') || ((str2[i - 1] == '*') && (str2[i - 2] == '.')) ||
		 ((str2[i - 1] == '0') && (str2[i - 2] == '.')) ||
		  ((ft_isdigit(str2[i - 1]) == 1) && (str2[i - 2] == '.')))
				data->point_d = 1;
				
		if (!data->s_zero)
		{
			puts_xg(data);
		}
		else if (data->u == 0 && data->prec == 0 && data->with > 0)
		{
			while (data->with > 0)
			{
				ft_putchar(' ');
				data->with--;
			}
		}
		else if (g==1)
		{
			ft_putchar(' ');
		}
		else if (g == 2)
		{
			ft_putchar('0');
		}
}

//////////////////////////////////////////////////////


else if (str2[i] == 'p')
{
		data->p = va_arg(st, unsigned long);

		char *hex;
		// if (data->p <= 9)
		// 	ft_putnbr(data->p);
		// else
		// {
			hex = conv_hexp(data->p);
			// ft_putstr(hex);
		// }

		////////////////////////


		if (data->prec < 0)
			{
		    	data->prec = 0;
				data->prec_moin = 1;
			}
		if (data->with < 0)
			{
			  data->with = (data->with * (-1));
			  data->moin = 1;
			}	
		data->lenD = ft_strlen(hex);
		int g = 0;
		if (data->p == 0 && data->prec == 0 && data->with > 0)
			g = 1;
		else if (data->p == 0 && data->prec == 1 && data->with == 0)
			g = 2;
		
		// if (data->p == 0)
		// 	data->lenD = 1;
		if (data->prec > data->with)
			data->with = 0;
		if (data->with < data->lenD)
			data->with = 0;
		else if (data->with >= data->lenD)
			data->with = data->with - data->lenD;

		if (data->with >= data->prec && data->prec < data->lenD)
			data->prec = 0;
			
		if (data->prec > data->with && data->prec < data->lenD)
			data->prec = 0;

		if (data->prec >= data->lenD)
			data->prec = data->prec - data->lenD;
		
		if (data->with >= data->prec)
			data->with = data->with - data->prec;

		
		if (((str2[i - 1] == '.') && (data->prec == 0) && !data->prec_moin && data->p == 0 && data->with == 0) 
			||((str2[i - 1] == '0') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->p == 0 && data->with == 0)
				|| ((str2[i - 1] == '*') && (str2[i - 2] == '.') && (data->prec == 0) && !data->prec_moin && data->p == 0 && data->with == 0 ) )
			data->s_zero = 1;
		
			
	if ((str2[i - 1] == '.') || ((str2[i - 1] == '*') && (str2[i - 2] == '.')) ||
		 ((str2[i - 1] == '0') && (str2[i - 2] == '.')) ||
		  (data->prec > 0 && (str2[i - data->lenD] == '.')))
				data->point_d = 1;

		// if (g==1)
		// {
		// 	data->with0 = data->with0 - 2;
		// 	while (data->with0)
		// 	{
		// 		ft_putchar(' ');
		// 		data->with0--;
		// 	}
		// 	ft_putstr("0x");
		// }	
		if (!data->s_zero)
		{
			puts_p(data);
		}
		else if (data->p == 0 && data->prec == 0 && data->with > 0)
		{
			while (data->with > 0)
			{
				ft_putchar(' ');
				data->with--;
			}
		}
		else if (g==1)
		{
			data->with0 = data->with0 - 2;
			while (data->with0)
			{
				ft_putchar(' ');
				data->with0--;
			}
			ft_putstr("0x");
		}
		else if (g == 2)
		{
			ft_putchar('0');
		}
		//else  if (data->p == 0 && data->with == 0 && data->prec == 0)
		{
			ft_putstr("0x");
		}
}

// //////////////////////////////////////////////////////



else if (str2[i] == 'p')
{
		data->p = va_arg(st, unsigned long);

		char *hex;
		hex = conv_hexp(data->p);
		data->lenS = ft_strlen(hex);
		data->lenD = lenR(data->prec) + 1;
		if ((str2[i - 1] == '.') || ((str2[i - 1] == '*') && (str2[i - 2] == '.')) ||
		 ((str2[i - 1] == '0') && (str2[i - 2] == '.')) ||
		  (data->prec > 0 && (str2[i - data->lenD] == '.')))
				data->point_d = 1;

		// if (data->with >= data->lenS)
		// 	data->with = data->with - data->lenS;
		// else
		// 	data->with = 0;

		if (data->prec < 0)
			{
		    	data->prec = 0;
				data->prec_moin = 1;
			}
		if (data->with < 0)
			{
			  data->with = (data->with * (-1));
			  data->moin = 1;
			}	
		// data->lenD = ft_strlen(hex);
		int g = 0;
		if (data->u == 0 && data->prec == 0 && data->with > 0)
			g = 1;
		else if (data->u == 0 && data->prec == 1 && data->with == 0)
			g = 2;
		
		if (data->u == 0)
			data->lenD = 1;
		if (data->prec > data->with)
			data->with = 0;
		if (data->with < data->lenD)
			data->with = 0;
		else if (data->with >= data->lenD)
			data->with = data->with - data->lenD;

		if (data->with >= data->prec && data->prec < data->lenD)
			data->prec = 0;
			
		if (data->prec > data->with && data->prec < data->lenD)
			data->prec = 0;

		if (data->prec >= data->lenD)
			data->prec = data->prec - data->lenD;
		
		if (data->with >= data->prec)
			data->with = data->with - data->prec;
			
		
		if (data->point_d == 0 || ( data->point_d == 1 && data->with0 > data->prec0))
		{
				if (data->moin)
				{
					ft_putstr(hex);
					while (data->with)
						{
							ft_putchar(' ');
							data->with--;
						}
				}
				else
				{
					while (data->with)
						{
							ft_putchar(' ');
							data->with--;
						}
					ft_putstr(hex);
				}
		}
		else
		{
			data->prec = data->prec - 1;
			ft_putstr(hex);
			while (data->prec)
			{
				ft_putchar('0');
				data->prec--;
			}
		}
		
		
		


		
}
//////////////////////////////////////////////////////


	free(data);
	return i;
}
*/
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