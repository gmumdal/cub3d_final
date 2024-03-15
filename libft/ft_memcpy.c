/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:45:33 by jongmlee          #+#    #+#             */
/*   Updated: 2023/11/01 19:09:10 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst_tmp;
	unsigned char	*src_tmp;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	dst_tmp = (unsigned char *) dst;
	src_tmp = (unsigned char *) src;
	while (i < n)
	{
		*(dst_tmp + i) = *(src_tmp + i);
		i++;
	}
	return (dst);
}
