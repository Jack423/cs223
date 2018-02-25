/*
Balancer.cpp
Using Stacks to determine if each paranthesis has a counterpart
Authors:		Scott Derbes and Jack Butler
Date:	    	2/21/2018
*/

#include <iostream>
#include "Balancer.h"
using namespace std;

Balancer::Balancer(long maxStackSize){
  if (maxStackSize <= 0){
            throw "Stack size should be a positive integer.";
        this->maxStackSize = maxStackSize;
        topOfStack = -1;
        stack = new char[maxStackSize];
  }
}

void Balancer::runBalancer(string str){// Input is a string
  string c;
  for(int i = 0; str[i] != '\0'; i++){
//If next Char is "{" or "(", push onto Stack
      if(str[i] == '{' || str[i] == '('){
        Balancer::push(str[i]);
      }
      else{
//If next char is "}" or ")", check if stack is empty
//If not empty, pop
        while(str[i+1] == '}'|| str[i+1] == ')'){
            if(Balancer::getSize() = 0){
                throw "Error: String is unbalanced.";
            }
            else{
              Balancer::pop();
            }
        }

//If the poped char is "{" and closing character is ")" or vice versa
//then string is unbalanced, run error
      if(stack[topOfStack] == '{' && str[i] == ')'){
          throw "Error: String is unbalanced.";
    }

      if(stack[topOfStack] == '(' && str[i] == '}'){
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

  //If the next character is { or (, then push it onto the stack
  //If the next character, say c, is } or ), then check if stack is empty.
  //If stack is empty then the string is unbalanced -- stop the process
  //Otherwise, pop from the stack -- if the popped character is { and c = ) or
  //the
