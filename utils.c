/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:19:45 by kyacini           #+#    #+#             */
/*   Updated: 2023/07/09 17:18:32 by skhali           ###   ########.fr       */
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

void	free_double_char(char	**str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void case_tab(int *tab, int *i, int type)
{
	tab[*i] = 5;
	tab[*i+1] = type;
	*i += 1;
}

int *create_type_table(char **div, int *tab)
{
	int i;

	i = 0;
	while (div[i])
	{
		if(ft_strcmp(div[i],">") == 0)
			case_tab(tab, &i, 1);
		else if(ft_strcmp(div[i],"<") == 0)
			case_tab(tab, &i, 2);
		else if(ft_strcmp(div[i],"<<") == 0)
			case_tab(tab, &i, 3);
		else if(ft_strcmp(div[i],">>") == 0)
			case_tab(tab, &i, 4);
		else
			tab[i] = WORD;
		i++;
	}
	return (tab);
}

