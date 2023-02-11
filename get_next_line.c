/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 10:43:44 by romaurel          #+#    #+#             */
/*   Updated: 2023/02/10 13:09:17 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*nx;
	int		i;
	int		len;

	if (!s1)
	{
		free(s1);
		return (ft_strndup(s2, 0, ft_strlen(s2)));
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	nx = malloc(sizeof(char) * (len + 1));
	if (!nx)
		return (0);
	i = 0;
	len = 0;
	while (s1[i])
		nx[len++] = s1[i++];
	i = 0;
	while (s2[i])
		nx[len++] = s2[i++];
	nx[len] = 0;
	free(s1);
	return (nx);
}

char	*reader(char *buffer, int fd)
{
	char	*str;
	int		rfl;

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (0);
	rfl = 1;
	while (rfl && !ft_strchr(str, '\n'))
	{
		rfl = read(fd, str, BUFFER_SIZE);
		if (!str)
		{
			free(str);
			return (0);
		}
		str[rfl] = 0;
		buffer = ft_strjoin(buffer, str);
	}
	free(str);
	return (buffer);
}

char	*ft_cl(char *str)
{
	char	*nx;
	int		i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	nx = malloc((i + 2) * sizeof(char));
	if (!nx)
		return (0);
	i = -1;
	while (str[++i] && str[i] != '\n')
		nx[i] = str[i];
	if (str[i] == '\n' && str[i])
		nx[i++] = '\n';
	nx[i] = 0;
	return (nx);
}

char	*ft_nl(char *str)
{
	char	*nx;
	int		i;
	int		u;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (0);
	}
	nx = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!nx)
		return (0);
	u = 0;
	while (str[++i])
		nx[u++] = str[i];
	nx[u] = 0;
	free(str);
	return (nx);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd == -1 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (0);
	buffer = reader(buffer, fd);
	if (!buffer)
		return (NULL);
	line = ft_cl(buffer);
	buffer = ft_nl(buffer);
	return (line);
}
/*
int	main(void)
{
	int fd = open("empty.txt", O_RDONLY);

	// printf("0 : %s", get_next_line(fd));
	// printf("1 : %s", get_next_line(fd));
	// printf("2 : %s", get_next_line(fd));
	// printf("3 : %s", get_next_line(fd));
	// printf("4 : %s", get_next_line(fd));
	for (int i = 0; i < 1; i++)
		printf("%s", get_next_line(fd));
		// get_next_line(fd);
	return (0);
}*/
