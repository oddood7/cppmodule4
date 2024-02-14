/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mais <lde-mais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:41:10 by lde-mais          #+#    #+#             */
/*   Updated: 2024/02/14 15:46:10 by lde-mais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << BLACK << "Materia Source created" << RESET << std::endl;
    for (int i = 0; i < 4; ++i)
        inventory[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other) 
{
    for (int i = 0; i < 4; ++i)
	{
		if (other.inventory[i])
			this->inventory[i] = (other.inventory[i])->clone();
        //inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : 0;
	}
	std::cout << YELLOW << "Materia source was created from copy" << RESET << std::endl;	
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other)
	{
        for (int i = 0; i < 4; ++i)
		{
            delete inventory[i];
            inventory[i] = other.inventory[i] ? other.inventory[i]->clone() : 0;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
        delete inventory[i];
	std::cout << PURPLE << "Materia source was destroyed" << RESET << std::endl;
	
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; ++i)
	{
        if (!inventory[i])
		{
            inventory[i] = m;
            break;
        }
    }
	std::cout << CYAN "Materia " << m->getType() << " was learned" << RESET << std::endl;

}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i)
	{
        if (inventory[i] && inventory[i]->getType() == type)
		{
			std::cout << GREEN "Materia " << type << " was created" << RESET << std::endl;
            return (inventory[i]->clone());
		}
    }
	std::cout << RED << "Materia does not exist" << RESET << std::endl;
    return 0;
}
