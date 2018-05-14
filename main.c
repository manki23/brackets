/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 12:54:08 by manki             #+#    #+#             */
/*   Updated: 2018/05/14 14:51:27 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int ac, char *av[])
{
	int		i;
	int		j;

	ac--;
	av++;
	i = -1;
	while (++i < ac)
	{
		ft_trim(av[i]);
		j = -1;
		while (av[i][++j])
		{
			if ((av[i][j] == '{' && av[i][j + 1] == '}')
				|| (av[i][j] == '(' && av[i][j + 1] == ')')
				|| (av[i][j] == '[' && av[i][j + 1] == ']'))
			{
				av[i][j] = '.';
				av[i][j + 1] = '.';
				ft_trim(av[i]);
				j = -1;
			}
		}
		if (av[i][0] == '\0')
			ft_putstr("OK\n");
		else
			ft_putstr("Error\n");
	}
	if (ac == 0)
		ft_putchar('\n');
	return (0);
}
