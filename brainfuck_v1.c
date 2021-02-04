/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/26 02:26:36 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/26 03:17:35 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	brainfuck(char *ptr, char *str)
{
	int cpt;

	while (*str)
	{
		cpt = 1;
		if (*str == '>')
			ptr++;
		else if (*str == '<')
			ptr--;
		else if (*str == '+')
			(*ptr)++;
		else if (*str == '-')
			(*ptr)--;
		else if (*str == '.')
			write(1, ptr, 1);
		else if (*str == '[' && !(*ptr))
		{
			while (cpt != 0)
			{
				str++;
				if (*str == '[')
					cpt++;
				if (*str == ']')
					cpt--;
			}
		}
		else if (*str == ']' && *ptr)
		{
			while (cpt != 0)
			{
				str--;
				if (*str == ']')
					cpt++;
				if (*str == '[')
					cpt--;
			}
		}
		str++;
	}
}

int		main(int ac, char **av)
{
	int 	i;
	char	*ptr;

	if (ac == 2)
	{
		i = 0;
		ptr = (char*)malloc(sizeof(char) * 2048);
		while (i < 2048)
			ptr[i++] = 0;
		brainfuck(ptr, av[1]);
	}
	else
		write(1, "\n", 1);
	return (0);
}
