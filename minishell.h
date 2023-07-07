/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:48:47 by kyacini           #+#    #+#             */
/*   Updated: 2023/07/07 21:54:01 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"


typedef struct s_heredoc
{
	char	*filename;
	char	*file;
}	t_heredoc;

typedef struct s_commande{
	char *cmd;
	char		**cmds_split;
	int			id;
	t_heredoc	*hd;
	struct s_commande	*next;
}	t_commande;

typedef struct s_partition
{
	t_commande	*cmds;
	int			pid;
	struct s_partition	*next;
} t_partition;

t_list *initialized_env(char **env);

#endif