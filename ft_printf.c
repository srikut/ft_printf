/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:14:23 by srikuto           #+#    #+#             */
/*   Updated: 2025/02/04 20:18:14 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdarg.h>
#include<stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list args;
	int	count;
	size_t	i;

	va_start (args, format);
	count = 0;
	while (*format)
	{
		if(*format == '%')
		{
			format++;
			if (*format == 'd')
				count += ft_print_nbr(va_arg(args, int));
			else if (*format == 's')
				count += ft_print_str(va_arg(args, char *));
			else if (*format == 'c')
				count += ft_print_char(va_arg(args, char));
			else if (*format == 'p')
				count += ft_print_ptr(va_arg(args, void *));
			else if (*format == 'u')
				count += ft_print_unsigned(va_arg(args, unsigned int));
			else if (*format == 'x' || *format == 'X')
				count += ft_print_hex(va_arg(args, unsigned int), *format);
			else if(*format == '%')
				count += write(1, "%", 1);
		}
		else
			count += write(1, &format, 1);
		i++;
	}
	va_end(args);
	return(count);
}