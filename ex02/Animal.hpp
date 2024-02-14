/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mais <lde-mais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:16:19 by lde-mais          #+#    #+#             */
/*   Updated: 2024/01/30 01:12:39 by lde-mais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
    
	std::string type;

	public:
    
	Animal();
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);
    virtual ~Animal() = 0;

    virtual void makeSound() const = 0;
    std::string getType() const;
};

#endif
