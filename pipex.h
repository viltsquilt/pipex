/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahdekiv <vahdekiv@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:49:48 by vahdekiv          #+#    #+#             */
/*   Updated: 2025/07/08 12:54:56 by vahdekiv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>                                                               
# include <fcntl.h>                                                               
# include <unistd.h>
# include "libft/libft.h"

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct	s_pipex
{
	int	in_fd;
	int	out_fd;
	t_bool	here_doc;
	t_bool	is_invalid_infile;
	char	**cmd_paths;
	char	***cmd_args;
	int		cmd_count;
}	t_pipex;

#endif
