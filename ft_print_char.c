/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:51:37 by srikuto           #+#    #+#             */
/*   Updated: 2025/02/13 17:14:16 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int n)
{
	int		ret;
	char	c;
	int		count;

	c = (char)n;
	ret = write(1, &c, 1);
	count = 0;
	if (ret > 0)
		count += ret;
	return (count);
}
