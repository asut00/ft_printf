/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_addr.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/15 08:28:15 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddress_fd(void *addr, int fd)
{
	int				i;
	char			*hex;
	unsigned long	address;
	int				digit;
	int				print;

	if (!addr)
		return (ft_putstr_fd_spe("(nil)", 1));
	address = (unsigned long)addr;
	i = 15;
	hex = "0123456789abcdef";
	ft_putchar_fd_spe('0', fd);
	ft_putchar_fd_spe('x', fd);
	print = 0;
	while (i >= 0)
	{
		digit = (address >> (i * 4)) & 0xf;
		if (digit != 0 || print)
		{
			ft_putchar_fd_spe(hex[digit], fd);
			print++;
		}
		i--;
	}
	return (print + 2);
}
