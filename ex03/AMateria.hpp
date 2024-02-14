/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-mais <lde-mais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:30:56 by lde-mais          #+#    #+#             */
/*   Updated: 2024/02/14 15:16:04 by lde-mais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <string>
# include <iostream>

# define BLACK    "\e[30m"
# define RED    "\e[31m"
# define GREEN    "\e[32m"
# define YELLOW    "\e[33m"
# define BLUE    "\e[34m"
# define PURPLE    "\e[35m"
# define CYAN    "\e[36m"
# define WHITE    "\e[37m"
# define RESET  "\e[0m"

class ICharacter;

class AMateria
{
	protected:
    
	std::string type;
	
	public:
    
	AMateria(std::string const & type);
    AMateria(const AMateria& other);
    AMateria& operator=(const AMateria& other);
    virtual ~AMateria();

    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif
