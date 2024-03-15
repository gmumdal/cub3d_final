/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeongsh <hyeongsh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:22:47 by jongmlee          #+#    #+#             */
/*   Updated: 2024/01/12 21:07:33 by hyeongsh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	del(char **words, int idx)
{
	if (words[idx] == 0)
	{
		while (idx >= 0)
		{
			free(words[idx]);
			idx--;
		}
		free(words);
		return (0);
	}
	return (1);
}

static char	*make_word(const char *str, char c)
{
	size_t		i;
	size_t		len;
	char		*arr;

	len = 0;
	i = 0;
	while (str[len] != '\0' && str[len] != c)
		len++;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (NULL);
	while (i < len)
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}

static char	count_word(const char *str, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*str != '\0')
	{
		while (*str == c)
			str++;
		if (*str != '\0')
			cnt++;
		while (*str != '\0' && *str != c)
			str++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	word_cnt;
	int		i;

	i = 0;
	word_cnt = count_word(s, c);
	words = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (words == NULL)
		return (NULL);
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			words[i] = make_word(s, c);
			if (del(words, i) == 0)
				return (NULL);
			i++;
		}
		while (*s != '\0' && *s != c)
			s++;
	}
	words[i] = NULL;
	return (words);
}
