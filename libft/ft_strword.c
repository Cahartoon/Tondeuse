/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strword.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:09:58 by edinguim          #+#    #+#             */
/*   Updated: 2017/11/11 19:21:52 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strword(const char *s, char c)
{
	size_t	count;

	count = 0;
	if (s && ft_strlen(s))
	{
		if (*s != c)
			count++;
		while (*s)
		{
			if (*s != c && *(s - 1) == c)
				count++;
			s++;
		}
	}
	return (count);
}
