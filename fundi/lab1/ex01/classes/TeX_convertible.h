/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TeX_convertible.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnicki <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:53:44 by dnicki            #+#    #+#             */
/*   Updated: 2021/02/18 21:04:30 by dnicki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class TeX_convertible
{
public:
	virtual std::string convert() const = 0;
};
