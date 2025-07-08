/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 13:17:05 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/08 13:17:59 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv)
{
	int fd;

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
