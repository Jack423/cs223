/*
Main.cpp
Stacks, Queues, and Binary Searches
Authors:		Scott Derbes and Jack Butler
Date:	    	2/21/2018
*/

#include <iostream>
//#include "Balancer.h"
#include "StackQueue.h"
using namespace std;

int binarySearch(int *A, int low, int high, int key);
int findPredecessor(int B[], int arrayLen, int key);

int main() {

  //Balancer test(6);
  //test.runBalancer("{{{}}}");

  /*StackUsingQueue stackViaQ(5);
  StackQueue stack(5);
  cout << "**** Push Test ****" << endl << endl;
  for (int i = 1; i <= 5; i++) {
        stackViaQ.push(i);
        stack.push(i);
        cout << "Queue implementation: ";
        stackViaQ.print();
        cout << endl;
        cout << "Standard implementation: ";
        stack.print();
        cout << endl << endl;
    }
  cout << "**** Pop Test ****" << endl << endl;
  for (int i = 1; i <= 5; i++) {
        cout << "Queue implementation: (Popped " << stackViaQ.pop() << ") ";
        stackViaQ.print();
        cout << endl;
        cout << "Standard implementation: (Popped " << stack.pop() << ") ";
        stack.print();
        cout << endl << endl;
    }
*/
  int array[10] = {1,2,3,5,5,5,6,6,7,9};
  int binAnswer = binarySearch(array, 0, 9, 5);

  int array2[7] = {9,10,13,22,31,34,88};
  int pred = findPredecessor(array2, 7,87);
  cout << "The predecessor is " << array2[pred] << "\n\n";

  return 0;
}

int binarySearch(int *A, int low, int high, int key){
          int mid = (low + high)/2;

          cout << "Low = " << low << "\n";
          cout << "High = " << high << "\n";
          cout << "Mid = " << mid << "\n";

  if(A[mid] == key){
              int left = mid;
              int right = mid;

              while(A[left - 1] == key){
                left = left - 1;
              }

              while(A[right + 1] == key){
                right = right + 1;
              }

              int totalKey = right - left;
              cout << "\nThe position of the top most key is " << right <<"\n";
              cout << "The position of the bottom most key is " << left <<"\n";
              cout << "The number of times the key, " << key <<", is used is " << totalKey + 1<< " time(s) \n\n\n";
          }
          else if(A[mid] < key){
               return binarySearch(A, mid + 1, high, key);
          }
          else if(A[mid] > key){
               return binarySearch(A, mid, high - 1, key);
          }
     }

int findPredecessor(int B[], int arrayLen, int key){
        int mid = (0 + arrayLen)/2;

        if(B[mid] == key){
          return mid;
          }
        else if(B[mid] < key){
          while(B[mid + 1] <= key && B[mid + 1] > B[arrayLen]){
              mid = mid + 1;
            }
          return mid;
          }
        else if(B[mid] > key){
            while(B[mid] > key){
              mid = mid - 1;
          }
          return mid;
        }
        else{
          return -1;
        }
     }
