/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srikuto <srikuto@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 21:14:22 by srikuto           #+#    #+#             */
/*   Updated: 2025/02/04 21:20:22 by srikuto          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_str(char *s)
{
	int	count;

	count = 0;
	while(s[count])
	{
		write(1, &s[count], 1);
		count++;
	}
	return (count);
}

// int	main(void)
// {
// 	char *s = "hello world";
// 	ft_print_str(s);
// 	return(0);
// }