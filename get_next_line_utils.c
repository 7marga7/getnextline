/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smargaro <smargaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 09:56:40 by smargaro          #+#    #+#             */
/*   Updated: 2026/02/01 13:14:15 by smargaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;
	char	d;

	i = 0;
	p = ((char *) s);
	d = ((char) c);
	while (s[i])
	{
		if (d == s[i])
			return (&p[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	long int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*r;
	size_t	i;

	if (!count || !size)
		return (malloc(1));
	if (size >= SIZE_MAX / count)
		return (NULL);
	r = malloc(count * size);
	if (!r)
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		((char *)r)[i] = '\0';
		i++;
	}
	return (r);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!src && !dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len1;
	size_t		len2;
	char		*ns;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ns = ft_calloc(sizeof(char), (len1 + len2 + 1));
	if (!ns)
		return (NULL);
	ft_memcpy(ns, s1, len1);
	ft_memcpy(ns + len1, s2, len2);
	return (ns);
}
