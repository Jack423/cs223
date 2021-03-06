/*
Balancer.cpp
Using Stacks to determine if each paranthesis has a counterpart
Authors:		Scott Derbes and Jack Butler
Date:	    	2/21/2018
*/

#include <iostream>
#include "Balancer.h"
#include <string>
using namespace std;

Balancer::Balancer(long maxStackSize){
  if (maxStackSize <= 0){
            throw "Stack size should be a positive integer.";
        this->maxStackSize = maxStackSize;
        topOfStack = -1;
        stack = new char[maxStackSize];
  }
}

void Balancer::runBalancer(string balStr){// Input is a string

  for(int i = 0; balStr[i] != '\0'; i++){
//If next Char is "{" or "(", push onto Stack
      if(balStr[i] == '{' || balStr[i] == '('){
          Balancer::push(balStr[i]);
      }
      else{
//If next char is "}" or ")", check if stack is empty
//If not empty, pop
          char c = Balancer::pop();
//If the poped char is "{" and closing character is ")" or vice versa
//then string is unbalanced, run error
          if(c == '{' && balStr[i] == ')'){
              throw "Error: String is unbalanced.";
          }

          if(c == '(' && balStr[i] == '}'){
              throw "Error: String is unbalanced.";
            }
      }
}
//If stack is not empty && string is read through then unbalanced
//and run error
  if(stack[topOfStack] >= 0){
    throw "Error: The string is unbalanced";
  }
  else{
    cout << "Things probably went right";
  }
  cout << "Stuff happened";
}

void Balancer::push(char val){
  if (topOfStack == maxStackSize - 1){
            throw "Cannot push! Stack is full.";
      }
  else{
      stack[++topOfStack] = val;
    }
}

char Balancer::pop(){
  if (topOfStack == -1){
            throw "Cannot pop! Stack is empty.";
          }
  else{
            return stack[topOfStack--];
  }
}

long Balancer::getSize() {
        return topOfStack + 1;
    }

Balancer::~Balancer(){
  delete stack;
}

char peek() {

}

void print() {

}
