/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:30:38 by edinguim          #+#    #+#             */
/*   Updated: 2018/09/13 21:01:58 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dptr;

	dptr = (unsigned char *)dest;
	while (n--)
		*dptr++ = *(unsigned char *)src++;
	*dptr = '\0';
	return (dest);
}
