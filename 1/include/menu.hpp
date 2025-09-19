#ifndef __MENU_H__
#define __MENU_H__

#include <iostream>
#include <limits>


using String = std::string;

using Choice = enum {
    Append1 = 1,
    Append2,
    Print1,
    Print2,
    Sub,
    Exit
};


template<typename T>
T input(const std::string& message, const std::string& error){
    T data;
    while (true) {
        std::cout << message;
        std::cin >> data;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << error;
            continue;
        }
        if (std::cin.peek() != '\n') {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << error;
            continue;
        }
        std::cin.ignore();
        return data;
    }
}

void menu();


#endif
