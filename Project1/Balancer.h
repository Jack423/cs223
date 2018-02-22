/*
Balancer.h
Using Stacks to determine if each paranthesis has a counterpart
Authors:		Scott Derbes and Jack Butler
Date:	    	2/21/2018
*/

class Stack{
private:
  long maxStackSize, topOfStack;
  int *stack;
public:
    Stack(long maxStackSize);
    ~Stack();
    void push(char val);
    char pop();
    long getSize();
    char peek();
    void print();
};
