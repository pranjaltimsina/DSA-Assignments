// Exp 2D: Program to evaluate infix expressions
// Author: Pranjal Timsina; 20BDS0392
#include <iostream>
#include <ctype.h>
#include <cmath>
#include <string>

// Initializing a stack
#define MAX 500
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

// returns precedence of an operator
int operator_precedence(char a) {
    switch (a) {
        case '+': case '-': return 1;
        case '*': case '/': case '%': return 2;
        case '^': return 3;
        default: return 0;
    }
}

// -1 for left, 1 for right parantheses
int parentheses(char a) {
    switch (a) {
        case '{': case '(': case '[': return -1;
        case '}': case ']': case ')': return 1;
        default: return 0;
    }
}

// function to convert infix to postfix
std::string infix_to_postfix(std::string infix) {
    std::string postfix{""}, temp; // initialize variables
    infix = '(' + infix + ')'; // surround the expressions
    // variables for processing the infix expression
    char current; int number;
    // loop to traverse the characters in infix expresison
    for (int i = 0; infix[i] != '\0'; i++){
        current = infix[i]; // storing in variable for ease
        // continues if the current character is whitespace
       if (current == ' ') {
            continue;
        }
        else if (isdigit(current)) {
            // checks adjacent characters for digits
            number = (int) (current - '0');
            while (i+1 < MAX && infix[i+1] != '\0' && isdigit(infix[i+1])) {
                i = i+1;
                current = infix[i];
                number = number*10 + (int) current - '0';
            }
            // adds the full number to the postfix expression
            postfix = postfix + std::to_string(number) + " ";
        } else {
            // storing the value of char current to a string
            // to make it a uniform data type for pushing to stack
            temp = current;

            // if the current character is a left parentheses
            // pushes it to the stack
            if (parentheses(current) == -1) push(temp);
            // if the current character is a right parentheses
            // pops everything in the stack and adds it to the postfix expr
            // until a left parentheses is found
            else if (parentheses(current) == 1) {
                while (peek()[0] != '('){
                    postfix +=  pop() + " ";
                }
                pop(); // popping the left parentheses
            }
            // if the stack is empty pushes the operator to stack
            // or the precedence of current operator is greater that the precedence of the stack top
            else if (is_empty() || operator_precedence(current) > operator_precedence(peek()[0])) push(temp);
            else {
                // pops all operators which have lower precedence than the current operator
                // then pushes the current operator to the stack
                while(!is_empty() && (operator_precedence(current) <= operator_precedence(peek()[0]))) {
                    postfix += pop() + " ";
                }
                push(temp);
            }
        }
    }
    return postfix;
}
// initialize stack for operators
int int_stack[500];
int int_top = -1;
void int_push(int data) {
    if(int_top != 499) int_stack[++int_top] = data;
}
int int_pop() {
    if (int_top != -1) return int_stack[int_top--];
    else return 1;
}
// takes operators, operators and applies it
int apply_operator(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return pow(a,b);
        default:
            return 0;
    }
}

int main() {
    std::string infix;
    std::cin >> infix;
    std::string postfix = infix_to_postfix(infix);
    char current;
    int number;
    // traverses the postfix expression
    for (int i = 0; i < MAX && postfix[i] != '\0'; i++) {
        current = postfix[i];
        if (current == ' ') {
            continue;
        }
        if (isdigit(current)) {
            number = (int) current - '0';
            // if the current char is an number,
            // it checks adjacent chars to find out the complete number
            while (i+1 < MAX && postfix[i+1] != '\0' && isdigit(postfix[i+1])){
                current = postfix[++i];
                number = number*10 + ((int)current - '0');
            }
            int_push(number); // pushing number to the stack
        } else if (operator_precedence(current)) {
            // pops two numbers and applies the operator
            // then pushes back the result to the stack
            int_push(apply_operator(int_pop(), int_pop(), current));
        }
    }
    std::cout << "ans = " << int_pop() << std::endl;
    return 0;
}
