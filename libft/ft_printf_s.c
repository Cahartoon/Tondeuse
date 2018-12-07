/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 00:19:34 by edinguim          #+#    #+#             */
/*   Updated: 2018/02/12 10:38:10 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_setprecision(t_print *p, char *s)
{
	if (p->precision < (int)ft_strlen(s) && p->precision > 0)
		s[p->precision] = '\0';
	if (p->precision == -1)
	{
		p->precision = 0;
		ft_strdel(&s);
		s = ft_strdup("");
	}
}

static void		ft_setflags(t_print *p)
{
	if (p->f_moins)
		p->f_zero = 0;
}

void			ft_printf_s(t_print *p)
{
	char	*tmp;
	char	*s;

	s = va_arg(p->arg, char *);
	if (s)
		tmp = ft_strdup(s);
	else
		tmp = ft_strdup("(null)");
	ft_setflags(p);
	ft_setprecision(p, tmp);
	ft_printf_flags(p, tmp, ft_strdup(""));
}
