/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include <iostream>
#include "split.h"

using namespace std;

Node* makeNode(int val, Node* next = NULL) {
  Node* n = new Node;
  n -> value = val;
  n -> next = next;
  return n;
}

Node* printList(Node* head) {
  while (head != NULL) {
    cout << head -> value << " ";
    head = head -> next;
  }
  cout << endl;
}

void deleteList(Node* head) {
  while (head != NULL) {
    Node* temp = head;
    head = head -> next;
    delete temp;
  }
}

int main(int argc, char* argv[]){
  Node* in = makeNode(1, makeNode(2, makeNode(3,
              makeNode(4, makeNode(5)))));
  Node* odds = NULL;
  Node* evens = NULL;

  cout << "Test: ";
  printList(in);

  split(in, odds, evens);

  cout << "Odds: ";
  printList(odds);

  cout << "Evens: ";
  printList(evens);

  deleteList(evens);
  deleteList(odds);

  return 0;
}
