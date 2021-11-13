#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <chrono>
#include <fstream>
#include "sequence.h"
template<class T,template<class M>class S>
class Sort {
public:
    Sequence<T> *sequence;

    Sort() {
        sequence = new S<T>();
    }

    static bool Compare(const int& i, const int& j)
    {
        if (i > j)
        {
            return true;
        } else{
            return false;
        }

    }
    double Run_time(Sequence<T>* data,int size)
    {
        int type ;
        std::ofstream Sort_file;
        Sort_file.open("Sort_file");
        for(auto i =0; i<size; i++)
        {
            data->Append(rand()%10000);
        }
        std::cin>>type;
        switch (type) {
            case 1: //Quick
            {
                auto start = std::chrono::high_resolution_clock::now();
                std::cout << "\nQuick Sort_"<<size<<"\n";
                data->Sort(Type::Quick, Compare);
                //sort finished
                auto end = std::chrono::high_resolution_clock::now();// determines stopping point
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
                std::cout << "Elapsed time: " <<  duration.count()  << "ms\n";
                //duration == duration.count();

                break;
            }
            case 2: //Bubble
            {
                auto start = std::chrono::high_resolution_clock::now();
                std::cout << "\nBubble Sort_"<<size<<"\n";
                data->Sort(Type::Bubble, Compare);
                //sort finished
                auto end = std::chrono::high_resolution_clock::now();// determines stopping point
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
                std::cout << "Elapsed time: " <<  duration.count()  << "ms\n";
                break;
            }
            case 3: //Selection
            {
                auto start = std::chrono::high_resolution_clock::now();
                std::cout << "\nBubble Sort_"<<size<<"\n";
                data->Sort(Type::Selection, Compare);
                //sort finished
                auto end = std::chrono::high_resolution_clock::now();// determines stopping point
                auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
                std::cout << "Elapsed time: " <<  duration.count()  << "ms\n";
                break;
            }

            default:
            {
                std::cout<<"_ERROR 1_\n";
                break;
            }

        }

    }
};

#endif