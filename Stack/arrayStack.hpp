#include <iostream>

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

/**
 * Stack is a LIFO structure
 * Methods:
 *  - push(data): push new data at the top
 *  - pop(): remove topmost element
 *  - get_top(): get the topmost element
 */

template <class T>
class ArrayStack{
    private:
    const size_t size; // size of the stack (array)
    T* arr; // actual array that will store elements of stack
    int top; // variable to keep track of top

    public:
    // Constructor
    // @param: size of stack
    ArrayStack(const size_t size) : size(size) {
        arr = new T[size];
        top = -1;
    }
    
    // Push
    // @param: data 
    void push(T data) {
        if(top == size - 1) {
            std::cerr << "Error: stack overflow." << std::endl;
        }else{
            arr[++top] = data;
        }
    }

    // Pop
    void pop(void) {
        if( top == -1) {
            std::cerr << "Error: stack underflow." << std::endl;
        }else{
            top--;
        }
    }

    // Get the topmost element
    T get_top(void) {
        if(top == -1) {
            std::cerr << "Error: stack is empty." << std::endl;
            return T();
        }else{
            return arr[top];
        }
    }

    // Check if stack is empty
    bool is_empty(void) {
        // if top is -1, stack is empty
        if(top == -1) return true;
        return false;
    }

    // Print stack
    void print_stack(void) {
        if(top == -1) {
            std::cout << "Stack is empty." << std::endl;
        }else{
            for( int i = 0; i <= top; i++) {
                std::cout << arr[i] << " ";
            }
            std::cout << std::endl;
        }
    }

};

#endif