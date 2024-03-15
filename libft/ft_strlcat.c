/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:08:28 by jongmlee          #+#    #+#             */
/*   Updated: 2023/10/12 14:30:19 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	si;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	si = 0;
	if (d_len >= dstsize)
		return (s_len + dstsize);
	while (*dst && si++ < dstsize)
		dst++;
	while (*src && si + 1 < dstsize)
	{
		*dst = *src;
		dst++;
		src++;
		si++;
	}
	*dst = '\0';
	return (d_len + s_len);
}
