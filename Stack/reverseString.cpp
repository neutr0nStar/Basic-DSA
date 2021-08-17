#include <iostream>
#include "arrayStack.hpp"
using namespace std;

/**
 * This program reverses string using stack
 * we will push string characters to stack
 * then, when we will pop them, when we pop them, they will come out in revese order
 * this is due to LIFO nature of stack
 */

int main() {
    string str;

    cout << "Enter string to be reversed (one word) : ";
    cin >> str;

    size_t string_length = str.length(); // Length of string

    ArrayStack<char> stack(string_length); // Stack to store characters of string

    // push to stack
    for(int i = 0; i < string_length; i++ ) {
        stack.push(str[i]);
    }

    // pop from stack
    for(int i = 0; i < string_length; i++ ) {
        str[i] = stack.get_top();
        stack.pop();
    }
    cout << "Reversed string: " << str << endl;
}