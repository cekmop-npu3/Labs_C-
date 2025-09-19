#include "array.hpp"
#include <algorithm>
#include <iostream>


Array::Array(int bufSize, int bufCount){
    this->data = new char[bufSize]{};
    this->bufSize = bufSize;
    this->bufCount = bufCount;
    this->len = 0;
}

Array::Array(const Array& other){
    if (this != &other){
        this->data = new char[other.bufSize * (other.len / other.bufSize + 1)]{};
        std::copy(other.data, other.data + other.len, this->data);
        this->bufSize = other.bufSize;
        this->bufCount = other.bufCount;
        this->len = other.len;
    }
}

Array& Array::operator=(const Array& other){
    if (this != &other){
        delete[] this->data;
        this->data = new char[other.bufSize * (other.len / other.bufSize + 1)]{};
        std::copy(other.data, other.data + other.len, this->data);
        this->bufSize = other.bufSize;
        this->bufCount = other.bufCount;
        this->len = other.len;
    }
    return *this;
}

Array::~Array(){
    delete[] this->data;
}

Array Array::operator-(const Array& other){
    Array result(this->bufSize, this->bufCount);
    int j;
    for (int i = 0; i < this->len; i++){
        for (j = 0; j < other.len; j++)
            if (this->data[i] == other.data[j])
                break;
        if (this->data[i] != other.data[j])
            result.append(this->data[i]);
    }
    return result;
}

Array& Array::operator-=(const Array& other){
    for (int i = 0; i < this->len; i++){
        for (int j = 0; j < other.len; j++)
            if (this->data[i] == other.data[j]){
                this->pop(i);
                break;
            }
    }
    return *this;
}

void Array::append(char data){
    if (this->len / this->bufSize == this->bufCount){
        std::cerr << "[ERROR] Memory block limit is reached\n";
        return;
    }
    if (!((this->len + 1) % this->bufSize) and (this->len + 1) / this->bufSize != this->bufCount){
        char *tmpData = new char[this->bufSize * ((this->len + 1) / this->bufSize + 1)]{};
        std::copy(this->data, this->data + this->len, tmpData);
        delete[] this->data;
        this->data = tmpData;
    }
    this->data[this->len++] = data;
}

char Array::pop(int index){
    while (index < 0)
        index = this->len + index;
    if (index > this->len - 1){
        std::cerr << "[ERROR] Array index out of range\n";
        return '\0';
    }
    char elem = this->data[index];
    for (int i = 0; i < this->len - 1; i++)
        this->data[i] = (i >= index ? this->data[i + 1] : this->data[i]);
    this->len--;
    return elem;
        
}

void Array::print(){
    std::cout << "[";
    for (int i = 0; i < this->len; i++)
        std::cout << this->data[i] << (i != this->len - 1 ? ", " : "");
    std::cout << "]\n";
}





