/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:51:24 by edinguim          #+#    #+#             */
/*   Updated: 2018/02/12 10:37:57 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printf_check_flags(t_print *p, char c)
{
	if (c == '#')
		p->f_hash = 1;
	else if (c == '0')
		p->f_zero = 1;
	else if (c == '-')
		p->f_moins = 1;
	else if (c == '+')
		p->f_plus = 1;
	else if (c == ' ')
		p->f_space = 1;
	else
		return (0);
	p->fmt_i++;
	return (1);
}

static int	ft_printf_check_modifier(t_print *p, const char *fmt)
{
	if (fmt[p->fmt_i] == 'l')
	{
		if (fmt[p->fmt_i + 1] && fmt[p->fmt_i + 1] == 'l' && p->fmt_i++)
			p->m_ll = 1;
		else
			p->m_l = 1;
	}
	else if (fmt[p->fmt_i] == 'h')
	{
		if (fmt[p->fmt_i + 1] && fmt[p->fmt_i + 1] == 'h' && p->fmt_i++)
			p->m_hh = 1;
		else
			p->m_h = 1;
	}
	else if (fmt[p->fmt_i] == 'j')
		p->m_j = 1;
	else if (fmt[p->fmt_i] == 'z')
		p->m_z = 1;
	else
		return (0);
	p->fmt_i++;
	return (1);
}

static int	ft_printf_check_width(t_print *p, const char *fmt)
{
	if (ft_isdigit(fmt[p->fmt_i]) && fmt[p->fmt_i - 1] != '.')
	{
		p->width = ft_atoi(fmt + p->fmt_i);
		p->fmt_i += ft_intmaxsize(p->width);
		return (1);
	}
	return (0);
}

static int	ft_printf_check_precision(t_print *p, const char *fmt)
{
	if (fmt[p->fmt_i] == '.' && fmt[p->fmt_i + 1] &&
		((fmt[p->fmt_i + 1] >= '0' && fmt[p->fmt_i + 1] <= '9') ||
		fmt[p->fmt_i + 1] == '.'))
	{
		p->fmt_i++;
		while (fmt[p->fmt_i] == '0' || fmt[p->fmt_i] == '.')
		{
			p->fmt_i++;
			p->f_zero = 1;
		}
		p->precision = ft_atoi(fmt + p->fmt_i);
		if (p->precision)
			p->fmt_i += ft_intmaxsize(p->precision);
		else if (p->precision <= 0)
			p->precision = -1;
		return (1);
	}
	else if (fmt[p->fmt_i] == '.')
	{
		p->fmt_i++;
		p->precision = -1;
		return (1);
	}
	return (0);
}

void		ft_printf_parse(t_print *p, const char *fmt)
{
	p->fmt_i++;
	while (fmt[p->fmt_i])
	{
		if (ft_printf_check_flags(p, fmt[p->fmt_i]))
			continue ;
		if (ft_printf_check_modifier(p, fmt))
			continue ;
		if (ft_printf_check_width(p, fmt))
			continue ;
		if (ft_printf_check_precision(p, fmt))
			continue ;
		if (ft_strchr("sSpidDoOuUxXcC%", fmt[p->fmt_i]))
		{
			p->conv = fmt[p->fmt_i];
			p->fmt_i++;
			break ;
		}
		else
			break ;
		p->fmt_i++;
	}
	ft_printf_conv(p);
}
