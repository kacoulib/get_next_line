/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacoulib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 23:07:51 by kacoulib          #+#    #+#             */
/*   Updated: 2016/12/29 04:54:38 by kacoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include "stdio.h" // to remove

t_list			*ft_get_or_create(t_list *lst, void const *content, size_t id)
{
	while (lst->next && lst->content_size != id)
	{
		lst = lst->next;
	}
	//printf("(%zu)",id);
	if (lst->content_size == id)
		return (lst);
	lst->next = ft_lstnew(content, id);
	return (lst->next);
}

char			*ft_get_first_char(char buff[])
{
	char		*tmp;

	tmp = ft_strdup(buff);
	while (*tmp && *tmp == '\n')
		tmp++;
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	static int	i;
	int			stop;
	int			end;
	static t_list	list;
	char		buff[BUFF_SIZE + 1];
	char		*r;

	i = 0;
	stop = 1;
	end = 0;
	list = (t_list){(void*)NULL, (size_t)fd, NULL};
	//printf("%p\t %zu\n", &lst->content_size, lst->content_size);
	r = ft_strnew(0);
	while (stop && (i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (ft_indexof(buff, '\0'))
			end = 1;
		buff[i] = '\0';
		if (ft_indexof(buff, '\n') >= 0)
		{
			buff[ft_indexof(buff, '\n')] = '\0';
			list.content = ft_strtrim(buff);
			if (list.content)
				r = ft_strjoin(r, list.content);
			else
				r = ft_strjoin(buff, r);
			stop = 0;
		}
		else
			r = ft_strjoin(r, buff);
	}
	line[0] = ft_strdup(r);
	free(r);
	return ((end) ? 1 : 0);
}
