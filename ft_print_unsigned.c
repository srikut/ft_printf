/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:51:19 by srikuto           #+#    #+#             */
/*   Updated: 2025/02/19 18:07:27 by srikuto          ###   ########.fr       */
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
// int	ft_print_unsigned(unsigned int n)
// {
// 	if (n < 0)
// 		n = 4294967294 + n;
// 	return (print_num(n));
// }
// int main(void)
// {
//     unsigned int num1;
//     unsigned int num2;
//     int count;

//     /* テストケース1: 普通の正の数 */
//     num1 = 12345;
//     printf("Test 1: ft_print_unsigned(%u)\nOutput: ", num1);
//     count = ft_print_unsigned(num1);
//     write(1, "\n", 1);
//     printf("Number of characters printed: %d\n\n", count);

//     /* テストケース2: (unsigned int)に変換した-1（32ビット環境なら4294967295となる） */
//     num2 = (unsigned int)-1;
//     printf("Test 2: ft_print_unsigned(%u)\nOutput: ", num2);
//     count = ft_print_unsigned(num2);
//     write(1, "\n", 1);
//     printf("Number of characters printed: %d\n", count);

//     return (0);
// }