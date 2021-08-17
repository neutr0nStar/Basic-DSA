#include <iostream>
#include "doublyLinkedList.hpp"
using namespace std;

int main() {
    DoublyLinkedList<int> dll;

    dll.insert_beg(1);
    dll.insert_beg(2);
    dll.insert_beg(3);
    dll.insert_end(4);

    dll.print_list();
    
    dll.print_rev();

    return 0;   
}