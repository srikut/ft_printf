/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:51:27 by srikuto           #+#    #+#             */
/*   Updated: 2025/02/13 17:13:40 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_conversion(char specifier, va_list args)
{
	int	count;
	int	ret;

	count = 0;
	if (specifier == 'd')
		count += ft_print_nbr(va_arg(args, int));
	else if (specifier == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (specifier == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (specifier == 'p')
		count += ft_print_ptr(va_arg(args, void *));
	else if (specifier == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
	{
		ret = write(1, "%", 1);
		if (ret > 0)
			count += ret;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		ret;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += handle_conversion(*format, args);
		}
		else
		{
			ret = write(1, format, 1);
			if (ret > 0)
				count += ret;
		}
		format++;
	}
	va_end(args);
	return (count);
}

// int	ft_printf(const char *format, ...)
// {
// 	va_list args;
// 	int		count;

// 	va_start (args, format);
// 	count = 0;
// 	while (*format)
// 	{
// 		if (*format == '%')
// 		{
// 			format++;
// 			if (*format == 'd')
// 				count += ft_print_nbr(va_arg(args, int));
// 			else if (*format == 's')
// 				count += ft_print_str(va_arg(args, char *));
// 			else if (*format == 'c')
// 				count += ft_print_char(va_arg(args, int));
// 			else if (*format == 'p')
// 				count += ft_print_ptr(va_arg(args, void *));
// 			else if (*format == 'u')
// 				count += ft_print_unsigned(va_arg(args, unsigned int));
// 			else if (*format == 'x' || *format == 'X')
// 				count += ft_print_hex(va_arg(args, unsigned int), *format);
// 			else if (*format == '%')
// 				count += write(1, "%", 1);
// 		}
// 		else
// 			count += write(1, &format, 1);
// 		format++;
// 	}
// 	va_end (args);
// 	return (count);
// }