#include <iostream>
#include "linkedListStack.hpp"
using namespace std;

/**
 * This program check if the brackets are balanced in the expression
 * this program checks for paranthesis '(', square brackets '[' and curly braces '{'
 * this program uses stack for checking
 * if it's a opening bracket, its pushed in the stack
 * if a closing bracket is encountered, first it's checked if stack is empty or not
 * it it's not empty, check if top is matching pair of that closing bracket '(' -> ')'
 * if not, it's not balanced
 * at last, check if stack is empty (no extra openning brackets are there)
 */

// Check whether exp is balanced or not
// @param: exp (the string to be checked for balancing)
bool is_balanced(string exp) {
    char c; // temporary character
    LinkedListStack<char> stack; // stack

    // iterate through characters of string
    for(int i = 0; i < exp.length(); i++) {
        c = exp[i];
        switch (c)
        {
        case '(':
        case '[':
        case '{':
            // if opening bracket, push in stack
            stack.push(c);
            break;
        case ')':
            // first check if stack is not empty, else get_top() will not return anything
            // check if top is '('
            // if yes pop it
            // else return false
            if(!stack.is_empty() && stack.get_top() == '(') { // if first expression is false, compiler doesn't evaluate second expression
                stack.pop();
            }else{
                return false;
            }
            break;
        case ']':
            // first check if stack is not empty, else get_top() will not return anything
            // check if top is '['
            // if yes pop it
            // else return false
            if(!stack.is_empty() && stack.get_top() == '[') {
                stack.pop();
            }else{
                return false;
            }
            break;
        case '}':
            // first check if stack is not empty, else get_top() will not return anything
            // check if top is '{'
            // if yes pop it
            // else return false
            if(!stack.is_empty() && stack.get_top() == '{') {
                stack.pop();
            }else{
                return false;
            }
            break;
        default:
            // Ignore any other character
            break;
        }
    }
    // If we have reached here, it means that there were no mismatches
    // now we return true if stack is empty (no remaining openning brackets) 
    return stack.is_empty(); // this will return true if stack empty and false if it's not empty
}

// Main function
int main() {

    string exp;
    cout << "Enter expresion to be checked for balancing: ";
    cin >> exp;

    if(is_balanced(exp)) {
        cout << "Expression is balanced." << endl;
    }else{
        cout << "Expression is not balanced." << endl;
    }

    return 0;
}