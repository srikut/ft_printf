/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sometani <sometani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:15:23 by srikuto           #+#    #+#             */
/*   Updated: 2025/02/07 16:38:51 by sometani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdint.h> 
#include<stdio.h>

int	print_hex_rec(uintptr_t address, const char *hex_base)
{
	size_t	index;
	int		count;

	index = address % 16;
	if (address >= 16)
		count += print_hex_rec(address / 16, hex_base);
	count += write(1, &hex_base[index], 1);
	return (count);
}
int	ft_print_ptr(void *ptr)
{
	const char *hex_base = "0123456789abcdef";
	uintptr_t address;
	int	count;

	count = 0;
	address = (uintptr_t)ptr;
	count += write(1, "0", 1);
	count += write(1, "x", 1);
	count += print_hex_rec(address, hex_base);
	return (count);
}

int	main(void)
{
	int		printed_chars;
	int		x;

	x = 42;
	/* 変数 x のアドレスを出力 */
	printed_chars = ft_print_ptr(&x);
	/* 出力結果の後に改行を追加 */
	write(1, "\n", 1);
	printf("%d", printed_chars);

	/* 出力した文字数を返しても良いです */
	return (0);
}