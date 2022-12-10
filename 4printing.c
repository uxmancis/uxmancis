/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4printing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:52:25 by uxmancis          #+#    #+#             */
/*   Updated: 2022/12/10 13:01:54 by uxmancis         ###   ########.fr       */
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

//Write only works with chars, not with ints. 
//As a consequence, we've to chop numbers into making them <10 so that...
//...we can write them as chars by ASCII table conversion (+48)
int	putnbr(int arg, int num_printed)
{
	if(arg == -2147483648)
	{
		num_printed = printchar('-', num_printed);
		num_printed = putstr("2147483648", num_printed);
		return(num_printed);
	}
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
