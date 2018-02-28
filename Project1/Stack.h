#include <iostream>
using namespace std;

class Stack {

private:
    long maxStackSize, topOfStack;
    int *stack;

public:

    Stack(long maxStackSize) {
        if (maxStackSize <= 0)
            throw "Stack size should be a positive integer.";
        this->maxStackSize = maxStackSize;
        topOfStack = -1;
        stack = new int[maxStackSize];
    }

    ~Stack() {
        delete stack;
    }

    void push(int val) {
        if (topOfStack == maxStackSize - 1)
            throw "Cannot push! Stack is full.";
        else
            stack[++topOfStack] = val;
    }

    int pop() {
        if (topOfStack == -1)
            throw "Cannot pop! Stack is empty.";
        else
            return stack[topOfStack--];
    }

    long getSize() {
        return topOfStack + 1;
    }

    int peek() {
        if (topOfStack == -1)
            throw "Cannot peek! Stack is empty.";
        else
            return stack[topOfStack];
    }

    void print() {
        if (getSize() == 0) {
            cout << "[]";
        } else {
            cout << "[";
            for (int i = 0; i < getSize() - 1; i++) {
                cout << stack[i] << ", ";
            }
            cout << stack[getSize() - 1] << "]";
        }
    }
};
