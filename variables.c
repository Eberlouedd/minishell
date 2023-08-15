/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:59:08 by kyacini           #+#    #+#             */
/*   Updated: 2023/08/15 18:52:16 by kyacini          ###   ########.fr       */
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

char *variable(char *str, int i)
{
	int c;
	static char *string = NULL;

	c = 0;
	while((ft_isalpha(str[i + c]) || str[i + c] == '_') && str[i + c])
	{
		string = ft_strjoin(string, char_to_string(str[i + c]));
		printf("%s\n", string);
		c++;
	}
	string = ft_strjoin(string, " ");
	return string;
}

char *illuminate_variables(char *str, t_list *var_env)
{
	int *tab;
	char *string;
	int i;
	char **variables;
	char *new;

	tab = create_quote_rep(str);
	i = 0;
	while (str[i])
	{
		if(str[i] == '$')
			string = variable(str, i);
		i++;
	}
	variables = ft_split(string, ' ');
	printf("%s\n", variables[0]);
	printf("%s\n", variables[1]);
	return string;
}