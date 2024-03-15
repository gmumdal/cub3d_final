/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:09:45 by jongmlee          #+#    #+#             */
/*   Updated: 2023/10/12 14:33:22 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char *haystack, const char *needle)
{
	size_t	i;

	i = 0;
	while (needle[i] != '\0')
	{
		if (haystack[i] != needle[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*haystack_tmp;

	if (haystack == NULL || needle == NULL)
		return (NULL);
	i = 0;
	haystack_tmp = (char *) haystack;
	if (*needle == '\0')
		return (haystack_tmp);
	while (*haystack_tmp != '\0' && i + ft_strlen(needle) <= len)
	{
		if (*haystack_tmp == *needle)
		{
			if (check(haystack_tmp, needle) == 1)
				return (haystack_tmp);
		}
		haystack_tmp++;
		i++;
	}
	return (NULL);
}
