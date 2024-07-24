/*
Author: Jameela Kauser
Date: 2/11/2024
Description: LinkedList class that keeps track of files and filenames (templated)
*/
#ifndef LINKEDLIST_KAUSER_HPP
#define LINKEDLIST_KAUSER_HPP
#include <stdio.h>
#include <iostream>
using namespace std;
template <typename T> class Node
{
    private:
        T item;
        Node<T>* next;
    public:
        T getItem()
        {
            return item;
        }
        Node<T>* getNext()
        {
            return next;
        }
        void setNext(Node<T>* newNext)
        {
            next= newNext;
        }
        Node( T& item){
            this->item=item;
            next=nullptr;
       }        
};
template <typename T> class LinkedList
{
    T item;
    Node<T>* front;
    int count;
    public:
    LinkedList()
    {
        // item=T();
        front=nullptr;
    }
    public: 
    ~LinkedList()
    {
    }
    public:
        Node<T>* getFront()
    {
      return front;  
    }
    void addTail(T data)
    {
        Node<T>* newNode = new Node<T>(data);
          
        if (front == nullptr) 
        {
            newNode->setNext(front);
            front = newNode;
        } 
        else 
        {
            Node<T>* frontTemp = front;
            while ((frontTemp->getNext()) != nullptr) 
            {
                frontTemp = frontTemp->getNext();
            }
            newNode->setNext(nullptr);
            frontTemp->setNext(newNode);
        }
        count++;
    }

    void removeFromList(T& delValue)
    {
        if (front==nullptr)
        {
            throw out_of_range("List Empty");
        }
        Node<T>* currentN=front;
        Node<T>* prevN=nullptr;
        while(currentN!=nullptr)
        {
            if((currentN->getItem().getFileName())==delValue.getFileName())
            {
                break;
            }
            else
            {
            prevN=currentN;
            currentN=currentN->getNext();                
            }
        }
        if(currentN==nullptr) 
        {
            throw out_of_range("File To Delete Not Found!");
        }  
        if(currentN==front)
        {
        front=currentN->getNext();
        }
        else
        {
            prevN->setNext(currentN->getNext());
        }
    }
    int size()
    {
        return count;
    }

};
#endif