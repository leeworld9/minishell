/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 17:32:45 by dohelee           #+#    #+#             */
/*   Updated: 2021/07/31 17:32:46 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	len_nb(int n)
{
	int	i;
	int	nb;

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

static int	power(int base, int pow)
{
	int	result;

	result = 1;
	while (pow != 0)
	{
		result = result * base;
		pow--;
	}
	return (result);
}

static int	is_negative(int n, int fd)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		return (n * -1);
	}
	else
	{
		return (n);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		len;
	int		result;
	char	result_str;

	i = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else
	{
		n = is_negative(n, fd);
		len = len_nb(n);
		while (i < len)
		{
			result = n / power(10, len - 1 - i);
			result = result % 10;
			result_str = result + '0';
			write(fd, &result_str, 1);
			i++;
		}
	}
}
