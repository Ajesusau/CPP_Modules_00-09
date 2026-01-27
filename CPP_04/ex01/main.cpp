#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    std::cout << "=== 1. ARRAY DE ANIMALES ===" << std::endl;
    
    const int size = 4;
    Animal* animals[size];

    for (int i = 0; i < size; i++) {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < size; i++) {
        std::cout << "\n[Borrando Animal " << i << "]" << std::endl;
        delete animals[i];
    }

    std::cout << "\n=== 2. DEEP COPY ===" << std::endl;

    Dog basic;
    basic.getBrain()->ideas[0] = "Idea Original";

    {
        Dog tmp = basic;
        std::cout << "Original: " << basic.getBrain()->ideas[0] << std::endl;
        std::cout << "Copia:    " << tmp.getBrain()->ideas[0] << std::endl;
        

        tmp.getBrain()->ideas[0] = "Idea NUEVA";
        std::cout << "Copia modificada a 'Idea NUEVA'." << std::endl;
    }

    std::cout << "Original tras borrar la copia: " << basic.getBrain()->ideas[0] << std::endl;
    
    if (basic.getBrain()->ideas[0] == "Idea Original")
        std::cout << "RESULTADO: OK (El original se mantuvo intacto)" << std::endl;
    else
        std::cout << "RESULTADO: ERROR (El original cambio o se corrompio)" << std::endl;

    return 0;
}
