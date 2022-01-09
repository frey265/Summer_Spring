#ifndef LIST_H
#define LIST_H
#include "sequence.h"
#include <ctime>
#include <chrono>
#include <fstream>

template<class T>
class ListElem
{
public:
    T data;
    ListElem* next;
    explicit ListElem(T _data)
            :data(std::move(_data)),next(NULL)
    {
    }
};

template <class T>class ListSequence: public Sequence <T>
        {
public:
    ListElem<T>* head;
    int a_size;

    ListSequence()
            :head(NULL)
    {
        a_size = 0;
    }

    ListSequence<T>(const ListSequence<T>& list)
            :head(list.head),a_size(list.a_size)
    {}

    bool isempty() override
    {
        if(this->head==NULL)
        {
            return true;
        }
        return false;
    }

    void Empty() override
    {
        {
            std::cout<<"Sequence is empty!\n";
        }
    }
    void Overflow() override{
        std::cout<<"Overflow!\n";
    }

    void Append(const T& item) override
    {
        auto* new_node = new ListElem<T>(item);
        new_node->next = this->head;
        this->head = new_node;
        a_size++;

    }

    void Print() override
    {
        ListElem<T>* temp;
        if(isempty()){
            Empty();
            return;
        }else{
            temp = this->head;
            while (temp)
            {
                std::cout<<temp->data<<" ";
                temp = temp->next;
            }std::cout<<std::endl;
        }
    }

    void delete_by_index(int pos) override
    {
        ListElem<T>* temp;
        temp = this->head;

        if(isempty())
        {
            Empty();
            return;
        }

        if(pos == 0)
        {
            this->head = temp->next;
            free(temp);
        }

        for(int i = 0;i<pos-1 && temp!= NULL; i++)
        {
            temp = temp->next;
        }

        if(temp == NULL)
        {
            return;
        }

        ListElem<T>* curr = temp->next->next;
        free(temp->next);
        temp->next = curr;
        a_size--;

    }

    void Delete_last() override
    {
        if(isempty())
        {
            Empty();
            return;
        }

        ListElem<T>* temp = this->head;
        while (temp->next->next!= NULL)
        {
            temp = temp->next;
        }
        ListElem<T>* last = temp->next;
        temp->next = NULL;
        free(last);
        a_size--;

    }

    void Delete_first()
    {
        if(isempty())
        {
            Empty();
            return;
        }
        ListElem<T>* temp = this->head;
        this->head = temp->next;
        free(temp);
        a_size--;

    }

    const T& getfirst() override
    {
        ListElem<T>* temp = this->head;
        return temp->data;
    }

    const T& getlast() override
    {
        ListElem<T>* temp = this->head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        return temp->data;

    }

    const T& get(int index) override{
        int position = 0;
        ListElem<T>* current = this->head;
        while (current!=NULL)
        {
            if(position == index)
            {
                return current->data;
            }position++;
            current = current->next;
        }
    }

    int get_len() override
    {
        return a_size;
    }

    void insertAt(const T& item, int index) override
    {
        int ptn = 0;
        auto* new_node = new ListElem<T>(item);
        ListElem<T>* curr = this->head;
        while (curr!=NULL)
        {
            if(ptn == index)
            {
                new_node->next = curr->next;
                curr->next = new_node;
                a_size++;
            }
            ptn++;
            curr = curr->next;
        }
    }

    void Push_front(int new_data)
    {
        auto* new_node = new ListElem<T>(new_data);
        auto* last = this->head;
        if(isempty())
        {
            this->head = new_node;
            return;
        }
        while(last->next != NULL)
        {
            last = last->next;
        }
        last->next = new_node;
        new_node->next = NULL;
    }

    bool Search(const T& key) override
    {
        ListElem<T>* current = this->head;
        while(current)
        {
            if(current->data == key)
            {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    Sequence<T>* con_cate(Sequence<T>*list) override
    {
        auto* curr = this->head;
        if(isempty())
        {
            Empty();
            return NULL;
        }
        while (curr!= NULL)
        {
            list->Append(curr->data);
            curr = curr->next;
        }
        return list;

    }

    Sequence<T>* where(bool(*cond)(const T&)) override
    {
        if(isempty())
        {
            return NULL;
        }
        auto* curr = this->head;
        Sequence<T>* ptr = new ListSequence<T>();
        while (curr)
        {
            for(int i = 0; i< this->get_len(); i++)
            {
                if(cond(curr->data))
                {
                    ptr->Append(curr->data);
                }
                curr = curr->next;
            }
        }
        return ptr;
    }

    Sequence<T>* map(T(*f)(const T&)) override
    {
        if(isempty())
        {
            return NULL;
        }
        auto* curr = this->head;
        Sequence<T>* ptr = new ListSequence<T>();
        while (curr)
        {
            for(int i = 0; i< this->get_len(); i++)
            {
                ptr->Append(f(curr->data));
                curr = curr->next;
            }
        }
        return ptr;
    }

    Sequence<T>* subsequence(int startIndex,int endIndex) override
    {
        Sequence<T>* Sub = new ListSequence<T>();
        int counter = 0;
        ListElem<T>* temp = this->head;

        while(temp && counter == startIndex)
        {
            counter++;
            temp = temp->next;
        }
        while (temp && counter== endIndex)
        {
            Sub->Append(temp->data);
            counter++;
            temp = temp->next;
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
        ListElem<T>* curr = this->head;
        ListElem<T>* next_node = NULL;

        for(int i=0; i<this->get_len(); i++)
        {
            next_node = curr->next;
            for(int j = i; j<this->get_len()-1; j++)
            {
                if(Compare(curr->data,next_node->data))
                {
                    Swap(&curr->data,&next_node->data);
                }
                next_node = next_node->next;
            }curr = curr->next;
        }
    }

    void Selection_Sort(bool(*Compare)(const T&, const T&))
    {
        ListElem<T>* temp = this->head;
        while(temp)
        {
            ListElem<T>* min_val = temp;
            ListElem<T>* j = temp->next;
            while(j)
            {
                if(Compare(min_val->data, j->data))
                {
                    min_val = j;
                }   j = j->next;
            }
            Swap(&temp->data,&min_val->data);
            temp = temp->next;
        }
    }

    //quick sort
    ListElem<T>*getTail(ListElem<T>* cur)
    {
        while (cur != NULL && cur->next != NULL)
            cur = cur->next;
        return cur;
    }

    ListElem<T>* partition(ListElem<T>* head, ListElem<T>*end,
                           ListElem<T> **newHead, ListElem<T>** newEnd,
                           bool(*Compare)(const T&, const T&))
    {
        ListElem<T> *pivot = end;
        ListElem<T> *prev = NULL, *cur = head, *tail = pivot;

        while (cur != pivot)
        {
            if (Compare(pivot->data,cur->data))
            {
                if ((*newHead) == NULL)
                    (*newHead) = cur;

                prev = cur;
                cur = cur->next;
            }
            else
            {
                if (prev)
                    prev->next = cur->next;
                ListElem<T> *tmp = cur->next;
                cur->next = NULL;
                tail->next = cur;
                tail = cur;
                cur = tmp;
            }
        }

        if ((*newHead) == NULL)
            (*newHead) = pivot;

        (*newEnd) = tail;

        return pivot;
    }

    ListElem<T> *quickSortRecur(ListElem<T> *head, ListElem<T> *end,bool(*Compare)(const T&, const T&))
    {
        if (!head || head == end)
            return head;

        ListElem<T> *newHead = NULL, *newEnd = NULL;

        ListElem<T> *pivot = partition(head, end, &newHead, &newEnd,Compare);

        if (newHead != pivot)
        {
            ListElem<T> *tmp = newHead;
            while (tmp->next != pivot)
                tmp = tmp->next;
            tmp->next = NULL;

            newHead = quickSortRecur(newHead, tmp,Compare);

            tmp = getTail(newHead);
            tmp->next =  pivot;
        }

        pivot->next = quickSortRecur(pivot->next, newEnd,Compare);

        return newHead;
    }

    void Quick_Sort(ListElem<T> **headRef,bool(*Compare)(const T&, const T&))
    {
        (*headRef) = quickSortRecur(*headRef, getTail(*headRef),Compare);
        return;
    }

    void Sort(Type type,bool (*Compare)(const T& , const T&)) //enum
    {

        switch(type) {
            case Type::Quick: {
                this->Quick_Sort(&(this->head),Compare);
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
                std::cout<<"[_ERROR!_in_list_seq_sort]\n";
                break;
            }
        }
    }

    ~ListSequence()
    {
        delete(head);
    }
};
#endif