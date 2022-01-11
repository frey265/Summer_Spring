
#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <cstring>
#include <list>
#include <vector>
#include <hashtable.h>
#include "queue.h"

template<class T, class V>
class HashEntry {
private:
    T key;
    V value;
    HashEntry<T,V>* next;
public:

    HashEntry(const T& key, const  V& value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }

    const T& getKey(){return key;}

    const V& getValue() {return value;}

    void setValue(const V& value) {this->value = value;}

    HashEntry<T,V> *getNext() {return next;}

    void setNext(HashEntry<T,V> *next) {this->next = next;}

};

template<class T, class V>
class HashMap{
private:
    HashEntry<T,V> **table;
    int size;
    int count = 0;
public:

    HashMap(int _size = 5) {
        this->size = _size;
        table = new HashEntry<T, V>* [size];
        for (int i = 0; i < size; i++)
            table[i] = NULL;
    }

    int hashFunction(const T& key)
    {
        int hashValue = std::hash<T>{}(key);
        return hashValue%size;
    }

    void insert(const T& key, const V& value)
    {
        int hash = hashFunction(key);
        if (table[hash] == NULL)
            table[hash] = new HashEntry<T,V>(key, value);
        else {
          HashEntry<T,V> *entry = table[hash];
            while (entry->getNext() != NULL)
                entry = entry->getNext();
            entry->setNext(new HashEntry<T,V>(key, value));
        }count++;
    }

    void remove(const T& key)
    {
        int hash = hashFunction(key);
        if (table[hash] != NULL)
        {
           HashEntry<T,V> *prevEntry = NULL;
           HashEntry<T,V> *entry = table[hash];
            while (entry->getNext() != NULL && entry->getKey() != key)
            {
                prevEntry = entry;
                entry = entry->getNext();
            }
            if (entry->getKey() == key)
            {
                if (prevEntry == NULL)
                {
                    HashEntry<T,V> *nextEntry = entry->getNext();
                    delete entry;
                    table[hash] = nextEntry;
                } else {
                    HashEntry<T,V> *next = entry->getNext();
                    delete entry;
                    prevEntry->setNext(next);
                }
                std::cout<<"\n[WARNING!] Entry removed"<<std::endl;
            }count--;
        }else{
            std::cout<<"\n[WARNING!] Entry not found"<<std::endl;
        }
    }

    bool searchTable(const T& key)
    {
        int hash = hashFunction(key);
        if (table[hash] != NULL)
        {
            HashEntry<T,V> *entry = table[hash];
            while (entry->getNext() != NULL && entry->getKey() != key)
            {
                if (entry->getKey() == key)
                {
                    return true;
                }
            } if (entry->getKey() == key)
            {
                return true;
            }
        } return false;

    }

    void printTable()
    {
        for(auto i = 0; i< this->size;i++)
        {
            if(table[i] == NULL)
            {
                continue;
            }else{
                HashEntry<T,V> *entry = table[i];
                while(entry!= NULL)
                {
                    std::cout<<"[INFO] Key:"<<entry->getKey() <<"  Value:" <<entry->getValue()<<std::endl;
                    entry = entry->getNext();
                }
            }
        }
    }

    ~HashMap() {
        for (int i = 0; i < size; i++)
            if (table[i] != NULL) {
              HashEntry<T,V> *prevEntry = NULL;
              HashEntry<T,V> *entry = table[i];
                while (entry != NULL) {
                    prevEntry = entry;
                    entry = entry->getNext();
                    delete prevEntry;
                }
            }
        delete[] table;
    }

};
#endif