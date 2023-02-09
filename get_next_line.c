/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 10:43:44 by romaurel          #+#    #+#             */
/*   Updated: 2023/02/10 00:11:43 by romaurel         ###   ########.fr       */
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

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = -1;
	if (!c)
		return (s + ft_strlen(s));
	while (s[++i])
		if (s[i] == c)
			return (s + i);
	return (NULL);
}

char	*ft_strndup(char *s, int start, int end)
{
	int		i;
	char	*cp;

	i = 0;
	cp = (char *) malloc(((end - start) + 1) * sizeof(char));
	if (!cp)
		return(NULL);
	while (start < end)
		cp[i++] = s[start++];
	cp[i] = 0;
	return (cp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*nx;
	int		i;
	int		len;

	if (!s1)
		return (ft_strndup(s2, 0, ft_strlen(s2)));
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

	printf("str cl : %s", str);
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
	if (!str[i] && str[i] == '\n')
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
	static char	*buffer = NULL;
	char		*line;

	if (fd == -1 || !BUFFER_SIZE || read(fd, 0, 0) < 0)
		return (0);
	buffer = reader(buffer, fd);
	if (!buffer)
		return (0);
	line = ft_cl(buffer);
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
