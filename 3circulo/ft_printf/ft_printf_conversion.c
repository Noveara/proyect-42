/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsueiro- <nsueiro-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 15:42:32 by nsueiro-          #+#    #+#             */
/*   Updated: 2025/02/15 16:28:38 by nsueiro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int num, char format)
{
	char	*hex_digits;
	int		count;

	if (format == 'x')
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	count = 0;
	if (num >= 16)
		count += ft_puthex(num / 16, format);
	count += ft_putchar(hex_digits[num % 16]);
	return (count);
}

int	ft_print_unsigned_hex(unsigned long u)
{
	int	len;

	len = 0;
	if (u >= 16)
		len += ft_print_unsigned_hex(u / 16);
	write(1, &"0123456789abcdef"[u % 16], 1);
	len++;
	return (len);
}

int	ft_putptr(void *ptr)
{
	unsigned long	address;
	int				count;

	if (!ptr)
		return (write(1, "(nil)", 5), 5);
	address = (unsigned long)ptr;
	count = ft_putstr("0x");
	if (address == 0)
		return (count + ft_putchar('0'));
	count += ft_print_unsigned_hex(address);
	return (count);
}
