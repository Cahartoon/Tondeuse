/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 04:54:30 by edinguim          #+#    #+#             */
/*   Updated: 2018/02/12 10:39:17 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_ublen(unsigned long long nb, int base)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		len++;
	}
	return (len);
}

char			*ft_utoa_base(unsigned long long nb, int base)
{
	char	*ret;
	size_t	len;

	len = ft_ublen(nb, base);
	ret = ft_strnew(len);
	if (!ret)
		return (NULL);
	if (nb == 0)
		ret[0] = '0';
	while (nb > 0)
	{
		ret[--len] = nb % base > 9 ? nb % base - 10 + 'a' : nb % base + '0';
		nb /= base;
	}
	return (ret);
}
