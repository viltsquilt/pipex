/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:26:28 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/15 15:41:23 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int f1, int f2, char **argv, char **envp)
{
	int		end[2];
	pid_t	parent;

	pipe(end);
	parent = fork();
	if (parent = -1)
		return (perror("fork"));
	else if (parent = 0)
		child_process(f1, argv[2], argv, envp);
	else
		parent_process(f2, argv[3], argv, envp);
}

void	child_process(int f1, char *cmd1, char **argv, char **envp)
{
	close(f2);
	dup2(f1, STDIN_FILENO);//f1 to be execve input
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	close(f1);
	//execve function for each possible path
	exit(EXIT_SUCCESS);
	cmd = ft_parse_cmds(cmd1, envp);
	execve(cmd, ft_parse_args(argv), envp);
	if (execve = -1)
		return (perror("child"));
	free(cmd);
	return(EXIT_FAILURE);
}

void	parent_process(int f2, char *cmd2, char **argv, char **envp)
{
	int	status;

	waitpid(-1, &status, 0);
	close(f1);
	dup2(f2, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);
	close(end[1]);
	close(f2);
	//execve function for each possible path
	cmd = ft_parse_cmds(cmd2, envp);
	execve(cmd, ft_parse_args(argv), envp);
	if (execve = -1)
		return (perror("parent"));
	free(cmd);
	return (EXIT_FAILURE);
}

//NOTES

/*
main()
{
//	ft_init_pipex()

	used to fill struct with some default data so as to not cause problems with Valgrind

//	ft_check_args()

	opens all files needed and handles here_doc as well as /dev/urandom
	use dup(2)

//	ft_parse_cmds()

	this finds the correct paths using envp and store them in an array
	the array wil look like this: ["/bin/cat", "/usr/bin/head", "usr/bin/wc"]
	we parse through the entire path and split it using ft_split and the colon as the delimiter
	This way we can find the correct shell command somewhere in the path

//	ft_parse_args()

	this contains the arguments to the program
	use ft_split to yield a 2D array:
	[["cat"], ["head", "-n", "5"], ["wc", "-l"]]
	remember to NULL terminate arrays

//	while (cmds)
//		ft_exec()

		Core idea is to mimic dataflow between programs
		Pseudocode of flow:

		{
			pipe()
			fork()
			if (child)
			{
				dup(2)
				execve()
			}
			else
			{
				close()
			}
		}

//	ft_cleanup()
}
*/
