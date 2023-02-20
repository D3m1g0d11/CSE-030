#ifndef LINKEDLIST_H 
#define LINKEDLIST_H
#include <iostream>

#include <string>

using namespace std; 

// Representation of an element in the linked list
template<class T>
struct Node 
{
    T val; // Value of the node
    Node *next; // Pointer to the next node
};

template<class T>
class LinkedList 
{
    // Public Functions/Variables
    public:
        /* IMPLEMENT THESE FUNCTIONS FOR EXERCISE1 */
        LinkedList(); // Constructor
        ~LinkedList(); // Destructor
        void insertAtBack(T valueToInsert);
        bool removeFromBack();
        void print();
        bool isEmpty();
        int size();
        void clear();

        /* IMPLEMENT THSES FUNCTIONS FOR EXERCISE2 */
        void insertAtFront(T valueToInsert);
        bool removeFromFront();

        Node<T> *first; // Pointer pointing to the begining of the list
        Node<T> *last; // Pointer pointing to the end of the list
};


template<class T>
LinkedList<T>::LinkedList()
{
    first = NULL;
    last = NULL;
}

template<class T>
LinkedList<T>::~LinkedList()
{
    while(!isEmpty())
    {
        removeFromBack();
    }
}

template<class T>
void LinkedList<T>::insertAtBack(T valueToInsert)
{
    Node<T> *tmp = new Node<T>();
    tmp ->val = valueToInsert;
    tmp ->next = NULL;
    if(first == NULL)
    {
        first = tmp;
        last = tmp;
    }
    else
    {
        last->next = tmp;
        last = last->next;
    }
}

template<class T>
bool LinkedList<T>::removeFromBack()
{
    if(isEmpty())
    {
        return false;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
        return true;
    }
    else
    {
        Node<T> *temp = first;
        while(temp -> next != last)
        {
            temp = temp ->next;
        }
        last = temp;
        temp = temp -> next;
        delete temp;
        last -> next = NULL;
        return true;
    }
}

template<class T>
void LinkedList<T>::print()
{
    if(first == NULL)
    {
        return;
    }
    Node<T>* tmp = first;
    while(tmp != last)
        {
        cout << tmp->val << ",";
        tmp = tmp->next;
        }
    cout << tmp->val;
}

template<class T>
bool LinkedList<T>::isEmpty()
{
    bool empty = false;
    if(first == NULL)
        {
            empty = true;
        }   
    return empty;
}

template<class T>
int LinkedList<T>::size()
{
    int count;
    if(isEmpty())
    {
        count = 0;
    }
    else
    {
        count = 0;
        Node<T>* tmp = first;
    while(tmp != last)
        {
            count++;
            tmp = tmp->next;
        }
        count++;
    }
    return count;
}

template<class T>
void LinkedList<T>::clear()
{
    while(!isEmpty())
    {
        removeFromBack();
    }
}

//For Excercise 2
template<class T>
void LinkedList<T>::insertAtFront(T valueToInsert)
{
    Node<T> *tmp = new Node<T>();
    tmp ->val = valueToInsert;
    tmp ->next = first;
    if(first == NULL)
    {
        first = tmp;
        last = tmp;
    }
    else
    {
        first = tmp;
    }
}

//For excercise 2
template<class T>
bool LinkedList<T>::removeFromFront()
{
    if(isEmpty())
    {
        return false;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
        return true;
    }
    else
    {
        Node<T> *temp = first;
        first = temp -> next;
        delete temp;
        return true;
    }
}

#endif

