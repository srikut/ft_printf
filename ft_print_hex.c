/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:51:44 by srikuto           #+#    #+#             */
/*   Updated: 2025/04/12 21:08:10 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*make_index_lower(char *index)
{
	index[0] = '0';
	index[1] = '1';
	index[2] = '2';
	index[3] = '3';
	index[4] = '4';
	index[5] = '5';
	index[6] = '6';
	index[7] = '7';
	index[8] = '8';
	index[9] = '9';
	index[10] = 'a';
	index[11] = 'b';
	index[12] = 'c';
	index[13] = 'd';
	index[14] = 'e';
	index[15] = 'f';
	index[16] = '\0';
	return (index);
}

static char	*make_index_upper(char *index)
{
	index[0] = '0';
	index[1] = '1';
	index[2] = '2';
	index[3] = '3';
	index[4] = '4';
	index[5] = '5';
	index[6] = '6';
	index[7] = '7';
	index[8] = '8';
	index[9] = '9';
	index[10] = 'A';
	index[11] = 'B';
	index[12] = 'C';
	index[13] = 'D';
	index[14] = 'E';
	index[15] = 'F';
	index[16] = '\0';
	return (index);
}

int	put_hex(unsigned int n, const char *nbr)
{
	int		count;
	size_t	index;
	int		ret;

	count = 0;
	index = n % 16;
	if (n >= 16)
	{
		ret = put_hex(n / 16, nbr);
		if (ret > 0)
			count += ret;
	}
	ret = write(1, &nbr[index], 1);
	if (ret > 0)
			count += ret;
	return (count);
}

int	ft_print_hex(unsigned int n, const char format)
{
	char	*nbr;
	int		count;

	nbr = (char *)malloc(sizeof(char) * 16);
	if (!nbr)
		return (0);
	if (format == 'x')
		nbr = make_index_lower(nbr);
	else
		nbr = make_index_upper(nbr);
	count = 0;
	count += put_hex(n, nbr);
	free (nbr);
	return (count);
}
