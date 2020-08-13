/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_member.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 05:40:37 by mashley           #+#    #+#             */
/*   Updated: 2020/08/13 05:40:40 by mashley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

t_member	get_member(t_cx c, int n)
{
	t_member result;
	result.z = c;
	result.n = n;
	return (result);
}
