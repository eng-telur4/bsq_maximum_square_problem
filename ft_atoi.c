/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eng-telur4 <eng-telur4@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:12:12 by skamijo           #+#    #+#             */
/*   Updated: 2024/09/25 02:18:48 by eng-telur4       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

// 本家のatoiに寄せてる
int	ft_atoi(char *str)
{
	int	ret;
	int	sign;

	ret = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
		{
			ret = ret * 10 + (*str - '0');
			str++;
		}
		else
			break ;
	}
	return (ret * sign);
}
