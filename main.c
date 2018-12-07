/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:09:24 by edinguim          #+#    #+#             */
/*   Updated: 2018/12/07 12:31:31 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tondeuse.h"

/*Fonction qui identifie si la ligne correspond a la pelouse*/
int		is_lawn(char *s)
{
	/*tant que le caractere est un nombre, on continue*/
	while (ft_isdigit(*s))
		s++;
	/*si le caractere n'est pas un espace, on retourne faux*/
	if (*s != ' ')
		return (0);
	s++;
	/*on regarde que l'on a bien une deuxieme coordonnees*/
	while (ft_isdigit(*s))
		s++;
	/*si on arrive a la fin de la chaine de caracteres, on retourne vrai*/
	if (!*s)
		return (1);
	/*sinon, on retourne faux*/
	return (0);
}

/*Fonction qui identifie une tondeuse*/
/*fonctionne comme is_lawn sauf qu'on cherche l'orientation a la fin de s*/
int		is_mower(char *s)
{
	while (ft_isdigit(*s))
		s++;
	if (*s != ' ')
		return (0);
	s++;
	while (ft_isdigit(*s))
		s++;
	if (*s != ' ')
		return (0);
	s++;
	if (*s != 'N' && *s != 'S' && *s != 'E' && *s != 'W')
		return (0);
	s++;
	if (!*s)
		return (1);
	return (0);
}

/*Fonction qui identifie une ligne de commande*/
int		is_move(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] != 'D' && s[i] != 'G' && s[i] != 'A')
			return (0);
		i++;
	}
	return (1);
}

void	init_lawn(t_lawn *lawn)
{
	lawn->x = 0;
	lawn->y = 0;
}

void	update_lawn(t_lawn *lawn, char *line)
{
	lawn->x = ft_atoi(line);
	while (*line != ' ')
		line++;
	lawn->y = ft_atoi(line);
}

void	init_mower(t_mower *mower)
{
	mower->name = 0;
	mower->x = 0;
	mower->y = 0;
	mower->orientation = 'A';
}

void	update_mower(t_mower *mower, int i, char *line)
{
	mower->name = i;
	mower->x = ft_atoi(line);
	while (*line != ' ')
		line++;
	mower->y = ft_atoi(line);
	line++;
	while (*line != ' ')
		line++;
	line++;
	mower->orientation = *line;
}

void	update_orientation(t_mower *mower, char c)
{
	if (c == 'D')
	{
		if (mower->orientation == 'N')
			mower->orientation = 'E';
		else if (mower->orientation == 'E')
			mower->orientation = 'S';
		else if (mower->orientation == 'S')
			mower->orientation = 'W';
		else if (mower->orientation == 'W')
			mower->orientation = 'N';
	}
	if (c == 'G')
	{
		if (mower->orientation == 'N')
			mower->orientation = 'W';
		else if (mower->orientation == 'W')
			mower->orientation = 'S';
		else if (mower->orientation == 'S')
			mower->orientation = 'E';
		else if (mower->orientation == 'E')
			mower->orientation = 'N';
	}
}

void	moving_forward(t_lawn *lawn, t_mower *mower)
{
	if (mower->orientation == 'N' && mower->y < lawn->y)
		mower->y = mower->y + 1;
	if (mower->orientation == 'S' && mower->y > 0)
		mower->y = mower->y - 1;
	if (mower->orientation == 'E' && mower->x < lawn->x)
		mower->x = mower->x + 1;
	if(mower->orientation == 'W' && mower->x > 0)
		mower->x = mower->x - 1;
}

void	move_mower(t_lawn *lawn, t_mower *mower, char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'G' || line[i] == 'D')
			update_orientation(mower, line[i]);
		if (line[i] == 'A')
			moving_forward(lawn, mower);
		i++;
	}
	ft_printf("Tondeuse %i : %i %i %c\n", mower->name, mower->x, mower->y,
			mower->orientation);
}
/*Fonction qui lit sur l'entree standard les instructions*/
void	read_instruction(char *file)
{
	t_lawn		*lawn;
	t_mower		*mower;
	char		*line;
	int			i;
	int			fd;

	lawn = (t_lawn*)malloc(sizeof(t_lawn));
	mower = (t_mower*)malloc(sizeof(t_mower));
	init_lawn(lawn);
	init_mower(mower);
	fd = open(file, O_RDONLY);
	i = 1;
	while (get_next_line(fd, &line))
	{
		if (is_lawn(line))
			update_lawn(lawn, line);
		else if(is_mower(line))
		{
			update_mower(mower, i, line);
			i++;
		}
		else if (is_move(line))
			move_mower(lawn, mower, line);
	}
	close(fd);
}

int		main(int ac, char **av)
{
	read_instruction(av[1]);
	return (0);
}
