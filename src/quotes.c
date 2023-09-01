/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:15:21 by kyacini           #+#    #+#             */
/*   Updated: 2023/09/01 20:27:37 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	last_character(char *str)
{
	int	c;
	int	i;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			c = i;
		i++;
	}
	return (str[c]);
}

int	test_quotes(char *str)
{
	int	i;
	int	c;
	int	j;

	i = 0;
	c = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			c++;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			j++;
		i++;
	}
	if (c % 2 != 0 && j % 2 != 0)
		return (0);
	return (1);
}

void	splitable(char *str)
{
	int	i;
	int	*tab;

	i = 0;
	tab = create_quote_rep(str);
	while (str[i])
	{
		if (str[i] == ' ' && tab[i] == 0)
			str[i] = (char) 177;
		i++;
	}
	free(tab);
}

void	clean_del(char **str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		while (str[i][c])
		{
			if (str[i][c] == (char) 177)
				str[i][c] = ' ';
			c++;
		}
		c = 0;
		i++;
	}
}

char	*first_transformation(char *commande, t_list *var_env)
{
	char	*new;
	char	**vars;

	if (ft_strcmp(commande, "") == 0)
		return ("");
	if (last_character(commande) == '>'
		|| last_character(commande) == '<'
		|| !test_quotes(commande)
		|| !check_unique(commande))
	{
		printf("error\n");
		free(commande);
	}
	new = add_spaces(commande);
	vars = stock_variables(new);
	new = illuminate_variables(new, var_env, vars);
	if (vars)
		free_double_char(vars);
	splitable(new);
	return (new);
}
