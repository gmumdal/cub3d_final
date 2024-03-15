/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:33:33 by jongmlee          #+#    #+#             */
/*   Updated: 2023/10/18 13:15:34 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = 0;
	while (src[c])
		c++;
	while (src[i] && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = 0;
	return (c);
}

void	*gnl_del(char **s)
{
	free(*s);
	*s = NULL;
	return (NULL);
}

char	*ret_eof(char **backup)
{
	char	*ret;

	if (*backup == NULL)
		return (NULL);
	if (**backup == '\0')
		return (gnl_del(backup));
	ret = gnl_strdup(*backup);
	gnl_del(backup);
	return (ret);
}

char	*ret_newline(char **backup, char *nl_loc)
{
	char	*ret;
	int		ret_len;

	ret_len = nl_loc - *backup + 1;
	ret = (char *)malloc((ret_len + 1) * sizeof(char));
	if (ret == NULL)
		return (gnl_del(backup));
	gnl_strlcpy(ret, *backup, ret_len + 1);
	*backup = gnl_substr(*backup, ret_len, gnl_strlen(*backup));
	return (ret);
}

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE + 1];
	static char		*backup[OPEN_MAX];
	ssize_t			read_size;
	char			*nl_loc;

	if (fd < 0)
		return (NULL);
	nl_loc = gnl_strchr(backup[fd], '\n');
	while (!nl_loc)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size < 0)
			return (gnl_del(&backup[fd]));
		buffer[read_size] = '\0';
		if (read_size == 0)
			return (ret_eof(&backup[fd]));
		backup[fd] = gnl_strjoin(backup[fd], buffer);
		if (backup[fd] == NULL)
			return (NULL);
		nl_loc = gnl_strchr(backup[fd], '\n');
	}
	return (ret_newline(&backup[fd], nl_loc));
}
