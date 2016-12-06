/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <hponcet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:39:46 by hponcet           #+#    #+#             */
/*   Updated: 2016/12/06 15:47:42 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int ac, char **av)
{
	int		i;
	int		l;
	char	test[2048];
	char	r;
	char	err[7] = "Error\n";
	char	ok[4] = "OK\n";

	r = '\n';
	if (ac < 2)
		return (write(1, &r, 1));
	ac = 1;
	while (av[ac])
	{
		i = -1;
		while (++i < 2048)
			test[i] = '\0';
		l = -1;
		i = 0;
		if (!av[ac][i])
			write(1, ok, 3);
		while (av[ac][i])
		{
			if (av[ac][i] == '{' || av[ac][i] == '[' || av[ac][i] == '(')
				test[++l] = av[ac][i];
			else if (av[ac][i] == '}')
			{
				if (test[l] == '{')
					test[l--] = '\0';
				else
				{
					write(1, err, 6);
					break ;
				}
			}
			else if (av[ac][i] == ']')
			{
				if (test[l] == '[')
					test[l--] = '\0';
				else
				{
					write(1, err, 6);
					break ;
				}
			}
			else if (av[ac][i] == ')') 
			{
				if (test[l] == '(')
					test[l--] = '\0';
				else
				{
					write(1, err, 6);
					break ;
				}
			}
			i++;
			if (!av[ac][i] && !test[l])
				write(1, ok, 3);
			else if (!av[ac][i] && test[l])
				write(1, err, 6);
		}
		ac++;
	}
	return (0);
}
