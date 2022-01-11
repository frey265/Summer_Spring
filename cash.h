#ifndef CASH_H
#define CASH_H
#include <iostream>
#include "hash.h"
#include "queue.h"
template<class T,class V>
class Cash{
private:
    double timeToLeave = 5e-6;
    HashMap<T,V>* HashMap;
    QueueItem<T>* Queue;
public:
    Cash()
    {
        timeToLeave = 0;
    }

    void Add(const T& key,const  V& item)
    {
        auto end = std::chrono::high_resolution_clock::now();
        auto curr = Queue->getFirst();
        int _key = Queue->getKey();
        double duration = std::chrono::duration<double, std::milli>(end - curr.second).count();
        std::cout<<duration<<std::endl;
        if((Queue->isEmpty())) //empty
        {
            Queue->Enqueue(key);
            HashMap->insert(key,item);
            return;
        } else if(Queue->getCapacity() >= Queue->getCount() && duration < timeToLeave)//not full but living
        {
            Queue->Enqueue(key);
            HashMap->insert(key,item);
            return;
        } else if(Queue->getCapacity() >= Queue->getCount() && duration > timeToLeave) //not full but dead
            { 
                HashMap->remove(_key); //removes the last element of table
                Queue->Dequeue();  //pops the last element
                Queue->Enqueue(key); //addsnew element to table and queue
                HashMap->insert(key,item);
            }else{//queue is full
                HashMap->remove(_key); //remove last element
                Queue->Dequeue();
                Queue->Enqueue(key);
                HashMap->insert(key,item);
            }
        
    
    }

    void Display()
    {
        Queue->display(); 
        HashMap->printTable();
    }

};
#endif //HASH_H_CASH_H
