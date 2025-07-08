/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:26:28 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/08 12:48:51 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 5)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else 
	{
		fd = open("example.txt", O_WRONLY | O_CREAT);
		dup2(fd, STDOUT_FILENO);
		clode(fd);
		ft_printf("Example print in example.txt\n");
	}
	return (0);
}
