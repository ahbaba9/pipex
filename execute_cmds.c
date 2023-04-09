/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbaba <ahbaba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:28:42 by ahbaba            #+#    #+#             */
/*   Updated: 2023/04/09 00:57:54 by ahbaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_errors(int i)
{
	if (i == 0)
	{
		write (2, "no such file or directory\n", 27);
		exit(1);
	}
	else if (i == 1)
	{
		write(2, "command not found\n", 19);
		exit (1);
	}
	else if (i == 2)
	{
		write(2, "error to open the pipe", 23);
		exit(1);
	}
	else if (i == 3)
	{
		write(2, "Failed to fork the child", 25);
		exit(1);
	}
}

void	execute_first_cmd(int *fd, char **av, char **envp)
{
	int		infile;
	char	**split;
	char	**s;
	char	*l;

	infile = open(av[1], O_RDONLY, 0644);
	if (infile == -1)
		ft_errors(0);
	close(fd[0]);
	split = ft_split(av[2], ' ');
	dup2(infile, 0);
	dup2(fd[1], 1);
	close(infile);
	close(fd[1]);
	s = find_path(envp);
	l = check_command(s, av[2]);
	if (!l)
		ft_errors(1);
	execve(l, &split[0], envp);
	ft_free(split);
	write(2, "error first child\n", 19);
	close(fd[0]);
	close(fd[1]);
	exit(1);
}

void	execute_second_cmd(int *fd, char **av, char **envp)
{
	int		outfile;
	char	**split;
	char	**s;
	char	*l;

	outfile = open(av[4], O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (outfile == -1)
		ft_errors(0);
	close(fd[1]);
	split = ft_split(av[3], ' ');
	dup2(fd[0], 0);
	dup2(outfile, 1);
	close(outfile);
	close(fd[0]);
	s = find_path(envp);
	l = check_command(s, av[3]);
	if (!l)
		ft_errors(1);
	execve(l, &split[0], envp);
	ft_free(split);
	write(2, "error second child\n", 20);
	close(fd[0]);
	close(fd[1]);
	exit(1);
}
