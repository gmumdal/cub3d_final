/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 19:38:01 by jongmlee          #+#    #+#             */
/*   Updated: 2023/10/17 12:18:19 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*ret_str;
	int		i;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (gnl_strdup(s2));
	i = 0;
	ret_str = malloc((gnl_strlen(s1) + gnl_strlen(s2) + 1) * sizeof(char));
	if (ret_str == NULL)
		return (gnl_del(&s1));
	while (s1[i] != '\0')
	{
		ret_str[i] = s1[i];
		i++;
	}
	while (*s2 != '\0')
	{
		ret_str[i] = *s2;
		s2++;
		i++;
	}
	free(s1);
	ret_str[i] = '\0';
	return (ret_str);
}

char	*gnl_strdup(const char *s1)
{
	char	*cpy;
	int		i;

	if (s1 == NULL)
		return (NULL);
	i = 0;
	cpy = (char *)malloc(sizeof(char) * (gnl_strlen(s1) + 1));
	if (cpy == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	char	*ret_str;
	size_t	s_len;

	ret_str = NULL;
	if (s == NULL)
		return (NULL);
	s_len = gnl_strlen(s);
	if (s_len <= start)
	{
		free(s);
		return (gnl_strdup(""));
	}
	if (s_len - start + 1 < len)
		len = s_len - start;
	ret_str = (char *)malloc(sizeof(char) * (len + 2));
	if (ret_str == NULL)
	{
		free(s);
		return (NULL);
	}
	gnl_strlcpy(ret_str, s + start, len + 1);
	free(s);
	return (ret_str);
}

char	*gnl_strchr(const char *s, char c)
{
	char	*s_tmp;

	if (s == NULL)
		return (NULL);
	s_tmp = (char *) s;
	while (*s_tmp != '\0')
	{
		if (*s_tmp == c)
			return (s_tmp);
		s_tmp++;
	}
	return (NULL);
}
