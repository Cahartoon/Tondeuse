/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:43:52 by edinguim          #+#    #+#             */
/*   Updated: 2017/11/14 21:45:05 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	if (ft_strlen(s1) >= ft_strlen(s2))
		return (ft_memcmp(s1, s2, ft_strlen(s1)));
	else
		return (ft_memcmp(s1, s2, ft_strlen(s2)));
}
