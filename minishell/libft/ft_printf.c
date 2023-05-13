/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dameneze <dameneze@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:24:37 by dameneze          #+#    #+#             */
/*   Updated: 2023/02/20 00:07:26 by dameneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

static int	ft_get_string(char c, va_list args_list)
{
	char	*str;
	int		rtn;

	str = NULL;
	if (c == 'u')
		str = ft_unsigned_itoa(va_arg(args_list, unsigned int));
	else if (c == 'x')
		str = ft_to_hexa((unsigned long)va_arg(args_list, unsigned int), 0);
	else if (c == 'X')
		str = ft_to_hexa((unsigned long)va_arg(args_list, unsigned int), 1);
	else if (c == 's')
	{
		str = va_arg(args_list, char *);
		if (str == NULL)
			str = "(null)";
	}
	else if (c == 'p')
		str = ft_to_hexa(va_arg(args_list, unsigned long), 0);
	else if (c == 'i' || c == 'd')
		str = ft_itoa(va_arg(args_list, int));
	ft_putstr_fd(str, 1);
	rtn = ft_strlen(str);
	if (c != 's' && !(str[0] == '0' && (c == 'p' || c == 'x' || c == 'X')))
		free(str);
	return (rtn);
}

static int	ft_checks(char c, va_list args_list)
{
	int	rtn;

	rtn = 0;
	if (c == 'c')
	{
		rtn++;
		ft_putchar_fd(va_arg(args_list, int), 1);
	}
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		rtn++;
	}
	else if (c == 'p')
	{
		rtn += 2;
		ft_putstr_fd("0x", 1);
		rtn += ft_get_string(c, args_list);
	}
	else
		rtn += ft_get_string(c, args_list);
	return (rtn);
}

int	ft_printf(const char *text, ...)
{
	va_list	args_list;
	int		rtn;
	int		i;

	i = -1;
	rtn = 0;
	va_start(args_list, text);
	while (text[++i])
	{
		if (text[i] == '%' && text[i + 1] != 0)
		{
			rtn += ft_checks(text[i + 1], args_list);
			i++;
		}
		else
		{
			rtn++;
			ft_putchar_fd(text[i], 1);
		}
	}
	va_end(args_list);
	return (rtn);
}
