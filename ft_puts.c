/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacarret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:21:07 by dacarret          #+#    #+#             */
/*   Updated: 2024/10/24 10:21:35 by dacarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdint.h>

int	put_char(int c)
{
	return (write(1, &c, 1));
}

int	put_string(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
	{
		count += put_string("(null)");
		return (count);
	}
	while (str[i])
	{
		count += put_char(str[i]);
		i++;
	}
	return (count);
}

int	put_num(unsigned long num, unsigned int base, char c)
{
	int		count;
	char	*letters;
	char	*letters_cap;

	count = 0;
	letters = "0123456789abcdef";
	letters_cap = "0123456789ABCDEF";
	if (num >= base)
		count += put_num(num / base, base, c);
	if (c == 'x' || c == 'p' || c == 'u')
		count += put_char(letters[num % base]);
	else if (c == 'X')
		count += put_char(letters_cap[num % base]);
	return (count);
}

int	put_int(long num, unsigned int base)
{
	int		count;

	count = 0;
	if (num < 0)
	{
		count += put_char('-');
		num *= -1;
	}
	if (num >= base)
		count += put_int(num / base, base);
	count += put_char(num % base + '0');
	return (count);
}

int	put_vect(void *p, unsigned int base, char c)
{
	int				count;
	unsigned long	address;

	count = 0;
	address = (unsigned long)p;
	if (!p)
	{
		count += put_string("(nil)");
		return (count);
	}
	count += put_string("0x");
	count += put_num(address, base, c);
	return (count);
}
