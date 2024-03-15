/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:46:25 by jongmlee          #+#    #+#             */
/*   Updated: 2023/10/11 16:49:00 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret_str;
	size_t	i;
	size_t	l;
	size_t	r;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	i = 0;
	l = 0;
	r = ft_strlen(s1);
	while (s1[l] != '\0' && ft_strchr(set, s1[l]) != NULL)
		l++;
	while (r > 0 && ft_strchr(set, s1[r]) != NULL)
		r--;
	if (l > r)
		return (ft_strdup(""));
	ret_str = ft_substr(s1, l, r - l + 1);
	return (ret_str);
}
