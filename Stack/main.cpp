#include <iostream>
#include "arrayStack.hpp"
#include "linkedListStack.hpp"
using namespace std;

int main() {

    /**
     * Operations for array stack
     */

    // ArrayStack<int> as(10);

    // as.push(1);
    // as.push(2);
    // as.push(3);

    // as.print_stack();

    // as.pop();

    // as.print_stack();

    // cout << as.get_top() << endl;

    // cout << endl << endl;
    /**
     * Operations for linked list stack
     */

    LinkedListStack<int> lls;
    
    lls.push(1);
    lls.push(2);
    lls.push(3);

    lls.print_stack();

    lls.pop();

    cout << lls.get_top() << endl;

    cout << lls.is_empty() << endl;
    

    return 0;
}