/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkono <hkono@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 23:26:50 by hkono             #+#    #+#             */
/*   Updated: 2020/12/18 01:31:41 by hkono            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	char	*str;
	char	cc;

	str = s;
	cc = (char)c;
	while (*str)
	{
		if (*str == cc)
			return (str);
		str++;
	}
	if (cc == '\0')
		return (str);
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_i;
	size_t	subs_i;

	if (s == NULL)
		return (0);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	s_i = 0;
	subs_i = 0;
	while (subs_i < len && s[s_i] != '\0')
	{
		if (s_i >= start)
		{
			substr[subs_i] = s[s_i];
			subs_i++;
		}
		s_i++;
	}
	substr[subs_i] = '\0';
	return (substr);
}

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1_len;
	int		s2_len;
	int		i;
	int		j;
	char	*str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(char *s1)
{
	char	*dst;
	size_t	dstsize;
	size_t	i;

	dstsize = ft_strlen(s1);
	if (!(dst = (char *)malloc(sizeof(char) * (dstsize + 1))))
		return (NULL);
	i = 0;
	while (i < dstsize && s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
