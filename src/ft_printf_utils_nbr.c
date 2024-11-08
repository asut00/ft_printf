/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/15 08:28:15 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd_spe(int n, int fd, int uns)
{
	long			ln;

	ln = n;
	if (n < 0 && uns)
		ln = (unsigned int)ln;
	if (ln < 0)
	{
		if (!uns)
			ft_putchar_fd_spe('-', fd);
		ln = -ln;
	}
	if (ln < 10)
		ft_putchar_fd_spe(ln + 48, fd);
	if (ln >= 10)
	{
		ft_putnbr_fd_spe(ln / 10, fd, uns);
		ft_putchar_fd_spe(((ln % 10) + 48), fd);
	}
}

int	deal_w_nbr(int n, int fd, int uns)
{
	int		len;
	long	ln;
	long	ln_temp;

	ln = n;
	ln_temp = ln;
	if (n < 0 && uns)
		ln = (unsigned int)ln;
	if (n < 0 && uns)
		ln_temp = (unsigned int)ln_temp;
	len = 0;
	if (ln < 0 && !uns)
		len++;
	while (ln != 0)
	{
		ln /= 10;
		len++;
	}
	ft_putnbr_fd_spe(ln_temp, fd, uns);
	if (ln_temp == 0)
		return (1);
	return (len);
}

void	ft_put_hex_byte(int c, int fd, int cap)
{
	char	*hex;

	if (cap == 1)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	ft_putchar_fd_spe(hex[c % 16], fd);
}

void	ft_putnbr_hex(int n, int fd, int cap)
{
	long	ln;
	int		len;

	ln = n;
	if (n < 0)
		ln = (unsigned int)ln;
	len = 16;
	if (ln < 0)
	{
		ft_putchar_fd_spe('-', fd);
		ln = -ln;
	}
	if (ln < len)
	{
		ft_put_hex_byte(ln, fd, cap);
	}
	else if (ln >= len)
	{
		ft_putnbr_hex(ln / len, fd, cap);
		ft_put_hex_byte((ln % len), fd, cap);
	}
}

int	deal_w_nbr_hex(int n, int fd, int cap)
{
	int		len;
	long	ln;
	long	ln_temp;

	ln = n;
	ln_temp = ln;
	if (n < 0)
		ln = (unsigned int)ln;
	if (n < 0)
		ln_temp = (unsigned int)ln_temp;
	len = 0;
	if (ln < 0)
		len++;
	while (ln != 0)
	{
		ln /= 16;
		len++;
	}
	ft_putnbr_hex(ln_temp, fd, cap);
	if (ln_temp == 0)
		return (1);
	return (len);
}
