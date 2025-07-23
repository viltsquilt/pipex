/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:17:05 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/23 15:46:40 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else
	{
		pipex.end[0] = open(argv[1], O_RDONLY);
		pipex.end[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (pipex.end[0] < 0)
			return (-1);
		if (pipex.end[1] < 0)
			{
				close(pipex.end[0]);
				return (-1);
			}
		ft_pipex(pipex, argv, envp);
	}
	return (EXIT_FAILURE);
}
