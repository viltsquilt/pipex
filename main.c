/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:17:05 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/30 11:12:03 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_open(char **av, int index)
{
	int	fd;

	if (index == 0)
		fd = open(av[1], O_RDONLY);
	else
		fd = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	return (fd);
}

static void	handle_files(t_pipex pipex, char **argv, int index)
{
	if (index == 0)
	{
		dup2(pipex.file[0], STDIN_FILENO);
		dup2(pipex.pipes[1], STDOUT_FILENO);
		close(pipex.file[0]);
		close(pipex.pipes[1]);
		pipex.cmd = argv[2];
	}
	else
	{
		dup2(pipex.pipes[0], STDIN_FILENO);
		dup2(pipex.file[1], STDOUT_FILENO);
		close(pipex.pipes[0]);
		close(pipex.file[1]);
		pipex.cmd = argv[3];
	}
}

static void	run_child(char **argv, char **envp, t_pipex pipex, int index)
{
	int	i;

	i = 0;
	pipex.mycmdargs = ft_parse_args(argv[index + 1 * 2]);
	pipex.mypaths = ft_parse_cmds(envp);
	close(pipex.pipes[index]);
	handle_files(pipex, argv, index);
	if (pipex.mypaths)
	{
		while (pipex.mypaths[i])
		{
			pipex.cmd = ft_join(pipex.mypaths[i], pipex.mycmdargs[0]);
			if (access(pipex.cmd, X_OK) == 0)
				break ;
			free(pipex.cmd);
			i++;
		}
		execve(pipex.cmd, pipex.mycmdargs, envp);
		free(pipex.cmd);
		ft_free(pipex.mypaths);
	}
	ft_free(pipex.mycmdargs);
}

int	child_process(char **argv, char **envp, t_pipex pipex, int index)
{
	pid_t	child;

	child = fork();
	if (child == -1)
		return (perror("fork"), -1);
	if (child == 0)
	{
		pipex.file[index] = ft_open(argv, index);
		if (!pipex.file[index])
			exit(-1);
		run_child(argv, envp, pipex, index);
	}
	return (child);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	child[2];
	t_pipex	pipex;
	int		status;

	status = 0;
	if (argc != 5)
	{
		write(2, "Required input: < file1 cmd1 | cmd2 > file2\n", 44);
		return (1);
	}
	if (pipe(pipex.pipes) == -1)
		return (perror("pipe"), -1);
	child[0] = child_process(argv, envp, pipex, 0);
	child[1] = child_process(argv, envp, pipex, 1);
	close(pipex.pipes[0]);
	close(pipex.pipes[1]);
	waitpid(child[0], &status, 0);
	waitpid(child[1], &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
