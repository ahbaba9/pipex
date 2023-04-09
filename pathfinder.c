/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbaba <ahbaba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:50:55 by ahbaba            #+#    #+#             */
/*   Updated: 2023/04/07 20:25:05 by ahbaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **env)
{
	char	**path;

	while (*env)
	{
		if (!ft_strncmp("PATH", *env, 4))
		{
			path = ft_split(*env + 5, ':');
			return (path);
		}
		env++;
	}
	return (NULL);
}

int	test(char **envp, char *s, char **p)
{
	free_string(p);
	if (!envp)
	{
		free(s);
		return (1);
	}
	return (0);
}

char	*check_command(char	**envp, char *command)
{
	int		i;
	char	**p;
	char	*z;
	char	*s;

	i = 0;
	p = ft_split(command, ' ');
	if (!access(p[0], X_OK))
		return (p[0]);
	s = ft_strjoin ("/", p[0]);
	if (test(envp, s, p) == 1)
		return (NULL);
	while (envp[i])
	{
		z = ft_strjoin(envp[i], s);
		if (access(z, X_OK) == 0)
		{
			free(s);
			return (z);
		}
		free(z);
		i++;
	}
	free(s);
	return (NULL);
}
