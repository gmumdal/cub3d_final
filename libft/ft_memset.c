/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 22:01:14 by jongmlee          #+#    #+#             */
/*   Updated: 2023/10/12 14:13:54 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*temp;

	if (b == NULL)
		return (NULL);
	i = 0;
	temp = (unsigned char *) b;
	while (i < len)
	{
		*(temp + i) = (unsigned char) c;
		i++;
	}
	return (b);
}
