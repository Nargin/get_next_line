/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 10:43:44 by romaurel          #+#    #+#             */
/*   Updated: 2023/02/09 17:41:37 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*nx;
	int		i;
	int		len;

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

	if (!buffer)
		buffer = ft_calloc(1, 1);
	str = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!str)
		return (0);
	rfl = 1;
	while (rfl)
	{
		rfl = read(fd, str, BUFFER_SIZE); 
		if (str)
		{
			str[rfl] = 0;
			buffer = ft_strjoin(buffer, str);
		}
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
	nx = ft_calloc(sizeof(char), i + 2);
	if (!nx)
		return (0);
	i = -1;
	while (str[++i] && str[i] != '\n')
		nx[i] = str[i];
	if (!str[i] || str[i] == '\n')
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
	nx = ft_calloc(sizeof(char), ft_strlen(str) - i + 1);
	if (!nx)
		return (0);
	u = 0;
	while (str[++i])
		nx[u++] = str[i];
	nx[u] = 0;
	free(str);
	return (nx);
}

void	 *ft_calloc(int n, int s)
{
	int	i;
	void	*p;
	char	*sdf;

	if (!n || !s)
		return (ft_calloc(1, 1));
	i = n * s;
	p = malloc(n * s);
	sdf = (char *) p;
	if (p)
		while (i--)
			*sdf++ = 0;
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd == -1 || !BUFFER_SIZE || read(fd, 0, 0) < 0)
		return (0);
	if (!buffer)
		buffer = reader(buffer, fd);
	if (!buffer)
		return (0);
	line = ft_cl(buffer);
	printf("%s\n", line);
	if (!line)
		return (0);
	buffer = ft_nl(buffer);
	return (line);
}

int	main(void)
{
	int fd = open("text.txt", O_RDONLY);

	printf("0 : %s", get_next_line(fd));
	printf("1 : %s", get_next_line(fd));
	printf("2 : %s", get_next_line(fd));
	printf("3 : %s", get_next_line(fd));
	printf("4 : %s", get_next_line(fd));
	return (0);
}
