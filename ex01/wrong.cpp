#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "========== Virtual Destructor Verification ==========" << std::endl;
    const int arraySize = 4;
    WrongAnimal* animals[arraySize];

    std::cout << "\n[1] Creating Dogs and Cats..." << std::endl;
    for (int i = 0; i < arraySize / 2; i++) {
        animals[i] = new WrongCat();
    }
    for (int i = arraySize / 2; i < arraySize; i++) {
        animals[i] = new WrongCat();
    }

    std::cout << "\n[2] Deleting objects via Animal* pointers..." << std::endl;
    for (int i = 0; i < arraySize; i++) {
        std::cout << "--- Deleting index " << i << " ---" << std::endl;
        delete animals[i];
    }
    std::cout << "========== End of Test ==========" << std::endl;
    return 0;
}

