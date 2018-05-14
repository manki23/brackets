/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 12:48:18 by manki             #+#    #+#             */
/*   Updated: 2018/05/14 14:57:35 by manki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char str[])
{
	int		i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

static void		ft_point(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
	{
		if (s[i] != '{' && s[i] != '}' && s[i] != '[' && s[i] != ']'
			&& s[i] != '(' && s[i] != ')')
			s[i] = '.';
	}
}

static void		ft_tt(char *s)
{
	int		i;

	i = -1;
	while (s[++i])
	{
		s[i] = s[i + 1];
	}
	s[i] = '\0';
}

void			ft_trim(char *s)
{
	int		i;
	int		switchs;

	ft_point(s);
	switchs = 1;
	while (switchs)
	{
		switchs = 0;
		i = -1;
		while (s[++i] != '\0')
		{
			if (s[i] == '.')
			{
				ft_tt(&s[i]);
				switchs = 1;
			}
		}
	}
}
