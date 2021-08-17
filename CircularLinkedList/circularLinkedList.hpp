#include <iostream>

#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

/**
 * Circular linked lists are just linked lists whose end node point to head instead of null;
 */

template <class T>
class CircularLinkedList {
    private:
    // Structure for Linked list node
    struct Node {
        T data;
        Node* next;
    } *head; // head pointer

    // Get new node
    // @param data: data of new node

    public:
    // Constructor
    CircularLinkedList() {
        head = nullptr;
    }

    // Insert new node at beginnig
    // @param data: data of node to be inserted
    void insert_beg(T data) {
        Node* temp = new Node();
        temp->data = data;
        if(head) {
            temp->next = head;
        }
        head = temp;
    }

    // Insert new node at end
    // @param data: data of node to be inserted
    void insert_end(T data) {
        Node* temp = new Node();
        temp->data = data;
        if(!head) {
            head = temp;
            temp->next = head;
        }else{
            Node *temptr = head;
            while(temptr->next != head) temptr = temptr->next;
            temp->next = head;
            temptr->next = temp;
        }
    }

    // Print the circular linked list
    void print(void) {
        if(!head) {
            std::cerr << "Error: list is empty." << std::endl;
            return;
        }
        Node* temp = head;
        do{
            std::cout << temp->data << " ";
            temp = temp->next;
        }while(temp != head);
        std::cout << std::endl;
    }
};

#endif