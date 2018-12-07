/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 21:20:50 by edinguim          #+#    #+#             */
/*   Updated: 2017/11/15 17:20:48 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t		len;
	char		*ret;

	ret = (char *)s;
	len = ft_strlen(s);
	if (s && c == 0)
		return (&ret[len]);
	while (len)
	{
		len--;
		if (s[len] == (char)c)
			return (&ret[len]);
	}
	return (NULL);
}
