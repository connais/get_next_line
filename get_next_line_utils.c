/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:53:42 by avaures           #+#    #+#             */
/*   Updated: 2021/12/14 17:14:02 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int ft_strline(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(const char *str, char c)
{
	int	i;

	i = 0;
		if (!str)
			return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlcpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	if (size > 0)
	{
		while (size - 1 > i && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	if (!s2)
		return (s1);
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	if (s1)
	{
		ft_strlcpy(res, s1, ft_strlen(s1) + 1);
		ft_strlcpy(&res[ft_strlen(s1)], s2, ft_strlen(s2) + 1);
	}
	else
		ft_strlcpy(res, s2, ft_strlen(s2) + 1);
	free(s1);
	return (res);
}
char *ft_found(char *str)
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
char *ft_newstr(char *str)
{
	int i;
	char *res;
	int taille;

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
