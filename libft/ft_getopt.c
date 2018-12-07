/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:15:11 by edinguim          #+#    #+#             */
/*   Updated: 2018/11/15 17:10:54 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int			ft_getopt(int ac, const char **av, const char *opstr)
{
	int				res;
	static size_t	optind;
	static size_t	nxtc;

	if (!optind)
		optind = 1;
	if (!nxtc)
		nxtc = 1;
	if (optind >= (size_t)ac)
		return (-1);
	res = -2;
	if (*av[optind] == '-' && av[optind][1] && av[optind][1] != '-')
	{
		if (ft_strsrch(opstr, av[optind][nxtc]))
			res = av[optind][nxtc];
		if (nxtc == ft_strlen(av[optind]) - 1)
		{
			++optind;
			nxtc = 1;
		}
		else
			++nxtc;
		return (res);
	}
	return (-1);
}
