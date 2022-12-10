/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_cases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:52:14 by uxmancis          #+#    #+#             */
/*   Updated: 2022/12/10 13:35:53 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//line 29: We print middle number, before last print
//line 30: We substract (restar) 16 n times so that we make it <16
int case_x_analyse(int num, int num_printed, char alpha)
{
	int n;
	int m;

	if (num < 16)
	{
		num_printed = case_x_lastprint(num, num_printed, alpha);	
	}
	if (num >= 16)
	{
		n = num / 16;
		num_printed = putnbr(n, num_printed);
		m = num - (16 * n);
		num_printed = case_x_lastprint(m, num_printed, alpha);
	}
	return (num_printed);
}

//Example: num = 3, num_printed = 0; alpha = 'A'
//Line 43: prints last number
//Line 46: prints last letter
//Line 49: depending on alpha being 'A' or 'a', final result will vary
int	case_x_lastprint(int num, int num_printed, char alpha)
{
	int	n;
	int	m;

	if (num >= 0 && num <= 9)
		num_printed = putnbr(num, num_printed);
	if (num >= 10 && num <= 15)
	{
		n = num - 10;
		m = alpha + n;
		num_printed = printchar(m, num_printed);
	}
	return (num_printed);
}
