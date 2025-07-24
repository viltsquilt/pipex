/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:26:28 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/24 13:17:43 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*
void	ft_pipex(t_pipex pipex, char **argv, char **envp)
{
	pid_t	child1;
	pid_t	child2;
	int		status;

	if (pipe(pipex.end) == -1)
		return (perror("pipe"));
	child1 = fork();
	child2 = fork();
	if (child1 == -1)
		return (perror("fork"));
	if (child1 == 0)
		child1_process(pipex, argv[2], argv, envp);
	if (child2 == -1)
		return (perror("child"));
	if (child2 == 0)
		child2_process(pipex, argv[3], argv, envp);
	close(pipex.end[0]);
	close(pipex.end[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

void	child1_process(t_pipex pipex, char *cmd, char **argv, char **envp)
{
	close(pipex.end[1]);
	dup2(pipex.fd[0], STDIN_FILENO);//end[0] to be execve input
	dup2(pipex.fd[1], STDOUT_FILENO);
	close(pipex.fd[0]);
	//execve function for each possible path
	ft_parse_cmds(cmd, argv[2], envp);
	exit(EXIT_SUCCESS);
}

void	child2_process(t_pipex pipex, char *cmd, char **argv, char **envp)
{
	close(pipex.end[0]);
	dup2(pipex.fd[1], STDOUT_FILENO);
	dup2(pipex.fd[0], STDIN_FILENO);
	close(pipex.fd[1]);
	//execve function for each possible path
	ft_parse_cmds(cmd, argv[3], envp);
}*/
