/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:59:08 by kyacini           #+#    #+#             */
/*   Updated: 2023/08/20 13:24:47 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *char_to_string(char c)
{
	char *string;

	string = malloc(2);
	string[0] = c;
	string[1] = '\0';
	return (string);
}

void variable(char *str, int i, char **new)
{
	int c;

	c = 1;
	while(str[i + c] && (ft_isalpha(str[i + c]) || str[i + c] == '_'))
	{
		*new = ft_strjoin(*new, char_to_string(str[i + c]));
		c++;
	}
	*new = ft_strjoin(*new, " ");
}

char **stock_variables(char *str)
{
	int *tab;
	char *string;
	int i;
	char **variables;

	string = NULL;
	variables = NULL;
	tab = create_quote_rep(str);
	i = 0;
	while (str[i])
	{
		if(str[i] == '$')
			variable(str, i, &string);
		i++;
	}
	if (string)
		variables = ft_split(string, ' ');
	return (variables);
}

int count_char(char **vars, t_list *var_env)
{
	int res;
	int i;
	t_list *buff;

	i = 0;
	res = 0;
	buff = var_env;
	while (vars)
	{
		while(var_env)
		{
			if(vars[i] == var_env->name)
				res += ft_strlen(var_env->content);
			var_env = var_env->next;
		}
		var_env = buff;
		i++;
	}
	return res;
}

char *illuminate_variables(char *str, t_list *var_env, char **vars)
{
	char *new;

	if(!vars)
		return(ft_strdup(str));
	while (vars)
	{

	}

}