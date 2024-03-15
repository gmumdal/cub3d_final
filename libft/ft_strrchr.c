/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:01:46 by jongmlee          #+#    #+#             */
/*   Updated: 2023/10/12 14:33:44 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*start;
	char	*s_tmp;

	if (s == NULL)
		return (NULL);
	s_tmp = (char *) s;
	start = s_tmp;
	start--;
	while (*s_tmp != '\0')
		s_tmp++;
	while (s_tmp != start)
	{
		if (*s_tmp == (char) c)
			return (s_tmp);
		s_tmp--;
	}
	return (NULL);
}
