/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mais <lde-mais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:35:29 by lde-mais          #+#    #+#             */
/*   Updated: 2024/02/14 16:06:02 by lde-mais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <string>

Cure::Cure() : AMateria("cure") {
	std::cout << BLACK << this->type << " was created" << RESET << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
	std::cout << YELLOW << "cure was created from copy" << RESET << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
    AMateria::operator=(other);
    return *this;
}

Cure::~Cure() {
	std::cout << PURPLE << this->type << " was destroyed" << RESET << std::endl;
}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << WHITE << " heals " << target.getName() << "'s wounds" << RESET << std::endl;
}
