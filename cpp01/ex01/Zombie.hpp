#ifndef ZOMBIE_H
#	define ZOMBIE_H

#	include <iostream>

class Zombie {
	private:
		std::string	_name;
	
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void		announce();
		void		setName(std::string name);
};

Zombie* zombieHord(int n, std::string name);

#endif