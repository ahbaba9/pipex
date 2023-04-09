/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbaba <ahbaba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:12:04 by ahbaba            #+#    #+#             */
/*   Updated: 2023/04/06 08:25:47 by ahbaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (needle[0] != 0 && len == 0)
		return (0);
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i] != 0 && len >= ft_strlen(needle))
	{
		if (haystack[i] == needle[0]
			&& ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0)
			return ((char *)(haystack + i));
		i++;
		len--;
	}
	return (0);
}
