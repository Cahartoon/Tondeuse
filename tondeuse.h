/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tondeuse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:10:29 by edinguim          #+#    #+#             */
/*   Updated: 2018/12/07 10:52:49 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TONDEUSE_H
# define TONDEUSE_H
# include "./libft/libft.h"

/*Structure tondeuse*/
typedef struct		s_mower
{
	int				name;
	int				x;
	int				y;
	char			orientation;
}					t_mower;

/*Structure pelouse*/
typedef struct		s_lawn
{
	int				x;
	int				y;
}					t_lawn;

#endif
