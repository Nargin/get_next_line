/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 10:43:44 by romaurel          #+#    #+#             */
/*   Updated: 2023/02/04 17:11:56 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_line(char *af)
{
	char	*line;
	size_t	lenght;

	while (af[lenght] != '\n')
		lenght++;
	line = malloc((lenght + 1) * sizeof(char *));
	lenght = 0;
	line[lenght]
}

char	*get_next_line(int fd)
{
	static char	buff[1024];
	int	size;

	size = read(fd, buff, 1023);
	
}

int	main(void)
{
	int	fd = open("text.txt", O_RDONLY);

	if (!fd)
		return (0);
	get_next_line(fd);
	return (0);
}
