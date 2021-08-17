#include <iostream>
#include "linkedListStack.hpp"
using namespace std;

/**
 * This program reverses a linked list using stack
 * we will push pointers to node of a linked list in stack
 * then, we will pop those, and assign head to topmost element of stack
 * this will be last element of original linked list (because of LIFO nature of stack)
 * than traverse, and set next element from stack, reversing the linked list
 */

// Node of the stack, data will be of int data type
struct Node {
    int data;
    Node* next;
}*head; // global head pointer

// Function to insert new node with give data at the beginnig of linked list
void insert_beg(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->next = head;
    head = temp;
}

// Function to print the linked list
void print_list(void) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {

    head = nullptr; // setting head pointer to null, empty list
    Node* temp; // temporary variable 
    
    // Insert 3 elements in list
    insert_beg(3);
    insert_beg(2);
    insert_beg(1);

    // Now list will be: 1 2 3
    cout << "List initially: ";
    print_list();

    // Stack to perform reverse operations
    LinkedListStack<Node* > stack;

    // Put the pointer to nodes in stack, starting from head
    temp = head;
    while(temp) {
        stack.push(temp);
        temp = temp->next;
    }

    // Now, we will start reversing the list
    // first, we will get the topmost element of stack (which is last element of list)
    // and asign head to it, then pop it from stack
    temp = stack.get_top();
    head = temp;
    stack.pop();

    // then loop through stack, till it's empty
    // set the topmost element to temp's next element, then pop it
    // then set the temp to next 
    while(!stack.is_empty()) {
        temp->next = stack.get_top();
        stack.pop();
        temp = temp->next;
    }
    // at last, the last element will point to second last element, forming a loop, to prevent this
    // set last element's next to null
    temp->next = nullptr;

    cout << "List after reversing: ";
    print_list();

    return 0;
}