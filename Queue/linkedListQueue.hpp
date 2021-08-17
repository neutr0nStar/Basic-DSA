#include <iostream>

#ifndef LINKED_LIST_QUEUE_H
#define LINKED_LIST_QUEUE_H

/**
 * This is Linked list implementation of queue data structure
 * Queue is a FIFO data structure
 * front is pointing to beginning of linked list
 * rear is pointing to the last node of linked list
 * rear is required to perform enqueue in O(1) time complexity
 */

template <class T>
class LinkedListQueue{
    private:
        // Node structure for linked list
        struct Node {
            T data;
            Node* next;
        }*front, *rear; // front and rear pointer
    
    public:
        // Constructor
        LinkedListQueue() {
            // initialize front and rear to nullptr
            // denoting empty queue
            front = rear = nullptr;
        }

        // Create new node at rear
        void enqueue(T data) {
            Node* temp = new Node();
            temp->data = data;
            temp->next = nullptr;
            if(front == nullptr && rear == nullptr) {
                // if queue is empty, this new node will be the first element of queue
                front = rear = temp;
            }else{
                // else append this new element and make rear to point to it
                rear->next = temp;
                rear = temp;
            }
        }

        // Pop node from front 
        void dequeue(void) {
            if(front == nullptr) {
                std::cerr << "Error: queue is empty." << std::endl;
            }else if(front == rear){
                // if it's the only element, after dequeue, list will be empty
                front = rear = nullptr;
            }else{
                Node* temp = front;
                front = front->next;
                delete temp; // delete the first element, free the memory
            }
        }

        // Get the front element
        T peek(void) {
            return front->data;
        }

        // Check if queue is empty
        bool is_empty(void) {
            if(front == nullptr) return true; // if front is null, rear will also be null
            return false;
        }

        // utility function: print
        void print_queue(void) {
            if(front == nullptr) {
                std::cerr << "Queue is empty." << std::endl;
                return;
            }
            Node* temp = front;
            while(temp) {
                std::cout << temp->data << " ";
                temp = temp->next;
            }
            std::cout << std::endl;
        }
};

#endif