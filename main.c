/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyacini <kyacini@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:42:35 by kyacini           #+#    #+#             */
/*   Updated: 2023/07/03 15:42:07 by kyacini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	main(int argc, char **argv, char **env)
{
	char *commande;

	while (1)
	{
		commande = readline("minishell>");
		if (!commande)
			break ;
	}
	
	return (0);
}
