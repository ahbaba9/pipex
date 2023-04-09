/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahbaba <ahbaba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:58:28 by ahbaba            #+#    #+#             */
/*   Updated: 2023/04/09 01:07:56 by ahbaba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	fd[2];
	int	id[2];

	if (ac != 5)
	{
		write(2, "Invalid arguments\n", 19);
		exit(1);
	}
	if (pipe(fd) == -1)
		ft_errors(2);
	id[0] = fork();
	if (id[0] == -1)
		ft_errors(3);
	if (id[0] == 0)
		execute_first_cmd(fd, av, envp);
	id[1] = fork();
	if (id[1] == -1)
		ft_errors(3);
	if (id[1] == 0)
		execute_second_cmd(fd, av, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(id[0], NULL, 0);
	waitpid(id[1], NULL, 0);
}
///qra ela processus u qra elih fmemmoire
// qra ela returns dyal kula function chnu katretni (dup2 , exc , close ......) WAITPID , PIPE, FORK, PIDS(0 CHILD,  > 0 PARENT)
// parent proc , u child procs , u zombie u orphelin procesuss
//elach kansedu des fds u elsh kihangi programme mli kankhliwhum mhlulin
// PAR DEFAUT FORK ENDHA LEAKSS DYALHA FMEMOIRE
// ACCESS  + FLAGS DYALHA