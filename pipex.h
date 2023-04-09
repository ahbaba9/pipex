/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbaba <ahbaba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:51:21 by ahbaba            #+#    #+#             */
/*   Updated: 2023/04/09 00:48:24 by ahbaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/types.h>

char	**free_string(char **strings);
void	execute_first_cmd(int *fd, char **av, char **envp);
char	**find_path(char **env);
void	execute_second_cmd(int *fd, char **av, char **envp);
char	*check_command(char	**envp, char *command);
// size_t	ft_strlen(char *s);
// char	**ft_split(char *s, char c);
// char	*ft_substr(char *s, unsigned int start, size_t len);
// int		ft_strncmp(char *s1, char *s2, size_t n);
// void	*ft_calloc(size_t count, size_t size);
// char	*ft_strjoin(char *s1, char *s2);
void	ft_free(char **split);
// char	*ft_strnstr(char *haystack, char *needle, size_t len);
// void	ft_bzero(void *s, size_t n);
void	ft_errors(int i);
#endif
