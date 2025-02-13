/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sometani <sometani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 21:11:58 by srikuto           #+#    #+#             */
/*   Updated: 2025/02/09 23:11:40 by sometani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int n)
{
	int	ret;
	char	c;
	int	count;

	c = (char)n;
	ret = write(1, &c, 1);
	count = 0;
	if (ret > 0)
		count += ret;
	return (count);
}