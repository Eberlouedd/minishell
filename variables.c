/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:59:08 by kyacini           #+#    #+#             */
/*   Updated: 2023/08/28 22:30:12 by kyacini          ###   ########.fr       */
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

void variable(char *str, int *i, char **new)
{
	int c;

	c = 1;
	if (!str[*i + c])
		return ;
	if  (str[*i + c] == '$')
	{
		*new = ft_strjoin(*new, "$ ");
		*i = *i + 1;
	}
	else
	{
		while(str[*i + c] && (ft_isalpha(str[*i + c]) || str[*i + c] == '_'))
		{
			*new = ft_strjoin(*new, char_to_string(str[*i + c]));
			c++;
		}
		*new = ft_strjoin(*new, " ");
	}
}

int kind_of_quote(char *str, int j)
{
	int *tab;

	tab = create_quote_rep(str);
	if (tab[j] == 0)
	{
		while (j < ft_strlen(str))
		{
			if(tab[j] == 2 || tab[j] == 3)
				return tab[j];
			j++;
		}
	}
	free(tab);
	return (0);
}

char **stock_variables(char *str)
{
	int *tab;
	char *string;
	int i;
	char **variables;

	string = NULL;
	variables = NULL;
	i = 0;
	while (str[i])
	{
		if(str[i] == '$' && kind_of_quote(str, i) != 2)
			variable(str, &i, &string);
		i++;
	}
	if (string)
		variables = ft_split(string, ' ');
	return (variables);
}

int count_char(char **vars, t_list *var_env)
{
	int res;
	int len_var;
	int i;
	t_list *buff;
	char *pid;

	i = 0;
	res = 0;
	len_var = 0;
	buff = var_env;
	pid = ft_itoa(getpid());

	while (vars[i])
	{
		if (!ft_strcmp(vars[i], "$"))
			res += ft_strlen(pid);
		else
		{
			while(var_env)
			{
				if(!ft_strcmp(vars[i],var_env->name))
					res += ft_strlen(var_env->content);
				var_env = var_env->next;
			}
		}
		var_env = buff;
		len_var += ft_strlen(vars[i]) + 1;
		i++;
	}
	free(pid);
	return res - len_var;
}

void replace_content(char *var, t_list *var_env, char *new, int *i)
{
	int c;
	char *pid;

	c = 0;
	pid = ft_itoa(getpid());
	if (!ft_strcmp(var, "$"))
	{
		while(pid[c])
		{
			new[*i + c] = pid[c];
			c++;
		}
		*i = *i + c - 1;
		return ;
	}
	while(var_env)
	{
		if(!ft_strcmp(var,var_env->name))
		{
			while(var_env->content[c])
			{
				new[*i + c] = var_env->content[c];
				c++;
			}
			break;
		}
		var_env = var_env->next;
	}
	*i = *i + c - 1;
	free(pid);
}


char *illuminate_variables(char *str, t_list *var_env, char **vars)
{
	char *new;
	int i;
	int j;
	int c;

	j = 0;
	i = 0;
	c = 0;
	if(!vars)
		return(ft_strdup(str));
	new = malloc(ft_strlen(str) + count_char(vars, var_env) + 1);
	new[ft_strlen(str) + count_char(vars, var_env)] = '\0';
	while (i < ft_strlen(str) + count_char(vars, var_env))
	{
		if(str[j] == '$' && kind_of_quote(str, j) != 2 && vars[c])
		{
			replace_content(vars[c], var_env, new, &i);
			j += ft_strlen(vars[c]) + 1;
			c++;
		}
		else
		{
			new[i] = str[j];
			j++;
		}
		i++;
	}
	free(str);
	return (ft_strdup(new));
}

void free_parsing(t_partition **partition)
{
	t_partition *buff;
	t_commande *buff_cmd;

	while ((*partition))
	{
		buff = (*partition)->next;
		while((*partition)->cmds)
		{
			buff_cmd = (*partition)->cmds->next;
			free((*partition)->cmds->cmd);
			if((*partition)->cmds->cmds_split)
				free_double_char((*partition)->cmds->cmds_split);
			free((*partition)->cmds);
			(*partition)->cmds = buff_cmd;
		}
		(*partition)->cmds = NULL;
		free(*partition);
		(*partition) = buff;
	}
	(*partition) = NULL;
}