#ifndef HASH_H_QUEUE_H
#define HASH_H_QUEUE_H
#include <iostream>
#include "hash.h"
#include <queue>
#include <chrono>
#include <ctime>

template<class T>
struct Node{
    std::pair<T,std::chrono::time_point<std::chrono::system_clock>> data;
    Node *next;
};

template<class T>
class QueueItem{
private:
    Node<T> *front;
    Node<T> *rear;
    int count;
    int size;
public:
    QueueItem()
    {
        front = rear = nullptr;
        count = 0;
        size = 5;
    }

    bool isEmpty() 
    {
        if(&(this->front) == &(this->rear))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Enqueue(const T& key)    // for insertion from rear
    {
        Node<T>* NewNode = new Node<T>();
        auto start_time = std::chrono::high_resolution_clock::now();
        NewNode->data.first = key;
        NewNode->data.second = start_time;
        NewNode->next = NULL;
        if(this->rear == NULL){
            front = NewNode;
            rear = NewNode;
            return;
        }else{
            rear->next = NewNode;
            rear = NewNode;
        }
        count++;
    }

    void Dequeue()             // for deletion from front
    {
        Node<T> *temp;
        if(front == NULL)
            std::cout<<"Queue is Empty";
        else
        {
            temp= front;
            front = front->next;
            delete temp;
        }
        count--;
    }

    void display()
    {
        Node<T> *temp;
        temp = front;
        while(temp!=NULL) // (temp!= rear->next)
        {
            std::chrono::time_point<std::chrono::system_clock> time_point;
            time_point = temp->data.second;
            std::time_t ttp = std::chrono::system_clock::to_time_t(time_point);
            std::cout<<"[KEY]:  "<<temp->data.first<<"  [time]:  " <<std::ctime(&ttp);
            temp = temp->next;
        }
        std::cout<<std::endl;
    }

    const std::pair<T,std::chrono::time_point<std::chrono::system_clock>>& getFirst() 
    {
        return front->data;
    }

    int getCapacity() const
    {
        return size;
    }

    int getCount() const
    {
        return count;
    }

    T getKey()
    {
        return front->data.first;
    }
};
#endif //HASH_H_QUEUE_H
