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
        queue = new int[maxQueueSize];
    }

    void StackQueue::enqueue(int val) {
        if (currentSize == maxQueueSize)
            throw "Failed to enqueue! Queue is full.";
        else {
            long rear = (front + currentSize) % maxQueueSize;
            currentSize++;
            queue[rear] = val;
        }
    }

    int StackQueue::dequeue() {
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

    void StackQueue::print() {
        if (StackQueue::getSize() == 0)
            cout << "[]";
        else {
            long rear = (front + currentSize) % maxQueueSize;
            int output;
            cout << "[";
            if (rear > front) {
                for (long i = front; i < rear; i++){
                    output = queue[i];
                    cout << output << ", ";
                    output = queue[rear - 1];
                    cout << output << "]";
                }
            } else {
                for (long i = front; i < maxQueueSize - 1; i++){
                    output = queue[i];
                    cout << output << ", ";
                    output = queue[maxQueueSize - 1];
                  }
                for (long i = 0; i < rear; i++){
                    cout << output << ", ";
                    output = queue[i];
                }
                  cout << output;
                  cout << "] \n";
            }
        }
    }

    StackQueue::~StackQueue() {
        delete queue;
    }
