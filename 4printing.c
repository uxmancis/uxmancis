/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4printing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:48:18 by uxmancis          #+#    #+#             */
/*   Updated: 2022/12/06 18:05:57 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchar(char c, int num_printed)
{
	write(1, &c, 1);
	num_printed++;
	return (num_printed);
}

int	putstr(char *str, int num_printed)
{
	int		i;
	char	c;

	i = 0;

	while (str[i] != '\0')
	{
		c = str[i];
		num_printed = printchar(c, num_printed);
		i++;
	}
	return (num_printed);
}

//write only works with chars, not with ints. As a consequence, we have to chop numbers into becoming <10 so that we can write them as chars by ASCII table conversion (+48)
int	putnbr(int arg, int num_printed)
{
	if (arg < 0)
	{
		num_printed = printchar('-', num_printed);
		arg = arg * (-1);
	}

	if (arg >= 10)
	{
		num_printed = putnbr((arg / 10), num_printed);
		num_printed = printchar(((arg % 10) + 48), num_printed);
	}
	if (arg < 10)
		num_printed = printchar((arg + 48), num_printed);
	return (num_printed);
}
