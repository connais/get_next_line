/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:22:30 by avaures           #+#    #+#             */
/*   Updated: 2021/12/15 12:02:35 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
