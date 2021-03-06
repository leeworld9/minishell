/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_dec_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 17:31:42 by dohelee           #+#    #+#             */
/*   Updated: 2021/07/31 17:31:43 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

static int	len_nb(long n)
{
	int		i;
	long	nb;

	i = 0;
	nb = n;
	while (nb != 0)
	{
		nb = nb / 10;
		i++;
	}
	if (i == 0)
		return (1);
	else
		return (i);
}

static long	power(int base, int pow)
{
	long	result;

	result = 1;
	while (pow != 0)
	{
		result = result * base;
		pow--;
	}
	return (result);
}

char	*ft_ltoa_dec(long n)
{
	int		i;
	int		len;
	long	result;
	char	*n_str;

	i = 0;
	len = len_nb(n);
	n_str = (char *)malloc(sizeof(char) * (len + 1));
	if (n_str == NULL)
		return (NULL);
	while (i < len)
	{
		result = n / power(10, len - 1 - i);
		result = result % 10;
		*(n_str + i) = result + '0';
		i++;
	}
	*(n_str + i) = '\0';
	return (n_str);
}
