/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mais <lde-mais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:44:14 by lde-mais          #+#    #+#             */
/*   Updated: 2024/02/14 16:09:13 by lde-mais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(std::string name) : name(name)
{
	std::cout << CYAN << "Character " << name << " was created" << RESET << std::endl;
    for (int i = 0; i < 4; ++i)
        inventory[i] = 0;
}

Character::Character(const Character& other) : name(other.name + "_copy")
{
    for (int i = 0; i < 4; ++i)
	{
        if (other.inventory[i])
            inventory[i] = other.inventory[i]->clone();
        else
            inventory[i] = 0;
    }
	std::cout << YELLOW << "Character " << name << " was created copied from " << other.name << RESET << std::endl;
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        name = other.name;
        for (int i = 0; i < 4; ++i)
        {
            delete inventory[i];
            if (other.inventory[i] != 0)
                inventory[i] = other.inventory[i]->clone();
            else
                inventory[i] = 0;
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
        delete inventory[i];
	std::cout << PURPLE << "Character " << this->name << " was destroyed" << RESET << std::endl;
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << PURPLE << "Character " << this->name << " tried to equip nothing and nothing happened" << RESET << std::endl;
		return ;
	}
    for (int i = 0; i < 4; ++i)
	{
		if (i >= 4)
			std::cout << PURPLE << " Cant equip more than 4 materia" << RESET << std::endl;
        if (!inventory[i])
		{
            inventory[i] = m;
			std::cout << CYAN << this->name << " equipped " << m->getType() << " in slot " << i << RESET << std::endl;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        std::cout << this->name << " tried to unequip nothing at slot " << idx << " and it did nothing\n";
    else if (!(this->inventory)[idx])
        std::cout << this->name << " has nothing equipped at slot " << idx << " so he can't unequip it\n";
    else
    {
        AMateria *tmp = this->inventory[idx];
        std::cout << this->name << " unequipped " << tmp->getType() << " at slot "<< idx << "\n";
        (this->inventory)[idx] = 0;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && inventory[idx] != 0)
	{
		std::cout << GREEN << name << RESET;
        inventory[idx]->use(target);
	}
	else
		std::cout << PURPLE << "Nothing to use" << RESET << std::endl;
}

AMateria *Character::getMateriaFromInventory(int idx)
{
    if (idx >= 0 && idx < 4)
        return inventory[idx];
    else
        return 0;
}
