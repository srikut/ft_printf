/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:51:53 by srikuto           #+#    #+#             */
/*   Updated: 2025/04/12 21:09:34 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr(int n)
{
	char	c;
	int		count;
	int		ret;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		ret = write(1, "-", 1);
		if (ret > 0)
			count += ret;
		n = -n;
	}
	if (n > 9)
		count += ft_print_nbr(n / 10);
	c = (n % 10) + '0';
	ret = write(1, &c, 1);
	if (ret > 0)
		count += ret;
	return (count);
}
