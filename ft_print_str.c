/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:52:06 by srikuto           #+#    #+#             */
/*   Updated: 2025/02/13 17:26:15 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(const char *s)
{
	size_t	index;
	int		count;
	int		ret;

	count = 0;
	index = 0;
	while (s[count])
	{
		ret = 0;
		ret = write(1, &s[index], 1);
		index++;
		if (ret > 0)
			count += ret;
	}
	return (count);
}

// int	main(void)
// {
// 	char *s = "hello world";
// 	ft_print_str(s);
// 	return(0);
// }