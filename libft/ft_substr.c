/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbaba <ahbaba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:02:56 by ahbaba            #+#    #+#             */
/*   Updated: 2023/04/09 01:01:32 by ahbaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*r;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s) || len == 0)
	{
		r = (char *)ft_calloc(1, 1);
		return (r);
	}
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start ;
	r = (char *)malloc(sizeof(char) * len + 1);
	if (r == NULL)
		return (NULL);
	i = 0;
	while (s[start] && i < len)
	{
		r[i] = s[start];
		start++;
		i++;
	}
	r[i] = '\0';
	return (r);
}

// #include <stdio.h>

// int main()
// {
//     printf("%s\n", ft_substr(0, 9, 0));
// }
