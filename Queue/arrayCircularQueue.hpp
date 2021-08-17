#include <iostream>

#ifndef ARRAY_CIRCULAR_QUEUE_H
#define ARRAY_CIRCULAR_QUEUE_H

/**
 * Queue is a FIFO strucutre
 * this is the circular array implementation of queue
 * this is circular because once dequeued, we wont be able to use those parts of array
 * to overcome this, we form a loop
 * All queue operations have O(1) time complexity
 */

template <class T>
class ArrayCircularQueue {
    private:
        int front, rear; // front and rear of queue
        T *array; // array to store elements
        const size_t array_size; // size of array

    public:
        // Constructor
        // @param: constant size of array
        ArrayCircularQueue(const size_t size): array_size(size) {
            front = -1;
            rear = -1;
            array = new T[array_size];
        }

        // Check if queue is empty or not
        bool is_empty(void) {
            if(front == -1 && rear == -1) return true;
            return false;
        }

        // Add an element to rear of queue, also known as push
        // @param: data to be enqueued
        void enqueue(const T data) {
            if((rear+1) % array_size == front) {
                // If array is full
                std::cerr << "Error: queue is full" << std::endl;
            }else if(is_empty()) {
                // If array is empty
                front = 0;
                rear = 0;
                array[rear] = data;
            }else{
                // else increment rear, and assign data to array[rear] 
                rear = (rear+1) % array_size;
                array[rear] = data;
            }
        }

        // Dequeue an element from front, also known as pop
        void dequeue(void) {
            if(is_empty()) {
                std::cerr << "Error: queue is empty." << std::endl;
                return;
            }else if(front == rear) {
                front = -1;
                rear = -1;
            }else{
                front = (front+1) % array_size;
            }
        }

        // Get the topmos element
        T peek(void) {
            return array[rear];
        }

        // Utility function print
        void print_queue(void) {
            if(front == rear) {
                if(is_empty()) {
                    std::cerr << "Error: queue is empty." << std::endl;
                }else{
                    std::cout << array[rear] << std::endl;
                }
            }else if(front > rear) {
                for( int i = front; i < array_size; i++) {
                    std::cout << array[i] << " ";
                }
                for( int i = 0; i <= rear; i++) {
                    std::cout << array[i] << " ";
                }
                std::cout << std::endl;
            }else{
                for(int i = front; i <= rear; i++) {
                    std::cout << array[i] << " ";
                }
                std::cout << std::endl;
            }
        }
};

#endif