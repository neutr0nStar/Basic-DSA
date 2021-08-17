#include <iostream>
#include "linkedList.hpp"
using namespace std;

int main() {
    LinkedList<int> ll;
    
    ll.insert_beg(1);
    ll.insert_beg(2);
    ll.insert_end(3);

    ll.insert_end(4);

    ll.insert_at_pos(5, 1);

    ll.print_list();
    
    cout << ll.get_size() << endl;

    ll.delete_at_pos(3);

    ll.print_rec();
    
    ll.reverse_rec();

    ll.print_list();

    cout << ll[2] << endl;

    ll.swap(1, 4);

    ll.print_list();

    return 0;
}