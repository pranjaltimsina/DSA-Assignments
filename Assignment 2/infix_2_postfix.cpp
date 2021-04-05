// 2C: Convert infix expression to postfix
// Author: Pranjal Timsina; 20BDS0392
#include <iostream>
#include <ctype.h>
#include <string>

#define MAX 500

// Initializing a stack
std::string stack[MAX];
int top = -1;

// functions to check if stack is empty or full
bool is_empty() { return (top == -1); }
bool is_full() { return (top == MAX-1); }

// returns the top element of stack without removing
std::string peek() {
    if (is_empty()) { throw "Stack underflow!";}
    return stack[top];
}

// pops the top most element of the stack and decrements top
std::string pop() {
    if (is_empty()) { throw "Stack underflow!";}
    return stack[top--];
}

// pushes data to the stack and increments top
void push(std::string data) {
    if (is_full()) {throw "Stack Overflow!";}
    stack[++top] = data;
}

// if a is an operator, returns its precedence
// if a is not an operator, returns 0
int operator(char a) {
    switch (a) {
        case '+': case '-': return 1;
        case '*': case '/': case '%': return 2;
        case '^': return 3;
        default: return 0;
    }
}

// if a is a left parentheses returns -1
// if a is a right parentheses returns 1
// if a is not a parentheses returns 0
int parentheses(char a) {
    switch (a) {
        case '{': case '(': case '[': return -1;
        case '}': case ']': case ')': return 1;
        default: return 0;
    }
}

// main function to convert infix to postfix
std::string infix_to_postfix(std::string infix) {
    std::string postfix{""}, temp; // initialize variables
    infix = '(' + infix + ')'; // surround the expression
    // variables for processing the infix expression
    char current; int number;

    // loop to traverse the characters in infix expresison
    for (int i = 0; infix[i] != '\0'; i++){

        current = infix[i]; // storing in variable for ease

        // continues if the current character is whitespace
        if (current == ' ') continue;
        else if (isdigit(current)) {
            // if the current character is a digit, it checks the adjacent characters
            // to see if they are digits too, and gets the full number
            number = (int) (current - '0');
            while (i+1 < MAX && infix[i+1] != '\0' && isdigit(infix[i+1])) {
                i = i+1;
                current = infix[i];
                number = number*10 + (int) current - '0';
            }
            // adds the number to the postfix expression
            postfix = postfix + std::to_string(number) + " ";
        } else {
            // storing the value of char current to a string
            // to make it a uniform data type for pushing to stack
            temp = current;
            // if the current character is a left parentheses
            // pushes it to the stack
            if (parentheses(current) == -1) {
                push(temp);
            }
            // if the current character is a right parentheses
            // pops everything in the stack and adds it to the postfix expr
            // until a left parentheses is found
            else if (parentheses(current) == 1) {
                while (peek()[0] != '('){
                    postfix +=  pop() + " ";
                }

                char temp = pop()[0]; // popping the left parentheses
            }
            // if the stack is empty pushes the operator to stack
            // or the precedence of current operator is greater that the precedence of the stack top
            else if (is_empty() || operator(current) > operator(peek()[0])) push(temp);
            else {
                // pops all operators which have lower precedence than the current operator
                // then pushes the current operator to the stack
                while(!is_empty() && (operator(current) <= operator(peek()[0]))) {
                    postfix += pop() + " ";
                }
                push(temp);
            }
        }
    }
    return postfix;
}

int main() {
    std::string infix;
    std::cin >> infix;
    std::cout << infix_to_postfix(infix) << std::endl;
    return 0;
}
