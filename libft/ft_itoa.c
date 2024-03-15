/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:24:32 by jongmlee          #+#    #+#             */
/*   Updated: 2023/10/12 13:55:12 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int	cnt;

	cnt = 0;
	if (n < 0)
		cnt++;
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	int			len;
	long long	tmp_n;
	char		*ret_str;

	if (n == 0)
		return (ft_strdup("0"));
	len = get_len(n);
	tmp_n = (long long)n;
	ret_str = (char *)malloc((len + 1) * sizeof(char));
	if (ret_str == NULL)
		return (NULL);
	if (tmp_n < 0)
	{
		ret_str[0] = '-';
		tmp_n *= -1;
	}
	ret_str[len] = '\0';
	while (tmp_n != 0)
	{
		ret_str[len - 1] = (tmp_n % 10) + '0';
		tmp_n /= 10;
		len--;
	}
	return (ret_str);
}
