#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    std::cout << "========== WrongAnimal/WrongCat Test (Static Binding) ==========" << std::endl;

    // 1. 基底クラスのポインタで基底クラスのオブジェクトを指す（通常）
    std::cout << "\n[1] Creating WrongAnimal* meta = new WrongAnimal()" << std::endl;
    const WrongAnimal* meta = new WrongAnimal();
    std::cout << "-> Type: " << meta->getType() << " " << std::endl;
    std::cout << "-> Sound: ";
    meta->makeSound(); // WrongAnimal のサウンド

    // 2. 基底クラスのポインタで派生クラスのオブジェクトを指す
    std::cout << "\n[2] Creating WrongAnimal* i = new WrongCat()" << std::endl;
    const WrongAnimal* i = new WrongCat();
    
    // getType() は正しく WrongCat のものを呼び出す（virtual でなくても）
    // ...もし getType() も virtual にしていなければ、これも WrongAnimal になる
    // ここでは getType() は virtual だったと仮定して進めます。
    std::cout << "-> Type: " << i->getType() << " " << std::endl; 

    // 3. makeSound() の呼び出し
    std::cout << "-> Sound (EXPECTING WrongAnimal's sound): ";
    
    // ★ ここがポイント ★
    // i は WrongAnimal* 型なので、makeSound() が virtual でない場合、
    // コンパイラは WrongAnimal::makeSound() を呼び出します。
    i->makeSound(); // 

    // 4. 比較用: 派生クラスのポインタで派生クラスのオブジェクトを指す
    std::cout << "\n[3] Creating WrongCat* j = new WrongCat() (for comparison)" << std::endl;
    const WrongCat* j = new WrongCat();
    std::cout << "-> Type: " << j->getType() << " " << std::endl;
    std::cout << "-> Sound (EXPECTING WrongCat's sound): ";
    j->makeSound(); // これは j が WrongCat* 型なので、WrongCat のサウンドが呼ばれる

    std::cout << "\n========== Cleanup ==========" << std::endl;
    delete meta;
    delete i;
    delete j;

    return 0;
}
