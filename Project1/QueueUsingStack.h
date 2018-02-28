#include <iostream>
#include "Stack.h"

using namespace std;

class QueueUsingStack {

    Stack *mainStack;
    long maxQueueSize;

public:
    QueueUsingStack(long maxQueueSize) {
        this->maxQueueSize = maxQueueSize;
        mainStack = new Stack(maxQueueSize);
    }

    ~QueueUsingStack() {
        delete mainStack;
    }

    void enqueue(int val) {
        if (getSize() == maxQueueSize)
            throw "Cannot enqueue! Queue is full.";
        else if (getSize() == 0) {
            mainStack->push(val);
        } else {
            Stack tempStack(mainStack->getSize());
            while (mainStack->getSize() > 0)
                tempStack.push(mainStack->pop());
            mainStack->push(val);
            while (tempStack.getSize() > 0)
                mainStack->push(tempStack.pop());
        }
    }

    int dequeue() {
        if (0 == getSize())
            throw "Cannot dequeue! Queue is empty.";
        else
            return mainStack->pop();
    }

    int peek() {
        if (0 == getSize())
            throw "Cannot peek! Queue is empty.";
        else
            return mainStack->peek();
    }

    long getSize() {
        return mainStack->getSize();
    }

    void print() {
        if (getSize() == 0)
            cout << "[]";
        else {
            Stack tempStack(mainStack->getSize());
            while (mainStack->getSize() > 0)
                tempStack.push(mainStack->pop());
            tempStack.print();
            while (tempStack.getSize() > 0)
                mainStack->push(tempStack.pop());
        }
    }
};
