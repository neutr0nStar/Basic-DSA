#include <iostream>
#include "binarySearchTree.hpp"
using namespace std;

int main() {

    BinarySearchTree<int> bst;

    bst.insert(15);
    bst.insert(10);
    bst.insert(20);
    bst.insert(25);
    bst.insert(8);
    bst.insert(2);
    bst.insert(9);

    cout << "Breadth first traversal: " ;        bst.print_breadth_first();
    cout << "Depth first traversal preorder " ;  bst.print_depth_first(BinarySearchTree<int>::Order::PREORDER);
    cout << "Depth first traversal inorder " ;   bst.print_depth_first(BinarySearchTree<int>::Order::INORDER);
    cout << "Depth first traversal postorder " ; bst.print_depth_first(BinarySearchTree<int>::Order::POSTORDER);

    int f = 15;
    if(bst.search(f))
        cout << "Found " << f << endl;
    else
        cout << f << " not found" << endl;

    cout << "Min element: " << bst.find_min() << endl;
    cout << "Max element: " << bst.find_max() << endl;

    cout << "Height: " << bst.height() << endl;

    bst.del(8);
    bst.print_breadth_first();

    return 0;
}