/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add_conv.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 22:38:24 by edinguim          #+#    #+#             */
/*   Updated: 2018/02/12 10:34:35 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_add_conv(t_print *p, char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (p->buff_i >= 3999)
			ft_printf_buffer(p);
		p->result[p->buff_i] = s[i];
		i++;
		p->buff_i++;
	}
	ft_strdel(&s);
}
