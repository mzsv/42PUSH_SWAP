/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amenses- <amenses-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 22:37:30 by amenses-          #+#    #+#             */
/*   Updated: 2024/08/01 23:03:10 by amenses-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps.h"

long long	ft_long_atoi(const char *nptr)
{
	long long	res;
	int			sign;

	sign = 1;
	res = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	if (ft_strlen(nptr) > 10)
		return (2147483648);
	while ((*nptr >= 48 && *nptr <= 57) && *nptr)
	{
		res = res * 10 + *nptr - '0';
		nptr++;
	}
	return (res * sign);
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_arrcpy(int *dst, int *src, int nelem)
{
	int	i;

	i = 0;
	while (i < nelem)
	{
		dst[i] = src[i];
		i++;
	}
}

int	*ft_arrsort(int *arr, int size)
{
	int	i;
	int	tmp;

	if (!arr || !size)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (arr);
}

int	ft_arrfind(int *arr, int value, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
