/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 22:54:53 by edinguim          #+#    #+#             */
/*   Updated: 2017/11/14 21:49:16 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n <= ft_strlen(s1) || n <= ft_strlen(s2))
		return (ft_memcmp(s1, s2, n));
	else
		return (ft_strcmp(s1, s2));
}
