/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:52:06 by srikuto           #+#    #+#             */
/*   Updated: 2025/04/12 21:08:51 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(const char *s)
{
	size_t	index;
	int		count;
	int		ret;

	if (s == NULL)
		return (write(1, "(null)", 6));
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
