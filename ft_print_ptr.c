/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:51:58 by srikuto           #+#    #+#             */
/*   Updated: 2025/02/19 20:56:11 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_rec(uintptr_t address, const char *hex_base)
{
	size_t	index;
	int		count;
	int		ret;

	count = 0;
	index = address % 16;
	if (address >= 16)
		count += print_hex_rec(address / 16, hex_base);
	ret = write(1, &hex_base[index], 1);
	if (ret > 0)
		count += ret;
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	const char	*hex_base = "0123456789abcdef";
	uintptr_t	address;
	int			count;
	int			ret;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	count = 0;
	address = (uintptr_t)ptr;
	ret = write(1, "0", 1);
	if (ret > 0)
		count += ret;
	ret = write(1, "x", 1);
	if (ret > 0)
		count += ret;
	count += print_hex_rec(address, hex_base);
	return (count);
}

// int	main(void)
// {
// 	int		printed_chars;
// 	int		x;

// 	x = 42;
// 	/* 変数 x のアドレスを出力 */
// 	printed_chars = ft_print_ptr(&x);
// 	/* 出力結果の後に改行を追加 */
// 	write(1, "\n", 1);
// 	printf("%d", printed_chars);

// 	/* 出力した文字数を返しても良いです */
// 	return (0);
// }