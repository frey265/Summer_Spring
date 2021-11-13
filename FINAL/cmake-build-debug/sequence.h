#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
#include <iterator>
#include <ctime>

template<class T>
class Sequence{
public:
    virtual T getfirst() = 0;
    virtual T getlast() = 0;
    virtual bool isempty() = 0;
    virtual void Overflow() = 0;
    virtual void Empty() = 0;
    virtual T get(int index) = 0;
    virtual int get_len() = 0;
    virtual void Push_back(T item) = 0; // change to -> append
    virtual void delete_by_index(int) = 0;        // change to delete by index
    virtual void insertAt(T item, int index) = 0;
    virtual void Delete_last() = 0;
    virtual void Delete_first() = 0;
    virtual Sequence<T>* con_cate(Sequence<T>*list) = 0;
    //virtual Sequence<T>* getsubsequence(int startIndex,int endIndex) = 0;
    virtual bool Search(T key) = 0;
    virtual Sequence<T>* map(T item) = 0;
    virtual void where(T item) = 0;
    virtual void Print() = 0;

};

#endif