#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <iostream>
#include <iterator>
#include <ctime>

    enum class Type{
        Quick,Bubble,Selection
    };
template<class T>
class Sequence{
public:
    virtual const T& getfirst() = 0;
    virtual const T& getlast() = 0;
    virtual bool isempty() = 0;
    virtual void Overflow() = 0;
    virtual void Empty() = 0;
    virtual const T& get(int pos) = 0;
    virtual int get_len() = 0;
    virtual void Append(const T& item) = 0;
    virtual void delete_by_index(int) = 0;
    virtual void insertAt(const T& item, int pos) = 0;
    virtual void Delete_last() = 0;
    virtual void Delete_first() = 0;
    virtual void Sort(Type sort,bool(*Compare)(const T& item1, const T& item2) = 0;
    virtual Sequence<T>* con_cate(Sequence<T>*list) = 0;
    virtual Sequence<T>* subsequence(int startIndex,int endIndex) = 0;
    virtual bool Search(const T &key) = 0;
    virtual Sequence<T>* map(T(*fun)(const T&)) = 0;
    virtual Sequence<T>* where(bool(*cond)(const T&)) = 0;
    virtual void Print() = 0;

};

#endif