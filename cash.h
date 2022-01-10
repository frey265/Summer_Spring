#ifndef HASH_H_CASH_H
#define HASH_H_CASH_H
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
        if(!(Queue->isEmpty()))
        {
            Queue->Enqueue(key);
            HashMap->insert(key,item);
            return;
        } else{
        while (!(Queue->isEmpty()))
        {
            auto end = std::chrono::high_resolution_clock::now();
            auto curr = Queue->getFirst();
            double duration = std::chrono::duration<double, std::milli>(end - curr.second).count();
            if(duration<timeToLeave)
            {
                Queue->Enqueue(key);
                HashMap->insert(key,item);
            }else{
                HashMap->remove(key);
                Queue->Dequeue();
            }
        }
    }
    }

    void Display()
    {
        HashMap->printTable();
    }

};
#endif //HASH_H_CASH_H
