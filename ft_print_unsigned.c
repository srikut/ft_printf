/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:51:19 by srikuto           #+#    #+#             */
/*   Updated: 2025/04/12 21:07:29 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_num(unsigned int n)
{
	int		count;
	int		ret;
	char	c;

	count = 0;
	ret = 0;
	c = n % 10 + '0';
	if (n >= 10)
		count += print_num(n / 10);
	ret = write(1, &c, 1);
	if (ret > 0)
		count += ret;
	return (count);
}

int	ft_print_unsigned(unsigned int n)
{
	return (print_num(n));
}
