#ifndef MAIN_CPP_INPUT_GEN_H
#define MAIN_CPP_INPUT_GEN_H
#include <stdlib.h>
#include "array.h"
#include "queue.h"
#include "list.h"

template<class T>
        T* RandomArray(int _size)
        {
            auto *P = new ArraySequence<T>();
            for(int i = 0; i<_size; i++)
            {
                P->Push_back(rand()%100);
            }
            return P;
        }

template<class T>
        T*  ConsoleArray(int _size)
        {
            T _data;
            auto *P = new ArraySequence<T>();
            for(int i = 0; i<_size; i++)
            {
                P->Push_back(std::cin>>_data);
            }

            return P;
        }

template<class T>
        T* RandomList(int _size)
        {
            auto* L = new ListSequence<T>();
            for(int i = 0; i<_size; i++)
            {
                L->Push_back(rand()%100);
            }
            return L;
        }

template<class T>
    T* ConsoleList(int _size)
    {
        auto* L = new ListSequence<T>();
        T _data;
        for(int i = 0; i<_size; i++)
        {
            L->Push_back(std::cin>>_data);
        }
        return L;
    }
//menu2 (determining the size of input data)
template<class T>
    void Menu_Array(){
        int option;
        int _size;
        std::cout<<"Select size of input...\n";
        std::cin>>_size;
        std::cout<<"Select Input Method...\n"
              "1. Random \n"
              "2. Console\n";
        std::cin>>option;

        switch (option)
        {
            case 1://Random generation
            {
                auto *P = new ArraySequence<T>();
                T **q; //generating pointer
                *q = RandomArray<T>(_size);
                P = *q;
                break;
            }

            case 2://Console input
            {
                auto *L = new ListSequence<T>();
                T **s; //generating pointer
                *s = ConsoleArray<T>(_size);
                L = *s;
                break;
            }

            default: {
                std::cout << "Invalid Option!\n"
                             "Select Again\n";
                Menu_Array<T>();
                break;
            }
        }
    }

//inputting a list
template<class T>
    void Menu_list()
    {
        int option;
        int _size;
        std::cout<<"Select size of input...\n";
        std::cin>>_size;
        std::cout<<"Select Input Method...\n"
                   "1. Random \n"
                   "2. Console\n";
        std::cin>>option;
        switch (option)
        {
            case 1: //random list
            {
                auto *P = new ListSequence<T>();
                T **q; //generating pointer
                *q = RandomList<T>(_size);
                P = *q;
                break;
            }

            case 2:
            {
                auto *P = new ListSequence<T>();
                T **s; //generating pointer
                *s = ConsoleArray<T>(_size);
                P = *s;
                break;
            }
            default:
            {
                std::cout<<"Invalid selection!\n"
                           "Select again\n";
                Menu_list<T>();
                break;
            }
        }
    }

    int main() {

       // Menu_Array<T>();
        return 0;
    }

#endif //MAIN_CPP_INPUT_GEN_H
