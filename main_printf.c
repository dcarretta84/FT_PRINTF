/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacarret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:52:50 by dacarret          #+#    #+#             */
/*   Updated: 2024/10/24 12:08:20 by dacarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
	
#include "ft_printf.h"
int main()
{
    	int number = 123;
	int *p = &number;
	ft_printf("\nFT_PRINTF\n");
	int count1 = ft_printf("Carattere: %c\nStringa: %s\nCarattere Speciale: %%\nIntero1: %d\nIntero2: %i\nHexadecimal: %x\nHEXADECIMAL: %X\nPointer: %p\n", 'a', NULL, -217896, 0, 635535, 65535, NULL);
	ft_printf("COUNT: %i\n\n", count1);

	printf("PRINTF\n");
        int count2 = printf("Carattere: %c\nStringa: %s\nCarattere Speciale: %%\nIntero1: %d\nInter02: %i\nHexadecimal: %x\nHEXADECIMAL: %X\nPointer: %p\n", 'a', NULL, -217896, 0, 635535, 65535, NULL);
	printf("COUNT: %i\n\n", count2);

	return (0);
}
