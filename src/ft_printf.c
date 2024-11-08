/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/15 08:28:15 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putformat(char c, va_list *args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar_fd_spe((char)va_arg(*args, int), 1);
	else if (c == 's')
		len += ft_putstr_fd_spe(va_arg(*args, char *), 1);
	else if (c == 'p')
		len += ft_putaddress_fd(va_arg(*args, void *), 1);
	else if (c == 'd' || c == 'i')
		len += deal_w_nbr(va_arg(*args, int), 1, 0);
	else if (c == 'u')
		len += deal_w_nbr(va_arg(*args, int), 1, 1);
	else if (c == 'x')
		len += deal_w_nbr_hex(va_arg(*args, int), 1, 0);
	else if (c == 'X')
		len += deal_w_nbr_hex(va_arg(*args, int), 1, 1);
	else if (c == '%')
		len += ft_putchar_fd_spe('%', 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	va_start(args, str);
	len = 0;
	if (str && *str)
	{
		while (*str)
		{
			if (*str == '%')
			{
				str++;
				len += ft_putformat(*str, &args);
			}
			else
				len += ft_putchar_fd_spe(*str, 1);
			str++;
		}
	}
	return (len);
}

/*
#include <stdio.h>
int main(void)
{
	printf("\n");
	char str[] = "hey comment ca va";
	int test_int = -1564;
	//char test_str[] = "moi ca va nickel";
	char test_char = 'X';

	printf("FT_PRINTF:\n");
	ft_printf("|");
	int ft_printf_ret = ft_printf(" %c %s %p %d %i %u %x %X %% ",
		test_char, str, str, test_int, test_int, test_int, test_int, test_int);
	ft_printf("|");
	printf("\n");

	printf("ft_printf returns : %d\n", ft_printf_ret);

	printf("\n\n");

	printf("PRINTF:\n");
	printf("|");
	int printf_ret = printf(" %c %s %p %d %i %u %x %X %% ",
		test_char, str, str, test_int, test_int, test_int, test_int, test_int);
	printf("|");
	printf("\n");

	printf("printf returns : %d\n", printf_ret);

	printf("\n\n\n");
}
*/