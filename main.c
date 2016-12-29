/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kacoulib <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 23:03:27 by kacoulib          #+#    #+#             */
/*   Updated: 2016/12/29 04:54:48 by kacoulib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "stdio.h"
#include "libft/libft.h"
#include "get_next_line.h"

int		main(int ac, char **av)
{
	char	*line;
	int		fd0;
	int		fd1;
	int		i;

	i = 0;
	line = (char *)malloc(sizeof(char *));
	if (ac == 1)
		return (0);
	fd0 = open(av[1], O_RDONLY);
	fd1 = open(av[2], O_RDONLY);
	while(i < 1)
	{
		get_next_line(fd0, &line);
	printf("%s", line);
		get_next_line(fd1, &line);
		printf("%s", line);
		i++;
	}
	return (0);
}
