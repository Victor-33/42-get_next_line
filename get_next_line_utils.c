/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-brit <vde-brit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 18:00:12 by vde-brit          #+#    #+#             */
/*   Updated: 2022/08/10 20:19:22 by vde-brit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	needs_null(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		return (1);
	return (0);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	s_len;
	char			*ptr_s;
	size_t			i;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if (((s_len - start) > len) && (start < s_len))
		ptr_s = malloc((len * sizeof(char) + 1));
	else if (start > s_len)
		ptr_s = malloc(sizeof(char));
	else
		ptr_s = malloc(((s_len - start) * sizeof(char) + 1));
	if (!ptr_s)
		return (NULL);
	if (start < s_len)
	{
		while (s[start] != '\0' && i < len)
			ptr_s[i++] = s[start++];
	}
	ptr_s[i] = '\0';
	return (ptr_s);
}

char	*ft_strchr(const char *s, int c)
{
	char	*aux;
	int		i;

	if (!s || !c)
		return (NULL);
	i = 0;
	aux = (char *)s;
	while (aux[i])
	{
		if (aux[i] == (char)c)
			return (&aux[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	j;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	ptr = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		ptr[i] = s1[i];
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}
