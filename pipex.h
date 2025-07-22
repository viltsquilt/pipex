/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:49:48 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/22 13:44:09 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>                                                               
# include <fcntl.h>                                                               
# include <unistd.h>
# include <sys/wait.h>
# include "libft/libft.h"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct	s_pipex
{
	int		end[2];
	int		f1;
	int		f2;
	char	*cmd1;
	char	*cmd2;
	char	*path;
	char	**mycmdargs;
	char	**mypaths;
}	t_pipex;

int		main(int argc, char **argv, char **envp);
int		findstart(const char *big, const char *little, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_parse_args(char **av);
int		newstrlen(char **envp, int start, char c);
char	*ft_parse_cmds(char *cmd, char **envp);
void	ft_pipex(t_pipex pipex, char **argv, char **envp);
void	child_process(int f1, char *cmd1, char **argv, char **envp);
void	parent_process(int f2, char *cmd2, char **argv, char **envp);

#endif
