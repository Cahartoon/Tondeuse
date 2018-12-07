/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 03:21:12 by edinguim          #+#    #+#             */
/*   Updated: 2017/11/15 03:37:59 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tabcat(const char **tab)
{
	char	*res;
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
		len += ft_strlen(tab[i++]);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		res = ft_strcat(res, tab[i]);
		i++;
	}
	return (res);
}
