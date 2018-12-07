/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabccat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 03:38:21 by edinguim          #+#    #+#             */
/*   Updated: 2017/11/15 04:03:48 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tabccat(const char **tab, const char *s)
{
	char	*res;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (!tab || !s)
		return (NULL);
	while (tab[i])
	{
		len += ft_strlen(tab[i]);
		if (tab[++i])
			len += ft_strlen(s);
	}
	if (!(res = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (tab[i])
	{
		res = ft_strcat(res, tab[i]);
		if (tab[++i])
			res = ft_strcat(res, s);
	}
	return (res);
}
