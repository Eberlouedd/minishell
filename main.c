/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:42:35 by kyacini           #+#    #+#             */
/*   Updated: 2023/07/07 16:48:51 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int afflist(t_list *var_env)
{
	while (var_env)
	{

		printf("%s\n", (char *)var_env->content);
		var_env = var_env->next;
	}
	
}

int	main(int argc, char **argv, char **env)
{
	char *commande;
	t_list *var_env;
	int i;

	c = 0;
	while ()
	{
		/* code */
	}
	
	var_env = ft_lstnew(ft_substr(env[i], ));
	while (env[i])
	{
		ft_lstadd_back(&var_env, ft_lstnew(env[i]));
		i++;
	}
	afflist(var_env);
	while (1)
	{
		commande = readline("minishell> ");
		if (!commande)
			break ;
	}
	return (0);
}
