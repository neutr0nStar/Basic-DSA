#include <iostream>
using namespace std;

/**
 * This program checks if a binary tree is a BST
 * Again, we will be using recursion here
 * we will recursively visit all elements, and check whether they lie in some range
 * for root, it will be -inf to +inf
 * for left of root, it'll be -inf to root's data (only upper limit will change)
 * for right of root, it'll be root's data to +inf (only lower limit will change)
 * now we will call this function on left and right subtree.
 */

/**
 * This can also be done by traversing inorder
 * if the result is a sorted array, the tree is BST
 */

// Structure for node of tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* root; // pointer to root of tree

// Create a new node
Node* get_new_node(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

// Recursive function to evaluate nodes of bst
bool rec_is_bst(Node* root, int min_value, int max_value) {
    if(!root) return true;
    if(root->data >= min_value 
        && root->data < max_value 
        && rec_is_bst(root->left, min_value, root->data)
        && rec_is_bst(root->right, root->data, max_value))
        return true;
    else
        return false;
}

// check for bst
bool is_bst(Node* root) {
    return rec_is_bst(root, INT_MIN, INT_MAX); // min value: -inf, max value: +inf
}

int main() {
    // Create a tree
    root = nullptr;
    root = get_new_node(7);
    root->left = get_new_node(4);
    root->left->left = get_new_node(1);
    root->left->right = get_new_node(6);
    root->right = get_new_node(9);

    // Evaluate
    if(is_bst(root))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}