/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_resources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:05:32 by uxmancis          #+#    #+#             */
/*   Updated: 2022/12/10 12:16:37 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_strlen(char * str)
{
    printf("SÍ entra en: ft_strlen\n");
    printf("el str que le he mandado a ft_strlen = %s\n", str);
    int i; 

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    printf("i = %d\n", i);
    return (i);
}
