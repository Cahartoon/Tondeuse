/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:03:30 by edinguim          #+#    #+#             */
/*   Updated: 2017/11/12 02:29:06 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(const char *str, int fd)
{
	if (!str || !fd)
		return ;
	ft_putstr_fd(str, fd);
	ft_putchar_fd('\n', fd);
}
