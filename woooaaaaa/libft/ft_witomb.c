/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_witomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamadori <aamadori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 17:51:41 by aamadori          #+#    #+#             */
/*   Updated: 2018/12/09 23:01:54 by aamadori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_witomb(char *str, wchar_t wc)
{
	if (wc < 0x80)
		str[0] = wc;
	else if (wc < 0x800)
	{
		str[0] = 0b11000000 | (wc >> 6);
		str[1] = 0b10000000 | (wc & 0b111111);
		return (4);
	}
	else if (0x10000)
	{
		str[0] = 0b11100000 | (wc >> 12);
		str[1] = 0b10000000 | ((wc >> 6) & 0b00111111);
		str[2] = 0b10000000 | (wc & 0b00111111);
		return (4);
	}
	else
	{
		str[0] = 0b11110000 | (wc >> 18);
		str[1] = 0b10000000 | ((wc >> 12) & 0b00111111);
		str[2] = 0b10000000 | ((wc >> 6) & 0b00111111);
		str[3] = 0b10000000 | (wc & 0b00111111);
		return (4);
	}
	return (1);
}