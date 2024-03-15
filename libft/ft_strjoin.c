/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:52:42 by jongmlee          #+#    #+#             */
/*   Updated: 2023/10/13 18:56:21 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret_str;
	char	*ret_tmp;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	ret_tmp = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (ret_tmp == NULL)
		return (NULL);
	ret_str = ret_tmp;
	while (*s1 != '\0')
	{
		*ret_tmp = *s1;
		ret_tmp++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*ret_tmp = *s2;
		ret_tmp++;
		s2++;
	}
	*ret_tmp = '\0';
	return (ret_str);
}
