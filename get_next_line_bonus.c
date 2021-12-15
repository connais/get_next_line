/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:22:03 by avaures           #+#    #+#             */
/*   Updated: 2021/12/15 11:53:18 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*ft_found(char *str)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = ft_strline(str);
	res = malloc(sizeof(char) * (len + 2));
	if (!res)
		return (NULL);
	while (str[i] != '\n' && str[i])
	{
		res[i] = str[i];
		i++;
	}
	if (ft_strlen(str) != ft_strline(str))
	{
		res[i] = '\n';
		res[i + 1] = '\0';
	}
	else
		res[i] = '\0';
	return (res);
}

char	*ft_newstr(char *str)
{
	int		i;
	char	*res;
	int		taille;

	taille = ft_strline(str) + 1;
	res = malloc(sizeof(char) * (ft_strlen(str) - taille + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[taille])
	{
		res[i] = str[taille];
		i++;
		taille++;
	}
	res[i] = '\0';
	free(str);
	return (res);
}

char	*check_get(char *str)
{
	free(str);
	str = NULL;
	return (str);
}

char	*get_next_line(int fd)
{
	int			nb;
	char		buffer[BUFFER_SIZE + 1];
	char static	*str[1024];
	char		*res;

	nb = 1;
	while (!ft_strchr(str[fd], '\n') && nb > 0)
	{
		nb = read(fd, buffer, BUFFER_SIZE);
		if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1 || nb == -1)
			return (NULL);
		str[fd] = ft_strjoin(str[fd], buffer, nb);
	}
	if (ft_strlen(str[fd]) == 0 || (nb == 0 && !str[fd]))
		return (str[fd] = check_get(str[fd]));
	if (nb == 0 && str[fd])
	{
		res = ft_found(str[fd]);
		free(str[fd]);
		str[fd] = NULL;
		return (res);
	}
	res = ft_found(str[fd]);
	str[fd] = ft_newstr(str[fd]);
	return (res);
}
