#ifndef ARRAY_H
#define ARRAY_H
#include "sequence.h"
#include "sort.h"
#include <chrono>
#include <fstream>

    template<class T> class ArraySequence:
    public Sequence<T>{
    private:
        T *Array;
        int a_size;
        int capacity;
    public:
    ArraySequence()
    {
        a_size = 4;
        Array = new T[a_size];
        capacity = 0;
    }

    explicit ArraySequence(int size)
    {
        a_size = size;
        Array = new T[a_size];
        capacity = size;
    }

    ArraySequence(const ArraySequence<T> &array)
            : a_size(array.a_size)
    {
        Array = new T[a_size];
        copy(array.Array, array.Array + a_size, Array);
        capacity = a_size;
    }

    void Resize()
    {
        int New_size = a_size * 2;
        auto* temp = new ArraySequence<T>(New_size);
        for(int i=0;i<this->get_len();i++)
        {
            temp->Array[i] = Array[i];
        }
        delete [] Array;
        Array = temp->Array;
        a_size = New_size;
    }

    bool isempty() override
    {
        if(capacity == 0)
        {
            return true;
        }
        else return false;
    }

    void Overflow() override
    {
        std::cout<<"Overflow!!!\n";
    }

    void Empty() override
    {
        {
            std::cout<<"Sequence is empty!\n";
        }
    }

    const T& getfirst() override
    {
        if(isempty())
        {
            Empty();
            //raise exception
        }
        return Array[0];
    }

    const T& getlast() override
    {
        if(isempty())
        {
            Empty();
            //raise exception

        }
        return Array[capacity-1];
    }

    const T& get(int pos) override
    {

        if(isempty())
        {
            Empty();
        }

        if(pos > capacity || pos < 0)
        {
            Overflow();
        }

        return Array[pos];
    }

    int get_len() override
    {
        return capacity;
    }

    void Append(const T& item) override
    {
        if(capacity == a_size)
        {
            Resize();
        }

        if(isempty())
        {
            Array[0] = item;
            capacity++;
        }else
        {
            Array[capacity] = item;
            capacity++;
        }
    }

    void delete_by_index(int pos) override
    {
        if(isempty())
        {
            Empty();
        }else
        {
            for(int i = pos-1; i<capacity; i++)
            {
                Array[i] = Array[i+1];
            }capacity--;
        }
    }

    void Delete_last() override
    {
        if(isempty())
        {
            Empty();
        }else{
            capacity--;
        }
    }

    void Delete_first() override
    {
        if(isempty())
        {
            Empty();
        }else
        {
            for(int i = 0; i<capacity; i++)
            {
                Array[i] = Array[i+1];
            }capacity--;
        }
    }

    void insertAt(const T& item, int index)  override
    {
        if(isempty())
        {
            Append(item);
            return;
        }else
        {
            for(auto i=capacity; i>=index-1; i--)
            {
                Array[i+1] = Array[i];
            }
            Array[index-1] = item;
            capacity++;
            return;
        }
    }

    Sequence<T>* con_cate(Sequence<T>* list) override
    {
        for(int i = 0; i<capacity; i++)
        {
            list->Append(Array[i]);
        }
        return list;
    }

    bool Search(const T& key) override
    {
        if(isempty())
        {
            return false;
        }
        for(int i=0; i<capacity; i++)
        {
            if(/*Array[i] == key - wrong*/ false)
            {
                return true;
            }
        }
        return false;
    }

    Sequence<T>* where( bool(*cond)(const T&) ) override
    {
        auto* ptr = new ArraySequence<T>() ;
        for(int i = 0; i< this->get_len(); i++)
        {
            if(cond(Array[i]))
            {
                ptr->Append(Array[i]);
            }

        }
        return ptr;
    }

    Sequence<T>* map(T(*f)(const T&)) override
    {
        auto* ptr = new ArraySequence<T>();
        for(int i = 0; i< this->get_len(); i++)
        {
            ptr->Append(f(Array[i]));
        }
        return ptr;
    }

    void Print() override
    {
        if(isempty())
        {
            Empty();
            return;
        }else{
            for(int i=0; i<capacity; i++)
            {
                std::cout<< Array[i] <<" ";
            }std::cout<<std::endl;
        }

    }

     Sequence<T>* subsequence(int startIndex,int endIndex) override
     {
         Sequence<T>* Sub = new ArraySequence<T>();
         for(int i = startIndex; i <= endIndex; i++)
         {
             Sub->Append(Array[i]);
         }
         return Sub;
     }


    void Swap(T *a, T *b)
        {
            int temp = *a;
            *a = *b;
            *b = temp;
        }

    void Bubble_Sort(bool(*Compare)(const T&, const T&))
    {
        if(isempty()){
            Empty();
        }
       auto start = std::chrono::high_resolution_clock::now();
        for(int i=0; i<this->get_len(); i++)
        {
            for(int j = i+1; j<this->get_len(); j++)
            {
                if(Compare(Array[i],Array[j]))
                {
                    Swap(&Array[i],&Array[j]);
                }
            }
        }
        auto end = std::chrono::high_resolution_clock::now();// determines stopping point
        this->Print();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "Elapsed time: " <<  duration.count()  << "ms\n";
        //duration_cast<microseconds>(stop - start);
    }

    int Separate(T [],int l_b,int u_b,bool(*Compare)(const T&, const T&)) {
        int pivot = Array[l_b];
        int start = l_b;
        int end = u_b;

        while (start < end) {
            while (Array[start] <= pivot) {
                start++; //stop when curr is < pivot
            }
            while (Array[end] > pivot) {
                end--; //stop when curr is > pivot
            }
            if (Compare(end,start)) {
                std::swap(Array[start], Array[end]); // swap the two positions
            }
        }
        std::swap(Array[l_b], Array[end]);

        return end; //return position of pivot
    }

    void Quick_sort(T[], int low, int high,bool(*Compare)(const T&, const T&))
        {
            if(low < high)
            {
                //pivot is the separation index
                int p_pivot = Separate(Array, low, high,Compare);
                Quick_sort(Array, low, p_pivot-1,Compare);
                Quick_sort(Array,p_pivot+1,high,Compare);
            }
        }

    void Selection_Sort(bool(*Compare)(const T&, const T&))
        {

            for(auto i = 0; i<this->get_len()-1; i++)
            {
                auto min_val = i;
                for(auto j = 1+i; j < this->get_len();j++)
                {
                    if(Compare(Array[j],Array[min_val]))
                    {
                        min_val = j;
                        Swap(&Array[min_val],&Array[i]);
                    }
                }
            }
        }

        void Sort(Type type,bool(*Compare)(const T&, const T&)) override //enum type
        {
            switch(type) {
                case Type::Quick: {
                    this->Quick_sort(Array,0,this->get_len()-1,Compare); //sort start
                    this->Print();
                    break;
                }
                case Type::Bubble:
                {
                    this->Bubble_Sort(Compare);
                    break;
                }
                case Type::Selection:
                {
                    this->Selection_Sort(Compare);
                    break;
                }
                default:{
                    std::cout<<"[_ERROR!_in_array_seq_sort]\n";
                }
            }
        }

        ~ArraySequence()
    {
        delete [] Array;
    }
};
#endif