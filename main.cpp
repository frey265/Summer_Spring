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


class Animal{
private:
    std::string name;
    int age;
public:
    Animal(){}
    Animal(std::string _name, int _age)
    {
        name = std::move(_name);
        age = _age;
    }
    void get_name(std::string _name)
    {
        name = _name;
    }
    void get_age(int _age)
    {
        age = _age;
    }
};


    bool Cond(const int& data)
    {
        if(data < 5)
        {
            return true;
        } else
        {
            return false;
        }
    }

    int By_2(int data)
    {
        return data*2;
    }


    int main()
    {
        ListSequence<int>* Array = new ListSequence<int>();
        for (int i = 0; i < 100; ++i) {
            Array->Append(rand()%200);
        }
        Array->Print();
        std::cout<<"\nSorted List..\n\n";
        Array->Sort(Type::Quick);

        return 0;
    }