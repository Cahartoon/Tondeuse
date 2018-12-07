/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:41:19 by edinguim          #+#    #+#             */
/*   Updated: 2018/05/14 01:11:12 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	word;
	char	**tab;

	if (!s)
		return (NULL);
	word = ft_strword(s, c);
	if (!(tab = (char**)malloc(sizeof(*tab) * (word + 1))))
		return (NULL);
	i = 0;
	while (i < word)
	{
		while (*s == c && *s)
			s++;
		tab[i] = ft_strsub(s, 0, ft_strclen(s, c));
		if (!tab[i])
			return (NULL);
		s = s + ft_strclen(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
