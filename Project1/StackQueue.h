/*
StackQueue.h
Using Queues to make a stack
Authors:		Scott Derbes and Jack Butler
Date:	    	2/21/2018
*/

#ifndef STACKQUEUE_H
#define STACKQUEUE_H

class StackQueue{
private:
  long maxQueueSize, front, currentSize;
  int *mainQueue, *tempQueue;

public:
  StackQueue();
  StackQueue(long maxQueueSize);
  ~StackQueue();
  void push(int x);
  void pop();
  void enqueue(int queue[], int val);
  int dequeue(int queue[]);
  long getSize();
  //void print();
};

#endif
