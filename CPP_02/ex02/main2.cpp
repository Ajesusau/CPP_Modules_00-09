#include "Fixed.hpp"

int main(void)
{
    Fixed a;                          // a se crea con constructor por defecto → valor 0.0
    Fixed b(10);                      // b se crea desde int → valor 10.0
    Fixed c(42.42f);                  // c se crea desde float → valor 42.42
    Fixed d(b);                       // d es copia de b → valor 10.0

    a = Fixed(1234.43f);            // a ahora vale aproximadamente 1234.43

    std::cout << "a = " << a << std::endl; // imprime 1234.43
    std::cout << "b = " << b << std::endl; // imprime 10
    std::cout << "c = " << c << std::endl; // imprime 42.42
    std::cout << "d = " << d << std::endl; // imprime 10

    std::cout << "b + c = " << (b + c) << std::endl;  // 10 + 42.42 = 52.42
    std::cout << "c - b = " << (c - b) << std::endl;  // 42.42 - 10 = 32.42
    std::cout << "b * c = " << (b * c) << std::endl;  // 10 * 42.42 = 424.2
    std::cout << "c / b = " << (c / b) << std::endl;  // 42.42 / 10 = 4.242

    a = Fixed(0);
    std::cout << "a = " << a << std::endl;   // imprime 0
    std::cout << "++a = " << ++a << std::endl; // incrementa primero → 0.00390625
    std::cout << "a = " << a << std::endl;   // confirma → 0.00390625
    std::cout << "a++ = " << a++ << std::endl; // imprime 0.00390625 y luego incrementa
    std::cout << "a = " << a << std::endl;   // ahora vale 0.00390625

    std::cout << "--a = " << --a << std::endl; // decrementa primero → 0.00390625
    std::cout << "a-- = " << a-- << std::endl; // imprime 0.00390625 y luego decrementa
    std::cout << "a = " << a << std::endl;   // ahora vale 0

    std::cout << "min(b, c) = " << Fixed::min(b, c) << std::endl; // devuelve b → 10
    std::cout << "max(b, c) = " << Fixed::max(b, c) << std::endl; // devuelve c → 42.42

    return 0; // fin del programa
}

