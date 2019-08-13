/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha512_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maks <maksym.haiduk@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 12:40:28 by mgayduk           #+#    #+#             */
/*   Updated: 2019/08/13 13:20:00 by maks             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sha512.h"

void	sha512_print_digest(unsigned char digest[SHA512_DIGEST_SIZE])
{
	unsigned int i;

	i = 0;
	while (i < SHA512_DIGEST_SIZE)
	{
		ft_printf("%02x", digest[i + 3]);
		ft_printf("%02x", digest[i + 2]);
		ft_printf("%02x", digest[i + 1]);
		ft_printf("%02x", digest[i]);
		i += 4;
	}
}

void	sha512_print(
	unsigned char digest[SHA512_DIGEST_SIZE],
	char *source,
	ft_bool is_file)
{
	if (!g_sha512_flags.q && !g_sha512_flags.r)
	{
		if (is_file)
			ft_printf("SHA512 (%s) = ", source);
		else
			ft_printf("SHA512 (\"%s\") = ", source);
	}
	sha512_print_digest(digest);
	if (g_sha512_flags.r && !g_sha512_flags.q)
		is_file ? ft_printf(" %s", source) : ft_printf(" \"%s\"", source);
	ft_putchar('\n');
}
