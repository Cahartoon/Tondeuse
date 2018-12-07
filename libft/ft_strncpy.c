/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:39:04 by edinguim          #+#    #+#             */
/*   Updated: 2017/11/15 02:31:31 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	dest = ft_memcpy(dest, src, n);
	if (n > ft_strlen(src))
		ft_bzero(dest + ft_strlen(src), n - ft_strlen(src));
	return (dest);
}
