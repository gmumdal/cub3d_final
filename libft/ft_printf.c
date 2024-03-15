/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:08:54 by jongmlee          #+#    #+#             */
/*   Updated: 2023/11/17 15:24:50 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print(t_data *data)
{
	if (write(1, data->buffer, data->buf_idx) == -1)
		return (-1);
	data->len += data->buf_idx;
	data->buf_idx = 0;
	return (1);
}

int	insert_buffer(t_data *data, char c)
{
	data->buffer[data->buf_idx] = c;
	data->buf_idx += 1;
	if (data->buf_idx >= BUFFER_SIZE)
	{
		if (print(data) == -1)
			return (-1);
	}
	return (1);
}

int	format(t_data *data, char c)
{
	if (c == 'c')
		return (insert_buffer(data, va_arg(data->ap, int)));
	else if (c == 's')
		return (format_s(data));
	else if (c == 'p')
		return (format_p(data, HEX_LO));
	else if (c == '%')
		return (insert_buffer(data, '%'));
	else if (c == 'd' || c == 'i')
		return (format_d(data));
	else if (c == 'x')
		return (format_x(data, HEX_LO));
	else if (c == 'X')
		return (format_x(data, HEX_UP));
	else if (c == 'u')
		return (format_u(data));
	return (1);
}

int	iter_str(t_data *data, char *str)
{
	int	buf_idx;

	buf_idx = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && *str != '%')
		{
			if (insert_buffer(data, *(str++)) == -1)
				return (-1);
		}
		if (*str != '\0')
		{
			if (format(data, *(++str)) == -1)
				return (-1);
			str++;
		}
	}
	if (print(data) == -1)
		return (-1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	t_data	data;

	data.len = 0;
	data.buf_idx = 0;
	va_start(data.ap, str);
	if (iter_str(&data, (char *)str) == -1)
		return (-1);
	va_end(data.ap);
	return (data.len);
}
