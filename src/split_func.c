/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:33:41 by kyacini           #+#    #+#             */
/*   Updated: 2023/09/01 20:05:44 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	fill_tab(char *str, int *quotes, char *new)
{
	int i;
	int c;

	c = 0;
	i = 0;
	while (str[i])
	{
		if (quotes[i] != 2 && quotes[i] != 3)
		{
			new[c] = str[i];
			c++;
		}
		i++;
	}
}
