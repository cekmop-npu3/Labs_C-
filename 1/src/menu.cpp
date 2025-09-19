#include "menu.hpp"
#include "array.hpp"


void menu(){
    Choice choice;
    Array array1{};
    Array array2{};
    Array array3;
    while (true){
        std::cout << "1. append to the first Array\n"
                     "2. append to the second Array\n"
                     "3. print the first Array\n"
                     "4. print the second Array\n"
                     "5. subtract the first Array from the second one\n"
                     "6. exit\n";
        choice = (Choice) input<int>(">> ", "Wrong input, try again");  
        switch (choice) {
            case Append1:
                array1.append(input<char>("Enter one char: ", "Error, try again\n"));
                break;
            case Append2:
                array2.append(input<char>("Enter one char: ", "Error, try again\n"));
                break;
            case Print1:
                array1.print();
                break;
            case Print2:
                array2.print();
                break;
            case Sub:
                array3 = array1 - array2;
                std::cout << "result Array: ";
                array3.print();
                break;
            case Exit:
                return;
        }
    }
}
