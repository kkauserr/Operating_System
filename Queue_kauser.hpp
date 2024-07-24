/*
Author: Jameela Kauser
Date: 2/11/2024
Description: keeps track of available block in hardware (templated) 
*/
#include <stdio.h>
#include <iostream>
using namespace std;
template <typename T> class QueueNode
{
    private:
        T item;
        QueueNode<T>* next;
    public:
        T getItem()
        {
            return item;
        }
        QueueNode<T>* getNext()
        {
            return next;
        }
        void setNext(QueueNode<T>* newNext)
        {
            next= newNext;
        }
        QueueNode( T item){
            this->item=item;
            next=nullptr;
       }        
};
template <typename T> class Queue
{
    T item;
    int count;
    QueueNode<T>* frontN;
    QueueNode<T>* endN;
    public:
    Queue()
    {
        frontN=nullptr;
        endN=nullptr;
        count=0;
    }
    public:
    void enqueue(T newItem)
    {
       QueueNode<T>* nodeNew= new QueueNode<T>(newItem);
       if (endN == nullptr) {
            frontN = endN = nodeNew;
        } else {
            endN->setNext(nodeNew);
            endN =nodeNew;
        }
        count++;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            throw out_of_range("Attempted to delete but queue is empty");
        }
        QueueNode<T>* frontTemp = frontN;
        frontN=frontN->getNext();
        if (frontN == nullptr) 
        {
            endN = nullptr;
        }
        delete frontTemp;
        count--;
    }
    T front()
    {
        return frontN->getItem();
    }
    int size()
    {
        return count;
    }
    void empty()
    {
        while(!isEmpty())
        {
            dequeue();
        }
    }
    bool isEmpty()
    {
        return (count==0);
    }
    ~Queue()
            {
                empty();
            }
};