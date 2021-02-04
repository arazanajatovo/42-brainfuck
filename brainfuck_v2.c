/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   brainfuck.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: arazanaj <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/02/26 12:27:12 by arazanaj     #+#   ##    ##    #+#       */
/*   Updated: 2019/02/26 14:24:24 by arazanaj    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	looper(char **str, int cpt, int move)
{
	cpt += (**str == '[' || **str == ']') ? '\\' - **str : 0;
	*str += cpt != 0 ? move : 0;
	cpt != 0 ? looper(str, cpt, move) : 0;
}

void	brainfuck(char *str, char *ptr)
{
	ptr += (*str == '>' || *str == '<') ? *str - '=' : 0;
	*ptr += (*str == '+' || *str == '-') ? ',' - *str : 0;
	*str == '.' ? write(1, ptr, 1) : 0;
	((*str == '[' && !(*ptr)) || (*str == ']' && *ptr)) ? looper(&str, 0, '\\' - *str) : 0;
	*str ? brainfuck(str + 1, ptr) : 0;
}

int		main(int ac, char **av)
{
	char	*ptr = (char*)malloc(sizeof(char) * 2048);
	if (ac == 2)
		brainfuck(av[1], ptr);
	else
		write(1, "\n", 1);
	return (1);
}
