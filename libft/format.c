/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:22:33 by jongmlee          #+#    #+#             */
/*   Updated: 2023/10/23 14:35:12 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format_s(t_data *data)
{
	char	*val;
	char	*out_null;

	val = va_arg(data->ap, char *);
	if (val == NULL)
	{
		out_null = OUT_NULL;
		while (*out_null != '\0')
		{
			if (insert_buffer(data, *(out_null++)) == -1)
				return (-1);
		}
		return (1);
	}
	while (*val != '\0')
	{
		if (insert_buffer(data, *(val++)) == -1)
			return (-1);
	}
	return (1);
}

int	format_p(t_data *data, int hex_flag)
{
	unsigned long	val;

	val = (unsigned long)va_arg(data->ap, void *);
	if (insert_buffer(data, '0') == -1)
		return (-1);
	if (insert_buffer(data, 'x') == -1)
		return (-1);
	if (ultohex(data, val, hex_flag) == -1)
		return (-1);
	return (1);
}

int	format_d(t_data *data)
{
	int	val;

	val = va_arg(data->ap, int);
	if (itos(data, val) == -1)
		return (-1);
	return (1);
}

int	format_x(t_data *data, int hex_flag)
{
	unsigned int	val;

	val = va_arg(data->ap, unsigned int);
	if (ultohex(data, val, hex_flag) == -1)
		return (-1);
	return (1);
}

int	format_u(t_data *data)
{
	unsigned int	val;

	val = va_arg(data->ap, unsigned int);
	if (itos(data, val) == -1)
		return (-1);
	return (1);
}
