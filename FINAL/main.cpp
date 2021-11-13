#include<iostream>
#include <algorithm>
#include "sequence.h"
#include "array.h"
#include "list.h"
#include "queue.h"
#include <array>
#include <cassert>
#include <utility>
#include <ctime>
#include <fstream>
#include <chrono>
#include <vector>
using namespace std;

    bool Compare(const int& i, const int& j)
    {
        if (i > j)
        {
            return true;
        } else{
            return false;
        }

    }

    long long int l_get_time(int _size,Type type)
    {
        ListSequence<int>* List = new ListSequence<int>();
        for (auto i = 0; i < _size; i++) {
            List->Append(rand() % 10000);
        }
        auto start = std::chrono::high_resolution_clock::now();
        List->Sort(type, Compare);
        auto end = std::chrono::high_resolution_clock::now();// determines stopping point
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        delete List;
        return duration.count();
    }


    long long int a_get_time(int _size,Type type)
    {
        ArraySequence<int>* Array = new ArraySequence<int>();
        for (auto i = 0; i < _size; i++) {
            Array->Append(rand() % 10000);
        }
        auto start = std::chrono::high_resolution_clock::now();
        Array->Sort(type, Compare);
        auto end = std::chrono::high_resolution_clock::now();// determines stopping point
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        delete  Array;
        return duration.count();
    }

void _Sort()
    {

        int curr = 1;
        std::ofstream Sort_file;
        Sort_file.open("Sort_file");
        std::vector<int> sample_sizes = {1000,10000,50000};
        for(int sample_size : sample_sizes)
        {
            std::cout << "\nQuick Sort_"<<sample_size<<"\n"; Sort_file<<"Quick sort_"<<sample_size<<"\n";
            Sort_file<<"Array\n";

            std::cout<<"                      ARRAY                     \n";
            auto duration = a_get_time(sample_size,Type::Quick);
            std::cout << "Elapsed time: " <<  duration << "ms\n"; Sort_file<<duration<<"ms\n\n";

            std::cout<<"                      LIST                     \n";
            Sort_file<<"List\n";
            duration = l_get_time(sample_size,Type::Quick);
            std::cout << "Elapsed time: " <<  duration  << "ms\n"; Sort_file<<duration<<"ms\n\n";


            std::cout << "\nSelection Sort_"<<sample_size<<"\n"; Sort_file<<"Selection_"<<sample_size<<"\n";

            std::cout<<"                      ARRAY                     \n";
            std::cout << "\nSelection Sort\n"; Sort_file<<"Array\n";
            duration = a_get_time(sample_size,Type::Selection);
            std::cout << "Elapsed time: " <<  duration  << "ms\n"; Sort_file<<duration<<"ms\n\n";

            std::cout<<"                      LIST                     \n";
            Sort_file<<"List\n";
            duration = l_get_time(sample_size,Type::Selection);
            std::cout << "Elapsed time: " <<  duration  << "ms\n"; Sort_file<<duration<<"ms\n\n";

            std::cout << "\nBubble Sort_"<<sample_size<<"\n"; Sort_file<<"Bubble_"<<sample_size<<"\n";

            std::cout<<"                      ARRAY                     \n";
            std::cout << "\nBubble Sort\n"; Sort_file<<"Array\n";
            duration = a_get_time(sample_size,Type::Bubble);
            std::cout << "Elapsed time: " <<  duration  << "ms\n"; Sort_file<<duration<<"ms\n\n";

            std::cout<<"                      LIST                     \n";
            Sort_file<<"List\n";
            duration = l_get_time(sample_size,Type::Bubble);
            std::cout << "Elapsed time: " <<  duration  << "ms\n"; Sort_file<<duration<<"ms\n\n";
        }
       /* while (curr<=3)
        {
            switch (curr)
            {
                case 1: {
                    std::cout << "\nQuick Sort_1000\n"; Sort_file<<"Quick sort_1000\n";
                    Sort_file<<"Array\n";

                    std::cout<<"                      ARRAY                     \n";
                    auto duration = a_get_time(1000,Type::Quick);
                    std::cout << "Elapsed time: " <<  duration << "ms\n"; Sort_file<<duration<<"ms\n";

                    std::cout<<"                      LIST                     \n";
                    Sort_file<<"List\n";
                    duration = l_get_time(1000,Type::Quick);
                    std::cout << "Elapsed time: " <<  duration  << "ms\n"; Sort_file<<duration<<"ms\n";


                    std::cout << "\nSelection Sort_1000\n"; Sort_file<<"Selection_1000\n";

                    std::cout<<"                      ARRAY                     \n";
                    std::cout << "\nSelection Sort\n"; Sort_file<<"Array\n";
                    duration = a_get_time(1000,Type::Selection);
                    std::cout << "Elapsed time: " <<  duration  << "ms\n"; Sort_file<<duration<<"ms\n";

                    std::cout<<"                      LIST                     \n";
                    Sort_file<<"List\n";
                    duration = l_get_time(1000,Type::Selection);
                    std::cout << "Elapsed time: " <<  duration  << "ms\n"; Sort_file<<duration<<"ms\n";

                    std::cout << "\nBubble Sort_1000\n"; Sort_file<<"Bubble_1000\n";

                    std::cout<<"                      ARRAY                     \n";
                    std::cout << "\nBubble Sort\n"; Sort_file<<"Array\n";
                    duration = a_get_time(1000,Type::Bubble);
                    std::cout << "Elapsed time: " <<  duration  << "ms\n"; Sort_file<<duration<<"ms\n";

                    std::cout<<"                      LIST                     \n";
                    Sort_file<<"List\n";
                    duration = l_get_time(1000,Type::Bubble);
                    std::cout << "Elapsed time: " <<  duration  << "ms\n"; Sort_file<<duration<<"ms\n";
                    break;
                }
                case 2:
                {
                    std::cout << "\nQuick Sort_10000\n"; Sort_file<<"Quick sort_10000\n";
                    Sort_file<<"Array\n";

                    std::cout<<"                      ARRAY                     \n";
                    auto duration = a_get_time(10000,Type::Quick);
                    std::cout << "Elapsed time: " <<  duration << "ms\n"; Sort_file<<duration<<"ms\n";

                    std::cout<<"                      LIST                     \n";
                    Sort_file<<"List\n";
                    duration = l_get_time(10000,Type::Quick);
                    std::cout << "Elapsed time: " <<  duration  << "ms\n"; Sort_file<<duration<<"ms\n";


                    std::cout << "\nSelection Sort_10000\n"; Sort_file<<"Selection_10000\n";

                    std::cout<<"                      ARRAY                     \n";
                    std::cout << "\nSelection Sort\n"; Sort_file<<"Array\n";
                    duration = a_get_time(10000,Type::Selection);
                    std::cout << "Elapsed time: " <<  duration  << "ms\n"; Sort_file<<duration<<"ms\n";

                    std::cout<<"                      LIST                     \n";
                    Sort_file<<"List\n";
                    duration = l_get_time(10000,Type::Selection);
                    std::cout << "Elapsed time: " <<  duration  << "ms\n"; Sort_file<<duration<<"ms\n";

                    std::cout << "\nBubble Sort_10000\n"; Sort_file<<"Bubble_10000\n";

                    std::cout<<"                      ARRAY                     \n";
                    std::cout << "\nBubble Sort\n"; Sort_file<<"Array\n";
                    duration = a_get_time(10000,Type::Bubble);
                    std::cout << "Elapsed time: " <<  duration  << "ms\n"; Sort_file<<duration<<"ms\n";

                    std::cout<<"                      LIST                     \n";
                    Sort_file<<"List\n";
                    duration = l_get_time(10000,Type::Bubble);
                    std::cout << "Elapsed time: " <<  duration  << "ms\n"; Sort_file<<duration<<"ms\n";

                    break;
                }
                case 3:
                {
                    std::cout << "\nQuick Sort_50000\n"; Sort_file<<"Quick sort_50000\n";
                    Sort_file<<"Array\n";

                    std::cout<<"                      ARRAY                     \n";
                   //auto duration = 0;
                   // = a_get_time(100000,Type::Quick);
                   // std::cout << "Elapsed time: " <<  duration << "ms\n"; Sort_file<<duration<<"ms\n";

                    std::cout<<"                      LIST                     \n";
                    Sort_file<<"List\n";
                    auto duration = l_get_time(50000,Type::Quick);
                    std::cout << "Elapsed time: " <<  duration  << "ms\n"; Sort_file<<duration<<"ms\n";


                    std::cout << "\nSelection Sort_50000\n"; Sort_file<<"Selection_50000\n";

                    std::cout<<"                      ARRAY                     \n";
                    std::cout << "\nSelection Sort\n"; Sort_file<<"Array\n";
                   // duration = a_get_time(100000,Type::Selection);
                    std::cout << "Elapsed time: " <<  duration  << "ms\n"; Sort_file<<duration<<"ms\n";

                    std::cout<<"                      LIST                     \n";
                    Sort_file<<"List\n";
                    duration = l_get_time(50000,Type::Selection);
                    std::cout << "Elapsed time: " <<  duration  << "ms\n"; Sort_file<<duration<<"ms\n";

                    std::cout << "\nBubble Sort_50000\n"; Sort_file<<"Bubble_50000\n";

                    std::cout<<"                      ARRAY                     \n";
                    std::cout << "\nBubble Sort\n"; Sort_file<<"Array\n";
                   // duration = a_get_time(100000,Type::Bubble);
                    std::cout << "Elapsed time: " <<  duration  << "ms\n"; Sort_file<<duration<<"ms\n";

                    std::cout<<"                      LIST                     \n";
                    Sort_file<<"List\n";
                   // duration = l_get_time(50000,Type::Bubble);
                    std::cout << "Elapsed time: " <<  duration  << "ms\n"; Sort_file<<duration<<"ms\n";
                    break;
                }
                default:
                {
                    std::cout<<"_ERROR_\n";
                    _Sort();
                    break;
                }
            }

            curr++;
        }*/
        Sort_file.close();
    }
    int main()
    {
      // Sort<int,ArraySequence>* data = new Sort<int, ArraySequence>();
      // data->Run_time()
      _Sort();
        return 0;
    }