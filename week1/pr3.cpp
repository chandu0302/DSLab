#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // for isdigit()

#define MAX 100

int st[MAX];
int top = -1;

void push(int st[], int val);
int pop(int st[]);
int evaluatePostfixExp(char exp[]);

int main() {
    int val;
    char exp[100];
    printf("\nEnter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);
    val = evaluatePostfixExp(exp);
    printf("\nValue of postfix expression is: %d\n", val);
    return 0;
}

int evaluatePostfixExp(char exp[]) {
    int i = 0, op1, op2, val;

    while (exp[i] != '\0' && exp[i] != '\n') {
        if (isdigit(exp[i])) {
            int digit = exp[i] - '0';
            push(st, digit);
        } else if (exp[i] != ' ' && exp[i] != '\t') {
            op2 = pop(st);
            op1 = pop(st);
            switch (exp[i]) {
                case '+':
                    val = op1 + op2;
                    break;
                case '-':
                    val = op1 - op2;
                    break;
                case '*':
                    val = op1 * op2;
                    break;
                case '/':
                    if (op2 == 0) {
                        printf("\nDivision by zero error\n");
                        exit(1);
                    }
                    val = op1 / op2;
                    break;
                case '%':
                    val = op1 % op2;
                    break;
                default:
                    printf("\nInvalid operator: %c\n", exp[i]);
                    exit(1);
            }
            push(st, val);
        }
        i++;
    }

    return pop(st);
}

void push(int st[], int val) {
    if (top == MAX - 1) {
        printf("\nStack overflow\n");
        return;
    }
    st[++top] = val;
}

int pop(int st[]) {
    if (top == -1) {
        printf("\nStack underflow\n");
        return -1;
    }
    return st[top--];
}

