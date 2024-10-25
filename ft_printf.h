/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dacarret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:28:47 by dacarret          #+#    #+#             */
/*   Updated: 2024/10/24 11:29:34 by dacarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	put_char(int c);
int	put_string(char *str);
int	put_int(long num, unsigned int base);
int	put_num(unsigned long num, unsigned int base, char c);
int	put_vect(void *p, unsigned int base, char c);
int	ft_retcar(va_list ap, char c);
int	ft_printf(const char *str, ...);
#endif             
