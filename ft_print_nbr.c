/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:39:32 by srikuto           #+#    #+#             */
/*   Updated: 2025/02/04 21:11:49 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_print_nbr(int n)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		count += ft_print_nbr(n / 10);
	c = (n % 10) + '0';
	count += write(1, &c, 1);
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
