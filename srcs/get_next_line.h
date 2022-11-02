/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:36:22 by lcalvie           #+#    #+#             */
/*   Updated: 2021/11/30 01:37:48 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

char	*ft_strndup(char *src, int size);
char	*ft_concat(char *s1, char *s2);
int		ft_strlen(const char *s);
char	*get_next_line(int fd);

#endif
