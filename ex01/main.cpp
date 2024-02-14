/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mais <lde-mais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 00:59:58 by lde-mais          #+#    #+#             */
/*   Updated: 2024/01/30 01:06:31 by lde-mais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " makes a sound: ";
    j->makeSound();

    std::cout << i->getType() << " makes a sound: ";
    i->makeSound();

    delete j;
    delete i;

    std::cout << "Tests avec tableau";

    const int numAnimals = 10;
    Animal* animals[numAnimals];

    for (int i = 0; i < numAnimals; ++i)
	{
        if (i < numAnimals / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
		std::cout << animals[i]->getType() << " created, it makes a sound: ";
        animals[i]->makeSound();
    }

    for (int i = 0; i < numAnimals; ++i)
        delete animals[i];
    return 0;
}

