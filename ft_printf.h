/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 10:52:39 by uxmancis          #+#    #+#             */
/*   Updated: 2022/12/10 13:36:03 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>  
# include <limits.h>

//file: ft_printf.c
int ft_printf(const char *str, ...);
int	find_specifier(const char *str, int i, va_list list, int num_printed);

//file: 4printing.c

int printchar(char c, int num_printed);
int	putstr(char *str, int num_printed);
int	putnbr(int arg, int num_printed);

//file: hex_cases.c
int case_x_analyse(int num, int num_printed, char alpha);
int	case_x_lastprint(int num, int num_printed, char alpha);

//file: other_resources.c
int ft_strlen(char * str);

#endif
