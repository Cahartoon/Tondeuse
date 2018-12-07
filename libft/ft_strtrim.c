/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:05:38 by edinguim          #+#    #+#             */
/*   Updated: 2017/11/15 01:53:21 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strtrim(const char *s)
{
	int				st;
	int				end;
	char			*res;

	if (s)
	{
		st = 0;
		end = ft_strlen(s) - 1;
		while ((s[st] == ' ' || s[st] == '\n' || s[st] == '\t') && st != end)
			st++;
		if (st == end || end == -1)
		{
			res = ft_strnew(0);
			if (!res)
				return (NULL);
			return (res);
		}
		while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
			end--;
		if (!(res = ft_strnew(end - st)))
			return (NULL);
		res = ft_strsub(s, st, end - st + 1);
		return (res);
	}
	return (NULL);
}
