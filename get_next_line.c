/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:53:15 by avaures           #+#    #+#             */
/*   Updated: 2021/12/14 19:19:14 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
char *check_w_value(char *value, char *trash)
{
	value = ft_found(trash);
	free(trash);
	trash = NULL;
	return (value);
}
char *check_get(char *str)
{
		free(str);
		str = NULL;
		return (str);
}
char *get_next_line(int fd)
{
	int nb;
	char	buffer[BUFFER_SIZE + 1];
	char	static	*str = NULL;
	char	*res;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	nb = 1;
	while (!ft_strchr(str, '\n') && nb > 0)
	{
		nb = read(fd, buffer, BUFFER_SIZE);
		if (nb == -1)
			return (NULL);
		buffer[nb] = '\0';
		str = ft_strjoin(str, buffer);
	}
	if (ft_strlen(str) == 0 || (nb == 0 && !str))
		return (str = check_get(str));
	if (nb == 0 && str) 
	{
		res = ft_found(str);
		free(str);
		str = NULL;
		return (res);
	}
	res = ft_found(str);
	str = ft_newstr(str);
	return (res);
}
