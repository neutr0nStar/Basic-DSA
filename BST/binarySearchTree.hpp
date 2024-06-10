#include <iostream>
#include "../Queue/linkedListQueue.hpp"

#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

/**
 * A binary search tree is a tree data structure
 * as it's binary tree, every node will have at max 2 children
 * and bst has a special property such that element to the left
 * of a node will be less than or equal to the node, and to 
 * right of the node will be greater than the node
 * this apply recursively.
 * Here, we use recursion extensivly
 * this is beacuse each sub tree must also be a bst.
 */

template <class T>
class BinarySearchTree {
    private:
    struct BstNode { // Structure of node of BST
        T data;
        BstNode* left;
        BstNode* right;
    } *root ; // pointer to root of tree

    // Create new node
    // @param: data of new node
    BstNode* get_new_node(T data) {
        // Create new node with given data
        // and initialize left and right pointers
        // to null pointer
        BstNode* temp = new BstNode();
        temp->data = data;
        temp->left = temp->right = nullptr;
        return temp;
    }

    // Recursive function for insert
    // @param: pointer to root
    // @param: data to be inserted
    BstNode* rec_ins(BstNode* rootptr, T data) {
        // Insert new node using recurion
        // if root is null pointer for given root,
        // root will point to new node
        // if root not null, 
        //   if data <= root's data: root's left will become new root, and this function will be called
        //   else: root's right will become new root, and this function will be called

        if(!rootptr) { // tree is empty for this root
            rootptr = get_new_node(data);
        }else if(data <= rootptr->data){
            rootptr->left = rec_ins(rootptr->left, data);
        }else{
            rootptr->right = rec_ins(rootptr->right, data);
        }
        return rootptr;
    }

    // ================================================================= //
    // All the recursive functions here are used in public function below
    // ================================================================= //

    // Recursive function for searching
    // @param: pointer to root
    // @param: key to search for
    bool rec_search(BstNode* rootptr, T key) {
        // This function is similar to insertion using recursion
        if(!rootptr) return false; // tree with this root is empty
        else if(rootptr->data == key) return true; // if key is the data of root
        else if(key <= rootptr->data) return rec_search(rootptr->left, key);
        else return rec_search(rootptr->right, key);
    }

    // Recursive function for finding height
    // @param: node to find height of 
    int rec_height(BstNode* node){
        // See notes.md for info about height
        if(!node) return -1; // returning -1 as to avoid counting of a path to a node that doesn't exist
        int left_height = rec_height(node->left);
        int right_height = rec_height(node->right);
        return 1 + (left_height > right_height ? left_height : right_height); // +1 for the path used to come to this node
    }

    // Recursive function for preorder traversal
    // @param: root pointer of tree/subtree
    void rec_preorder(BstNode* rootptr) {
        if(!rootptr) return;
        std::cout << rootptr->data << " ";
        rec_preorder(rootptr->left);
        rec_preorder(rootptr->right);
    }

    // Recursive function for inorder traversal
    // @param: root pointer of tree/subtree
    void rec_inorder(BstNode* rootptr) {
        if(!rootptr) return;
        rec_inorder(rootptr->left);
        std::cout << rootptr->data << " ";
        rec_inorder(rootptr->right);
    }

    // Recursive function for postorder traversal
    // @param: root pointer of tree/subtree
    void rec_postorder(BstNode* rootptr) {
        if(!rootptr) return;
        rec_postorder(rootptr->left);
        rec_postorder(rootptr->right);
        std::cout << rootptr->data << " ";
    }

    // Recursive function to delete a node
    // @param: root pointer
    // @param: key to be deleted
    BstNode* rec_del(BstNode* rootptr, T key) {
        // Three cases are possible for the node to be deleted
        // if it's leaf node, it'll have no children
        // we can simply delete it, and set pointer to null
        // other 2 cases are shown below
        if(!rootptr) return rootptr;
        else if(key < rootptr->data) rootptr->left = rec_del(rootptr->left, key);
        else if(key > rootptr->data) rootptr->right = rec_del(rootptr->right, key);
        else { // Node with given key is found
            // Case 1: no child (leaf node)
            if(rootptr->left == nullptr && rootptr->right == nullptr) {
                delete rootptr; // now rootptr has become dangling pointer
                rootptr = nullptr;
            }
            // Case 2: one child 
            else if(rootptr->left == nullptr){
                // if right node exists
                // point current node's pointer to right node's
                // and delete current node
                BstNode* temp = rootptr;
                rootptr = rootptr->right;
                delete temp;
            }
            else if(rootptr->right == nullptr){
                // if left node exists
                // point current node's pointer to left node's
                // and delete current node
                BstNode* temp = rootptr;
                rootptr = rootptr->left;
                delete temp;
            }
            // Case 3: two children
            else{
                // Here, we will find minimum element from the right side of the subtree to this rootptr (say rmin)
                // then we will change the current node's value to the value of rmin
                // then delete rmin from right side subtree
                // We can also do this with left side using maximum element.
                BstNode* parent = rootptr, *child = rootptr->right;
                while (child->left) {
                    parent = child;
                    child = child->left;
                }
                rootptr->data = child->data;
                if(parent->left == child) {
                    parent->left = child->right;
                } else {
                    parent->right = child->right;
                }
                delete child;
            }
        }
        return rootptr; 
    }


    public:
    // Constructor
    BinarySearchTree(void) { root = nullptr; } // initiate root to null pointer, -> tree is empty

    // Insert new element
    // @param: data to be inserted
    void insert(T data) {
        // use recursive function, passing tree's root as root pointer
        root = rec_ins(root, data);
    }

    // Search
    // @param: key to be searched
    bool search(T key) {
        // use recursive function, passing tree's root as root pointer
        return rec_search(root, key);
    }

    // Find minimum element
    T find_min(void) {
        if(!root) { // if tree is empty
            std::cerr << "Error: Tree is empty." << std::endl;
            return T();
        }
        BstNode* temp = root;
        while(temp->left) temp = temp->left;
        return temp->data;
    }

    // Find maximum element
    T find_max(void) {
        if(!root) { // if tree is empty
            std::cerr << "Error: Tree is empty." << std::endl;
            return T();
        }
        BstNode* temp = root;
        while(temp->right) temp = temp->right;
        return temp->data;
    }

    // Height of tree
    int height(void) {
        // See notes.md for info
        return rec_height(root);
    }

    // Breadth first or Lever order traversal
    void print_breadth_first(void) {
        // We traverse tree level by level
        // to keep track of nodes, we use a queue
        // We print each node's data, and enqueue (push) 
        // the left and right nodes to the queue, then dequeue (pop) this node
        // repeat this process
        if(!root) { // if tree is empty
            std::cerr << "Error: Tree is empty." << std::endl;
            return;
        }
        LinkedListQueue<BstNode*> queue;
        BstNode* temp;
        queue.enqueue(root);
        while(!queue.is_empty()) {
            temp = queue.peek();
            std::cout << temp->data << " ";
            if(temp->left) queue.enqueue(temp->left);
            if(temp->right) queue.enqueue(temp->right);
            queue.dequeue();
        }
        std::cout << std::endl;
    }
    
    // enum for order of depth first traversal
    enum class Order { 
        PREORDER, // <root> <left> <right>
        INORDER,  // <left> <root> <right>
        POSTORDER // <left> <right> <root>
    };

    // Depth first traversal
    void print_depth_first(Order order = Order::INORDER) { // order is inorder by default
        if(!root) {
            std::cerr << "Error: Tree is empty." << std::endl;
            return;
        }
        switch(order) {
            case Order::PREORDER:
                rec_preorder(root);
                break;
            case Order::INORDER:
                rec_inorder(root);
                break;
            case Order::POSTORDER:
                rec_postorder(root);
                break;
            default:
                break;
        }
        std::cout << std::endl;
    }

    void del(T key) {
        // Pass root as rootptr to rec_del function
        root = rec_del(root, key);
    }

};

#endif