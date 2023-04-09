/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbaba <ahbaba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 20:22:09 by ahbaba            #+#    #+#             */
/*   Updated: 2023/04/09 01:12:57 by ahbaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include<stdlib.h>
# include<stdio.h>
# include<unistd.h>

char		*ft_strnstr( char *haystack, char *needle, size_t len);
char		**ft_split( char *s, char c);
char		*ft_substr( char *s, unsigned int start, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(char *s);
int			ft_strncmp( char *s1, char *s2, size_t n);
#endif
