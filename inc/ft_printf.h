/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asuteau <asuteau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 07:47:56 by asuteau           #+#    #+#             */
/*   Updated: 2024/05/15 08:28:15 by asuteau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_putchar_fd_spe(int c, int fd);
size_t	ft_strlen(const char *s);
int		ft_putstr_fd_spe(char *s, int fd);
int		ft_putaddress_fd(void *addr, int fd);
void	ft_putnbr_fd_spe(int n, int fd, int uns);
int		deal_w_nbr(int n, int fd, int uns);
void	ft_put_hex_byte(int c, int fd, int cap);
void	ft_putnbr_hex(int n, int fd, int cap);
int		deal_w_nbr_hex(int n, int fd, int cap);
int		ft_printf(const char *str, ...);

#endif