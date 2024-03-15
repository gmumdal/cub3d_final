/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:28:12 by jongmlee          #+#    #+#             */
/*   Updated: 2023/11/03 18:39:13 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret_str;

	ret_str = NULL;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) - start + 1 < len)
		len = ft_strlen(s) - start;
	if (ft_strlen(s) <= start)
		return (ft_strdup(""));
	ret_str = (char *)malloc(sizeof(char) * (len + 1));
	if (ret_str == NULL)
		return (NULL);
	ft_strlcpy(ret_str, s + start, len + 1);
	return (ret_str);
}
