/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:59:16 by jongmlee          #+#    #+#             */
/*   Updated: 2023/10/21 16:49:17 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ultohex(t_data *data, unsigned long nb, int hex_flag)
{
	char	*base;

	if (hex_flag == HEX_LO)
		base = HEXBASE_LO;
	else
		base = HEXBASE_UP;
	if (nb < 16)
	{
		if (insert_buffer(data, base[nb]) == -1)
			return (-1);
		return (1);
	}
	if (ultohex(data, nb / 16, hex_flag) == -1)
		return (-1);
	return (insert_buffer(data, base[nb % 16]));
}

int	itos(t_data *data, long long nb)
{
	if (nb < 0)
	{
		if (insert_buffer(data, '-') == -1)
			return (-1);
		nb *= -1;
	}
	if (nb < 10)
	{
		if (insert_buffer(data, nb + '0') == -1)
			return (-1);
		return (1);
	}
	if (itos(data, nb / 10) == -1)
		return (-1);
	return (insert_buffer(data, (nb % 10) + '0'));
}
