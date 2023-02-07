/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdeeyien <sukitd@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:52:01 by sdeeyien          #+#    #+#             */
/*   Updated: 2022/12/19 17:10:30 by sdeeyien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*seek_disx(const char *fstr, unsigned int *flag)
{
	int	i;

	i = 0;
	while (fstr[i])
	{
		if (ft_strchr("idsxX", fstr[i]))
			break ;
		else if (fstr[i] == '+')
			*flag = *flag | 0x000F;
		else if (fstr[i] == ' ')
			*flag = *flag | 0x00F0;
		else if (fstr[i] == '#')
			*flag = *flag | 0x0F00;
		i++;
	}
	return (&fstr[i] + 1);
}

static int	check_fstr(const char **fstr, va_list ar_lst, int *no_prn)
// To check conversion csdixXpu
{
	unsigned int	flag;

	flag = 0x0;
	if (**fstr == '%')
	{
		if (*(*fstr + 1) == ' ' || *(*fstr + 1) == '+' || *(*fstr + 1) == '#')
			*fstr = seek_disx(*fstr + 1, &flag);
		else if (ft_strchr("csdixXpu", *(*fstr + 1)))
			*fstr += 2;
		if (*(*fstr - 1) == 'c')
			return (*no_prn += putchr(va_arg(ar_lst, int), 1));
		if (*(*fstr - 1) == 's')
			return (*no_prn += putstr(va_arg(ar_lst, char *), 1, flag));
		if (*(*fstr - 1) == 'd' || *(*fstr - 1) == 'i')
			return (*no_prn += putnbr(va_arg(ar_lst, int), 1, flag));
		if (*(*fstr - 1) == 'x' || *(*fstr - 1) == 'X')
			return (*no_prn += puthex(va_arg(ar_lst, int), 1, *fstr - 1, flag));
		if (*(*fstr - 1) == 'p')
			return (*no_prn += putptr(va_arg(ar_lst, void *), 1));
		if (*(*fstr - 1) == 'u')
			return (*no_prn += putunbr(va_arg(ar_lst, unsigned int), 1));
	}
	return (0);
}

int	ft_printf(const char *fstr, ...)
{
	va_list	ar_lst;
	int		no_prn;

	va_start(ar_lst, fstr);
	no_prn = 0;
	while (*fstr)
	{
		if (*fstr == '%' && *(fstr + 1) == '%')
		{
			fstr += 2;
			ft_putchar_fd('%', 1);
			++no_prn;
		}
		else if (!check_fstr(&fstr, ar_lst, &no_prn))
		{
			if (!(*fstr))
				break ;
			ft_putchar_fd(*(fstr), 1);
			fstr++;
			no_prn++;
		}
	}
	va_end(ar_lst);
	return (no_prn);
}
