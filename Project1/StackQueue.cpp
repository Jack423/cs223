/*
StackQueue.cpp
Using Queues to make a stack
Authors:		Scott Derbes and Jack Butler
Date:	    	2/21/2018
*/
#include <iostream>
#include "StackQueue.h"
using namespace std;

    StackQueue::StackQueue(long maxQueueSize) {
        if (maxQueueSize <= 0)
            throw "Queue size should be a positive integer.";
        this->maxQueueSize = maxQueueSize;
        front = 0;
        currentSize = 0;
        mainQueue = new int[maxQueueSize];
        tempQueue= new int[maxQueueSize];
    }

    void StackQueue::push(int x){
          while(currentSize != 0){
              int transfer = StackQueue::dequeue(mainQueue);
              StackQueue::enqueue(tempQueue, transfer);
          }

          StackQueue::enqueue(mainQueue, x);

          while(StackQueue::getSize() != 0){
              int putBack = StackQueue::dequeue(tempQueue);
              StackQueue::enqueue(mainQueue, putBack);
          }
    }

    void StackQueue::pop(){
        int popValue = StackQueue::dequeue(mainQueue);
        cout << "The value being popped is " << popValue << "\n";
    }

    void StackQueue::enqueue(int queue[], int val) {
        if (currentSize == maxQueueSize)
            throw "Failed to enqueue! Queue is full.";
        else {
            long rear = (front + currentSize) % maxQueueSize;
            currentSize++;
            queue[rear] = val;
        }
    }

    int StackQueue::dequeue(int queue[]) {
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

    long StackQueue::getSize(){
        return currentSize;
    }
/*
    void StackQueue::print() {
        if (StackQueue::getSize() == 0)
            cout << "[]";
        else {
            long rear = (front + currentSize) % maxQueueSize;
            string output = "[";
            if (rear > front) {
                for (long i = front; i < rear - 1; i++)
                    output += mainQueue[i] + ", ";
                    output += mainQueue[rear - 1] + "]";
            } else {
                for (long i = front; i < maxQueueSize - 1; i++)
                    output += mainQueue[i] + ", ";
                    output += mainQueue[maxQueueSize - 1];

                for (long i = 0; i < rear; i++)
                    output += ", " + mainQueue[i];
                    output += "]";
            }
            cout << output;
        }
    }
*/

    StackQueue::~StackQueue() {
        delete mainQueue;
        delete tempQueue;
    }
