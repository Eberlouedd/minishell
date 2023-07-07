/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:19:45 by kyacini           #+#    #+#             */
/*   Updated: 2023/07/07 19:22:49 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *parsed_env_content(char *env)
{
	char *res;
	int	i;

	i = 0;
	while (env[i])
	{
		if(env[i] == '=')
			break;
		i++;
	}
	res = ft_substr(env, i + 1, 100000);
	return(res);
}

char *parsed_env_name(char *env)
{
	char *res;
	int	i;

	i = 0;
	while (env[i])
	{
		if(env[i] == '=')
			break;
		i++;
	}
	res = ft_substr(env, 0, i);
	return(res);
}

t_list *initialized_env(char **env)
{
	t_list	*res;
	int		i;
	
	i = 1;
	res = ft_lstnew(parsed_env_content(env[0]), parsed_env_name(env[0]));
	while (env[i])
	{
		ft_lstadd_back(&res, ft_lstnew(parsed_env_content(env[i]), parsed_env_name(env[i])));
		i++;
	}
	return (res);
}