#ifndef _STACK_H
#define _STACK_H
#include "LinkedList.h"
using namespace std; 
#include <iostream>


template<class T>
class Stack : public LinkedList<T>
{
    // Public Functions/Variables
    public:
        Stack(); // Constructor
        ~Stack(); // Destructor
        void push(T value);
        T pop();
        T& top();

};


template<class T>
Stack<T>::Stack():LinkedList<T>()
{
}

template<class T>
Stack<T>::~Stack()
{
}

template<class T>
void Stack<T>::push(T value)
{
    LinkedList<T>::insertAtFront(value);
}

template<class T>
T Stack<T>::pop()
{

    Node<T> *temp = LinkedList<T>::first;
    T val = temp -> val;
    LinkedList<T>::removeFromFront();
    return val;

}

template<class T>
T& Stack<T>::top()
{
    Node<T> *n = LinkedList<T>::first;
    return n->val;
}

#endif

