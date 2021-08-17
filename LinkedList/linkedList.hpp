#include<iostream>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

template<class T>

class LinkedList {
    
    private:
    // Structure for Nodes of linked list
    struct Node {
        T data;
        Node* next;
    }*head; // Head pointer 

    // Child function for printing recursively
    // @param p: node pointer of current node
    void print_rec_child_fun(Node* p) {
        // recursively traverse through nodes until null is encountered
        // print the data of current node
        // then call this function for next node 
        if(!p) {
            // base case
            // if null, print endline
            std::cout << std::endl;
            return;
        }
        std::cout << p->data << " "; // move this line below next one to print list in reverse order recursivelly
        print_rec_child_fun(p->next);
    }

    // Reverse list child function
    // @param p: node pointer of current node
    void reverse_rec_child_function(Node* p) {
        // go to next node until next node is null
        // if next node is null, set head to point to this node
        // else, after returning, point the next node's next to current
        // and current node's next to null
        // repeat till first node's next becomes null, list is reversed
        if(!p->next) {
            head = p;
        }else{
            reverse_rec_child_function(p->next);
            Node* nex = p->next;
            nex->next = p;
            p->next = nullptr;
        }
    }


    public:
    // Constructor
    LinkedList() { head = nullptr; }; // Initialize head to null, denoting list is empty

    // Print linked list
    void print_list(void) {
        if(!head){ // If head is null, list is empty
            std::cout << "List is empty!\n";
        }else{
            // print data of each node starting from head
            // move to next node untill next node is null
            // repeat 
            Node* temp_ptr = head;
            while(temp_ptr) { // while temporary pointer is not null
                std::cout << temp_ptr->data << " ";
                temp_ptr = temp_ptr->next;
            }
        }
        std::cout << std::endl;
    }

    // Insert element at the beginning
    // @param data: data of the node of type T
    void insert_beg(const T data) {
        // make new node
        // set next of new node to point at where head is pointing
        // point head to new node
        Node* temp = new Node();
        temp->next = head; // If head is null (list is empty), this will automatically assign next of new node to null
        temp->data = data;
        head = temp;
    }

    // Insert element at the end
    // @param data: data of the node of type T
    void insert_end(const T data) {
        // find the last node (next node of that node will be null)
        // change next pointer of last node to new node
        Node* temp = new Node();
        temp->next = nullptr;
        temp->data = data;
        Node* temp_ptr = head;
        if(head) {
            while(temp_ptr->next) temp_ptr = temp_ptr->next;
            temp_ptr->next = temp;
        }else{ // if head is null, the new node will become the first node
            head = temp;
        }
    }

    // Insert node at a specific location (pos, position is zero indexed)
    // @param data: data to be inserted
    // @param pos: position at which node is to be inserter
    void insert_at_pos(const T data, const int pos) {
        // make new temporary node with given data
        // find node that comes just before that position (we will call it prev)
        // make the new node's next point to the prev's next node
        // make prev's next point to new node
        if(pos < 0){
            std::cerr << "Negative index not allowed!" << std::endl;
        }else if(pos == 0) { 
            insert_beg(data); // For first position, insert at the beginning 
        }else{
            Node* temp = new Node();
            temp->data = data;
            Node* prev_ptr = head;
            for( int i = 0; i < pos-1; i++) { // Find node just before the position where new node is to be inserted
                prev_ptr = prev_ptr->next;
                if(prev_ptr == nullptr) {
                    std::cerr << "Index out of bounds!" << std::endl;
                    return;
                }
            }
            temp->next = prev_ptr->next;
            prev_ptr->next = temp;
        }
    }

    // Delete node at specified position (position is zero indexed)
    // @param position: position at which element is to be deleted
    void delete_at_pos(const int pos) {
        // find the node that comes just before the position to be deleted (we will call it prev)
        // let the node to be deleted (at position pos) be curr
        // point prev's next to curr's next
        // delete curr
        if(pos < 0){
            std::cerr << "Negative index not allowed!" << std::endl; 
        }else if( pos == 0 ) {
            Node* temp_ptr = head;
            head = head->next; // If position is zero, point head to next node
            delete temp_ptr;
        }else{
            Node* prev_ptr = head;
            for( int i = 0; i < pos-1; i++ ){
                prev_ptr = prev_ptr->next;
                if(prev_ptr == nullptr || prev_ptr->next == nullptr) { // Second condition checks if node to be deleted exists or not
                    std::cerr << "Index out of bounds!" << std::endl;
                    return;
                }
            }
            Node* temp = prev_ptr->next;
            prev_ptr->next = temp->next;
            delete temp;
        }
    }

    // Print linked list recursively
    void print_rec(void) {
        // Call the print recursively child function with head as starting point
        print_rec_child_fun(head);
    }

    
    // Reverse linked list iteratively
    void reverse_iterative(void) {
        // curr is the current node
        // nex store next node of current node
        // prev is the previous node to current node
        // curr's next node is set to prev node
        // prev then points to current node
        // curr then points to next node
        // at last, head will point to last node, which will be prev
        Node *curr, *prev, *nex;
        prev = nullptr;
        curr = head;
        while(curr) {
            nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        head = prev;
    }

    // Reverse the list using recursion
    void reverse_rec(void) {
        // call reverse recursively child function with head as starting point
        reverse_rec_child_function(head);
    }

    // Get the size of linked list
    int get_size(void) {
        // if head is null, size is zero
        // else iterate through list, and get size;
        if(head) {
            int s = 0;
            Node* temp = head;
            while(temp) {
                s++;
                temp = temp->next;
            }
            return s;
        }
        return 0;
    }

    // [] operator overloading
    // @param index: index of element
    T& operator[](size_t index) {
        // check if index is valid
        // if yes, return element at that index
        // else print error to cerr
        if(get_size() == 0) {
            std::cerr << "Error: List is empty." << std::endl;
        }
        if(index >= get_size() || index < 0) {
            std::cerr << "Error: Invalid index." << std::endl;
        }
        Node* temp = head;
        for(int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    // Swap 2 elements by key
    // @param k1: key 1
    // @param k2: key 2
    void swap(T k1, T k2) {
        // we will find nodes with keys k1 (say x) and k2 (say y)
        // and their previous nodes (prevx and prevy)
        // if prev is not null (not head), set prevx's next to y and set prevy's next to x

        // if k1 and k2 are same, no need to swap
        if(k1==k2) return;

        // Find node (say x) with k1 key, and keep track of it's previous node as well
        Node *prevx = nullptr, *currx = head;
        while(currx && currx->data != k1) {
            prevx =  currx;
            currx = currx->next;
        }

        // Find node (say y) with k2 key, and keep track of it's previous node as well
        Node* prevy = nullptr, *curry = head;
        while(curry && curry->data != k2) {
            prevy =  curry;
            curry = curry->next;
        }

        // if currx is not head, then set prevx's next to curry
        if(prevx) {
            prevx->next = curry;
        }else{
            head = curry;
        }

        // if curry is not head, then set prevy's next to currx
        if(prevy) {
            prevy->next = currx;
        }else{
            head = currx;
        }

        Node* temp = curry->next;
        curry->next = currx->next;
        currx->next = temp;
    }
};   

#endif