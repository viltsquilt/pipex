/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:17:05 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/24 16:12:57 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_open(char **av, int index)
{
	int	fd;

	if (index == 0)
		fd = open(av[1], O_RDONLY);
	else
		fd = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (fd);
}

//    int execve(const char *pathname, char *const argv[], char *const envp[]);
int	child_process(char **argv, char **envp, int *fds, int index)
{
	t_pipex	pipex;
	int		file[2];
	pid_t	child;
	int		i;

	i = 0;
	pipex.mycmdargs = ft_parse_args(argv[index + 1 * 2]);
	pipex.mypaths = ft_parse_cmds(envp);
	file[0] = ft_open(argv, index);
	if (!file[0])
		exit(-1);
	file[1] = ft_open(argv, index);
	if (!file[1])
	{
		close(file[0]);
		exit(-1);
	}
	child = fork();
	if (child == -1)
		return (perror("fork"), -1);
	close(fds[index]);
	if (index == 0)
	{
		dup2(file[1], STDIN_FILENO);
		dup2(fds[0], STDOUT_FILENO);
		close(fds[0]);
		close(file[0]);
		pipex.cmd = argv[2];
		while (pipex.mypaths[i])
		{
			pipex.cmd = ft_join(pipex.mypaths[i], pipex.mycmdargs[0]);
			if (access(pipex.cmd, X_OK) == 0)
				break;
			i++;
		}
		execve(pipex.cmd, pipex.mycmdargs, envp);
	}
	else
	{
		dup2(fds[1], STDIN_FILENO);
		dup2(file[0], STDOUT_FILENO);
		close(fds[1]);
		close(file[1]);
		pipex.cmd = argv[3];
		while (pipex.mypaths[i])
		{
			pipex.cmd = ft_join(pipex.mypaths[i], pipex.mycmdargs[0]);
			if (access(pipex.cmd, X_OK) == 0)
				break;
			i++;
		}
		execve(pipex.cmd, pipex.mycmdargs, envp);
	}
	return (child);
}

int main(int argc, char **argv, char **envp)
{
	pid_t	child[2];
	int		pipes[2];
	int		status;

	if (argc != 5)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (pipe(pipes) == -1)
		return (perror("pipe"), -1);
	child[0] = child_process(argv, envp, pipes, 0);
	child[1] = child_process(argv, envp, pipes, 1);
	close(pipes[0]);
	close(pipes[1]);
	waitpid(child[0], &status, 0);
	waitpid(child[1], &status, 0);
	if (WIFEXITED(status))
		return (WIFEXITED(status));
	return (1);
}
