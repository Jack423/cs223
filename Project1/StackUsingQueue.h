#include <iostream>
#include "Queue.h"

using namespace std;

class StackUsingQueue {

    Queue *mainQueue;
    long maxStackSize;

public:
    StackUsingQueue(long maxStackSize) {
        this->maxStackSize = maxStackSize;
        mainQueue = new Queue(maxStackSize);
    }

    ~StackUsingQueue() {
        delete mainQueue;
    }

    void push(int val) {

    }

    int pop() {

    }

    int peek() {

    }

    long getSize() {

    }

    void printArray(int *array, int arrayLength) {
        cout << "[";
        for (int i = 0; i < arrayLength - 1; i++)
            cout << array[i] << ", ";
        cout << array[arrayLength - 1] << "]";
    }

    void print() {
        if (getSize() == 0)
            cout << "[]";
        else {
            long len = mainQueue->getSize();
            int array[len];
            for (long i = mainQueue->getSize() - 1; i >= 0; i--)
                array[i] = mainQueue->dequeue();
            printArray(array, len);
            for (long i = len - 1; i >= 0; i--)
                mainQueue->enqueue(array[i]);
        }
    }
};
