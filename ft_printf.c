/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:35:56 by uxmancis          #+#    #+#             */
/*   Updated: 2022/12/06 18:30:42 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//find_specifier acts as an Index by identifying format specifier to then call to corresponding printing functions
int	find_specifier(const char *str, int i, va_list list, int num_printed)
{
	if (!str)
		num_printed = putstr("(null)", num_printed);
	if (str[i + 1] == 'c')
		num_printed = printchar(va_arg(list, int), num_printed);
	if (str[i + 1] == 's')
		num_printed = putstr(va_arg(list, char *), num_printed);
	if (str[i + 1] == 'p')
	{
		num_printed = putstr("0x", num_printed);
		num_printed = case_x_analyse(va_arg(list, int), num_printed, 'a');
	}
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
		num_printed = putnbr(va_arg(list, int), num_printed);
	if (str[i + 1] == 'u')
		printf("printed_u");
	if (str[i + 1] == 'x')
		num_printed = case_x_analyse(va_arg(list, int), num_printed, 'a');
	if (str[i + 1] == 'X')
		num_printed = case_x_analyse(va_arg(list, int), num_printed, 'A');
	if (str[i + 1] == '%')
		num_printed = printchar('%', num_printed);
	return (num_printed);
}

//We declare needed macros for variadic functions and then call function named "find_specifier"
int ft_printf(const char *str, ...)
{
	int		num_printed;
	int		i;
	va_list list;

	num_printed = 0;
	i = 0;
	va_start(list, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			num_printed = printchar(str[i], num_printed);
		}
		else
		{	
			num_printed = find_specifier(str, i, list, num_printed);
			i++;
		}
		i++;
	}
	va_end(list);
	//printf function returns total sum of printed characters
	return (num_printed);
}

int	main(void)
{
	//Testing my ft_printf function
	printf("= prints ft_printf\n%d= returns ft_printf\n", ft_printf("%X", 28));
	//Checking original printf function
	printf("= prints printf\n%d= returns printf\n", printf("%X", 28));
	return (0);
}
