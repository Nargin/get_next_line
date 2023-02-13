/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 10:43:44 by romaurel          #+#    #+#             */
/*   Updated: 2023/02/13 17:17:11 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*nx;
	int		i;
	int		len;

	if (!s1 && s2)
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
	char	str[BUFFER_SIZE + 1];
	int		rfl;

	rfl = 1;
	while (rfl && !ft_strchr(str, '\n'))
	{
		rfl = read(fd, str, BUFFER_SIZE);
		str[rfl] = 0;
		buffer = ft_strjoin(buffer, str);
	}
	return (buffer);
}

char	*ft_cl(char *str)
{
	char	*nx;
	int		i;

	if (!str)
		return ((void)free(str), (char *)NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (i == ft_strlen(str) - 1)
		nx = malloc((i + 1) * sizeof(char));
	else
		nx = malloc((i + 2) * sizeof(char));
	if (!nx)
		return ((char *)NULL);
	i = -1;
	while (str[++i] && str[i] != '\n')
		nx[i] = str[i];
	if (str[i] == '\n')
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
		return ((char *)NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), (char *)NULL);
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

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd < 0)
		return (0);
	if (!ft_strchr(buffer, '\n'))
		buffer = reader(buffer, fd);
	if (!buffer)
		buffer = NULL;
	printf("ft_cl : %s avec %s.\n", ft_cl(buffer), buffer);
	line = ft_cl(buffer);
	// printf("line before return : %d", line == NULL ? 1 : 0);
	buffer = ft_nl(buffer);
	return (line);
}

int	main(void)
{
	int fd = open("text.txt", O_RDONLY);
	char	*str;
	// int i = 0;

	if (0 == NULL)
		printf("gnl : \n");
	str = get_next_line(fd);
	while (str)
	{
		printf(" - %s", str);
		free(str);
		str = get_next_line(fd);
		// if (i++ == 5)
		// 	str = 0;
	}
	printf("%p\n", str);
	return (0);
}
