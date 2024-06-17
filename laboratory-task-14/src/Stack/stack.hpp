#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>
#include <stdexcept>


template <typename T>
class Stack {
private:
    T* stack;
    size_t capacity;
    int32_t topIndex;
    void resize();
public:
    Stack();
    Stack(const Stack&);
    ~Stack();

    Stack& operator=(const Stack&);

    T& operator[](size_t);

    void push(const T&);
    T pop();

    T& top();
    void print();
    
    bool isEmpty();
};

#include "stack.inl"
#endif //STACK_HPP
