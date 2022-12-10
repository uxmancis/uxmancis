/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:51:59 by uxmancis          #+#    #+#             */
/*   Updated: 2022/12/10 14:17:27 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//1. find_specifier function acts as Index by identifying format specifier... 
//...to then call to respective functions 4printing
int	find_specifier(const char *str, int i, va_list list, int num_printed)
{
	if (!str)
		num_printed = putstr("(null)", num_printed);
	if (str[i + 1] == 'c')
		num_printed = printchar(va_arg(list, int), num_printed);
	if (str[i + 1] == 's')
    {   
        /*printf("SÍ entra en: caso s\n");
		if(va_arg(list, char *) == NULL)
            num_printed = putstr("(null)", num_printed);
		printf("LO QUE LE ESTOY PASANDO = %s\n", va_arg(list, char *));
        if(ft_strlen(va_arg(list, char *)) == 0)
            printf("JAJA");
		else*/
            num_printed = putstr(va_arg(list, char *), num_printed);
    }
	if (str[i + 1] == 'p')
	{
		num_printed = putstr("0x", num_printed);
		num_printed = case_x_analyse(va_arg(list, int), num_printed, 'a');
	}
	if (str[i + 1] == 'd' || str[i + 1] == 'i')
		num_printed = putnbr(va_arg(list, int), num_printed);
	if (str[i + 1] == 'u')
		num_printed = putnbr(va_arg(list, unsigned int), num_printed);
	if (str[i + 1] == 'x')
		num_printed = case_x_analyse(va_arg(list, int), num_printed, 'a');
	if (str[i + 1] == 'X')
		num_printed = case_x_analyse(va_arg(list, int), num_printed, 'A');
	if (str[i + 1] == '%')
		num_printed = printchar('%', num_printed);
	return (num_printed);
}

//1. Declare macros for variadic functions, then call function "find_specifier"
//2. printf function returns total sum of printed characters

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
	return (num_printed);
}

int	main(void)
{
	//Testing my ft_printf function
	printf("= prints ft_printf\n%d= returns ft_printf\n", ft_printf("%u", -10));
	//Checking original printf function
	printf("= prints printf\n%d= returns printf\n", printf("%u", -10));
	return (0);
}
