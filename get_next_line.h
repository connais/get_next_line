/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:54:02 by avaures           #+#    #+#             */
/*   Updated: 2021/12/15 12:00:49 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*check_get(char *str);
char	*get_next_line(int fd);
int		ft_strlcpy(char *dest, char *src, int size);
char	*ft_strjoin( char *s1, char *s2, int nb);
int		ft_strline(char *str);
char	*ft_found(char *str);
char	*ft_newstr(char *str);
int		ft_strchr(char *str, char c);
int		ft_strlen(char *str);

#endif
