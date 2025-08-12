#include <stdio.h>
#include <ctype.h>  // for isalnum()
#include <string.h> // for strlen()

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1)
        stack[++top] = c;
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

char peek() {
    if (top >= 0)
        return stack[top];
    return '\0';
}

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int i, k = 0;

    for (i = 0; i < strlen(infix); i++) {
        char ch = infix[i];

        if (isalnum(ch)) {  // Operand
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // Remove '('
        }
        else if (isOperator(ch)) {
            while (top != -1 && precedence(peek()) >= precedence(ch)) {
                // Special case for right-associative '^'
                if (ch == '^' && peek() == '^') break;
                postfix[k++] = pop();
            }
            push(ch);
        }
    }

    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';  // Null-terminate the string
    printf("Postfix: %s\n", postfix);
}

int main() {
    char infix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix);
    return 0;
}