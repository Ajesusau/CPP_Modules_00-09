#include <iostream>
#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{

    //AAnimal* test = new AAnimal(); 
 
    AAnimal* perro = new Dog();
    AAnimal* gato = new Cat();

    perro->makeSound();
    gato->makeSound();

    delete perro;
    delete gato;

    return 0;
}
