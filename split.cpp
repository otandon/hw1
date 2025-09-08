/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
/* Add a prototype for a helper function here if you need */
Node* attach(Node*& list, Node* node);

void split(Node*& in, Node*& odds, Node*& evens) {
  /* Add code here */
// WRITE YOUR CODE HERE
  if (in == NULL) return;

  Node* curr = in;
  Node* next = curr -> next;
  curr -> next = NULL;
  
  if (in -> value % 2 == 0) attach(evens, in);
  else attach(odds, in);

  split(next, odds, evens);
  in = NULL;
}

/* If you needed a helper function, write it here */
Node* attach(Node*& list, Node* node) {
  if (list == NULL) {
    list = node;
    node -> next = NULL;
  }
  else {
    attach(list -> next, node);
  }
}
