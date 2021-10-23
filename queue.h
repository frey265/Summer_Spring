#ifndef QUEUE_H
#define QUEUE_H
#include "sequence.h"

template<class T,template<class M>class S>
class Queue{
public:
    Sequence<T>* sequence;

    Queue()
    {
        sequence = new S<T>();
    }

    void push( T data )
    {
        sequence->Append(data);
    }

    void pop()
    {
        sequence->Delete_last();
    }

    void Search(T item)
    {
        sequence->Search(item);
    }


    Sequence<T>* Where(bool(*cond)(const T&))
    {
        return sequence->where(cond);
    }

    Sequence<T>* Map( T(*fun)(const T&))
    {
        return  sequence->map(fun);
    }

    void Sort(bool(*Compare)(const T& i,const T& j))
    {
        sequence->Sort(Compare);
    }

    T get_first()
    {
       return sequence->getfirst();
    }

    T get_last()
    {
        return sequence->getlast();
    }

    T get_pos(int pos)
    {
       return sequence->get(pos);
    }

    void Del_pos(int pos)
    {
        sequence->delete_by_index(pos);
    }

    void Del_first()
    {
        sequence->Delete_first();
    }

    void Del_last()
    {
        sequence->Delete_last();
    }

    void Insert_At(int pos)
    {
        sequence->insertAt(pos);
    }

    int get_size()
    {
        return sequence->get_len();
    }

    Sequence<T>* Subsequence(int start,int end)
    {
        sequence = sequence->subsequence(start,end);
        return sequence;
    }

    Sequence<T>* Concate(Sequence<T>* list)
    {
        sequence = sequence->con_cate(list);
        return list;
    }

    void Display()
    {
        sequence->Print();
    }

    void Reduce()
    {
        sequence->Delete_last();
    }

    ~Queue()
    {
        delete(sequence);
    }
};
#endif