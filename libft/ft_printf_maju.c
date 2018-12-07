/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_maju.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 10:04:20 by edinguim          #+#    #+#             */
/*   Updated: 2018/02/12 10:36:44 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_setflags(t_print *p, char *s)
{
	if (p->f_moins)
		p->f_zero = 0;
	if (ft_strlen(s) == 1 && s[0] == '0' && p->precision == -1)
	{
		p->f_hash = 0;
		p->f_zero = 0;
		ft_strdel(&s);
		s = ft_strdup("");
	}
}

void			ft_printf_maju(t_print *p)
{
	char	*tmp;

	tmp = ft_utoa_base(va_arg(p->arg, unsigned long), 10);
	ft_setflags(p, tmp);
	ft_printf_flags(p, tmp, ft_strdup(""));
}
