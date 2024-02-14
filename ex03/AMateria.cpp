/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mais <lde-mais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:34:29 by lde-mais          #+#    #+#             */
/*   Updated: 2024/02/14 15:18:01 by lde-mais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(std::string const & type) : type(type) {
	std::cout << GREEN << "AMateria constructor called" << RESET << std::endl;
}

AMateria::AMateria(const AMateria& other) : type(other.type) {
	std::cout << GREEN << "AMateria constructor called" << RESET << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other)
        this->type = other.type;
    return *this;
}

AMateria::~AMateria() {
	std::cout << RED << "AMateria destructor called" << RESET << std::endl;
}

std::string const & AMateria::getType() const {
	return type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "AMateria abstractly used on " << target.getName() << std::endl;
}
