/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:30:24 by jongmlee          #+#    #+#             */
/*   Updated: 2023/10/12 14:02:54 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_tmp;
	size_t			i;

	if (s == NULL)
		return (NULL);
	i = 0;
	s_tmp = (unsigned char *) s;
	while (i < n)
	{
		if (s_tmp[i] == (unsigned char) c)
			return (s_tmp + i);
		i++;
	}
	return (NULL);
}
