/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_str_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohelee <dohelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 17:34:12 by dohelee           #+#    #+#             */
/*   Updated: 2021/07/31 17:34:13 by dohelee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_toupper_str(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		*(str + i) = ft_toupper(*(str + i));
		i++;
	}
}
