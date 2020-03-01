/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:27:22 by rel-bour          #+#    #+#             */
/*   Updated: 2020/03/01 11:36:30 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include "libft/libft.h"
#include <string.h>

#define f "%%%s", "Reda"

//"TEST TEST 0000%%%*.*s%%%-15.8dTEST%-15.8u0000000\t%%%15%%.3% %---15d %00015x", 7,5, "ABC",15,0,20,0x99

//"%0.10p", (void*)0

int main()
{
    
    // int r1 = 0;
    // ft_printf(f);
    // printf("\n");
    // r1 = printf(f);
    // printf("\nr = %d\nrd = %d", r1, g_r);
    
    printf("\n%d\n", ft_printf(f));
    printf("\n%d\n", printf(f));

        
//     system("leaks a.out");
    
}
