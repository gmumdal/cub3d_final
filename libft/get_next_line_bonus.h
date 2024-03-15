/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmlee <jongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:02:50 by jongmlee          #+#    #+#             */
/*   Updated: 2023/10/18 13:15:39 by jongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10211
# endif

# if BUFFER_SIZE <= 0
#  error "invalid BUFFER_SIZE"
# endif

size_t	gnl_strlen(const char *s);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strdup(const char *s1);
char	*gnl_substr(char *s, unsigned int start, size_t len);
char	*gnl_strchr(const char *s, char c);
size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize);
char	*get_next_line(int fd);
char	*ret_newline(char **backup, char *nl_loc);
char	*ret_eof(char **backup);
void	*gnl_del(char **s);

#endif