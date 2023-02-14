/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romaurel <romaurel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 10:43:44 by romaurel          #+#    #+#             */
/*   Updated: 2023/02/14 15:36:07 by romaurel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2, int ilen)
{
	char	*nx;
	int		i;
	int		len;

	if (!s1)
		return (ft_strndup(s2, ft_strlen(s2)));
	len = ft_strlen(s1);
	nx = malloc(len + ilen + 1);
	if (!nx)
		return (free(s1), (char *)NULL);
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
	while (rfl && !ft_strchr(buffer, '\n'))
	{
		rfl = read(fd, str, BUFFER_SIZE);
		str[rfl] = 0;
		buffer = ft_strjoin(buffer, str, BUFFER_SIZE);
	}
	return (buffer);
}

char	*ft_cl(char **buffer)
{
	char	*nx;
	char	*temp;
	int		i;
	int		u;

	if (!*buffer)
		return (NULL);
	i = 0;
	temp = *buffer;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		i++;
	nx  = malloc((i + 1) * sizeof(char));
	if (!nx)
		return (NULL);
	u = -1;
	while (temp[++u] != '\n' && temp[u])
		nx[u] = temp[u];
	if (temp[u] == '\n')
		nx[u++] = '\n';
	*buffer = ft_strndup(temp + i, ft_strlen(temp + i));
	free(temp);
	nx[u] = 0;
	return (nx);
}

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || fd < 0)
		return (0);
	if (!ft_strchr(buffer, '\n'))
		buffer = reader(buffer, fd);
	if (!buffer)
		buffer = NULL;
	return (ft_cl(&buffer));
}

int	main(void)
{
	int fd = open("read_error.txt", O_RDONLY);
	char	*str;

	if (0 == NULL)
		printf("gnl : \n");
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	printf("%p\n", str);
	return (0);
}
