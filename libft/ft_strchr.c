/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:54:18 by jongmlee          #+#    #+#             */
/*   Updated: 2023/10/12 14:23:02 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_tmp;

	if (s == NULL)
		return (NULL);
	s_tmp = (char *) s;
	while (*s_tmp != '\0')
	{
		if (*s_tmp == (unsigned char) c)
			return (s_tmp);
		s_tmp++;
	}
	if ((unsigned char) c == '\0')
		return (s_tmp);
	return (NULL);
}
