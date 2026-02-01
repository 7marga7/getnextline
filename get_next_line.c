/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 00:43:23 by smargaro          #+#    #+#             */
/*   Updated: 2026/01/27 11:35:02 by smargaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	salvataggio(char **memory, char *temp, ssize_t fine_lettura)
{
	char	*provvisorio;

	temp[fine_lettura] = '\0';
	if (!*memory)
		*memory = (char *)ft_calloc(1, 1);
	provvisorio = ft_strjoin(*memory, temp);
	free (*memory);
	*memory = provvisorio;
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		return (ft_calloc (1, 1));
	}
	i = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	p = (char *)ft_calloc(len + 1, sizeof(char));
	if (p == NULL)
		return (NULL);
	while (i < len && s[start + i])
	{
		p[i] = s[start + i];
		i++;
	}
	return (p);
}

char	*estrazione_aggio(char **memory)
{
	int		i;
	char	*r;
	char	*temp;

	i = 0;
	if (!memory || !*memory)
		return (NULL);
	while ((*memory)[i] != '\0' && ((*memory)[i] != '\n'))
		i++;
	if ((*memory)[i] == '\n')
		r = ft_substr(*memory, 0, i + 1);
	else
		r = ft_substr(*memory, 0, i);
	if (!r)
		return (NULL);
	temp = ft_substr (*memory, ft_strlen(r), ft_strlen(*memory) - ft_strlen(r));
	if (*memory)
		free (*memory);
	*memory = temp;
	if (ft_strlen(*memory) == 0)
	{
		free (*memory);
		*memory = NULL;
	}
	return (r);
}

char	*get_next_line(int fd)
{
	char			temp[BUFFER_SIZE + 1];
	ssize_t			fine_lettura;
	static char		*memory;
	char			*r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	r = NULL;
	fine_lettura = read(fd, temp, BUFFER_SIZE);
	while (fine_lettura > 0)
	{
		salvataggio(&memory, temp, fine_lettura);
		if (memory && ft_strchr (memory, '\n'))
			break ;
		fine_lettura = read(fd, temp, BUFFER_SIZE);
	}
	if (fine_lettura < 0)
	{
		free (memory);
		memory = NULL;
	}
	r = estrazione_aggio (&memory);
	if (r && *r)
		return (r);
	return (NULL);
}

/*int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	if (fd < 0)
		return (1);

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}

	close(fd);
	return (0);
}*/

/*int	main(void)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		printf("LINEA: %s", line);
		free(line);
	}
	return (0);
}*/
