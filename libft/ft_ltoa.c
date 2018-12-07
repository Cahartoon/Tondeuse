/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 03:24:56 by edinguim          #+#    #+#             */
/*   Updated: 2018/02/12 10:38:55 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ltoa(intmax_t n)
{
	char		*res;
	size_t		len;

	len = ft_intmaxsize(n);
	res = ft_strnew(len);
	if (n == -9223372036854775807 - 1)
		return (ft_strdup("-9223372036854775808"));
	if (!res)
		return (NULL);
	len--;
	if (n < 0)
	{
		n = -n;
		res[0] = '-';
	}
	if (n == 0)
		res[0] = '0';
	while (n > 0)
	{
		res[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
