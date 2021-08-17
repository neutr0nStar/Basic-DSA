#include <iostream>
#include "../LinkedList/linkedList.hpp"

#ifndef LINKED_LIST_STACK_H
#define LINKED_LIST_STACK_H

/**
 * Stack is a LIFO structure
 * Methods:
 *  - push(data): push new data at the top
 *  - pop(): remove topmost element
 *  - get_top(): get the topmost element
 */

template<class T>
class LinkedListStack{
    private:
    // linked list as stack
    LinkedList<T> stack;

    public:

    // Push new element to stack
    void push(T data) {
        // push operations pushes to the beginnig of the linked list, which will be the first element
        stack.insert_beg(data);
    }

    // Pop the topmost element if it exists
    void pop(void) {
        // pop deletes first element
        if(stack.get_size() == 0) {
            std::cerr << "Error: stack underflow." << std::endl;
        }else{
            stack.delete_at_pos(0);
        }
    }

    // Return the topmost element
    T get_top(void) {
        return stack[0];
    }

    // Check if stack is empty
    bool is_empty(void) {
        if(stack.get_size() == 0) return true;
        return false;
    }

    // Print the stack
    void print_stack(void) {
        stack.print_list();
    }
};

#endif