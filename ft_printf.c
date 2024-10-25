/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacarret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:45:28 by dacarret          #+#    #+#             */
/*   Updated: 2024/10/24 10:13:56 by dacarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_retcar(va_list ap, char c)
{
	int	count;

	count = 0;
	if (c == '%')
		count += put_char(c);
	else if (c == 'c')
		count += put_char(va_arg(ap, int));
	else if (c == 's')
		count += put_string(va_arg(ap, char *));
	else if (c == 'u')
		count += put_num((unsigned long)va_arg(ap, unsigned int), 10, c);
	else if (c == 'd' || c == 'i')
		count += put_int((long)va_arg(ap, int), 10);
	else if (c == 'x' || c == 'X')
		count += put_num((unsigned long)va_arg(ap, unsigned int), 16, c);
	else if (c == 'p')
		count += put_vect(va_arg(ap, void *), 16, c);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	ap;

	if (!str)
		return (0);
	count = 0;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			count += ft_retcar(ap, str[i]);
		}
		else
			count += put_char(str[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
