/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnguyen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 08:40:45 by lnguyen           #+#    #+#             */
/*   Updated: 2018/08/11 18:01:20 by lnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_mate.h"

int main(int ac, char **av)
{
	int i;
	int l;
	profile *king = NULL;
	profile *attacker = NULL;
	profile **kings = &king;
	profile **attackers = &attacker;

	if (ac < 2)
	{
		ft_putchar('\n');
		return (0);
	}
	l =	ft_strlen(av[1]);
	i = 1;
	while (i < ac)
	{
		scan(av[i], i - 1, kings, attackers);
		++i;
	}
	print_profile(kings);
	print_profile(attackers);
	if (check_mate(kings, attackers, l) == 1)
//		ft_putstr("Success.");
		write(1,"s",1);
	else
		//ft_putstr("Failure.");
		write(1,"f",1);
	free(*kings);
	while(*attackers)
	{
		free(*attackers);
		*attackers = (*attackers)->next;
	}
	return(0);
}
