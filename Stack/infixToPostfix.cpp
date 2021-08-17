#include <iostream>
#include "LinkedListStack.hpp"
using namespace std;

/**
 * Infix to prefix conversion using stack
 * Brackets have higest priority
 * Operator precedence: 
 *    '^' > '*', '/' > '+', '-'
 * associativity:
 *    '^': right to left
 *    else: left to right
 */

// checks if character is an operator
// @param: character c
bool is_operator(const char c) {
    char operators[5] = {'+', '-', '*', '/', '^'};
    for(int i = 0; i < 5; i++) if (c == operators[i]) return true;
    return false;
}

// check for valid operator [a-zA-Z0-9]
// @param: character c
bool is_operand(const char c) {
    if(c >= 'A' && c <= 'Z') return true;
    if(c >= 'a' && c <= 'z') return true;
    if(c >= '0' && c <= '9') return true;
    return false;
}

// operator precedence
// @param: character c
int get_operator_precedence(const char c) {
    switch(c) {
        case '+': 
        case '-':
            return 1; 
        case '*': 
        case '/':
            return 2; 
        case '^':
            return 3;
        default:
            return -1;
    }
}

// Function to convert infix to prefix
// @param: infix string
string infix_to_postfix(const string infix) {
    // We iterate throught all the characters of the string
    // and keep track of result using res string, and stack using stack variable
    // if current character is operand, it'll be directly appended to the res
    // if current character is '(', push it to the stack
    // if current character is ')', pop elements from stack and append to res until top of stack is '('
    // the also remove '(' from the top of stack
    // if current character is an operator, compare it's precedence with that of the top of stack
    // if precedence of current operator is greater than that of at the top of stack
    // push current operator to the top of stack
    // else keep popping from stack and appending to res until precedence of current character is lesser than
    // that of top of stack

    string res = "";
    char c;
    LinkedListStack<char> stack;

    for(int i = 0; i < infix.length(); i++) {
        c = infix[i];

        if(is_operand(c)) res += c; // If it's an operand, directly push it to the result string

        if(c == '(') stack.push(c); // If opening bracket, push it to stack

        if(c == ')') {
            // if opening bracket is encountered, pop elements from stack and
            // append to res until ')' is encountered
            while(!stack.is_empty() && stack.get_top() != '(') {
                res += stack.get_top();
                stack.pop();
            }
            stack.pop(); // remove the remaining '(' from stack
        }

        if(is_operator(c)) {
            // if operator, compare it with operator on top of stack
            // if precedence of current operator is equall to or lesser than that of on top of stack
            // append it to res, and pop from stack
            // repeat until   
            while(!stack.is_empty() && get_operator_precedence(c) <= get_operator_precedence(stack.get_top())) {
                res += stack.get_top();
                stack.pop();
            }
            stack.push(c);
        }
    }
    while(!stack.is_empty()) {
        res += stack.get_top();
        stack.pop();
    }
    return res;
}

int main() {
    string infix = "a+b*(c-d)^e";  
    string postfix = infix_to_postfix(infix);
    cout << postfix << endl;
    return 0;
}