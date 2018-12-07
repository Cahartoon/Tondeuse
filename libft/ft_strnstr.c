/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:05:55 by edinguim          #+#    #+#             */
/*   Updated: 2017/11/12 04:54:31 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(s2) > ft_strlen(s1) || ft_strlen(s2) > len || !s1)
		return (NULL);
	if (!ft_strlen(s2))
		return ((char*)s1);
	while (s1[i] && i < len)
	{
		j = 0;
		while (s1[i + j] == s2[j] && (i + j) < len)
		{
			if (j == ft_strlen(s2) - 1)
				return ((char*)&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
