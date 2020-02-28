/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:27:22 by rel-bour          #+#    #+#             */
/*   Updated: 2020/02/28 15:47:14 by rel-bour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include "libft/libft.h"
#include <string.h>

#define f "%u", 65456

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
