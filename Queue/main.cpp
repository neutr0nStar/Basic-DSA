#include <iostream>
#include "arrayCircularQueue.hpp"
#include "linkedListQueue.hpp"
using namespace std;

int main() {
    // ArrayCircularQueue<int> acq(5);

    // acq.enqueue(1);
    // acq.enqueue(2);
    // acq.enqueue(3);
    // acq.enqueue(4);
    // acq.enqueue(5);

    // acq.print_queue();

    // acq.dequeue();
    // acq.dequeue();
    // acq.dequeue();

    // acq.print_queue();

    // acq.dequeue();

    // acq.enqueue(6);
    // acq.enqueue(7);
    // acq.enqueue(8);

    // acq.print_queue();


    LinkedListQueue<int> llq;

    llq.enqueue(1);
    llq.enqueue(2);
    llq.enqueue(3);
    llq.enqueue(4);
    llq.enqueue(5);

    llq.print_queue();

    llq.dequeue();
    llq.dequeue();
    llq.dequeue();

    llq.print_queue();

    llq.dequeue();

    llq.enqueue(6);
    llq.enqueue(7);
    llq.enqueue(8);

    llq.print_queue();
    
    return 0;
}