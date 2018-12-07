/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edinguim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:54:39 by edinguim          #+#    #+#             */
/*   Updated: 2018/10/24 03:09:06 by edinguim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_findrest(t_list *lst, size_t fd)
{
	char	*res;

	if (!lst)
		res = ft_strnew(1);
	else
	{
		while (lst->next && lst->content_size != fd)
			lst = lst->next;
		if (lst->content_size == fd)
		{
			res = ft_strdup(lst->content);
			ft_strdel((char**)&(lst->content));
		}
		else
			res = ft_strnew(1);
	}
	return (res);
}

static t_list	*ft_newfd(const char *rest, size_t fd)
{
	t_list	*lst;

	lst = (t_list*)malloc(sizeof(t_list));
	if (lst)
	{
		if (rest)
			lst->content = ft_strdup(rest);
		else
		{
			lst->content = ft_strnew(1);
		}
		lst->content_size = fd;
		lst->next = NULL;
	}
	return (lst);
}

int				get_next_line(int fd, char **line)
{
	static t_list	*liste;
	char			*buffer;
	char			*tmp;
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	ret = 1;
	tmp = ft_findrest(liste, fd);
	while (!ft_strchr(tmp, '\n') && ret > 0)
	{
		buffer = ft_strnew(BUFF_SIZE);
		ret = read(fd, buffer, BUFF_SIZE);
		buffer[ret] = '\0';
		tmp = ft_joinfree(tmp, buffer);
	}
	*line = ft_strsub(tmp, 0, ft_strclen(tmp, '\n'));
	buffer = ft_strsub(tmp, ft_strclen(tmp, '\n') + 1, ft_strlen(tmp));
	ft_strdel(&tmp);
	if (!liste)
		liste = ft_newfd(buffer, fd);
	else
		ft_lstadd(&liste, ft_newfd(buffer, fd));
	ft_strdel(&buffer);
	return ((*line) ? 1 : ret);
}
