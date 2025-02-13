/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sometani <sometani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:39:32 by srikuto           #+#    #+#             */
/*   Updated: 2025/02/10 21:45:53 by sometani         ###   ########.fr       */
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

// int	main(void)
// {
// 	int	a = 0;
// 	int	b = 512;
// 	int	c = -512;
// 	int	d = -2147483648;
// 	int e = 2147483647;

// 	ft_print_nbr(a);
// 	write(1, "\n", 1);
// 	ft_print_nbr(b);
// 	write(1, "\n", 1);
// 	ft_print_nbr(c);
// 	write(1, "\n", 1);
// 	ft_print_nbr(d);
// 	write(1, "\n", 1);
// 	ft_print_nbr(e);
// 	write(1, "\n", 1);
	
// 	return (0);
// }
