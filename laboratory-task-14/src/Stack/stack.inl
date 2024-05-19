#include "stack.hpp"

template <typename T>
bool Stack<T>::isEmpty()
{
    return topIndex == -1;
}

template <typename T>
void Stack<T>::resize()
{
    this->capacity *= 2;
    T* tempStack = new T[this->capacity];
    for (size_t i = 0; i <= this->topIndex; ++i) {
        tempStack[i] = stack[i];
    }
    delete[] stack;
    stack = tempStack;
}

template <typename T>
Stack<T>::Stack() : capacity(10), topIndex(-1)
{
    stack = new T[capacity];
}

template<typename T>
Stack<T>::Stack(const Stack& src) : capacity(src.capacity), topIndex(src.topIndex)
{
    stack = new T[capacity];
    for (size_t i = 0; i <= topIndex; ++i) {
        stack[i] = src.stack[i];
    }
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] this->stack;
}

template<>
Stack<char*>::~Stack()
{
    if (!this->isEmpty()) {
        delete[] this->stack[this->topIndex--];
    }
    delete[] this->stack;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& src) 
{
    if (this != &src) {
        delete[] this->stack;
        this->capacity = src.capacity;
        this->topIndex = src.topIndex;
        this->stack = new T[this->capacity];
        for (size_t i = 0; i <= this->topIndex; ++i) {
            this->stack[i] = src.stack[i];
        }
    }
    return *this;
}

template <typename T>
T& Stack<T>::operator[](size_t index)
{
    if (index < 0 || index > topIndex) {
        throw std::out_of_range("Index out of range");
    }
    return stack[index];
}

template <typename T>
void Stack<T>::push(const T& element)
{
    if (topIndex == -1) {
        stack[++topIndex] = element;
    }
    else {
        if (topIndex >= (capacity - 1)) {
            this->resize();
        } 
        stack[++topIndex] = element;
    }
}

template <typename T>
T Stack<T>::pop()
{
    if (this->isEmpty()) {
        throw std::runtime_error("Stack is Empty");
    }
    return this->stack[this->topIndex--];
}

template <typename T>
T& Stack<T>::top()
{
    if (this->isEmpty()) {
        throw std::runtime_error("Stack is Empty");
    }
    return this->stack[this->topIndex];
}

template <typename T>
void Stack<T>::print()
{
    for (size_t i = 0; i <= this->topIndex; ++i) {
        std::cout << i << "." << this->stack[i] << " ";
    }
    std::cout << std::endl;
}
