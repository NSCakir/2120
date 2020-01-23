/*
 * Name: Enes Cakir
 * Date Submitted:
 * Lab Section: 002
 * Assignment Name: Linked List Based Stacks and Queues
 */
#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Constructs an empty list by initializig this list's instance variables
template <class T>
List<T>::List(){
    start = nullptr;
    mySize = 0;
}

//Destroys all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
    //checks if empty
    if(empty() == true){
        cout << "The List is already empty" << endl;
    }

    //iterates and deletes every node
    else{
        Node<T> *current = start;
        Node<T> *temp;
        while(current -> next != nullptr){
            temp = current;
            current = current -> next;
            free(temp);
        }
        //frees last node
        free(current);
        mySize = 0;
    }
    
}

//Return the size of this list
template <class T>
int List<T>::size(){
    return mySize;
}

//Return true if this list is empty
//Otherwise, returns false
template <class T>
bool List<T>::empty(){
    if(mySize == 0){
        return true;
    }else{
        return false;
    }
}

//Creates a new node with value, and inserts that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){
    //if List is empty, create node at start
    if(empty() == true){
        Node<T> *newNode = new Node<T>(value);
        start = newNode;
        mySize++;
    }
    
    //else, add node to start by making *newNode next point to start
    //and then setting start equal to *newNode
    else{
        Node<T> *newNode = new Node<T>(value);
        newNode -> next = start;
        start = newNode;
        mySize++; 
    }
}

//Creates a new node with value, and inserts that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){
    //Check if list is empty, if so, insert at start
    if(empty() == true){
        insertStart(value);
    }
    
    //else, add node at end
    else{
        Node<T> *newNode = new Node<T>(value);
        Node<T> *current = start;
        
        //iterate until *current node is the final node
        while(current -> next != nullptr){
            current = current -> next;
        }
        //make *current node point to *newNode
        current -> next = newNode;
        mySize++;
    }
}

//Creates a new node with value <value>, and inserts that new node at
//position j
template <class T>
void List<T>::insertAt(T value, int j){
    //check if the list is empty, if so, insert at Start
    if(empty() == true){
       insertStart(value);
    }
    
    //check if j is larger than the size of list
    //if so, insert at end
    else if(j > mySize){
        insertEnd(value);
    }
    
    //check if j is < than.
    else if(j < 0){
        insertStart(value);
    }
    
    //check if j is equal to 1
    else if( j == 0){
        insertStart(value);
        
    }
    
    //if edge cases passed, create two temp nodes
    //one for *current position, other for prev
    else{
        Node<T> *newNode = new Node<T>(value);
        Node<T> *current = start;
        Node<T> *prev = current;
        int i = 0;
        
        //Iterate through until position j is found
        while(i < j){
            prev = current;
            current = current -> next;
            i++;
        }
        //insert node inbetween previous and *current node
        prev -> next = newNode;
        newNode -> next = current;
        mySize++;
    }
}

//Removes node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart(){
    //checks if list is empty
    if(empty() == true){
        cout <<"Error, list is empty" << endl;
    }
    
    //checks if size is 1 and removes
    else if(mySize == 1){
        start = nullptr;
        mySize = 0;
    }
    
    //else, removes start and frees the memory there
    else{
        Node<T> *toFree = start;
        start = start -> next;
        mySize = mySize - 1;
        free(toFree);
    }
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd(){
    //checks if list is empty 
    if(empty() == true){
        cout <<"Error, list is empty" << endl;
    }
    
    //checks if the size is 1
    else if(mySize == 1){
        start = nullptr;
        mySize = 0;
    }
    
    //iterates through and removes end
    else{
        Node<T> *current = start;
        Node<T> *prev = current;
        //iterate until *current node is the final node
        while(current -> next != nullptr){
            prev = current;
            current = current -> next;
        }
        prev -> next = nullptr;
        mySize = mySize - 1;
        free(current);
    }
    
}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j){
    //check if the list is empty, if so, error
    if(empty() == true){
       cout << " Error, list is empty" << endl;
    }
    //check if j is larger than the size
    //if so, removeEnd()
    else if(j > mySize){
        removeEnd();
    }
    
    //check if j is less than 0
    else if(j < 0){
        removeStart();
    }
    //if edge cases passed, create two temp nodes
    //one for *current position, other for prev
    else{
        Node<T> *current = start;
        Node<T> *prev = current;
        int i = 0;
        //Iterate through until position j is found
        while(i < j){
            prev = current;
            current = current -> next;
            i++;
        }
        //delete node inbetween previous and *current node
        prev -> next = current -> next;
        mySize = mySize - 1;
        free(*current);

    }
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst(){
    //check if the list is empty, if so, error
    if(empty() == true){
       cout << " Error, list is empty" << endl;
       return(T());
    }
    
    //else, return start value
    else{
        return(start -> value);
    }
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast(){
    //check if the list is empty, if so, error
    if(empty() == true){
       cout << " Error, list is empty" << endl;
       return(T());
    }
    
    //else, loop through and return end value
    else{
       Node<T> *current = start;
       while(current -> next != nullptr){
           current = current -> next;
       }
       return(current->value);
    }
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){
    //check if the list is empty, if so, error
    if(empty() == true){
       cout << " Error, list is empty" << endl;
       return(T());
    }
    
    //if j > nySize, just return last
    else if(j > mySize){
        getLast();
    }
    
    //check if j < 0
    else if(j < 0){
        getFirst();
    }
    
    //else, iterate through and find j node
    else{
        Node<T> *current = start;
        int i = 0;
        while(i < j){
            current = current -> next;
            i++;
        }
        //after found, return value
        return(current->value);
        
    }
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){
    //check if empty
    if(empty() == true){
        cout << "Error, list empty" << endl;
        return(-1);
    }
    
    //else, create a *current node that will
    //iterate through until its value attribute
    //is equal to the key
    else{
        int position = 0;
        Node<T> *current = start;
        while((current->value != key) && (current -> next != nullptr)){
            current = current -> next;
            position++;
        }
        //once loop ends, check if the value is equal to key
        //needs to be here since the loop will end at either end of list
        //or at key value, so need to know which one
        if(current -> value == key){
            return(position);
        }else{
            return(-1);
        }
    }
}
