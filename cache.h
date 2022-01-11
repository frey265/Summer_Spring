#ifndef CACHE_H
#define CACHE_H
#include <iostream>
#include "hash.h"
#include "queue.h"



template<class T,class V>
class Cache{
private:
    double timeToLeave ;
    HashMap<T,V>* hashmap;
    QueueItem<T>* Queue;
    int size;
public:
    Cache(double lifespan = 30000,int _size = 5)
    {
        hashmap =  new HashMap<T,V>();
        this->timeToLeave = lifespan;
        this->size = _size;
        Queue = new QueueItem<T>();
    }

    void Add(const T& key,const  V& item)
    {
        if(Queue->isEmpty()) //empty
        {
            Queue->Enqueue(key);
            hashmap->insert(key, item);
            return;
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto curr = Queue->getFirst();
        int _key = Queue->getKey();
        double duration = std::chrono::duration<double, std::milli>(end - curr.second).count();

        if(Queue->getCapacity() > Queue->getCount())//not full
        {
            Queue->Enqueue(key);
            hashmap->insert(key, item);
            return;
        } else if(Queue->getCapacity() == Queue->getCount() || duration > timeToLeave) // full and dead
        {
            hashmap->remove(_key); //removes the element corresponding to last element of queue
            Queue->Dequeue();  //pops the last element
            Queue->Enqueue(key); //adds new element to table and queue
            hashmap->insert(key, item);
        }else{//queue is full
            return;
        }


    }

    void Display()
    {
        Queue->display();
        hashmap->printTable();
    }

};
#endif //HASH_H_CASH_H
