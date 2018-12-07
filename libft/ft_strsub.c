/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:03:57 by edinguim          #+#    #+#             */
/*   Updated: 2017/11/12 00:35:52 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	if (s && start < ft_strlen(s))
	{
		i = 0;
		if (!(res = ft_strnew(len)))
			return (NULL);
		while (i < len && s[i])
		{
			res[i] = (char)s[start + i];
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}
