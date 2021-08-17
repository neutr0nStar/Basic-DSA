#include <iostream>
#include "circularLinkedList.hpp"
using namespace std;

int main() {

    CircularLinkedList<int> cll;

    cll.insert_end(1);
    cll.insert_end(2);
    cll.insert_end(3);
    cll.insert_end(4);

    cll.print();

    return 0;
}