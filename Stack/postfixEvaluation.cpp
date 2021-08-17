#include <iostream>
#include "arrayStack.hpp"
using namespace std;

/**
 * Evaluate postfix expression
 * It is inefficient for the computer to evaluate infix expression (repeated traversal is required)
 * so computeres use postfix for evaluating
 * In this program, all the numbers in expression will be single digits
 */

// Evaluate postfix expression
// @param: expression to be evaluated
int evaluate_postfix(const string exp) {
    // To evaluate a postfix expression we loop through the postfix expression
    // if current character is a digit, push it on the stack
    // if it's an operator, pop the last two numbers from stack, and perform that operation on them
    // and push the result to the stack

    char c;
    int op1, op2;
    ArrayStack<int> stack(exp.length());

    for(int i = 0; i < exp.length(); i++) {
        c = exp[i];
        if(isdigit(c)){
            // if it's digit, push it to stack
            stack.push(c-'0'); // convert to integer from character by subtracting '0'(48)
        }else{
            // in case of operator, perform that operation
            switch(c) {
                case '+':
                    op2 = stack.get_top(); stack.pop();
                    op1 = stack.get_top(); stack.pop();
                    stack.push(op1 + op2);
                    break;
                case '-':
                    op2 = stack.get_top(); stack.pop();
                    op1 = stack.get_top(); stack.pop();
                    stack.push(op1 - op2);
                    break;
                case '*':
                    op2 = stack.get_top(); stack.pop();
                    op1 = stack.get_top(); stack.pop();
                    stack.push(op1 * op2);
                    break;
                case '/':
                    op2 = stack.get_top(); stack.pop();
                    op1 = stack.get_top(); stack.pop();
                    stack.push(op1 / op2);
                    break;
                case '^':
                    op2 = stack.get_top(); stack.pop();
                    op1 = stack.get_top(); stack.pop();
                    stack.push(op1 ^ op2);
                    break;
                default:
                    // do nothing in case of invalid operator
                    break;
            }
        }
    }
    return stack.get_top();
}

int main() {
    string exp = "123*+";
    cout << evaluate_postfix(exp) << endl;
    return 0;
}