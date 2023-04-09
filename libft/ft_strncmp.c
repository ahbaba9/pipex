/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbaba <ahbaba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 22:58:10 by ahbaba            #+#    #+#             */
/*   Updated: 2023/04/09 00:52:40 by ahbaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if (n == 0)
	{
		return (0);
	}
	while ((str1[i] && str2[i]) && (str1[i] == str2[i]) && i < n - 1)
	{
		i++;
	}
	return (str1[i] - str2[i]);
}
// int main()
// {
// 	printf("%d", strncmp("abcdef", "abc\xfdxx", 5));
// }