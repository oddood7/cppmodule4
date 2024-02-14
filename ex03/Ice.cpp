/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mais <lde-mais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:35:02 by lde-mais          #+#    #+#             */
/*   Updated: 2024/02/14 16:05:54 by lde-mais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << BLACK << this->type << " was created" << RESET << std::endl;

}

Ice::Ice(const Ice& other) : AMateria(other) {
	std::cout << YELLOW << "ice was created from copy" << RESET << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
    AMateria::operator=(other);
    return *this;
}

Ice::~Ice() {
	std::cout << PURPLE << this->type << " was destroyed" << RESET << std::endl;
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << CYAN << " shoots an ice bolt at " << target.getName() << RESET << std::endl;
}
