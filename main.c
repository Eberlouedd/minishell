/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:42:35 by kyacini           #+#    #+#             */
/*   Updated: 2023/07/07 19:36:00 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	afflist(t_list *var_env)
{
	while (var_env)
	{

		printf("%s\n", (char *)var_env->content);
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
	afflist(var_env);
	while (1)
	{
		commande = readline("minishell> ");
		if (!commande)
			break ;
	}
	ft_lstclear(&var_env, free);
	return (0);
}
