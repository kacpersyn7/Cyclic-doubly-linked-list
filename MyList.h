//
// Created by kacper on 09.01.17.
//

#ifndef ZADANIE4_MYLIST_H
#define ZADANIE4_MYLIST_H
#include <stdexcept>
#include <iostream>
#include "ListNode.h"
template <class DT>
class MyList {
public:
    MyList (){};
    ~MyList ();
    typedef ListNode<DT> node;
    int size();
    void insert (const DT &newDataItem);
    void remove ();
    void replace (const DT &newDataItem);
    void clear ();
    bool isEmpty () const { return head == nullptr; }
    //bool isFull () const;
    void gotoBeginning () ;
    void gotoEnd ();
    bool gotoNext ();
    bool gotoPrior ();
    DT getCursor () const;
    void showStructure () const;
private:
    ListNode<DT> *head = nullptr;
    ListNode<DT> *cursor = nullptr;
};

template < class DT >
void MyList<DT>::insert(const DT &newDataItem) {
    if(isEmpty()) {
        head = new ListNode<DT>(newDataItem);
        cursor = head;
    }
    else {
        node *element;
        if(cursor->next != nullptr) {
            element = new ListNode<DT>(newDataItem, cursor, cursor->next);
            cursor->next->prior = element;
        } else
            element = new ListNode<DT>(newDataItem, cursor, nullptr);
        cursor->next = element;
        cursor = element;
    }
}
template < class DT >
MyList<DT>::~MyList() {
    if (!isEmpty()){
        if(head->next == nullptr)
            delete head;
        else{
            ListNode<DT> * ptr = head;
            ListNode<DT> * ptr2 = head;
            while (ptr != nullptr)
            {
                ptr2 = ptr;
                ptr = ptr ->next;
                delete ptr2;
            }
        }
    }
}
template < class DT >
void MyList<DT>::showStructure() const {
    if(!isEmpty()) {
        ListNode<DT> *ptr = head;
        std::cout << ptr->dataItem << " ";
        while (ptr->next != nullptr) {
            ptr = ptr->next;
            std::cout << ptr->dataItem << " ";
        }
        std::cout << "\n";
    }
}
template < class DT >
DT MyList<DT>::getCursor() const {
    if(isEmpty())
        throw std::logic_error("brak elementow!");
    return cursor->dataItem;
}
template < class DT >
void MyList<DT>::gotoBeginning() {
    if(isEmpty())
        throw std::logic_error("brak elementow!");
    cursor = head;
}
template < class DT >
void MyList<DT>::gotoEnd() {
    if(isEmpty())
        throw std::logic_error("brak elementow!");
    while(cursor->next != nullptr)
        gotoNext();
}
template < class DT >
bool MyList<DT>::gotoNext() {
    if(isEmpty() || cursor->next == nullptr) {
        throw std::logic_error("nie istnieje następny element listy");
    }
    cursor = cursor->next;
    if(cursor->next == nullptr)
        return false;
    return true;
}
template < class DT >
bool MyList<DT>::gotoPrior() {
    if(isEmpty() || cursor->prior == nullptr) {
        throw std::logic_error("nie istnieje poprzedni element listy");
    }
    cursor = cursor->prior;
    return true;
}
template < class DT >
void MyList<DT>::remove() {
    if(isEmpty())
        throw std::logic_error("brak elementow!");
    node * temp = cursor;
    if(temp->next != nullptr)
        temp->next->prior = temp->prior;
    if(temp->prior != nullptr)
        temp->prior->next = temp->next;
    if(cursor->prior != nullptr) {
        cursor = cursor->prior;
    }
    else{
        head = nullptr;
        cursor = nullptr;
    }
    delete temp;
}
template < class DT >
void MyList<DT>::replace(const DT &newDataItem) {
    if(isEmpty())
        throw std::logic_error("brak elementow!");
    cursor->dataItem = newDataItem;
}
template < class DT >
void MyList<DT>::clear() {
    if (!isEmpty()) {
        ListNode<DT> *temp = head;
        if (temp->next == nullptr)
            delete temp;
        else {
            do {
                temp = temp->next;
                delete temp->prior;
            } while (temp->next != head);
            delete temp;
        }
    }
    head = nullptr;
    cursor = nullptr;;
}
template < class DT >
int MyList<DT>::size() {
    node *ptr = head;
    int i = 0;
    while(ptr != nullptr)
    {
        ptr = ptr->next;
        ++i;
    }
    return i;
}

#endif //ZADANIE4_MYLIST_H
