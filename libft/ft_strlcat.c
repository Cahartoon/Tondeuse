/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:03:45 by edinguim          #+#    #+#             */
/*   Updated: 2017/11/14 23:09:44 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t		ft_strlcat(char *dest, const char *src, size_t l)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dest);
	slen = ft_strlen(src);
	i = 0;
	if (l <= dlen)
		return (l + slen);
	while (i < l - 1 && dest[i])
		i++;
	while (i < l - 1 && *src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (slen + dlen);
}
