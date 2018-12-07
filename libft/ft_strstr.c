/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:33:54 by edinguim          #+#    #+#             */
/*   Updated: 2017/11/29 17:33:59 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(s2) > ft_strlen(s1) || !s1)
		return (NULL);
	if (!ft_strlen(s2))
		return ((char*)s1);
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j])
		{
			if (j == ft_strlen(s2) - 1)
				return ((char*)&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
