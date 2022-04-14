/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fporto <fporto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:45:05 by fporto            #+#    #+#             */
/*   Updated: 2022/04/14 00:45:34 by fporto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char	*__asan_default_options(void)
{
	return ("strict_string_checks=1:\
		detect_stack_use_after_return=1:\
		check_initialization_order=1:\
		strict_init_order=1:\
		detect_invalid_pointer_pairs=9:\
		halt_on_error=0\
		detect_leaks=1\
		use_unaligned=1");
}
