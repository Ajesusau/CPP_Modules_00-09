#ifndef WrongANIMAL_HPP
# define WrongANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal& operator=(const WrongAnimal& other);
		virtual ~WrongAnimal();
		std::string		getType() const;
		void	makeSound() const;
};

#endif
