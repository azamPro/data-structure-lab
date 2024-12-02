#include <iostream>
#include <cstring>
#include <stack>
#include <cctype>
#include <cmath>
#include <string>
using namespace std;

// Function to determine the precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to convert infix expression to postfix expression
string infixToPostfix(string infix) {
    stack<char> s;
    string postfix;
    s.push('(');  
    infix += ')'; 

    for (char ch : infix) {
        if (isdigit(ch)) {
            postfix += ch; 
        }
        else if (ch == '(') {
            s.push(ch);
        }
        else if (ch == ')') {
            while (s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); 
        }
        else { 
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    return postfix;
}

// Function to evaluate postfix expression
int evaluatePostfix(string postfix) {
    stack<int> s;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            s.push(ch - '0'); 
        }
        else {
            int op2 = s.top(); s.pop();
            int op1 = s.top(); s.pop();

            switch (ch) {
            case '+': s.push(op1 + op2); break;
            case '-': s.push(op1 - op2); break;
            case '*': s.push(op1 * op2); break;
            case '/': s.push(op1 / op2); break;
            case '^': s.push(pow(op1, op2)); break;
            default:
                cout << "Unknown operator: " << ch << endl;
                return 0;
            }
        }
    }
    return s.top();
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Result of the postfix expression: " << result << endl;

    return 0;
}