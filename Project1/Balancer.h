/*
Balancer.h
Using Stacks to determine if each paranthesis has a counterpart
Authors:		Scott Derbes and Jack Butler
Date:	    	2/21/2018
*/
#ifndef BALANCER_H
#define BALANCER_H

#include <string>

class Balancer{
private:
  long maxStackSize, topOfStack;
  char *stack;
public:
    Balancer();
    Balancer(long maxStackSize);
    ~Balancer();
    void runBalancer(std::string statement);
    void push(char val);
    char pop();
    long getSize();
    //char peek();
    //void print();
};
#endif
