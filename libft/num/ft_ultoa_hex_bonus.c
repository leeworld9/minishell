/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 17:31:54 by dohelee           #+#    #+#             */
/*   Updated: 2021/07/31 17:31:55 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

static int	len_nb(unsigned long n)
{
	int		i;
	long	nb;

	i = 0;
	nb = n;
	while (nb != 0)
	{
		nb = nb / 16;
		i++;
	}
	if (i == 0)
		return (1);
	else
		return (i);
}

static unsigned long	power(int base, int pow)
{
	unsigned long	result;

	result = 1;
	while (pow != 0)
	{
		result = result * base;
		pow--;
	}
	return (result);
}

char	*ft_ultoa_hex(unsigned long n)
{
	int				i;
	int				len;
	unsigned long	result;
	char			*n_str;

	i = 0;
	len = len_nb(n);
	n_str = (char *)malloc(sizeof(char) * (len + 1));
	if (n_str == NULL)
		return (NULL);
	while (i < len)
	{
		result = n / power(16, len - 1 - i);
		result = result % 16;
		if (result < 10)
			*(n_str + i) = result + '0';
		else
			*(n_str + i) = result - 10 + 'a';
		i++;
	}
	*(n_str + i) = '\0';
	return (n_str);
}
