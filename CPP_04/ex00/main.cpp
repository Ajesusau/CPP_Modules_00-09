#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	delete i;
	delete j;
	delete meta;

	std::cout << std::endl;

	std::cout << "------------------------------------------------" << std::endl;
	std::cout << "Testing WrongAnimal:" << std::endl;

	std::cout << std::endl;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << std::endl;

	std::cout << wrongCat->getType() << " " << std::endl;

	wrongCat->makeSound(); 
	wrongMeta->makeSound();

	std::cout << std::endl;

	delete wrongCat;
	delete wrongMeta;

	return 0;
}
