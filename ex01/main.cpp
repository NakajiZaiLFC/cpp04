#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main()
{
    std::cout << "========== Deep Copy Verification ==========" << std::endl;

    std::cout << "\n[1] Creating original Dog 'basic'..." << std::endl;
    Dog basic;
    Brain* basicBrainAddr = basic.getBrain();
    std::cout << "-> basic's Brain address: " << basicBrainAddr << std::endl;

    std::cout << "\n[2] Testing Copy Constructor (Dog tmp = basic;)..." << std::endl;
    {
        Dog tmp = basic;
        Brain* tmpBrainAddr = tmp.getBrain();
        
        std::cout << "-> tmp's Brain address:   " << tmpBrainAddr << std::endl;

        if (basicBrainAddr != tmpBrainAddr)
            std::cout << "✅ SUCCESS: Addresses are different. (Deep Copy verified)" << std::endl;
        else
            std::cout << "❌ FAILURE: Addresses are same! (Shallow Copy detected)" << std::endl;
    } 

    std::cout << "\n[3] Testing Assignment Operator (Dog assign = basic;)..." << std::endl;
    {
        Dog assign;
        std::cout << "-> assign's OLD Brain address: " << assign.getBrain() << std::endl;
        
        assign = basic;
        
        Brain* assignBrainAddr = assign.getBrain();
        std::cout << "-> assign's NEW Brain address: " << assignBrainAddr << std::endl;

        if (basicBrainAddr != assignBrainAddr)
            std::cout << "✅ SUCCESS: Addresses are different. (Deep Copy verified)" << std::endl;
        else
            std::cout << "❌ FAILURE: Addresses are same! (Shallow Copy detected)" << std::endl;
    }

    std::cout << "\n========== End of Test ==========" << std::endl;
    return 0;
}
