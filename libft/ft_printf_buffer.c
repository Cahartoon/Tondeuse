/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 21:24:38 by edinguim          #+#    #+#             */
/*   Updated: 2018/02/12 10:34:46 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_buffer(t_print *p)
{
	int		i;

	i = 0;
	p->result[p->buff_i] = '\0';
	ft_putstr(p->result);
	p->buff_i = 0;
	p->result[p->buff_i] = '\0';
}
