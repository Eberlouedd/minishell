/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:42:35 by kyacini           #+#    #+#             */
/*   Updated: 2023/08/25 09:02:37 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	afflistc(t_commande *var_env)
{
	while (var_env)
	{
		printf("%s\n", var_env->cmd);
		printf("%d\n", var_env->id);
		var_env = var_env->next;
	}
}

int	afflist(t_partition *var_env)
{
	while (var_env)
	{
		afflistc(var_env->cmds);
		var_env = var_env->next;
	}
}

int	main(int argc, char **argv, char **env)
{
	char	*commande;
	t_list	*var_env;
	char **path;
	
	var_env = initialized_env(env);
	path = ft_split(env[30], ':');
	while (1)
	{
		commande = readline("minishell> ");
		if (!commande)
			break ;
		add_history(commande);
		commande = first_transformation(commande, var_env);
		printf("%s\n", commande);
		// afflist(parsing(commande));
	}
	ft_lstclear(&var_env, free);
	free_double_char(path);
	return (0);
}
