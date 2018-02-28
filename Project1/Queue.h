#include <iostream>
using namespace std;

class Queue {

private:

    long maxQueueSize, front, currentSize;
    int *queue;

public:
    Queue(long maxQueueSize) {
        if (maxQueueSize <= 0)
            throw "Queue size should be a positive integer.";
        this->maxQueueSize = maxQueueSize;
        front = 0;
        currentSize = 0;
        queue = new int[maxQueueSize];
    }

    ~Queue() {
        delete queue;
    }

    void enqueue(int val) {
        if (currentSize == maxQueueSize)
            throw "Failed to enqueue! Queue is full.";
        else {
            long rear = (front + currentSize) % maxQueueSize;
            currentSize++;
            queue[rear] = val;
        }
    }

    int dequeue() {
        if (currentSize == 0)
            throw "Failed to dequeue! Queue is empty.";
        else {
            currentSize--;
            int x = queue[front++];
            if (front == maxQueueSize)
                front = 0;
            return x;
        }
    }

    int peek() {
        if (currentSize == 0)
            throw "Failed to peek! Queue is empty.";
        else
            return queue[front];
    }

    long getSize() {
        return currentSize;
    }

    void print() {
        if (getSize() == 0)
            cout << "[]";
        else {
            long rear = (front + currentSize) % maxQueueSize;
            string output = "[";
            if (rear > front) {
                for (long i = front; i < rear - 1; i++)
                    output += std::to_string(queue[i]) + ", ";
                output += std::to_string(queue[rear - 1]) + "]";
            } else {
                for (long i = front; i < maxQueueSize - 1; i++)
                    output += std::to_string(queue[i]) + ", ";
                output += std::to_string(queue[maxQueueSize - 1]);

                for (long i = 0; i < rear; i++)
                    output += ", " + std::to_string(queue[i]);
                output += "]";
            }
            cout << output;
        }
    }
};
