#include <iostream>

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

template <class T>
class DoublyLinkedList {
    private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
    }*head;

    // Create a new node, initialize next and prev to nullptr
    Node* get_new_node(T data) {
        Node* temp = new Node();
        temp->data = data;
        temp->next = nullptr;
        temp->prev = nullptr;
        return temp;
    }

    public:
    // Constructor
    DoublyLinkedList() { head = nullptr; }

    // Print the list
    void print_list(void) {
        if(!head) {
            std::cout << "List is empty" << std::endl;
        }else{
            Node* temp = head;
            while(temp) {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
    }

    // Print in reverse order, using prev
    void print_rev(void) {
        if(!head) {
            std::cout << "List is empty" << std::endl;
        }else{
            Node* temp = head;
            while(temp->next) temp = temp->next;
            while(temp) {
                std::cout << temp->data << " ";
                temp = temp->prev;
            }
            std::cout << std::endl;
        }
    }

    // Insert node at the beginning
    void insert_beg(T data) {
        Node* new_node = get_new_node(data);
        if(head) {
            head->prev = new_node;
            new_node->next = head;
            head = new_node;
        }else{
            head = new_node;
        }
    }

    // Insert node at the end
    void insert_end(T data) {
        Node* new_node = get_new_node(data);
        Node* temp = head;
        if(head) {
            while(temp->next) temp = temp->next;
            new_node->prev = temp;
            temp->next = new_node;
        }else{
            head = new_node;
        }
    }
};

#endif
