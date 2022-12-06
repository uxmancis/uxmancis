/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_cases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:56:12 by uxmancis          #+#    #+#             */
/*   Updated: 2022/12/06 18:02:04 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		num_printed = putnbr(n, num_printed); //Here we print middle number, before last print
		m = num - (16 * n); //Si le restamos 16 las veces que haga falta para convertirse en <16.
		num_printed = case_x_lastprint(m, num_printed, alpha);
	}
	return(num_printed);
}

int	case_x_lastprint(int num, int num_printed, char alpha)
{
	//num = 3, num_printed = 0; alpha = 'A'
	int	n;
	int	m;

	//prints last number
	if (num >= 0 && num <= 9) 
		num_printed = putnbr(num, num_printed);
	//prints last letter
	if (num >=10 && num <= 15)
	{
		n = num - 10;
		m = alpha + n; //segun si alpha es 'A' o 'a' el resultado será uno u otro
		num_printed = printchar(m, num_printed);
	}
	return (num_printed);
}
