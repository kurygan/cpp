#pragma once

#	include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	public:
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(FragTrap const &copy);
		FragTrap	&operator=(FragTrap const &copy);

		void	attack(std::string const &target);
		void	highFivesGuys();
};