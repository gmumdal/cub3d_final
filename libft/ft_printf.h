/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:09:23 by jongmlee          #+#    #+#             */
/*   Updated: 2023/11/17 15:15:36 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# define BUFFER_SIZE 256
# define OUT_NULL "(null)"
# define HEXBASE_LO "0123456789abcdef"
# define HEXBASE_UP "0123456789ABCDEF"
# define HEX_LO 0
# define HEX_UP 1

typedef struct s_data
{
	char	buffer[BUFFER_SIZE];
	int		buf_idx;
	int		len;
	va_list	ap;
}	t_data;

int		ft_printf(const char *str, ...);
int		iter_str(t_data *data, char *str);
int		format(t_data *data, char c);
int		insert_buffer(t_data *data, char c);
int		print(t_data *data);
int		itos(t_data *data, long long nb);
int		ultohex(t_data *data, unsigned long nb, int hex_flag);
int		format_u(t_data *data);
int		format_x(t_data *data, int hex_flag);
int		format_d(t_data *data);
int		format_p(t_data *data, int hex_flag);
int		format_s(t_data *data);

#endif
